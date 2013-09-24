.PHONY: check clean really-clean

APYC = ../apyc

GOODTEST = python test-proj1 

BADTEST = python test-proj1 --errors

check: 
	$(MAKE) -C .. compile
	@echo Testing correct programs...
	rm -f errflag
	-$(GOODTEST) --compiler=$(APYC) correct/*.py || touch errflag
	@echo
	@echo Testing erroneous programs...
	-$(BADTEST) --compiler=$(APYC) error/*.py || touch errflag
	@if test -f errflag; then code=1; else code=0; fi; \
        rm -f errflag; exit $$code

clean:
	$(RM) errflag *~ */*~ 

really-clean: clean
