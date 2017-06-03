all: debug release

release: ai.h gene.h machine.h ai2machine.cpp pymachine.so
	g++ -std=c++11 -Wall -o ai2machine.exe ai2machine.cpp
	g++ -std=c++11 -Wall -o a.exe ai2machine.cpp

debug: ai2machine.exe tests pymachine.so

pymachine.so: pymachine.cpp machine.h setup.py
	#g++ -std=c++11 -Wall -g -o pymachine.exe pymachine.cpp -I/usr/include/python3.5 -lpython3.5m
	python setup.py build
	cp ./build/lib.linux-x86_64-3.5/pymachine.cpython-35m-x86_64-linux-gnu.so pymachine.so
	cp pymachine.so ./tests/pymachine.so

ai2machine.exe: ai.h gene.h machine.h ai2machine.cpp
	g++ -std=c++11 -Wall -g -o ai2machine.exe ai2machine.cpp

tests:
	cd tests && $(MAKE) $@

clean:
	rm test_file.exe
	rm test_loadGene.exe
	rm test_random_text.exe
	rm test_scan.exe
	rm ai2machine.exe
	rm a.exe

.PHONY: all release debug clean