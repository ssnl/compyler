/* -*-C++-*- */

/* This file contains infrastructural code common to all generated
 * Horn parsers.  It comes in four parts: the first two get included
 * in the generated Bison parser, and the last two in the generated
 * Flex lexer.  They are included depending on which of the
 * preprocessor macros YY_PARSER_1, YY_PARSER_2, YY_LEXER_1, 
 * YY_LEXER_2, YY_ILEXER_1, and YY_ILEXER_2 are initially defined 
 * at the point the file is included.  The indicated section(s) get(s) 
 * included, and the indicator macros get #undefed. */

/* Copyright (C) 2011 by Paul N. Hilfinger and the Regents of the
 * University of California under terms of the BSD license. */


#ifdef YY_PARSER_1

# include <cassert>
# include <cstdarg>
# include <cstring>
# include <cstdlib>
# include <cstdio>
# include <string>
# include <sstream>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <algorithm>
# include <vector>
# include <utility>
# include <stdexcept>

#include "horn-common.h"

#ifdef YYNAMESPACE
namespace YYNAMESPACE {
#endif
    extern Location_Type yysource_location ();
    extern std::string yyprinted_location (Location_Type loc);
    extern int yylocation_line (Location_Type loc);
    extern std::string yylocation_source (Location_Type loc);

    extern void yylex_init ();
    extern void yypush_lexer (FILE*, const std::string&);
    extern void yypush_lexer (const std::string&, const std::string&);
    extern void yypop_lexer ();
    extern const char* yyexternal_token_name (int syntax);
    extern int yylex ();
#ifdef YYNAMESPACE
};
#endif

#ifdef YYNAMESPACE
# define YYNAMESPACE_OPEN namespace YYNAMESPACE {
# define YYNAMESPACE_CLOSE };
#else
# define YYNAMESPACE_OPEN 
# define YYNAMESPACE_CLOSE
# define YYNAMESPACE
#endif
#endif


#ifdef YY_PARSER_2

#   define YYSTYPE yysem

#   define YYSTYPE_IS_TRIVIAL 1

#   if !defined(__attribute__) && !defined(__GNUC__)
#       define __attribute__(LST)
#   endif

#   if !defined(UNUSED)
#       define UNUSED __attribute__ ((unused))
#   endif

