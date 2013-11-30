PIC = gpic

TEX = latex

DVIPS = dvips

PS2PDF = ps2pdf

%.ps: %.pic
	$(PIC) -t $< > $*.tex
	$(TEX) $*.tex < /dev/null
	$(TEX) $*.tex < /dev/null
	$(DVIPS) -o $@ $*.dvi

%.pdf: %.ps
	$(PS2PDF) $< $@

.PHONY: default clean

default: horn.pdf

really-clean: clean
	$(RM) *.pdf

clean:
	$(RM) *.ps *~ *.out *.aux *.log *.dvi *.cb 
	$(RM) horn.tex
