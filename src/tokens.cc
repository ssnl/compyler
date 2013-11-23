/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* tokens.cc: Definitions related to AST_Token and its subclasses. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include <cerrno>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

static GCINIT _gcdummy;

/** Default print for tokens. */
void
AST_Token::_print (ostream& out, int indent)
{
    out << "(<Token>)";
}

/** Default implementation. */
gcstring
AST_Token::string_text () const
{
    throw logic_error ("unimplemented operation: string_text");
}

/** Default implementation. */
void
AST_Token::append_text(const gcstring& s)
{
    throw logic_error ("unimplemented operation: append_text");
}


/** The supertype of tokens with a type. */
class Typed_Token : public AST_Token {
public:

    Type_Ptr getType () {
        if (_type == NULL)
            _type = computeType ();
        return _type;
    }

protected:

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities,
                          bool& errors) {
        if (_type == NULL) {
            _type = computeType ();
        }
        return this;
    }

    /** Computes my type, which is then cached by getType(). */
    virtual Type_Ptr computeType () {
        return NULL;
    }

    Type_Ptr _type;

    TOKEN_BASE_CONSTRUCTORS (Typed_Token, AST_Token);

};

/** Represents an integer literal. */
class Int_Token : public Typed_Token {
protected:

    void _print (ostream& out, int indent) {
	out << "(int_literal " << lineNumber () << " " << value
	    << ")";
    }

    TOKEN_CONSTRUCTORS(Int_Token, Typed_Token);

    Int_Token* post_make () {
        gcstring text = as_string ();
        errno = 0;
        value = strtol (text.c_str (), (char**) NULL, 0);
        if (errno != 0 || value > (1L<<30)) {
            error (loc (), "literal value out of range: %s",
                   text.c_str ());
            value = 0;
        }
        return this;
    }

    Type_Ptr computeType () {
        return primitiveDecls[Int]->asType();
    }

    long value;

};

TOKEN_FACTORY(Int_Token, INT_LITERAL);

/** Represents an identifier. */
class Id_Token : public Typed_Token {
protected:

    void _print (ostream& out, int indent) {
	    out << "(id " << lineNumber () << " " << as_string ();
        if (getDecl () != NULL)
            out << " " << getDecl ()->getIndex ();
        out << ")";
    }

    TOKEN_CONSTRUCTORS (Id_Token, Typed_Token);

    int numDecls () {
        return _me.size ();
    }

    Decl* getDecl (int k = 0) {
        if (k >= (int) _me.size ())
            return NULL;
        else
            return _me[k];
    }

    void addDecl (Decl* decl) {
        _me.push_back (decl);
    }

    void removeDecl (int k) {
        assert (k >= 0 && k < (int) _me.size ());
        _me.erase (_me.begin () + k);
    }

    Type_Ptr computeType () {
        if (numDecls() > 1) {
            return ambiguous_type;
        }
        return getDecl()->getType();
    }

    AST_Ptr rewriteNone () {
        gcstring text = as_string();
        if (text == "None") {
            AST_Ptr noneId = make_token(ID, 8, "__None__");
            AST_Ptr body = consTree(EXPR_LIST);
            AST_Ptr call = consTree(CALL, noneId, body);
            noneId->set_loc(loc());
            body->set_loc(loc());
            call->set_loc(loc());
            return call;
        }
        return this;
    }

    AST_Ptr rewriteSimpleTypes (const Environ* env) {
        gcstring text = as_string();
        Decl* decl = env->find(text);
        if (decl == NULL) {
            error (loc(), "name error: name '%s' is not defined",
                   text.c_str());
        } else if (decl->isType()) {
            AST_Ptr params = consTree(TYPE_LIST);
            AST_Ptr type = consTree(TYPE, this, params);
            params->set_loc(loc());
            type->set_loc(loc());
            return type;
        }
        return this;
    }