#   if !defined(YYPARAM)
#       define YYPARAM Simple_Value_Semantics< int >
#   endif

    class yysembase;
    class yyvar;
    class yysem;
    class yysemlhs;
    class yylexlhs;

    static void yyqueue_token(int tok, const YYPARAM::value_type& val,
                              Location_Type loc = NULL, const char* text = NULL,
                              size_t text_size = 0) UNUSED;
    static void yyqueue_token(int tok, const yysem& val) UNUSED;

    class yysembase {
        friend class yyvar;
        friend class yysem;
        friend class yysemlhs;
        friend class yylexlhs;
    public:
        typedef YYPARAM::value_type value_type;
        typedef RefCountedList<value_type> list_obj;
        typedef Pointer<list_obj> list_type;
        typedef list_obj::const_iterator list_iterator;
        
        inline bool missing () const {
            return _end < _start;
        }

        value_type value () const {
            if (missing ())
                return YYPARAM::make_list_value ();
            if (_start + 1 == _end)
                return (*v)[_start];
            else
                return YYPARAM::make_list_value (v->begin() + _start, 
                                                 v->begin() + _end);
        }

        /** The list of values I represent, as a reference-counted list. */
        list_type list_value () const {
            if (_start > _end)
                return new list_obj ();
            else
                return new list_obj (v->begin() + _start, 
                                     v->begin() + _end);
        }
 
        /** A const_iterator to the beginning of the values I represent. */
        list_iterator begin () const {
            if (missing ())
                return yysemstack.end ();
            else
                return v->begin () + _start;
        }

        /** A const_iterator to the end of the values I represent. */
        list_iterator end () const {
            if (missing ())
                return yysemstack.end ();
            else
                return v->begin () + _end;
        }

        /** The number of values I contain. */
        inline size_t size () const {
            return _end < _start ? 0 : _end - _start;
        }

        /** Value #K (0-based) in the sequence of values I represent. */
        inline const value_type& operator[] (size_t k) const {
            if (k >= size ())
                throw std::out_of_range ("$x[...]::range_check");
            return v->at(k + _start);
        }
        
        inline void set_loc (Location_Type loc) {
            _loc = loc;
            if (_start+1 == _end)
                YYPARAM::set_loc ((*v)[_start], loc);
        }

        inline void set_loc (const yysembase& sym) {
            set_loc (sym.loc ());
        }

        Location_Type loc () const {
            if (_loc != NULL)
                return _loc;
            if (_start+1 == _end)
                return YYPARAM::loc ((*v)[_start]);
            else
                return NULL;
        }

        std::string text () const {
            if (_text != NULL)
                return std::string (_text, _text_size);
            if (_start+1 == _end) 
                return YYPARAM::text ((*v)[_start]);
            else
                return "";
        }

        const char* c_text () const {
            if (_text != NULL)
                return _text;
            if (_start+1 == _end)
                return YYPARAM::c_text ((*v)[_start]);
            else
                return NULL;
        }

        size_t text_size () const {
            if (_text != NULL)
                return _text_size;
            if (_start+1 == _end)
                return YYPARAM::text_size ((*v)[_start]);
            else
                return 0;
        }

        void set_text (const char* text, size_t text_size) {
            _text = text; _text_size = text_size;
        }

#ifdef YYSEMDUMPER
        void dump () const {
            fprintf (stderr, "<%d-%d: ", _start, _end);
            for (size_t i = _start; i < _end; i += 1) {
                YYSEMDUMPER ((*v)[i]);
                fprintf (stderr, " ");
            }
            fprintf (stderr, ">\n");
        }
#endif

    protected:
        /** Indicates the action associated with a semantic value via
         *  the ! (IGNORE) or ^ (TREEOP) operators. */
        enum ACTION_TAG { GATHER = 0, IGNORE, TREEOP };

        typedef list_obj::iterator var_list_iterator;

        void clear () {
            _start = 1; _end = 0;
            _text = NULL;
            _text_size = 0;
            _loc = NULL;
        }

        void set (std::vector<value_type>* v, std::vector<ACTION_TAG>* act,
                  size_t start, size_t end,
                  const char* text, size_t len, Location_Type loc) {
            this->v = v; this->act = act;
            this->_start = start; this->_end = end;
            this->_text = text; this->_text_size = len; this->_loc = loc;
        }

        void _set_text (const yysembase& src) {
            _text = src._text; _text_size = src._text_size;
        }

        void _set_loc (const yysembase& src) {
            _loc = src._loc;
        }

        /* + If _start > _end, we have no value (.missing() is true).
         * + Otherwise, v[_start .. _end-1] is the sequence of values and 
         *   act[_start .. _end-1] are the corresponding actions. */
        std::vector<value_type>* v;
        std::vector<ACTION_TAG>* act;
        size_t _start, _end;

        const char* _text;
        size_t _text_size;
        Location_Type _loc;

        /** The main stack of semantic values created by semantic actions.  
         *  Objects of type yysembase refer to subsequences of this
         *  stack by their indices (_start and end).  */
        static std::vector<YYPARAM::value_type> yysemstack;

        /** A stack, parallel to yysemstack, that marks values that
         *  are to be discarded (IGNORE) or used as an operator or tree-node
         *  label (TREEOP) when forming a semantic value. The default
         *  mark (GATHER) means to gather the value into the current
         *  tree or list. */
        static std::vector<ACTION_TAG> yyactstack;
        
    };
        
    std::vector<YYPARAM::value_type> yysembase::yysemstack;
    std::vector<yysembase::ACTION_TAG> yysembase::yyactstack;

    /** Semantic values on the Bison semantic stack ($1, $2, etc.).  
     *  In general, a yysem is a reference to a continguous subsequence
     *  of values within some vector of values.  */
    class yysem : public yysembase {
        friend class yysemlhs;
        friend class yyvar;
    public:
        /** Cut back the semantic value stack and the dynamic-binding
         *  stack to the point prior to the creation of this value.
         *  This is intended for use in Bison %destructors.
         *  We don't use a C++ destructor for this to allow yysem to be a
         *  POD type (for the benefit of certain Bison
         *  configurations).  This could change in the future. */
        void _destructor () const;
            
        /** Initialize me to have a missing semantic value and not to
         *  start a frame. */
        void _clear () {
            yysembase::clear ();
            bindings_pushed = false;
        }

        /** Mark all semantic entries I control to be discarded, as
         *  indicated by the Horn '!' notation. */
        void ignore () const {
            for (size_t i = _start; i < _end; i += 1)
                (*act)[i] = IGNORE;
        }

        /** Mark my semantic entry (there must be only one) as the
         *  operator of a tree node, as indicated by the Horn '^' notation. */
        void mark_tree_op () const {
            if (_end != _start + 1)
                throw std::logic_error ("attempt to mark multiple values with ^");
            (*act)[_start] = TREEOP;
        }

    protected:

        /** If I refer to the token stack, release space for me on
         *  that stack.   Returns true iff anything released. */
        bool release_token () const;

        /** True if THIS represents a point at which a new frame was
         *  pushed on the dynamic-binding stack. */
        bool bindings_pushed;

    };

    /** Represents the $$ value in CFG grammar actions and also concentrates
     *  administrative functions performed at the beginning and end of
     *  an action.  When initialized, it is given a reference to a
     *  yysem value (Bison's idea of $$), which it sets before being
     *  destructed. */
    class yysemlhs : public yysembase {
        void init (bool push_frame);

    public:
        enum Action_Type { INNER, PASS, OUTER };

        /** Administer an action for which BISON_LHS is the $$
         *  variable used by Bison, OUTER is true iff this is an outer
         *  action on a non-generated rule, and PUSH_FRAME is true if
         *  a new binding-stack frame needs to be started here.  The N
         *  trailing arguments are pointers to the RHS symbols (type
         *  const yysem*). */         
        yysemlhs (bool push_frame, Action_Type type, yysem& bison_lhs, 
                  int sym1, size_t n, ...);

        ~yysemlhs ();

        yysemlhs& operator= (const yysem& val) {
            setup_assign ();
            yysemstack.insert (yysemstack.end (), val.begin (), val.end ());
            yyactstack.insert (yyactstack.end (), val.size (), GATHER);
            _end = yysemstack.size ();
            return *this;
        }

        yysemlhs& operator= (yyvar& val);

        yysemlhs& operator= (const value_type& val) {
            setup_assign ();
            yysemstack.push_back (val);
            yyactstack.push_back (GATHER);
            _end = yysemstack.size ();
            return *this;
        }

        /** Release current values from the semantic value stack and
         *  set my value to "missing". */
        void clear () {
            yysemstack.erase (yysemstack.begin () + base,
                              yysemstack.end ());
            yyactstack.erase (yyactstack.begin () + base,
                              yyactstack.end ());
            yysembase::clear ();
        }

    private:
        /** Clear out any previous values from semantic and action
         *  stacks, check for legal assignment, and set _start and
         *  use_default for an assignment. */
        void setup_assign () {
            if (type != OUTER)
                throw std::logic_error ("$$ is not assignable in inner actions.");
            if (! missing ()) {
                yysemstack.erase (yysemstack.begin () + base,
                                  yysemstack.end ());
                yyactstack.erase (yyactstack.begin () + base,
                                  yyactstack.end ());
            }
            use_default = false;
            _start = base;
        }


        /** Set START to the first index in yysemstack referenced by a
         *  symbol in rhs[sym1..], or to base if none.
         *  Set LEN to the total number of semantic values in all
         *  members of rhs[sym1..]. */
        void get_rhs_bounds (size_t& start, size_t& len) {
            start = base;
            len = 0;
            for (size_t k = rhs.size (); k > sym1; k -= 1) {
                const yysem& sym = *rhs[k-1];
                len += sym.size ();
                if (!sym.missing () && sym.v == &yysemstack)
                    start = sym._start;
            }
        }

        /** Process all ^ and ! operators recorded in the parallel yyactstack.
         *  Leaves _start and _end bracketing the values to be
         *  returned.  */
        void assemble_values () {
            size_t sym;
            size_t k;
            value_type op;
            bool have_op;

            assert (base == yysemstack.size ());
            sym = sym1;
            k = 0;
            op = YYPARAM::default_value ();
            have_op = false;
            while (sym < rhs.size ()) {
                const yysem& R = *rhs[sym];
                if (k + R._start >= R._end) {
                    sym += 1;
                    k = 0;
                    continue;
                }
                switch ((*R.act)[R._start + k]) {
                case GATHER:
                    yysemstack.push_back ((*R.v)[R._start + k]);
                    yyactstack.push_back (GATHER);
                    break;
                case IGNORE:
                    break;
                case TREEOP:
    #ifdef YYPRODUCING_TREES
                    if (have_op) {
                        value_type tree = 
                            YYPARAM::make_tree (op, 
                                                yysemstack.begin () + base,
                                                yysemstack.end ());

                        yysemstack.resize (base+1);
                        yyactstack.resize (base+1);
                        yysemstack[base] = tree;
                        yyactstack[base] = GATHER;
                    }
                    have_op = true;
                    op = (*R.v)[R._start + k];
    #else
                    throw std::logic_error ("semantic type does not support "
                                            "'^' operator");
    #endif
                    break;
                default:
                    assert (false);
                }
                k += 1;
            }
    #ifdef YYPRODUCING_TREES
            if (have_op) {
                value_type tree = 
                    YYPARAM::make_tree (op, 
                                        yysemstack.begin () + base,
                                        yysemstack.end ());

                yysemstack.resize (base+1);
                yyactstack.resize (base+1);
                yysemstack[base] = tree;
                yyactstack[base] = GATHER;
            }
    #endif
            _start = base;
            _end = yysemstack.size ();
        }                              

        /** Consolidate all RHS values into a single sequence at the
         *  end of the semantic stack, assuming that the stack is at
         *  least large enough to hold them without disturbing prior
         *  values.   Leaves _start and _end bracketing the values to 
         *  be returned.  */
        void consolidate_values () {
            _start = _end = yysemstack.size ();
            for (size_t i = rhs.size (); i > sym1; i -= 1) {
                const yysem& sym = *rhs[i-1];
                if (!sym.missing ()) {
                    size_t to = _start - sym.size ();
                    std::copy (sym.v->begin () + sym._start, 
                               sym.v->begin () + sym._end,
                               yysemstack.begin () + to);
                    std::copy (sym.act->begin () + sym._start,
                               sym.act->begin () + sym._end,
                               yyactstack.begin () + to);
                    _start = to;
                }
            }
        }

        void release_rhs() {
            for (size_t k = sym1; k < rhs.size (); k += 1)
                rhs[k]->release_token ();
        }

    public:
        /** As for assemble_values, but place the resulting values in
         *  V, without disturbing the current stack contents. */
        list_type all_values () {
            list_type result = new list_obj ();
            size_t sym;
            size_t k;
            value_type op;
            bool have_op;

            sym = sym1;
            k = 0;
            op = YYPARAM::default_value ();
            have_op = false;
            while (sym < rhs.size ()) {
                const yysem& R = *rhs[sym];
                if (k + R._start >= R._end) {
                    sym += 1;
                    k = 0;
                    continue;
                }
                switch ((*R.act)[R._start + k]) {
                case GATHER:
                    result->push_back ((*R.v)[R._start + k]);
                    break;
                case IGNORE:
                    break;
                case TREEOP:
    #ifdef YYPRODUCING_TREES
                    if (have_op) {
                        value_type new_val = 
                            YYPARAM::make_tree (op, result->begin (),
                                                result->end ());
                        result->clear ();
                        result->push_back (new_val);
                    }
                    have_op = true;
                    op = (*R.v)[R._start + k];
    #else
                    throw std::logic_error ("semantic type does not support "
                                            "'^' operator");
    #endif
                    break;
                default:
                    assert (false);
                }
                k += 1;
            }
    #ifdef YYPRODUCING_TREES
            if (have_op) {
                value_type new_val = 
                    YYPARAM::make_tree (op, result->begin (), result->end ());
                result->clear ();
                result->push_back (new_val);
            }
    #endif

            return result;
        }

    private:
        yysem& bison_lhs;
        std::vector<const yysem*> rhs;
        size_t base;
        size_t sym1;
        bool use_default;
        Action_Type type;
    };

    /** The representation data for yyvar.  This is a separate class
     *  in order that we may have (internally) a place to store
     *  yyvars' data verbatim with the default assignment operation,
     *  while having special implementations of assignment on yyvar. */
    class yyvarbase {
        friend class yyvar;
    public: 
        typedef yysembase::value_type value_type;
        typedef yysembase::list_obj list_obj;
        typedef yysembase::list_type list_type;

        yyvarbase () {
            fc = 0;
            clear ();
        }

        yyvarbase (const yyvarbase& x) {
            *this = x;
        }

    protected:
        void clear () {
            _list_value.clear ();
            status = MISSING;
            _text = NULL; _text_size = 0; _loc = NULL;
        }

        /** If status is SINGLE, the single value is in _value, and
         *  _list_value is empty.  Otherwise, the value list is in 
         *  _list_value.  We make a special case of a single list to
         *  avoid unnecessary allocations. */
        enum Status { MISSING, SINGLE, LIST };
        Status status;
        value_type _value;
        std::vector<value_type> _list_value;

        /** Number of frames on the binding stack at the time of my current
         *  value's assignment. */
        size_t fc;
        const char* _text;
        size_t _text_size;
        Location_Type _loc;
    };

    class yyvar : public yyvarbase {
        friend class yysem;
        friend class yysemlhs;
    public:

        yyvar& operator= (const yysem& vals) {
            save ();
            if (vals.missing ())
                clear ();
            else if (vals.size () == 1) {
                status = SINGLE;
                _value = vals[0];
            } else {
                status = LIST;
                _list_value.assign (vals.begin (), vals.end ());
            }
            set_text (vals);
            set_loc (vals);
            return *this;
        }

        yyvar& operator+= (const yysem& vals) {
            save ();
            if (vals.missing ())
                return *this;
            if (status == MISSING) {
                set_text (vals);
                set_loc (vals);
            }
            if (status == SINGLE && vals.size () > 0) {
                _list_value.assign (1, _value);
                status = LIST;
            } else if (status == MISSING && vals.size () == 1)  {
                _value = vals[0];
                status = SINGLE;
            } else if (status == MISSING) {
                status = LIST;
            }
            if (status == LIST)
                _list_value.insert (_list_value.end (),
                                    vals.begin (), vals.end ());
            if (vals.size () > 1) {
                _text = NULL;
                _text_size = 0;
            }
            return *this;
        }

        bool missing () {
            save ();
            return status == MISSING;
        }

        value_type value () {
            save ();
            if (missing ())
                return YYPARAM::make_list_value ();
            if (size () == 1)
                return (*this)[0];
            else
                return YYPARAM::make_list_value (_list_value.begin (),
                                                 _list_value.end ());
        }

        list_type list_value () {
            save ();
            switch (status) {
            case MISSING:
                return new list_obj ();
            case SINGLE:
                return new list_obj (_value);
            default:
                return new list_obj (_list_value.begin (),
                                     _list_value.end ());
            }
        }

        /** A const_iterator to the beginning of the values I represent. */
        const value_type* begin () {
            save ();
            if (status != LIST || _list_value.size () == 0 )
                return &_value;
            else
                return &_list_value[0];
        }

        /** A const_iterator to the end of the values I represent. */
        const value_type* end () {
            save ();
            if (size () == 0)
                return &_value;
            else if (status == SINGLE)
                return &_value + 1;
            else
                return &_list_value[0] + _list_value.size ();
        }

        /** The number of values I contain. */
        size_t size () {
            save ();
            switch (status) {
            case MISSING:
                return 0;
            case SINGLE:
                return 1;
            default:
                return _list_value.size ();
            }
        }

        /** Value #K (0-based) in the sequence of values I represent. */
        const value_type& operator[] (size_t k) {
            save ();
            switch (status) {
            case MISSING:
                throw std::out_of_range ("$x[...]::range_check");
            case SINGLE:
                if (k != 0)
                    throw std::out_of_range ("$x[...]::range_check");
                else
                    return _value;
            default:
                return _list_value.at (k);
            }
        }

        inline void set_loc (const Location_Type& loc) {
            save ();
            _loc = loc;
            if (size () == 1)
                YYPARAM::set_loc ((*this)[0], loc);
        }

        inline void set_loc (const yysembase& sym) {
            set_loc (sym.loc ());
        }

        Location_Type loc () {
            save ();
            if (_loc != NULL)
                return _loc;
            else if (size () == 1)
                return YYPARAM::loc ((*this)[0]);
            else
                return NULL;
        }

        std::string text () {
            save ();
            if (_text != NULL)
                return std::string (_text, _text_size);
            if (size () == 1) 
                return YYPARAM::text ((*this)[0]);
            else
                return "";
        }

        const char* c_text () {
            save ();
            if (_text != NULL)
                return _text;
            if (size () == 1) 
                return YYPARAM::c_text ((*this)[0]);
            else
                return NULL;
        }

        size_t text_size () {
            save ();
            if (_text != NULL)
                return _text_size;
            if (size () == 1)
                return YYPARAM::text_size ((*this)[0]);
            else
                return 0;
        }

        void set_text (const char* text, size_t text_size) {
            save ();
            _text = text; _text_size = text_size;
        }

        void set_text (const yysembase& val) {
            save ();
            set_text (val._text, val._text_size);
        }

    protected:

        void save () {
            if (fc != binding_fp.size ()) {
                binding_stack.push_back 
                    (SavedBinding (* const_cast<yyvar*> (this)));
                fc = binding_fp.size ();
                clear ();
            }
        }

        /* Semantic variable binding */

        /** We use a form of shallow binding to maintain variable bindings. 
         *  During the processing of a given semantic action, we first
         *  use start_frame to push the current size of binding_stack 
         *  on binding_fp (fp == "frame pointer"). Whenever we subsequently 
         *  assign a semantic value to a named variable (yyvar), we push 
         *  its old value on binding_stack, if we have not already
         *  done so in the current frame (i.e., since the last start_frame).  
         *  We know whether we have done so for a given variable by storing 
         *  with the variable the number of frames on binding_stack at the time 
         *  of assignment (the size of binding_fp).  The pop_frame
         *  operation now removes the bindings from binding_stack,
         *  restoring the values of the variables saved, and pops the
         *  frame pointer from binding_fp. */

        /** Information needed to reset a yyvar object to a
         *  previous value.  We cannot make proper use of virtual
         *  methods here due to the requirement that yysems on the
         *  Bison stack be POD, hence the use of manual type tagging. */
        class SavedBinding {
        public:
            /** Store information. */
            SavedBinding (yyvar& val)
                : prev_data ((yyvarbase&) val), var (&val) {
            }

            SavedBinding () 
                : var (NULL) {
            }

            /** Restore value to the variable I am tracking. */
            void restore () {
                if (var != NULL)
                    *var = prev_data;
            }

        private:
            yyvarbase prev_data;
            yyvarbase* var;
        };

        static std::vector<SavedBinding> binding_stack;
        static std::vector<size_t> binding_fp;

        static void start_frame () {
            binding_fp.push_back (binding_stack.size ());
            binding_stack.push_back (SavedBinding ());
        }

        static void pop_frame () {
	    assert (!binding_fp.empty ());
            size_t fp = binding_fp.back ();
            binding_fp.pop_back ();
            while (binding_stack.size () > fp) {
                binding_stack.back ().restore ();
                binding_stack.pop_back ();
            }
        }

    #ifdef YYPRODUCING_TREES
    #       define YYMAKE_TREE yyvar::_make_tree
    #else
    #       define YYMAKE_TREE(...)                                         \
        throw std::logic_error ("semantic type does not support $^");
    #endif

        /** Support for making trees "by hand".  Unfortunately, C++ does not 
         *  allow passing non-POD data through ..., so we spell out overloadings
         *  (up to 10 operands).  Sorry about that. */

    private:
        /** An adapter that accepts value_type or yysembase arguments.  We
         *  rely on the fact that C++ does not deallocate temporary variables
         *  until completion of the complete expression containing them. */
        struct Prm {
            Prm (const value_type& arg)
                : opnd0 (&arg), opnds1 (NULL), opnds2 (NULL) { }
            Prm (yyvar& arg) 
                : opnd0 (NULL), opnds1 (&arg), opnds2 (NULL) { }
            Prm (const list_type& v)
                : opnd0 (NULL), opnds1 (NULL), opnds2 (v) { }

            void add (std::vector<value_type>& v) const {
                if (opnd0 != NULL)
                    v.push_back (*opnd0);
                else if (opnds1 != NULL)
                    v.insert (v.end (), opnds1->begin (), opnds1->end ());
                else 
                    v.insert (v.end (), opnds2->begin (), opnds2->end ());
            }

            const value_type* opnd0;
            yyvar* opnds1;
            const list_type opnds2;
        };                

    public:

    #ifdef YYPRODUCING_TREES
        static value_type 
        _make_tree (int syntax) {
            std::vector<value_type> opnds;
            return YYPARAM::make_tree (syntax, opnds.begin (), opnds.end ());
        }

        static value_type 
        _make_tree (int syntax,  const Prm& x1) {
            std::vector<value_type> opnds;
            x1.add (opnds);
            return YYPARAM::make_tree (syntax, opnds.begin (), opnds.end ());
        }

        static value_type 
        _make_tree (int syntax, const Prm& x1, const Prm& x2) {
            std::vector<value_type> opnds;
            x1.add (opnds); x2.add (opnds);
            return YYPARAM::make_tree (syntax, opnds.begin (), opnds.end ());
        }

        static value_type 
        _make_tree (int syntax, const Prm& x1, const Prm& x2,
                    const Prm& x3) {
            std::vector<value_type> opnds;
            x1.add (opnds); x2.add (opnds); x3.add (opnds);
            return YYPARAM::make_tree (syntax, opnds.begin (), opnds.end ());
        }

        static value_type 
        _make_tree (int syntax, const Prm& x1, const Prm& x2,
                    const Prm& x3, const Prm& x4) {
            std::vector<value_type> opnds;
            x1.add (opnds); x2.add (opnds); x3.add (opnds); x4.add (opnds);
            return YYPARAM::make_tree (syntax, opnds.begin (), opnds.end ());
        }

        static value_type 
        _make_tree (int syntax, const Prm& x1, const Prm& x2,
                    const Prm& x3, const Prm& x4, const Prm& x5) {
            std::vector<value_type> opnds;
            x1.add (opnds); x2.add (opnds); x3.add (opnds); x4.add (opnds);
            x5.add (opnds);
            return YYPARAM::make_tree (syntax, opnds.begin (), opnds.end ());
        }

        static value_type 
        _make_tree (int syntax, const Prm& x1, const Prm& x2,
                    const Prm& x3, const Prm& x4, const Prm& x5, const Prm& x6) {
            std::vector<value_type> opnds;
            x1.add (opnds); x2.add (opnds); x3.add (opnds); x4.add (opnds);
            x5.add (opnds); x6.add (opnds);
            return YYPARAM::make_tree (syntax, opnds.begin (), opnds.end ());
        }

        static value_type 
        _make_tree (int syntax, const Prm& x1, const Prm& x2,
                    const Prm& x3, const Prm& x4, const Prm& x5, const Prm& x6,
                    const Prm& x7) {
            std::vector<value_type> opnds;
            x1.add (opnds); x2.add (opnds); x3.add (opnds); x4.add (opnds);
            x5.add (opnds); x6.add (opnds); x7.add (opnds);
            return YYPARAM::make_tree (syntax, opnds.begin (), opnds.end ());
        }

        static value_type 
        _make_tree (int syntax, const Prm& x1, const Prm& x2,
                    const Prm& x3, const Prm& x4, const Prm& x5, const Prm& x6,
                    const Prm& x7, const Prm& x8) {
            std::vector<value_type> opnds;
            x1.add (opnds); x2.add (opnds); x3.add (opnds); x4.add (opnds);
            x5.add (opnds); x6.add (opnds); x7.add (opnds); x8.add (opnds);
            return YYPARAM::make_tree (syntax, opnds.begin (), opnds.end ());
        }

        static value_type 
        _make_tree (int syntax, const Prm& x1, const Prm& x2,
                    const Prm& x3, const Prm& x4, const Prm& x5, const Prm& x6,
                    const Prm& x7, const Prm& x8, const Prm& x9) {
            std::vector<value_type> opnds;
            x1.add (opnds); x2.add (opnds); x3.add (opnds); x4.add (opnds);
            x5.add (opnds); x6.add (opnds); x7.add (opnds); x8.add (opnds);
            x9.add (opnds);
            return YYPARAM::make_tree (syntax, opnds.begin (), opnds.end ());
        }

        static value_type 
        _make_tree (int syntax, const Prm& x1, const Prm& x2,
                    const Prm& x3, const Prm& x4, const Prm& x5, const Prm& x6,
                    const Prm& x7, const Prm& x8, const Prm& x9, 
                    const Prm& x10) {
            std::vector<value_type> opnds;
            x1.add (opnds); x2.add (opnds); x3.add (opnds); x4.add (opnds);
            x5.add (opnds); x6.add (opnds); x7.add (opnds); x8.add (opnds);
            x9.add (opnds); x10.add (opnds);
            return YYPARAM::make_tree (syntax, opnds.begin (), opnds.end ());
        }

        static value_type 
        _make_tree (value_type op) {
            std::vector<value_type> opnds;
            return YYPARAM::make_tree (op, opnds.begin (), opnds.end ());
        }

        static value_type 
        _make_tree (value_type op,  const Prm& x1) {
            std::vector<value_type> opnds;
            x1.add (opnds);
            return YYPARAM::make_tree (op, opnds.begin (), opnds.end ());
        }

        static value_type 
        _make_tree (value_type op, const Prm& x1, const Prm& x2) {
            std::vector<value_type> opnds;
            x1.add (opnds); x2.add (opnds);
            return YYPARAM::make_tree (op, opnds.begin (), opnds.end ());
        }

        static value_type 
        _make_tree (value_type op, const Prm& x1, const Prm& x2,
                    const Prm& x3) {
            std::vector<value_type> opnds;
            x1.add (opnds); x2.add (opnds); x3.add (opnds);
            return YYPARAM::make_tree (op, opnds.begin (), opnds.end ());
        }

        static value_type 
        _make_tree (value_type op, const Prm& x1, const Prm& x2,
                    const Prm& x3, const Prm& x4) {
            std::vector<value_type> opnds;
            x1.add (opnds); x2.add (opnds); x3.add (opnds); x4.add (opnds);
            return YYPARAM::make_tree (op, opnds.begin (), opnds.end ());
        }

        static value_type 
        _make_tree (value_type op, const Prm& x1, const Prm& x2,
                    const Prm& x3, const Prm& x4, const Prm& x5) {
            std::vector<value_type> opnds;
            x1.add (opnds); x2.add (opnds); x3.add (opnds); x4.add (opnds);
            x5.add (opnds);
            return YYPARAM::make_tree (op, opnds.begin (), opnds.end ());
        }

        static value_type 
        _make_tree (value_type op, const Prm& x1, const Prm& x2,
                    const Prm& x3, const Prm& x4, const Prm& x5, const Prm& x6) {
            std::vector<value_type> opnds;
            x1.add (opnds); x2.add (opnds); x3.add (opnds); x4.add (opnds);
            x5.add (opnds); x6.add (opnds);
            return YYPARAM::make_tree (op, opnds.begin (), opnds.end ());
        }

        static value_type 
        _make_tree (value_type op, const Prm& x1, const Prm& x2,
                    const Prm& x3, const Prm& x4, const Prm& x5, const Prm& x6,
                    const Prm& x7) {
            std::vector<value_type> opnds;
            x1.add (opnds); x2.add (opnds); x3.add (opnds); x4.add (opnds);
            x5.add (opnds); x6.add (opnds); x7.add (opnds);
            return YYPARAM::make_tree (op, opnds.begin (), opnds.end ());
        }

        static value_type 
        _make_tree (value_type op, const Prm& x1, const Prm& x2,
                    const Prm& x3, const Prm& x4, const Prm& x5, const Prm& x6,
                    const Prm& x7, const Prm& x8) {
            std::vector<value_type> opnds;
            x1.add (opnds); x2.add (opnds); x3.add (opnds); x4.add (opnds);
            x5.add (opnds); x6.add (opnds); x7.add (opnds); x8.add (opnds);
            return YYPARAM::make_tree (op, opnds.begin (), opnds.end ());
        }

        static value_type 
        _make_tree (value_type op, const Prm& x1, const Prm& x2,
                    const Prm& x3, const Prm& x4, const Prm& x5, const Prm& x6,
                    const Prm& x7, const Prm& x8, const Prm& x9) {
            std::vector<value_type> opnds;
            x1.add (opnds); x2.add (opnds); x3.add (opnds); x4.add (opnds);
            x5.add (opnds); x6.add (opnds); x7.add (opnds); x8.add (opnds);
            x9.add (opnds);
            return YYPARAM::make_tree (op, opnds.begin (), opnds.end ());
        }

        static value_type 
        _make_tree (value_type op, const Prm& x1, const Prm& x2,
                    const Prm& x3, const Prm& x4, const Prm& x5, const Prm& x6,
                    const Prm& x7, const Prm& x8, const Prm& x9, 
                    const Prm& x10) {
            std::vector<value_type> opnds;
            x1.add (opnds); x2.add (opnds); x3.add (opnds); x4.add (opnds);
            x5.add (opnds); x6.add (opnds); x7.add (opnds); x8.add (opnds);
            x9.add (opnds); x10.add (opnds);
            return YYPARAM::make_tree (op, opnds.begin (), opnds.end ());
        }
    #endif  
    };

    std::vector<yyvar::SavedBinding> yyvar::binding_stack;
    std::vector<size_t> yyvar::binding_fp;

    void yysem::_destructor () const {
        if (!missing ()) {
            if (!release_token ()) {
                yysemstack.resize (_start);
                yyactstack.resize (_start);
            }
        }
        if (bindings_pushed)
            yyvar::pop_frame ();
    }

    yysemlhs::yysemlhs (bool push_frame, Action_Type type, 
                        yysem& bison_lhs, int sym1, size_t n, ...)
        : bison_lhs (bison_lhs), base (yysemstack.size ()), sym1 (sym1),
          use_default (true), type (type)
    {
        _start = 1;
        _end = 0;
        v = &yysemstack;
        act = &yyactstack;
        _text = NULL; _text_size = 0;
        _loc = NULL; // FIXME ?

        if (type != INNER) {
            va_list syms;
            va_start (syms, n);
            for (size_t i = 0; i < n; i += 1)
                rhs.push_back (va_arg (syms, const yysem*));
            va_end (syms);
        }

        if (push_frame) {
            yyvar::start_frame ();
            bison_lhs.bindings_pushed = (type != OUTER);
        } else
            bison_lhs.bindings_pushed = false;	    
    }

    yysemlhs::~yysemlhs () 
    {
        if (type == INNER) {
            bison_lhs._clear ();
            return;     
        }
        size_t start, len;
        get_rhs_bounds (start, len);
        if (type == OUTER) {
            if (use_default)
                assemble_values ();
            for (size_t k = _start; k < _end; k += 1)
                yyactstack[k] = GATHER;
            yyvar::pop_frame ();
        } else {
            if (start + len > yysemstack.size ()) {
                yysemstack.resize (start + len);
                yyactstack.resize (start + len);
            }
            consolidate_values ();
        }
        if (missing ()) {
            yysemstack.erase (yysemstack.begin () + start);
            yysemstack.erase (yysemstack.end ());
        } else {
            size_t diff = _start - start;
            if (diff > 0) {
                yysemstack.erase (yysemstack.begin () + start,
                                  yysemstack.begin () + _start);
                yyactstack.erase (yyactstack.begin () + start,
                                  yyactstack.begin () + _start);
                _start -= diff;
                _end -= diff;
            }
        }
        release_rhs ();
        * (yysembase*) &bison_lhs = * (yysembase*) this;
    }

    yysemlhs& yysemlhs::operator= (yyvar& val) {
        setup_assign ();
        yysemstack.insert (yysemstack.end (), val.begin (), val.end ());
        yyactstack.insert (yyactstack.end (), val.size (), GATHER);
        _end = yysemstack.size ();
        return *this;
    }            

    /* Define administrative variable, which handles assignments to $$ and
     * deals with variable scoping.  Legend:
     *   YYCTLxy, where x and y may either be empty or...
     *     + x = P for "create new variable frame".
     *     + y = A for "if $$ is defaulted, accumulate rhs values, processing '!'
     *           and '^' operators, releasing space on semstack and
     *           actstack for RHS values, and leave result stack, setting
     *           _start and _end.
     *     + y = C for "consolidate all values into a contiguous
     *           sequence on semstack and actstack, releasing RHS values,
     *           and setting _start and _end accordingly.
     * YYCTLx is for user-supplied inner actions.
     * YYCTLxC is for outer actions on generated rules (for Z*, Z?, Z+, etc.).
     * YYCTLxA is for normal outer actions.
     *
     * YYCTLPy is for the first action(s) reduced when processing a RHS
     *    and its generated rules.
     */
    #define YYCTL(...) yysemlhs yylhs(false, yysemlhs::INNER, __VA_ARGS__)
    #define YYCTLP(...) yysemlhs yylhs(true, yysemlhs::INNER, __VA_ARGS__)
    #define YYCTLA(...) yysemlhs yylhs(false, yysemlhs::OUTER, __VA_ARGS__)
    #define YYCTLC(...) yysemlhs yylhs(false, yysemlhs::PASS, __VA_ARGS__)
    #define YYCTLPA(...) yysemlhs yylhs(true, yysemlhs::OUTER, __VA_ARGS__)
    #define YYCTLPC(...) yysemlhs yylhs(true, yysemlhs::PASS, __VA_ARGS__)

    static void yyqueue_token(int, const YYPARAM::value_type&, const char*,
                              const char*, size_t);

    static void yyqueue_token(int, const yysem&);


