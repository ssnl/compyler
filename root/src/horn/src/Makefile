SRCDIR  = /Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/tools/horn/src
BINDIR  = /Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/tools/horn/src/../../../root/bin
DATADIR = /Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/tools/horn/src/../../../root/share/horn
INCLUDEDIR = /Users/impguard/Dropbox/Documents/college/fa2013/cs164/proj/tools/horn/src/../../../root/include
PYTHON  = /usr/local/bin/python
BISON   = /usr/bin/bison
FLEX    = /usr/bin/flex
GCDIR = @GCDIR@
HERE := $(shell pwd)/

GC_SRCDIR = $(SRCDIR)/bdw-gc

GC_MAKEFILE = $(GC_SRCDIR)/Makefile.horn

GC_MAKE = $(MAKE) -C bdw-gc -f $(GC_MAKEFILE) SRCDIR=$(GC_SRCDIR)

DESTDIR =

GNULIB_SRCS = xmalloc.cc

CXX_SRCS = util.cc text_buffer.cc nodes.cc \
	   process-lexical.cc process-cfg.cc lang-specific.cc \
	   $(GNULIB_SRCS)

GENERATED_SRCS = parse-horn.cc scan-horn.cc scan-action.cc 

GENERATED_HEADERS = parse-horn.h

INCLUDE_FILES = horn-common.h horn-parse-lex.cc

DATA_FILES = interactive-lexer-template.l lexer-template.l parser-template.y

LOCAL_INSTALLS = bin/hornpp bin/horn $(DATA_FILES:%=lib/%)

ALL_SRCS = $(CXX_SRCS:%=$(SRCDIR)/%) $(GENERATED_SRCS)

RELEASE_SRCDIR_FILES = Makefile.in configure VERSION horn.in README \
        params.h.in parse-horn.y scan-horn.l scan-action.l \
        $(CXX_SRCS) horn.h xalloc.h \
	$(DOC_RELEASE_FILES) $(DATA_FILES:%=data/%) $(INCLUDE_FILES:%=data/%)

RELEASE_FILES = $(RELEASE_SRCDIR_FILES:%=$(SRCDIR)/%) \
	$(GENERATED_SRCS) $(GENERATED_HEADERS)

DOC_RELEASE_FILES = doc/horn.pic doc/Makefile doc/horn.pdf

OBJS = $(patsubst %.c,%.o,$(patsubst %.cc,%.o, $(CXX_SRCS) $(GENERATED_SRCS)))

TEST_OBJS = $(filter-out parse-horn.o,$(OBJS)) 

PROGRAM = hornpp

MAJOR_VERSION = $(shell sed -e 's/\..*//' $(SRCDIR)/VERSION)

MINOR_VERSION = $(shell sed -e 's/.*\.//' $(SRCDIR)/VERSION)

VERSION = $(MAJOR_VERSION).$(MINOR_VERSION)

CXX = g++

CC = gcc

OPT = -O2

DEBUGGING = -g -O0

CXXINCLUDES = -I. -I$(SRCDIR)

CXXFLAGS = $(CXXINCLUDES) $(OPT) $(DEBUGGING) -Wall  

LDFLAGS = $(DEBUGGING) 

YACC = bison

LEX = flex

%.cc: $(SRCDIR)/%.l
	$(LEX) -o $@ $<

%.o: $(SRCDIR)/%.cc
	$(CXX) $(CXXFLAGS) -c $<

lib/%: data/% lib
	$(RM) $@
	cp -p $< $@
	chmod a-w $@

.PHONY: all default clean gc local-clean distclean depend check doc \
	install uninstall make-release install-gc uninstall-gc \
	install-linked

default: $(PROGRAM) gc .local-installs

all: default doc 

$(PROGRAM): $(OBJS) 
	$(CXX) -o $@ $(LDFLAGS) $^

gc:
	$(GC_MAKE) 

parse-horn.h parse-horn.cc: $(SRCDIR)/parse-horn.y
	$(YACC) -v -o parse-horn.cc --defines=parse-horn.h $<

scan-horn.cc: $(SRCDIR)/scan-horn.l

scan-horn.o: scan-horn.cc parse-horn.h 
	$(CXX) -c $(CXXFLAGS) -Wno-sign-compare $<

scan-action.cc: $(SRCDIR)/scan-action.l 

scan-action.o: scan-action.cc
	$(CXX) -c $(CXXFLAGS) -Wno-sign-compare $<

local-clean: 
	$(RM) *.o *~ *.output *.tab.* *.hh
	$(RM) $(PROGRAM) 
	$(RM) $(OBJS) $(GENERATED_SRCS) $(GENERATED_HEADERS) .depend
	$(RM) -r bin lib .local-installs