    void resolveSimpleIds (const Environ* env) {
        gcstring text = as_string();
        Decl_Vector decls;
        env->find(text, decls);
        if (!decls.empty()) {
            for (int i = decls.size() - 1; i >= 0; i--)
                addDecl(decls.at(i));
        } else {
            error (loc(), "name error: name '%s' is not defined", text.c_str());
        }
    }

    void addTargetDecls (Decl* enclosing) {
        gcstring text = as_string();
        Decl* decl = curr_environ->find_immediate(text);
        if (decl == NULL) {
            decl = enclosing->addVarDecl(this);
            curr_environ->define(decl);
        }
    }

    void addParamDecls (Decl* enclosing, int k) {
        gcstring text = as_string();
        Decl* decl = enclosing->getEnviron()->find_immediate(text);
        if (decl == NULL) {
            Decl *decl = makeParamDecl (as_string(), enclosing, k,
                Type::makeVar ());
            enclosing->addMember(decl);
            curr_environ->define(decl);
        } else {
            error (loc(), "syntax error: duplicate argument '%s' in function definition",
                text.c_str());
        }
    }

private:

    Decl_Vector _me;

};

TOKEN_FACTORY(Id_Token, ID);

/** Represents a string. */
class String_Token : public Typed_Token {
private:

    String_Token* post_make () {
        if (syntax () == RAWSTRING) {
            literal_text = gcstring (as_chars (), text_size ());
        } else {
            int v;
            const char* s = as_chars ();
            size_t i;
            i = 0;
            literal_text.clear ();
            while (i < text_size ()) {
                i += 1;
                if (s[i-1] == '\\') {
                    i += 1;
                    switch (s[i-1]) {
                    default: literal_text += '\\'; v = s[i-1]; break;
                    case '\n': continue;
                    case 'a': v = '\007'; break;
                    case 'b': v = '\b'; break;
                    case 'f': v = '\f'; break;
                    case 'n': v = '\n'; break;
                    case 'r': v = '\r'; break;
                    case 't': v = '\t'; break;
                    case 'v': v = '\v'; break;
                    case '\'': v = '\''; break;
                    case '"': case '\\': v = s[i-1]; break;
                    case '0': case '1': case '2': case '3': case '4':
                    case '5': case '6': case '7':
                    {
                        v = s[i-1] - '0';
                        for (int j = 0; j < 2; j += 1) {
                            if ('0' > s[i] || s[i] > '7')
                                break;
                            v = v*8 + (s[i] - '0');
                            i += 1;
                        }
                        break;
                    }
                    case 'x': {
                        if (i+2 > text_size () ||
                            !isxdigit (s[i]) || !isxdigit (s[i+1])) {
                            error (s, "bad hexadecimal escape sequence");
                            break;
                        }
                        sscanf (s+i, "%2x", &v);
                        i += 2;
                        break;
                    }
                    }
                } else
                    v = s[i-1];
                literal_text += (char) v;
            }
        }
        return this;
    }

    void _print (ostream& out, int indent) {
        out << "(string_literal " << lineNumber () << " \"";
        for (size_t i = 0; i < literal_text.size (); i += 1) {
            char c = literal_text[i];
            if (c < 32 || c == '\\' || c == '"') {
                out << "\\" << oct << setw (3) << setfill('0') << (int) c
                    << setfill (' ') << dec;
            } else
                out << c;
        }
        out << "\")";
    }

    gcstring string_text () const {
        return literal_text;
    }

    void append_text(const gcstring& s) {
        literal_text += s;
    }

    Type_Ptr computeType () {
        return primitiveDecls[Str]->asType();
    }

    TOKEN_CONSTRUCTORS(String_Token, Typed_Token);
    static const String_Token raw_factory;

    gcstring literal_text;
};

TOKEN_FACTORY(String_Token, STRING);

/** A dummy token whose creation registers String_Token as the class
 *  to use for RAWSTRING tokens produced by the lexer.  (The
 *  TOKEN_FACTORY macro above registers String_Token as the class for
 *  non-raw STRING tokens as well.)
 */
const String_Token String_Token::raw_factory (RAWSTRING);

