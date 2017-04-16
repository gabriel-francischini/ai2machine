tests: test_file.exe test_loadGene.exe test_getTicket.exe test_random_text.exe test_scan.exe

test_file.exe: test_file.cpp
	g++ -std=c++11 -Wall -g -o test_file.exe test_file.cpp

test_loadGene.exe: test_loadGene.cpp ../ai.h 
	g++ -std=c++11 -Wall -g -o test_loadGene.exe test_loadGene.cpp

test_getTicket.exe: test_getTicket.cpp ../ai.h 
	g++ -std=c++11 -Wall -g -o $@ test_getTicket.cpp

test_random_text.exe: ../text_handler.h test_random_text.cpp
	g++ -std=c++11 -Wall -g -o $@ test_random_text.cpp

test_scan.exe: ../ai_scan.h ../ai.h test_scan.cpp
	g++ -std=c++11 -Wall -g -o $@ test_scan.cpp

test_memory_dec.exe: ../ai_scan.h ../ai.h test_memory_dec.cpp
	g++ -std=c++11 -Wall -g -o $@ test_memory_dec.cpp   