#ifndef YYERROR_DECLARED
static inline void
yyerror (const char* msg)
{
#ifdef YYERROR_FUNCTION_NAME
    YYERROR_FUNCTION_NAME (yysource_location (), msg);
#else
    fprintf (stderr, "%s: %s\n",
             yyprinted_location (yysource_location ()).c_str (), msg);
#endif
}
#endif

#endif


#if defined(YY_LEXER_1) || defined(YY_ILEXER_1)

#include <vector>
#include <utility>

#define YY_DECL int yylexer ()
static std::vector<Location_Type> yylast_locations;
std::vector< std::pair<yysem,int> > yypending_tokens;
static bool empty_matched;
static bool eof_triggered;

# define YY_LEXLHS                                                           \
    if (yyleng > 0 && yytext[yyleng-1] == YYEOF_CHAR)                        \
        yyless (yyleng-1);                                                   \
    yylexlhs yylhs

# define YYLEXRET return yylhs.yyret ()

# define YYSIMPLELEXRET                                                      \
    YY_LEXLHS(yytext[0]); return yylhs.yyret ()

# define YYIGNORE do { yylhs.set_token (-1); } while (0)

# define YYSET_TOKEN(TOK) yylhs.set_token (TOK)
# define YYSET_TEXT(TEXT, LEN) yylhs.set_text (TEXT, LEN)
# define YYSET_LOC(LOC) yylhs.set_loc (LOC)
# define YYGET_LOC yylhs.loc ()

