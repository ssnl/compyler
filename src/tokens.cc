/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* tokens.cc: Definitions related to AST_Token and its subclasses. */

/* Authors:  YOUR NAMES HERE */

#include <cctype>
#include <iostream>
#include <cerrno>
#include <sstream>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

static GCINIT _gcdummy;

/** True iff NAME is a special identifier that does not participate in
 *  symbol resolution. */
static bool
leaveUnresolved (const gcstring& name)
{
    int c0 = name[0];
    return !(islower (c0) || isupper (c0) || c0 == '_')
        || name == "is" || name == "in" || name == "not"
        || name == "notin" || name == "isnot";
}

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

    bool setType (Type_Ptr type) {
        if (_type == NULL) {
            _type = type;
            return true;
        } else return _type->unify (type);
    }

protected:

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
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

    TOKEN_BASE_CONSTRUCTORS_INIT (Typed_Token, AST_Token, _type (NULL));

};

/** Represents an integer literal. */
class Int_Token : public Typed_Token {
protected:

    void _print (ostream& out, int indent) {
	out << "(int_literal " << lineNumber () << " " << value
	    << ")";
    }

    TOKEN_CONSTRUCTORS(Int_Token, Typed_Token);

    void exprCodeGen (int depth) {
        // e.g. new int_0$ (5)
        stringstream ss;
        ss << "new " << intDecl->getRuntimeName () << " (";
        ss << as_string () << ")";
        VM->emit (ALLOC, ss.str ());
        VM->emit (PUSH);
    }

    Int_Token* post_make () {
        gcstring text = as_string ();
        errno = 0;
        value = strtol (text.c_str (), (char**) NULL, 0);
        if (errno != 0 || value > (1L<<30)) {
            error (this, "literal value out of range: %s",
                   text.c_str ());
            value = 0;
        }
        return this;
    }

    Type_Ptr computeType () {
        return intDecl->asType ();
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

    AST_Ptr getId () {
        return this;
    }

    int numDecls () {
        return _me.size ();
    }

    Decl* getDecl (int k = 0) {
        if (k >= (int) _me.size ())
            return NULL;
        else
            return _me[k];
    }

    bool isType () {
        Decl* me = getDecl ();
        return (me != NULL && me->isType ());
    }

    void addDecl (Decl* decl) {
        _me.push_back (decl);
    }

    void removeDecl (int k) {
        assert (k >= 0 && k < (int) _me.size ());
        _me.erase (_me.begin () + k);
    }

    void addTargetDecls (Decl* enclosing) {
        gcstring name = as_string ();
        if (undefinable (name)) {
            error (this, "attempt to redefine %s", name.c_str ());
            return;
        }
        Decl* old = enclosing->getEnviron ()->find_immediate (name);
        if (old == NULL) {
            addDecl (enclosing->addVarDecl(this));
        } else if (! old->assignable ()) {
            error (this, "attempt to assign to non-assignable object: %s",
                   name.c_str ());
            addDecl (old);
        } else {
            addDecl (old);
        }
    }

    void exprCodeGen (int depth) {
        // e.g. ((__main__*) cf->sl->sl) -> x
        gcstring expr;
        gcstring runtimeName = getDecl ()->getRuntimeName ();
        gcstring frameName = getDecl ()->getContainer ()->getRuntimeName();
        int myDepth = getDecl ()->getDepth ();

        gcstring frameString = VM->staticLinkStr (myDepth, depth);
        expr += VM->typeCastStr (frameName + "*", frameString);
        expr += VM->fieldAccessStr (expr, runtimeName);

        VM->emit (PUSH, expr);
    }

    AST_Ptr resolveSimpleIds (const Environ* env) {
        gcstring name = as_string ();
        if (leaveUnresolved (name))
            return this;
        if (getDecl () != NULL)
            return this;
        Decl_Vector defns;
        env->find (name, defns);
        if (defns.empty ()) {
            error (this, "undefined identifier: %s", name.c_str ());
            addDecl (makeUnknownDecl (name, false));
            return this;
        }
        if (defns.size () == 1 && defns[0]->isType ()) {
            addDecl (defns[0]);
            return consTree (TYPE, this, consTree(TYPE_LIST));
        }
        for (size_t i = 0; i < defns.size (); i += 1)
            addDecl (defns[i]);
        return this;
    }

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        if (leaveUnresolved (as_string ()))
            return this;
        if (_type == NULL) {
            if (_me.size () == 1) {
                _type = _me[0]->getType ();
            } else {
                _type = Type::makeVar ();
                ambiguities += _me.size () - 1;
            }
            return this;
        }
        for (int i = _me.size () - 1; i >= 0; i -= 1) {
            if (!_type->unifies (_me[i]->getType ())) {
                _me.erase (_me.begin () + i);
            }
        }
        if (_me.size () == 0)
            error (this, "%s has no definition consistent with the context",
                   as_string ().c_str ());
        else if (_me.size () == 1) {
            resolved += 1;
            if (!setType (_me[0]->getType ()))
                error (this,
                       "%s has no definition consistent with the context",
                       as_string ().c_str ());
        } else {
            ambiguities += _me.size () - 1;
        }
        return this;
    }

    void resolveSelectedType (Type_Ptr objectType, int& resolved,
                              int& ambiguities) {
        objectType = objectType->binding ();
        gcstring name = as_string ();
        if (getDecl () == NULL) {
            Decl_Vector defns;
            objectType->getEnviron ()->find_immediate (name, defns);
            if (defns.empty ())
                error (this, "object has no attribute named %s",
                       name.c_str ());
            else {
                for (size_t i = 0; i < defns.size (); i += 1)
                    addDecl (defns[i]);
            }
        }
        if (numDecls () == 0) {
            addDecl (makeUnknownDecl (name, false));
            if (_type == NULL)
                setType (getDecl ()->getType ());
            return;
        } else
            ambiguities += numDecls () - 1;

        if (numDecls () > 1 || getDecl ()->isMethod ())
            resolveTypes (NULL, resolved, ambiguities);
        else {
            gcvector<Type_Ptr> typePair;
            Type_Ptr objectBaseType =
                objectType->binding ()->getDecl ()->asBaseType ();
            if (objectBaseType == NULL) {
                error (this, "object has no (known) members");
                return;
            }
            typePair.push_back (getDecl ()->getType ());
            typePair.push_back (objectBaseType);
            Type::freshen (typePair);
            if (!typePair[1]->unify(objectType) || !setType (typePair[0])) {
                error (this,
                       "attribute %s has no definition that fits the context.",
                       as_string ().c_str ());
                if (_type == NULL)
                    setType (Type::makeVar ());
            }
        }
    }

    AST_Ptr convertNone (bool definingContext) {
        if (definingContext || as_string () != "None")
            return this;
        else
            return consTree (CALL, make_id ("__None__", loc ()),
                             consTree (EXPR_LIST));
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

    void exprCodeGen (int depth) {
        // e.g. new str_0$ ("hi")
        gcstring expr = "new " + strDecl->getRuntimeName () + " (";
        expr += "\"" + as_string () + "\")";
        VM->emit (ALLOC, expr);
        VM->emit (PUSH);
    }

    void append_text(const gcstring& s) {
        literal_text += s;
    }

    Type_Ptr computeType () {
        return strDecl->asType ();
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

