
/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* Interfaces for apyc. */

#ifndef _APYC_H_
#define _APYC_H_

#include <cstdio>
#include <string>
#include <stdexcept>
#include <iostream>
#include "ast.h"

class Decl;
class Environ;

/** A dummy class whose sole purpose is to provide a constructor that
 *  initializes the garbage collector (required for Darwin).  Put a
 *  definition of a dummy GCINIT at the beginning of each source
 *  file. */
class GCINIT {
public:
    GCINIT() {
        if (!initialized)
            GC_init();
        initialized = true;
    }
private:
    static bool initialized;
};

class semantic_error : public std::runtime_error {
public:
    explicit semantic_error (const std::string& s) : std::runtime_error (s)
        { }
};

#define UNIMPLEMENTED(name) \
    throw logic_error ("unimplemented method: " #name)

/** Print an error message in standard Unix format:
 *      <filename>:<linenum>: <message>
 *  where <filename> and <linenum> denote the file and line number
 *  containing source location LOC, and <message> is composed from
 *  FORMAT and the trailing arguments as
 *  for the printf family. */
extern void error (const char* loc, const char* format, ...);
/** Print an error message as for error(loc, format, ...), using
 *  NODE->loc() as the location.  Reports only one error per node. */
extern void error (AST_Ptr node, const char* format, ...);
/** Print an error message (without file or line number indications)
 *  composed from FORMAT and the trailing arguments as for the printf
 *  family. */
extern void error_no_file (const char* format, ...);
/** The cumulative error count. */
extern int numErrors ();


/* Defined by Horn framework. */
extern
gcstring yyprinted_location (const char* loc);

extern void add_source_file (const gcstring& name);

extern void parse_init ();
extern AST_Ptr parse ();

/** True iff parser should produce debugging output. */
extern bool debugParser;

/** The --phase argument. */
extern int maxPhase;

/* Decls */

/** A declaration node, containing semantic information about a
 *  program entity.  Subtypes of Decl refer to local variables,
 *  parameters, global variables, defined functions, methods, constants,
 *  modules, and classes. */
class Decl : public gc {
public:

    Decl (const gcstring& name, Decl* container, Environ* members = NULL);

    /** My index value (if I appear explicitly), and otherwise -1 to
     *  indicate that I am unindexed. */
    int getIndex () const { return _index; }

    const gcstring& getName () const { return _name; }

    /** Gets my name rewritten in the format that will be used at runtime. For
     *  type variables returns an empty string. */
    gcstring getRuntimeName () const { return _runtimeName; };

    /** Sets my runtime name. */
    void setRuntimeName (gcstring name) { _runtimeName = name; };

    /** Sets up my name rewritten in the format that will be used at runtime,
     *  using NAMES to disambiguate my name. Does nothing for typevars. */
    void setupRuntimeName (gcmap<gcstring, int>& names);

    /** My depth value indicating my frame depth, and otherwise -1 to
     *  indicate that I have no depth. */
    int getDepth () const { return _depth; }

    /** Set my depth to DEPTH. */
    void setDepth (int depth) { _depth = depth; }

    /** Print THIS on OUT. */
    virtual void print(std::ostream& out) const;

    /** Print THIS on the standard output. */
    virtual void print () const;

    /** Get my container (null if none). */
    virtual Decl* getContainer () const { return _container; }

    /** Get the type of the entity I represent. */
    virtual Type_Ptr getType () const;

    /** Set my type to TYPE. */
    virtual void setType (Type_Ptr type);

    /** Gets the name of the type of the entity I represent rewritten in the
     *  format that will be used at runtime. Always returns $Object, since types
     *  have already been determined at compile time, and all declarations will
     *  extend $Object. */
    virtual gcstring getRuntimeTypeName () const;

    /** My associated AST, if any.  A Decl may be associated with a
     *  particular AST that corresponds to the declaration of the
     *  entity it declares.  */
    virtual AST_Ptr getAst () const;

    /** Set getAst() to AST. */
    virtual void setAst (AST_Ptr ast);

    /** True iff I am an overloadable kind of entity (defined by def). */
    virtual bool isOverloadable () const;

    /** True iff I represent a method. */
    virtual bool isMethod () const;

    /** True iff I represent a type. */
    virtual bool isType () const;

    /** True iff I represent a type variable. */
    virtual bool isTypeVar () const;

    /** True iff I represent an internally generated type variable
     *  (which should not be included in the output list). */
    virtual bool isInternal () const;

    /** A Type representing me with ARITY (0 <= ARITY <=2) type parameters
     *  taken from T0 and T1.  Requires isType(). */
    virtual Type_Ptr asType (int arity = 0,
                             Type_Ptr t0 = NULL, Type_Ptr t1 = NULL) const;

    /** A Type representing me with parameters PARAMS[0 .. ARITY-1]. */
    virtual Type_Ptr asType (int arity, Type_Ptr* params) const;

    /** A Type representing me with the type parameters supplied at my
     *  definition. */
    virtual Type_Ptr asBaseType () const;

    /** A Type representing me with generic type parameters. */
    virtual Type_Ptr asGenericType ();

    /** If I am type, returns the number of type arguments. */
    virtual int getTypeArity () const;

    /** Get my position (in a parameter list, indexed from 0). */
    virtual int getPosition () const;

    /** A view of all member Decls I contain (modules, classes). */
    virtual const Environ* getEnviron () const;

    /** Add DECL to the end of my list of member Decls. */
    virtual void addMember (Decl* new_member);

    /** Return a declaration of ID appropriate for a variable declaration to
     *  my members. */
    virtual Decl* newVarDecl (AST_Ptr id);

    /** Create and add a declaration of ID appropriate for a variable
     *  declaration to my members.  There must not already be one. Returns the
     *  resulting declaration */
    virtual Decl* addVarDecl (AST_Ptr id);

    /** Return a declaration of ID appropriate for a 'def' with K
     *  parameters to my members. */
    virtual Decl* newDefDecl (AST_Ptr id, int k);

    /** Create and add a declaration of ID appropriate for a 'def'
     *  with K parameters to my members.  Returns the resulting declaration. */
    virtual Decl* addDefDecl (AST_Ptr id, int k);

    /** Add a new parameter declaration for ID, returning the declaration.
     *  K is the index of this parameter in its formal parameter list.
     *  If the parameter declaration already exists, indicate an error
     *  and return the previous declaration. */
    virtual Decl* addParamDecl (AST_Ptr id, int k);

    /** Add a type variable declaration for ID, if it does not already
     *  exist.  Return either the previously existing declaration or
     *  the new one, as appropriate. */
    virtual Decl* addTypeVarDecl (AST_Ptr id);

    /** True iff the entity I represent can be assigned to or defined
     *  by assignment. */
    virtual bool assignable () const;

    /** True iff my type is currently "frozen", meaning that getType is
     *  not to freshen type variables in it.  Everything in a class is
     *  frozen until processing of the class definition is finished.
     *  Likewise for outer-level functions. */
    virtual bool isFrozen () const;

    /** If my freezing status is mutable, set it to FROZEN.
     *  Otherwise, does nothing. */
    virtual void setFrozen (bool frozen);

    virtual ~Decl ();

protected:

    /** The name of this type of Decl for external printing purposes. */
    virtual const char* declTypeName () const;

    /** Print my container's index on OUT, if
     *  applicable, and otherwise do nothing. */
    virtual void printContainer (std::ostream& out) const;

    /** Print my position in my container, if applicable, on OUT,
     *  and otherwise do nothing. */
    virtual void printPosition (std::ostream& out) const;

    /** Print my type on OUT, if applicable, and  otherwise do nothing. */
    virtual void printType (std::ostream& out) const;

    /** Print my list of type parameters on OUT,
     *  if applicable, and otherwise do nothing. */
    virtual void printTypeParams (std::ostream& out) const;

    /** Print my index list of members or local definitions on OUT,
     *  if applicable, and otherwise do nothing. */
    virtual void printMembersList (std::ostream& out) const;

protected:
    bool _frozen;

private:
    int _index;
    int _depth;
    const gcstring _name;
    gcstring _runtimeName;
    Decl* _container;
    Environ* _members;
    AST_Ptr _ast;
};

/** Declaration of local or module-level variable NAME, defined
 *  immediately inside function or module CONTAINER and having type
 *  TYPE. */
extern Decl* makeVarDecl (const gcstring& name,
                          Decl* container, AST_Ptr type);
/** Declaration of parameter #K (numbered from 0) named NAME in function FUNC
 *  and of type TYPE. */
extern Decl* makeParamDecl (const gcstring& name,
                            Decl* func, int k, AST_Ptr type);
/** Declaration of an instance variable named NAME of type TYPE
 *  in class CLAZZ. */
extern Decl* makeInstanceDecl (const gcstring& name, Decl* clazz,
                               AST_Ptr type);
/** Declaration of type variable NAME, associated with type variable
 *  CANONICAL. */
extern Decl* makeTypeVarDecl (const gcstring& name, AST_Ptr canonical);
/** Declaration of function NAME of type TYPE, nested inside the
 *  function or module CONTAINER. */
extern Decl* makeFuncDecl (const gcstring& name,
                           Decl* container, AST_Ptr type);
/** Declaration for a class NAME with ARITY type parameters. */
extern Decl* makeClassDecl (const gcstring& name, AST_Ptr params);
/** Declaraton for the module MAIN.  This always has sequence number 0. */
extern Decl* makeModuleDecl (const gcstring& name);

/** Declaration for an unknown entity: intended to provide a non-null
 *  dummy declaration to use for erroneous references. If ISTYPE, the
 *  Decl is marked as a type. */
extern Decl* makeUnknownDecl (const gcstring& name, bool isType);

/** True iff NAME may not be defined or set by assignment once it has
 *  been defined once. */
extern bool undefinable (const gcstring& name);

/** If DECL represents a declaration of a builtin class, set the
 *  appropriate global variable to point to it. */
extern void setBuiltinDecl (Decl* decl);

/** Output all Decl nodes to standard output. */
extern void outputDecls (std::ostream& out);

/** Decls for built-in types. */
extern Decl* intDecl;
extern Decl* listDecl;
extern Decl* tupleDecl[];
extern Decl* strDecl;
extern Decl* dictDecl;
extern Decl* boolDecl;
extern Decl* fileDecl;
extern Decl* rangeDecl;

typedef gcvector<Decl*> Decl_Vector;

class Environ : public gc {
public:

    /** An initialiy empty environment enclosed in ENCLOSING. */
    Environ (const Environ* enclosing);

    /** An environment initialized to the (immediate) contents of
     *  ENVIRON0, enclosed in enclosing. */
    Environ (const Environ* environ0, const Environ* enclosing);

    /** An entry for NAME, or NULL if none.  Does not search enclosing
     *  Environs. */
    Decl* find_immediate (const gcstring& name) const;

    /** Set DEFNS to a list of all my entries for NAME  Does not search
     *  enclosing Environs. */
    void find_immediate (const gcstring& name, Decl_Vector& defns) const;

    /** An entry for NAME in me or enclosing Environs, or NULL if
     *  none. */
    Decl* find (const gcstring& name) const;

    /** Set DEFNS to all definitions of NAME in the innermost Environ
     *  in me or my enclosing Environs that has any.  DEFNS is set
     *  empty if it is nowhere defined. */
    void find(const gcstring& name, Decl_Vector& defns) const;

    /** Define DECL in me by its name.  */
    void define (Decl* decl);

    /** The environment enclosing me (passed to my constructor), if
     *  any. */
    const Environ* get_enclosure () const;

    /** A view of my members (not including enclosing Environs). */
    const Decl_Vector& get_members () const;

private:

    Decl_Vector members;
    const Environ* enclosure;
};

/** The current outer (__main__) environment */
extern const Environ* outerEnviron;

/** The declaration of the main module. */
extern Decl* mainModule;

/** A constant empty environment. */
extern const Environ* theEmptyEnviron;

/* Virtual Machine */

typedef gcstring VMLabel;

class VirtualMachine : public gc {
public:

    VirtualMachine (std::ostream& _out);

    /**
     * Outputs an instruction as code to my output stream.
     *
     * ===================== Instruction Set ======================
     * FORMAT
     * ------------------------------------------------------------
     * inst: the instruction along with its arguments
     * args: a description of each argument
     * desc: a description of the instruction
     * rslt: how the STACK MACHINE, STACK, or HEAP changes after this
     *       instruction
     * ------------------------------------------------------------
     *
     * ------------------------------------------------------------
     * inst: CALL
     * desc: Assuming that the item at the top of the STACK MACHINE is a
     *       FuncDesc*, sets up the return label, and the static link of the
     *       call before jumping to the label of the call. The static link and
     *       the label address should be provided by the FuncDesc* at the top of
     *       the STACK MACHINE.
     * rslt: The top of the STACK MACHINE is removed.
     * ------------------------------------------------------------
     * inst: POP
     * desc: Pops off the top of the STACK MACHINE.
     * rslt: Top of the STACK MACHINE is removed.
     * ------------------------------------------------------------
     * inst: PUSH
     * desc: Pushes the top of the HEAP onto the top of the STACK
     *       MACHINE.
     * rslt: New element added to the top of the STACK MACHINE.
     * ------------------------------------------------------------
     * inst: PUSH STR
     * args: STR (gcstring) the name of the data to push onto the STACK MACHINE,
     *       fully linked to from the current frame and its static links, e.g.
     *       "((someframe *) cf->sl->sl->locals)->x".
     * desc: Pushes STR onto the top of the STACK MACHINE.
     * rslt: New element added to the top of the STACK MACHINE.
     * ------------------------------------------------------------
     * inst: MOVE
     * desc: Sets the value of the item at the top of the STACK to be
     *       the value of the item underneath it.
     * rslt: The item at the top of the STACK remains the same, though its
     *       value has been changed. The item underneath it is removed.
     * ------------------------------------------------------------
     * inst: GOTO LBL
     * args: LBL (gcstring) the name of the label to jump to (should be a
     *       function name or a label generated by VM::newLabel)
     * desc: Jumps to LBL.
     * rslt: No change.
     * ------------------------------------------------------------
     * inst: GTZ LBL
     * args: LBL (gcstring) the name of the label to jump to
     * desc: Jumps to LBL iff the top of the STACK MACHINE is an integer with
     *       the value of 0.
     * rslt: The top of the STACK MACHINE is removed.
     * ------------------------------------------------------------
     * inst: ALLOC OBJ
     * args: OBJ (gcstring) the name of the expression to create the object
     * desc: Allocates OBJ, assuming that OBJ is a constructing expression that
     *       creates a new runtime object. Automatically adds the "new" keyword
     *       and places OBJ at the top of the HEAP.
     * rslt: A new element is added to the top of the HEAP.
     * ------------------------------------------------------------
     * inst: SETSL FRAME
     * args: FRAME (gcstring) the name of the static frame, fully linked from
     *       the  current frame, e.g. "cf->sl->sl".
     * desc: Assuming that the item at the top of the STACK MACHINE is a
     *       FuncDesc*, sets the static link of this FuncDesc* to be FRAME.
     *       Leaves the FuncDesc* at the top of the STACK MACHINE.
     * rslt: No change.
     * ------------------------------------------------------------
     * inst: SETLBL LABEL
     * args: LABEL (gcstring) the name of the label
     * desc: Assuming that the item at the top of the STACK MACHINE is a
     *       FuncDesc*, sets the label of this FuncDesc* to be LABEL. Leaves
     *       the FuncDesc* at the top of the STACK MACHINE.
     * rslt: No change.
     * ------------------------------------------------------------
     * inst: NATIVE NAME ARITY
     * args: NAME (gcstring) the name of the native function
     *       ARITY (int) the number of parameters the native function takes
     * desc: Assuming that the ARITY items at the top of the stack machine are
     *       proper parameters to the native function NAME, calls the native
     *       function and places the result at the top of the STACK MACHINE.
     * rslt: A new element is added to the top of the STACK MACHINE. New
     *       elements may also be added to the HEAP depending on whether or not
     *       the NATIVE call allocates any new objects.
     * ------------------------------------------------------------
     * inst: EXPAND ARITY
     * args: ARITY (gcstring) the arity of the tuple being expanded
     * desc: Assuming that there is a tuple at the top of the STACK MACHINE
     *       with size ARITY, pops this tuple off the STACK MACHINE and expands
     *       its elements, placing them in backwards order at the top of the
     *       STACK MACHINE.
     * rslt: ARITY elements are added to the top of the STACK MACHINE,
     *       corresponding to the items that were in the tuple.
     **/
    void emit (const int& instr);
    void emit (const int& instr, gcstring arg);
    void emit (const int& instr, gcstring arg1, int arg2);

    /** Outputs code to handle the start of a function call into my output
     *  stream. */
    void emitDefPrologue (gcstring name);

    /** Outputs code to handle the end of a function call into my output
     *  stream. */
    void emitDefEpilogue (gcstring name);

    /** Outputs the runtime prologue that precedes the body of the main
     *  method */
    void emitMainPrologue ();

    /** Outputs the runtime epilogue that succeeds the body of the main
     *  method */
    void emitMainEpilogue ();

    /** Creates and returns new code label. */
    VMLabel newLabel (gcstring id="L");

    /** Creates and returns new code label. */
    VMLabel asLabel (gcstring name);

    /** Given a code label, inserts the label into the code in the output
      * stream. */
    void placeLabel (VMLabel label);

    /** Outputs datastructures required by the "compiled" C++ program at
      * runtime. */
    void emitRuntime ();

    /** Outputs a string preceded by indent as a comment into my output
      * stream. */
    void comment (gcstring s, int indent=4);

    /** Outputs a string preceded by indent into my output stream. */
    void code (gcstring s, int indent=4);

    /** Outputs a newline into my output stream. */
    void newline (int num=1);

    /** Given two depths, depth1 <= depth2, creates a string that follows
     *  (depth2 - depth1) static links from the current frame. */
    gcstring staticLinkStr (int depth1, int depth2);

    /** Given an expr, field, and accessor, combines into a single string. */
    gcstring fieldAccessStr (gcstring expr, gcstring field, gcstring acc="->");

    /** Given a type and expr, builds a string that casts the expr as the
     *  type. */
    gcstring typeCastStr (gcstring type, gcstring expr);

private:

    std::ostream& out;
    int numLabels;

    /** Yeah, necessary for uhh...convenience. */
    gcstring tostr(int val);

    /** Testing purposes only */
    void __test_codegen();
};

/** VirtualMachine that will be used to compile the code. */
extern VirtualMachine* VM;

/** Virtual machine instructions indicating which of command to emit. */
const int FCALL = 0;
const int GOTO = 1;
const int GTZ = 2;
const int PUSH = 3;
const int POP = 4;
const int MOVE = 5;
const int ALLOC = 6;
const int NTV = 7;
const int SETSL = 8;
const int SETLBL = 9;
const int EXPAND = 10;

#endif