#ifdef YY_LEXER_1

#define YY_INPUT(buf,result,max_size) (result=YY_NULL)

#else

/* Interactive version */

#define YY_INPUT(buf,result,max_size)                                        \
   {                                                                         \
      result = 1;                                                            \
      if (eof_triggered) {                                                   \
         eof_triggered = false;                                              \
         result = YY_NULL;                                                   \
      } else {                                                               \
         int c = getc (yyin);                                                \
         if (c == EOF) {                                                     \
             buf[0] = '\377';                                                \
             eof_triggered = true;                                           \
         } else                                                              \
             buf[0] = c;                                                     \
      }                                                                      \
   }
  
#endif
/* of interactive version */

static const char YYEOF_CHAR = '\377';

static bool yy_input_provided = false;

static std::vector<std::string*> input_sources;
static std::vector<std::string> input_names;

/** Represents the $$ value in lexical grammar actions. 
 *  When initialized, it is given a reference to a yysem value 
 *  (Bison's idea of $$ and Flex's idea of yylval), which it sets 
 *  before being destructed. */
class yylexlhs {
public:
    typedef YYPARAM::value_type value_type;

    /** A lexical LHS ($$) value. */
    yylexlhs () 
        : token (-1), have_value (false) {
        init_text ();
    }

    yylexlhs (int token) 
        : token (token), have_value (false) {
        init_text ();
    }

