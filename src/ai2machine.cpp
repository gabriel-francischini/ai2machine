#include <iostream>
#include <fstream>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

#include "ai.h" 
#include "text_handler.h"

using namespace std;


int main(){
	srand(time(NULL));

	// Since the Lusiads were written in Portuguese,
	// we need this piece for correctly displaying it in
	// portuguese windows command prompt
	setlocale(LC_ALL, "Portuguese");
	
	// This one holds the AI's to be trained
	// that will be capable of writing text
	machine writers[100];

	// This one hold the genes of the writing AIs
	gene gene_writers[100];
	

	// Those AIs are for detecting if a text
	// was wrote by the real Camoes or by an AI
	// The objective is that these AIs be so good as an human
	// to the detect if a text was written by a human, and if
	// that happen we can make the machine writers[] hold
	// AIs that passes the Turing Test
	machine readers[100];

	// Below are the readers[]'s genes
	gene gene_readers[100];
	

	return 0;
}


