.PHONY: check clean really-clean

APYC = ../apyc

check: check1 check2

check%:
	$(MAKE) -C .. compile
	@echo Testing correct programs...
	rm -f errflag
	-if [ -f runtime$*.py ]; then run="--runtime=runtime$*.py"; fi; \
	python test-proj$* --compiler=$(APYC) $$run correct$*/*.py || touch errflag
	@echo
	@echo Testing erroneous programs...
	-python test-proj$* --errors --compiler=$(APYC) error$*/*.py || touch errflag
	@if test -f errflag; then code=1; else code=0; fi; \
        rm -f errflag; exit $$code

clean:
	$(RM) errflag *~ */*~ 

really-clean: clean