    const value_type& value () {
        if (have_value)
            return val;
        else
            throw std::domain_error ("$$ has no assigned value"); 
    }

    bool missing () {
        return !have_value;
    }

    const value_type& operator[] (size_t k) {
        if (k != 0)
            throw std::out_of_range ("$$[...]::range_check");
        return value ();
    }

    yylexlhs& operator= (const value_type& v) {
        val = v;
        have_value = true;
        return *this;
    }

    void set_text (const char* text, size_t len) {
        _text = text; _text_size = len;
    }

    void set_loc (Location_Type text) {
        _loc = text;
    }

    void set_token (int token) {
        this->token = token;
    }

    const char* text () {
        return _text;
    }

    size_t text_size () {
        return _text_size;
    }

    Location_Type loc () {
        return _loc;
    }

    int yyret ();

    static void yyqueue (int tok, const YYPARAM::value_type& val, 
                         Location_Type loc, const char* text, size_t text_size) {
        int k = alloc ();
        tokens[k] = val;
        yypending_tokens.resize (yypending_tokens.size () + 1);
        yypending_tokens.back ().first.set (&tokens, &act, k, k+1, 
                                            text, text_size, loc);
        yypending_tokens.back ().second = tok;
    }

    static void yyqueue (int tok, const yysem& val) {
        yyqueue (tok, val.value (), val.loc (), val.c_text (),
                 val.text_size ());
    }