clean: local-clean
	-$(MAKE) -C tests clean
	-$(MAKE) -C $(SRCDIR)/doc clean
	-$(GC_MAKE) clean

distclean: local-clean
	$(RM) -r config.log config.status Makefile release
	-$(MAKE) -C tests distclean
	-$(MAKE) -C $(SRCDIR)/doc clean
	-$(GC_MAKE) distclean

depend: $(ALL_SRCS) 
	$(RM) .depend
	g++ -MM $(CXXINCLUDES) $^ > .depend

doc:
	if [ ! -d doc ]; then mkdir doc; fi
	$(MAKE) -C $(SRCDIR)/doc 

check: default
	$(MAKE) -C tests $(CHECKFLAGS) check

install: $(PROGRAM)
	@if [ "$(BINDIR)" = "" -o "$(DATADIR)" = "" ]; then \
	    echo "Must specify or configure BINDIR and DATADIR."; \
            exit 1; \
        fi;
	@if [ ! -d $(DESTDIR)$(BINDIR) ]; then \
             echo mkdir -p $(DESTDIR)$(BINDIR); mkdir -p $(DESTDIR)$(BINDIR); \
        fi
	@if [ ! -d $(DESTDIR)$(DATADIR) ]; then \
             echo mkdir -p $(DESTDIR)$(DATADIR); mkdir -p $(DESTDIR)$(DATADIR); \
        fi
	@if [ ! -d $(DESTDIR)$(INCLUDEDIR) ]; then \
             echo mkdir -p $(DESTDIR)$(INCLUDEDIR); mkdir -p $(DESTDIR)$(INCLUDEDIR); \
        fi
	cp -fp $(PROGRAM) $(DESTDIR)$(BINDIR);
	$(RM) $(DESTDIR)$(BINDIR)/horn
	sed -e 's,@DATADIR@,$(DESTDIR)$(DATADIR),g' \
	    -e 's,@BINDIR@,$(DESTDIR)$(BINDIR),g' \
	    -e 's,@PYTHON@,$(PYTHON),g' \
	    -e 's,@BISON@,$(BISON),g' \
	    -e 's,@FLEX@,$(FLEX),g' \
	    -e 's,@VERSION@,$(VERSION),g' \
	    $(SRCDIR)/horn.in > $(DESTDIR)$(BINDIR)/horn
	chmod 0555 $(DESTDIR)$(BINDIR)/horn
	cd $(SRCDIR)/data; cp -f $(DATA_FILES) $(DESTDIR)$(DATADIR);
	cd $(SRCDIR)/data; cp -f $(INCLUDE_FILES) $(DESTDIR)$(INCLUDEDIR)
	cd $(DESTDIR)$(DATADIR); chmod a-w $(DATA_FILES)

install-gc:
	$(GC_MAKE) install

uninstall:
	$(RM) $(DESTDIR)$(BINDIR)/horn $(DESTDIR)$(BINDIR)/$(PROGRAM)
	cd $(DESTDIR)$(DATADIR); $(RM) $(DATA_FILES)
	cd $(DESTDIR)$(INCLUDEDIR); $(RM) $(INCLUDE_FILES)

uninstall-gc:
	$(GC_MAKE) uninstall

bump:
	$(RM) $(SRCDIR)/VERSION
	echo "$(MAJOR_VERSION).`expr $(MINOR_VERSION) + 1`" > $(SRCDIR)/VERSION

make-release: 
	$(RM) -r release
	$(MAKE) doc 
	mkdir release release/doc release/data
	for f in $(RELEASE_SRCDIR_FILES); do \
	    cp -p $(SRCDIR)/$$f release/$$f; \
	done
	for f in $(GENERATED_SRCS) $(GENERATED_HEADERS); do \
	    cp -p $$f release; \
        done
	rsync -a $(SRCDIR)/bdw-gc release

$(LOCAL_INSTALLS): .local-installs

.local-installs: $(PROGRAM) $(DATA_FILES:%=$(SRCDIR)/data/%) $(SRCDIR)/horn.in
	@if [ ! -d bin ]; then \
             echo mkdir -p bin; mkdir -p bin; \
        fi
	$(RM) bin/$(PROGRAM)
	cp -fp $(PROGRAM) bin
	$(RM) bin/horn
	sed -e 's,@DATADIR@,$(SRCDIR)/data,g' \
	    -e 's,@BINDIR@,$(HERE)bin,g' \
	    -e 's,@PYTHON@,$(PYTHON),g' \
	    -e 's,@BISON@,$(BISON),g' \
	    -e 's,@FLEX@,$(FLEX),g' \
	    -e 's,@VERSION@,$(VERSION),g' \
	    $(SRCDIR)/horn.in > bin/horn
	chmod 0555 bin/horn
	touch .local-installs

.depend:
	touch .depend
	$(MAKE) depend

-include .depend
