package = ai2machine
version = alpha-0.0.0
tarname = $(package)
distdir = $(package)-$(version)

all: debug release

debug:
	cd src && $(MAKE) $@

test:
	cd src && $(MAKE) $@

release:
	cd src && $(MAKE) $@
	cp src/ai2machine.exe ./ai2machine.exe
	cp src/a.exe ./a.exe
	rm src/ai2machine.exe
	rm src/a.exe


dist: $(distdir).tar.gz

$(distdir).tar.gz: $(distdir)
	tar -chof temp.tar $(distdir) 
	gzip -9 -c temp.tar > $@
	rm -rf $(distdir)
	rm temp.tar

$(distdir):
	mkdir $(distdir)
	mkdir -p $(distdir)/src
	cp makefile $(distdir)
	cp src/makefile $(distdir)/src
	cp src/ai2machine.cpp $(distdir)/src
	cp src/ai.h $(distdir)/src

.PHONY: all dist