    static void release (size_t k);

private:

#ifdef YY_LEXER_1

    void init_text () {
        _text = _loc = yytext;
        _text_size = yyleng;
    }

#else
    /* Interactive version */

    /** Move yytext to a permanent location. */
    void init_text () {
        _text_size = yyleng;
        if (_text_size
            >= input_sources.back()->capacity() - input_sources.back()->size()) {
            input_sources.push_back (new string());
            input_names.push_back (input_names.back());
            input_sources.back()->reserve(_text_size > YY_BUF_SIZE ? 2*_text_size
                                          : YY_BUF_SIZE);
        }
        string& input_source = *input_sources.back();
        _text = _loc = input_source.data()+input_source.size();
        input_source.append(yytext);
    }

#endif
/* of interactive version */

    int token;
    value_type val;
    bool have_value;
    const char* _text;
    size_t _text_size;
    Location_Type _loc;

    static size_t alloc ();

    static size_t free_list;
    static vector<size_t> free_link;
    static vector<YYPARAM::value_type> tokens;
    static vector<yysembase::ACTION_TAG> act;
};
#endif


#if defined(YY_LEXER_2) || defined(YY_ILEXER_2)

using namespace std;

size_t yylexlhs::free_list = 0;
vector<size_t> yylexlhs::free_link;
vector<YYPARAM::value_type> yylexlhs::tokens;
vector<yysembase::ACTION_TAG> yylexlhs::act;

