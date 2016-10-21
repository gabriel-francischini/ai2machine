#include <iostream>
#include <fstream>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include "ia.h"
using namespace std;


#define BUFF_SIZE 400

int main(){
	
	// Since the Lusiads were written in Portuguese,
	// we need this piece for correctly displaying it in
	// portuguese windows command prompt
	setlocale(LC_ALL, "Portuguese");
	
	// This holds the file itself with the text
	fstream lusiadas;

	// This buff is for reading the file
	char buff[BUFF_SIZE];

	// This actually opens the text for reading
	lusiadas.open("lusiadas.txt");
	
	// This reads 10 junks of BUFF_SIZE lenght
	// out of the text file and put it on buff[],
	// then we print it to the console
	for(int i=0; i<10;i++){

		// This is the actual reading instruction
		lusiadas.read(&buff[0], BUFF_SIZE);

		// This one is for printing to the stdout
		// we could not use "cout <<" because that
		// is a not-counted method. i.e. it tries
		// to guess the lenght of the text and expects
		// a null-terminating character, but we
		// don't have such a character in our text
		// Also, it's a lot safer for buffer overflow hacking attacks
		cout.write(buff, BUFF_SIZE);
	}
	
	// This one holds the AI's to be trained
	// tha will be capable of writing text
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
	
	// Load up the genes inside the writers
	for(int i=0;i<100;i++){
		writers[i].loadGene(gene_writers[i].getMemory(), gene_writers[i].memory_limit);	
	}
	
	// This tests for memory and below we test for mutations
	//writers[0].printMemory();
	for(int i=0;i<1000;i++){
	
	gene_writers[2].checkMutations();
	
	}
	

	// See the binary code of a random number
	for(int i;i<80;i++){
		char j = (int) rand();
		int c=1;
		
		while((j != 0) || ((j%2) !=0) || ((j/2) !=0)){
			if(j%2) cout << "1";
			if(!(j%2)) cout << "0";
			if(!(c%8)) cout<<" ";
			c +=1;
			j = (j/2);	
		}
		 cout <<"\n";
	}
	
/*	char x[]= "bubble";
	char *y = &x[0];
	int *z = (int *) y;
	char *d[] = {&x[0], &x[1], &x[2], &x[3], &x[4], &x[5]};
	cout << "\nx[0]: " << x[0];
	cout << "\ny: " << y;
	cout << "\n&x[0]: " << &x[0];
	cout << "\nz = (int *) y: " << ((int *) y);
	cout << "\n(char*) z: " << (char *) z;
	for(int i=0; i<6; i++){
		cout << "\n(int *) d[" << i << "] : " << (int *) d[i];
	}

	for(int i=0; i<726; i++){
		int *f = (int *) d[3];
		cout << "\n&d[3] + " << i << " : " << (*f+=1);
		cout << "\nd[0] : " << d[0];
	}*/

	
	// Close the text file
	lusiadas.close();
	return 0;
}


