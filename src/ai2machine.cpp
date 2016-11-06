#include <iostream>
#include <fstream>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

#include "ai.h" 
#include "text_handler.h"

using namespace std;

class literaryMachine: public machine {
	public:
		literaryMachine() : machine(){}

		virtual int interrupt(int interrupt_code);

};

class examMachine: public machine {
	public:
		examMachine() : machine() {}
		virtual int interrupt(int interrupt_code);

};


int literaryMachine::interrupt(int interrupt_code){

	return INTERRUPT_SIGNAL;
}

int examMachine::interrupt(int interrupt_code){

	return INTERRUPT_SIGNAL;
}




int main(){
	srand(time(NULL));

	// Since the Lusiads were written in Portuguese,
	// we need this piece for correctly displaying it in
	// portuguese windows command prompt
	setlocale(LC_ALL, "Portuguese");
	
	// This one holds the AI's to be trained
	// that will be capable of writing text
	literaryMachine writers[100];

	// This one hold the genes of the writing AIs
	gene gene_writers[100];
	

	// Those AIs are for detecting if a text
	// was wrote by the real Camoes or by an AI
	// The objective is that these AIs be so good as an human
	// to the detect if a text was written by a human, and if
	// that happen we can make the machine writers[] hold
	// AIs that passes the Turing Test
	examMachine readers[100];

	// Below are the readers[]'s genes
	gene gene_readers[100];

	for(int i=0; i<100; i++){

		writers[i].loadGene(gene_writers[i]);
		readers[i].loadGene(gene_readers[i]);

	}
	

	return 0;
}