bool
yysem::release_token () const
{
    if (!missing () && v != &yysemstack) {
        yylexlhs::release (_start);
        return true;
    } else
        return false;
}

Location_Type
yysource_location ()
{
    if (yylast_locations.empty ())
        return NULL;
    else
        return yylast_locations.back ();
}

static bool
yy_get_location (Location_Type loc, yy_size_t& s, int& line)
{
    s = line = 0;

    if (loc == NULL)
        return false;

    for (s = 0; s < input_sources.size (); s += 1) {
        if (loc >= input_sources[s]->data () &&
            loc < input_sources[s]->data () + input_sources[s]->size ()) {
            break;
        }
    }

    if (s >= input_sources.size ())
        return false;

    line = 1;
    string& input_source = *input_sources[s];
    for (size_t p = input_source.find ('\n'); 
         p != string::npos && p+input_source.data () < loc; 
         p = input_source.find ('\n', p+1)) {
         line += 1;
    }
    return true;
}

bool
yyis_known_location (Location_Type loc)
{
    yy_size_t s;
    int line;
    return yy_get_location (loc, s, line);
}

string
yyprinted_location (Location_Type loc)
{
    stringstream result;
    
    yy_size_t s;
    int line;

    if (!yy_get_location (loc, s, line))
        return "<unknown>";

    if (!input_names[s].empty ())
        result << input_names[s] << ":";
    result << line;
    return result.str ();
}

int
yylocation_line (Location_Type loc)
{
    yy_size_t s;
    int line;
    
    if (!yy_get_location (loc, s, line))
        return 0;

    return line;
}

std::string
yylocation_source (Location_Type loc)
{
    yy_size_t s;
    int line;
    
    if (!yy_get_location (loc, s, line))
        return "";

    return input_names[s];
}

int
yylexlhs::yyret ()
{
    if (token >= 0) {                                           
        yylast_locations.back () = _text;                               
        if (!have_value)
            val = YYPARAM::default_make_token (token, _text, _text_size);
        YYPARAM::set_loc (val, _loc);
        size_t k = alloc ();
        tokens[k] = val;
        act[k] = yysembase::GATHER;
        yylval.set(&tokens, &act, k, k+1, _text, _text_size, _loc);
    }
    return token;
}

size_t
yylexlhs::alloc ()
{
    if (free_list == tokens.size ()) {
        for (int i = 1; i < 16; i += 1)
            free_link.push_back (free_link.size ()+1);
    }
    tokens.resize (free_link.size ());
    act.resize (free_link.size ());

    size_t result = free_list;
    free_list = free_link[free_list];
    return result;
}

void
yylexlhs::release (size_t k)
{
    free_link[k] = free_list;
    free_list = k;
}   

extern std::vector< std::pair<yysem,int> > yypending_tokens;

static void
yyqueue_token(int tok, const YYPARAM::value_type& val, Location_Type loc,
              const char* text, size_t text_size)
{
    yylexlhs::yyqueue (tok, val, loc, text, text_size);
}

static void
yyqueue_token(int tok, const yysem& val)
{
    yylexlhs::yyqueue (tok, val);
}

#ifdef YY_LEXER_2
void
yypush_lexer (FILE* inp, const string& name)
{
    char chunk[YY_BUF_SIZE];
    yy_size_t chunk_size;
    struct stat file_info;
    int fd = fileno (inp);

    if (fstat (fd, &file_info) != 0)
        return;
  
    input_sources.push_back (new string ());
    input_names.push_back (name);

    string& input_source = *input_sources.back ();

    while ((chunk_size = fread (chunk, 1, YY_BUF_SIZE, inp)) > 0) {
        input_source.append (chunk, chunk_size);
    }
    input_source.append ("\377\000\000", 3);

    yylast_locations.push_back (input_source.data ());
    yypush_buffer_state (YY_CURRENT_BUFFER);
    yy_scan_buffer (&input_source[0], input_source.size ());
    eof_triggered = false;
    yy_input_provided = true;
}

void
yypush_lexer (const string& inp, const string& name)
{
    input_sources.push_back (new string (inp));
    input_names.push_back (name);
    string& input_source = *input_sources.back ();

    input_source.append ("\377\000\000", 3);
    yylast_locations.push_back (input_source.data ());
    yypush_buffer_state (YY_CURRENT_BUFFER);
    yy_scan_buffer (&input_source[0], input_source.size ());
    eof_triggered = false;
    yy_input_provided = true;
}

void
yypop_lexer ()
{
    yypop_buffer_state ();
    yylast_locations.pop_back ();
    eof_triggered = false;
}

#else

/* Interactive version */

void
yypush_lexer (FILE* inp, const string& name)
{
    if (!yy_input_provided) {
        input_sources.push_back (new string ());
        input_names.push_back ("");
        input_sources.back ()->reserve (YY_BUF_SIZE);
        yylast_locations.push_back (input_sources.back ()->data ());
    }

    struct stat file_info;
    int fd = fileno (inp);

    if (fstat (fd, &file_info) != 0)
        return;
  
    yypush_buffer_state (yy_create_buffer (inp, YY_BUF_SIZE));
    eof_triggered = false;
    yy_input_provided = true;
}

void
yypush_lexer (const string& inp, const string& name)
{
    if (!yy_input_provided) {
        input_sources.push_back (new string (inp));
        input_names.push_back ("");
        input_sources.back ()->reserve (YY_BUF_SIZE);
        yylast_locations.push_back (input_sources.back ()->data ());
    }
    yypush_buffer_state (YY_CURRENT_BUFFER);
    string input_source (inp);
    input_source.append ("\377\000\000", 3);
    yy_scan_bytes (input_source.data (), input_source.size ());
    eof_triggered = false;
    yy_input_provided = true;
}

void
yypop_lexer ()
{
    yypop_buffer_state ();
    eof_triggered = false;
}

#endif
/* of interactive version */
    
void
yylex_init ()
{
    for (size_t i = 0; i < input_sources.size (); i += 1)
        delete input_sources[i];
    input_sources.clear ();
    input_names.clear ();
    yylast_locations.clear ();
    yylast_locations.push_back (NULL);
    while (YY_CURRENT_BUFFER != NULL)
        yypop_buffer_state ();
    empty_matched = false;
    yy_input_provided = false;
    eof_triggered = false;
}    

int
yylex ()
{
    int tok;
    
    tok = -1;
    if (! yy_input_provided)
        yypush_lexer (stdin, "<stdin>");
    while (tok < 0) {
        if (!yypending_tokens.empty ()) {
            yylval = yypending_tokens.front ().first;
            tok = yypending_tokens.front ().second;
            yypending_tokens.erase (yypending_tokens.begin ());
        } else {
            int bol0 = YY_AT_BOL();
            if (!empty_matched)
                BEGIN YYPREFERRED;
            tok = yylexer ();
            if (yyleng == 0) {
                empty_matched = true;
                yy_set_bol (bol0);
            } else
                empty_matched = false;
            BEGIN INITIAL;
        }
    }
    return tok;
}
#endif

#undef YY_PARSER_1
#undef YY_PARSER_2
#undef YY_LEXER_1
#undef YY_LEXER_2
#undef YY_ILEXER_1
#undef YY_ILEXER_2
