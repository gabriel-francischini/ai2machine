#include <iostream>
#include <fstream>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <random>

#include "ai.h" 
#include "text_handler.h"
#include "ai_scan.h"

using namespace std;

#define TEXT_BUFFER 1024
#define MAX_TICKETS 100000

unsigned int MAX_INT = ((int) pow(2,(sizeof(int)*8)-1));


//mt19937 my_rand(1493 + time(NULL));
default_random_engine my_rand(1493 + time(NULL));

// This one is a shared buffer for
// ai calling
char text_buffer[TEXT_BUFFER];

// This one is a length randomiser for text_buffer
// It randomizes how much text is typed unto text_buffer
uniform_int_distribution<int> dist_text(200, TEXT_BUFFER-1);
uniform_int_distribution<int> dist_ticket((MAX_TICKETS/10), MAX_TICKETS);

// Distribution to randomly selects a machine
uniform_int_distribution<int> dist_machine(0,99);
uniform_int_distribution<unsigned long int> dist_the_better_half(0, 49);
uniform_int_distribution<unsigned long int> dist_ulong_int(0, pow(2,(sizeof(unsigned long int)*8)-1));


// This two holds how much text is on text_buffer
// and how big is text_buffer
int buffer_length = TEXT_BUFFER;
const int buffer_limit = TEXT_BUFFER;
int buffer_pointer = 0;

#define isBufferFull() (buffer_length < buffer_limit)


int last_interrupt_code = 0;



void getTextOnBuffer(){

	// First we get a random length
	buffer_length = dist_text(my_rand);

	// Then we load that much of text inside buffer
	random_text("lusiadas.txt", &text_buffer[0], buffer_length);

	// And set pointer to the beginning of buffer
	buffer_pointer = 0;
}

void getTextFromBuffer(char *dest, int size){

	// If we have text to print out AND
	// we have sufficient characters to fulfill the request
	if((buffer_pointer+size) < buffer_length){

		// Copies size characters to destination buff
		for(int i=0; i< size; i++){

			// Copy byte at position 0, 1, 2, 3, ..., size-1
			// to the destination buff
			*(dest+i) = text_buffer[buffer_pointer];

			// Increase the buff pointer, since we want to copy the 
			// buffer, not the same character over and again as if
			// we didn't increase the buffer pointer
			buffer_pointer++;
		}
	}
	else
		// If more bytes have been requested than how many we have,
		// print out all that was left out
		if(buffer_pointer < buffer_length){

			// Copy bytes 0, 1, 2, .... size-1 to the dest buff
			for(int i=0; buffer_pointer < buffer_length; buffer_pointer++){
				*(dest + i) = text_buffer[buffer_pointer];

				// Be sure to write to the buffer, not the same char
				// over and over again
				i++;
			}
		}

	// If none of above conditions are met, it means that
	// we have no bytes to output [all of them already have been
	// printed out]	

	return;

}

void getTextToBuffer(char *source, int size, bool resetBuffLength = false){

	if(resetBuffLength){
		buffer_pointer = 0;
		buffer_length = 0;
	}

	if((buffer_length + size) < buffer_limit){
		for(int i = 0; i < size; i++){
			text_buffer[buffer_length] = *(source+i);
			buffer_length++;
		}
	}
	else

		if(buffer_length < buffer_limit){
			for(int i = 0; i < buffer_limit; i++){
				text_buffer[buffer_length] = *(source+i);
				buffer_length++;
			}
		}


	return;
}


class literaryMachine: public machine {
	public:
		literaryMachine() : machine(){}

		virtual int interrupt(int interrupt_code, int parameter);

};

class examMachine: public machine {
	public:
		examMachine() : machine() {}
		virtual int interrupt(int interrupt_code, int parameter);

};


int literaryMachine::interrupt(int interrupt_code, int parameter){

	int *stack_pointer = &this->registers[1];
	int stack_position = *stack_pointer;

	

	if(this->chkm(stack_position)){
		getTextToBuffer(&this->memory[stack_position], 1);
	}


	

	last_interrupt_code = interrupt_code;
	return INTERRUPT_SIGNAL;
}

int examMachine::interrupt(int interrupt_code, int parameter){

	int *stack_pointer = &this->registers[1];
	int stack_position = *stack_pointer;


	if(this->chkm(stack_position)){
		getTextFromBuffer(&this->memory[stack_position], 1);
	}


	

	last_interrupt_code = interrupt_code;
	return INTERRUPT_SIGNAL;
}



	/*
	 *
	 *		ATTENTION
	 *
	 *	The following code MUST be in the
	 *	main memory, however very compilers
	 *	declare varibale's (and arrays')
	 *	space in the stack.
	 *
	 *	It's too much bytes so doing that
	 *	will lead to a run-time stack overflow.
	 *
	 *	That why, and only that, the variable
	 *	became global.
	 *
	 */



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


int main(){

	// Since the Lusiads were written in Portuguese,
	// we need this piece for correctly displaying it in
	// portuguese windows command prompt
	setlocale(LC_ALL, "Portuguese");

	// Variable to holds each one score's
	unsigned long int writers_score[100];
	unsigned long int readers_score[100];

	for(int i=0; i<100; i++){

		writers[i] = literaryMachine();
		gene_writers[i] = gene();
		readers[i] = examMachine();
		gene_readers[i] = gene();


		writers[i].loadGene(gene_writers[i]);
		readers[i].loadGene(gene_readers[i]);

		writers_score[i] = 0;
		readers_score[i] = 0;

	}

	cout << "\n\n Crossover mutation at " << CROSSOVER_RATE << " with mutation chance at " << MUTATION_CHANCE << "\n";


	cout << "\n";
	// Now we start to evolve the machines
	for(int generation=0; generation < 1000000; generation++){

		time_t now = time(nullptr);
		char *string_now = asctime(gmtime(&now));

		cout << "\n[";
		cout.write(string_now, 24);
		cout << "]: Started generation " << generation << "\n";

		// First, we get a random sample of each one's score

		/*cout << "\n Printing every first byte of every gene: \n";

		char hex[3];

		for(int i=0;i < 100; i++){
			getHexFromChar(&gene_readers[i].memory[0], &hex[0]);
			cout << "\t " << hex;
		
		}

		cout << "\n";*/


		for(int examples=0; examples < 2000; examples++){

			if(!(examples%200))
				cout << ".";

			// We randomly decides if the text to be examinated will
			// be from the text input OR it will be generated by a machine			
			if(dist2(my_rand) == 1){

				// So a machine will generate the text

				// We choose a random machine
				int literary_number = dist_machine(my_rand);
				literaryMachine *random_literary = &writers[literary_number];

				// How much tickets (clocks) this machine has to waste
				long int tickets = dist_ticket(my_rand);


				// Now we use all the tickets!
				for(int used_tickets=0; used_tickets < tickets; used_tickets++){					
					random_literary->getTicket();
				}

				// Now we examine how good that AI was on generating text

				// We randomly choose a examiner
				int temp, *ptemp;
				int exam_number;
				temp = dist_machine(my_rand);

				exam_number = temp;

				while((exam_number < 0) || (exam_number > 99)){
					exam_number = dist_machine(my_rand);
				}

				//cout << "\n\n exam_number: " << exam_number;

				examMachine *random_examinator = &readers[exam_number];

				ptemp = ((int *) ((char *) (&random_examinator)));
				temp = (int) *((char *)(&random_examinator));
				ptemp = ((int*) ((char *) (&readers[exam_number])));
				temp =  (readers[exam_number].registers[0]);
				ptemp = (int *) (char *) &readers[0];

				// Get another round of tickets
				temp = dist_ticket(my_rand);
				tickets = temp;


				// Now we BURN those tickets!
				for(int used_tickets=0; used_tickets < tickets; used_tickets++){
					readers[exam_number].getTicket();
				}

				// And now we assign each one his score
				unsigned int evaluated_score; 

				

				// The score of the literary one is what the exam one said
				writers_score[literary_number] += evaluated_score;

				// And the score of the exam one is the value of how much
				// right he was to say that this one is another AI
				readers_score[exam_number] += MAX_INT - evaluated_score;

				if(readers_score[exam_number] == 0)
					readers_score[exam_number] = 1;

				// Now we reset the buffer for reuse
				buffer_length = 0;
				buffer_pointer = 0;
			}
			else{

				// We decided to get text from the file input text file
				getTextOnBuffer();

				// We randomly choose a examiner
				int exam_number = dist_machine(my_rand);
				examMachine *random_examinator = &readers[exam_number];

				// Get a round of tickets
				long int tickets = dist_ticket(my_rand);

				// Now we BURN those tickets!
				for(int used_tickets=0; used_tickets < tickets; used_tickets++){
					random_examinator->getTicket();
				}

				// And now we assign each one his score
				unsigned int evaluated_score = *((random_examinator->getRegisters())+5);

				// And the score of the machine is how much it was right
				// saying if this a real text (0) or fake text (65355)
				readers_score[exam_number] += evaluated_score;

				if(readers_score[exam_number] == 0)
					readers_score[exam_number] = 1; 

				// Now we reset the buffer for reuse
				buffer_length = 0;
				buffer_pointer = 0;
			}

		}

		// After everyone has been tested, we need to kill the worst ones

		// first we copy ours score's array
		static unsigned int long writers_score_arranged[100];
		static unsigned int long readers_score_arranged[100];

		for(int i=0;i<100;i++){
			writers_score_arranged[i] = writers_score[i];
			readers_score_arranged[i] = readers_score[i];
		}

		// Now we sort it
		sort(&writers_score_arranged[0], &writers_score_arranged[100]);
		sort(&readers_score_arranged[0], &readers_score_arranged[100]);


		// After we sorted the scores, we need to sort the machines themselves
		// We'll do that by relating each score with one array

		static bool used_writers[100];
		static bool used_readers[100];

		for(int i=0;i < 100; i++){
			used_writers[i] = false;
			used_readers[i] = false;
		}

		int writers_arranged[100];
		int readers_arranged[100];


		// For each score, we find a correlative machine
		// First we get a score
		for(int arranged_position=0; arranged_position < 100; arranged_position++){
			// Then we need to find it's machine
			for(int old_position=0; old_position<100; old_position++){

				// If a writer machine hasn't connected to his score yet
				// and the actual score is it's score
				if( (!used_writers[old_position]) && (writers_score_arranged[arranged_position] == writers_score[old_position]) ){
					// We put the machine number in the arranged array
					// so each writers_arranged[] holds the number of a machine
					writers_arranged[arranged_position] = old_position;

					// Now we mark that machine as used
					// so a machine can't have 2 scores
					used_writers[old_position] = true;
					break;
				}
			}
		}


		// Same for the examinaters/readers
		for(int arranged_position=0; arranged_position < 100; arranged_position++){
			for(int old_position=0; old_position<100; old_position++){
				if( (!used_readers[old_position]) && (readers_score_arranged[arranged_position] == readers_score[old_position]) ){
					readers_arranged[arranged_position] = old_position;
					used_readers[old_position] = true;
					break;
				}
			}
		}



		// If it's the time, we print the better one so far
		if(!(generation%1)){

			literaryMachine *theBest = &writers[writers_arranged[0]];

			for(int used_tickets=0; used_tickets < MAX_TICKETS; used_tickets++)
				theBest->getTicket();

			cout << "\n Score of the best reader: " << readers_score_arranged[0];
			cout << "\n Score of the best writer so far: " << writers_score_arranged[0];
			cout << "\n Score of the worst reader: " << readers_score_arranged[99];
			cout << "\n Score of the worst writer so far: " << writers_score_arranged[99];
			cout << "\n The best one so far:\n\n";
			cout.write(&text_buffer[0], buffer_length);
			cout << "\n\n Compare with:\n\n";

			getTextOnBuffer();
			cout.write(&text_buffer[0], buffer_length);
			cout << "\n\n";

			buffer_length = 0;
			buffer_pointer = 0;

		}



		// Now we made a reference array for selecting the worse
		static unsigned long int reference_writers_score[100];
		static unsigned long int reference_readers_score[100];

		unsigned long int writers_sum = 0;
		unsigned long int readers_sum = 0;

		for(int i=0; i < 100; i++){
			writers_sum += writers_score_arranged[i];
			readers_sum += readers_score_arranged[i];

			reference_writers_score[i] = writers_sum;
			reference_readers_score[i] = readers_sum;


		}

		cout << "\nThe median score for writers is: " << (writers_sum/100);
		cout << "\nThe median score for readers is: " << (readers_sum/100);



		// Finally, we can select the better ones and
		// discard away the not-so-good ones
		uniform_int_distribution<unsigned long int> dist_writers(0, writers_sum);
		uniform_int_distribution<unsigned long int> dist_readers(0, readers_sum);
		//uniform_int_distribution<unsigned long int> dist_the_better_half(0, 50);

		// We will kill 30 of both writers and readers
		for(int deaths=0; deaths < 20; deaths++){

			// This we will use to scan through scores
			unsigned long int last_writer_value = 0;
			unsigned long int last_reader_value = 0;

			// This one helds the score desired, but
			// after for they'll held the number of the
			// machine desired
			unsigned long int writers_unlucky_one = dist_writers(my_rand);
			unsigned long int readers_unlucky_one = dist_readers(my_rand);

			// We use these switches to know when to stop
			bool writers_done = false, readers_done = false;

			/*for(int i=0; i < 100; i++){
				used_readers[i] = false;
				used_writers[i] = false;
			}*/

			//cout << "\nReference_writers_score: ";
			// We will search through all the machines
			for(int i=0; i < 101; i++){
				
				//cout << "\t " << reference_writers_score[i];

				// If we have not found a unlucky writer yet
				if(!writers_done){

					//if(used_writers[i]){

					//}

					if(i == 100){
						writers_unlucky_one = dist_machine(my_rand);
					}
					else{

						// We see if it was the unlucky one to be randomised to death
						// (i.e. its score is the nearest one to the randomised score)
						if((last_writer_value <= writers_unlucky_one) && (writers_unlucky_one <= reference_writers_score[i])){
						
							// If it was, we mark it
							writers_unlucky_one = writers_arranged[i];
						
							if(i != 0)
								reference_writers_score[i] = reference_writers_score[i-1];
							else
								reference_writers_score[i] = 0;

							writers_done = true;
						}

						else {

							// Otherwise, we keep looking
							last_writer_value = reference_writers_score[i];
						}
					}
					
				}

				// Same as above
				// See if we have already found a unlucky reader
				if(!readers_done){

					if(i == 100){
						readers_unlucky_one = dist_machine(my_rand);
					}
					else{

						// Test to see if it is the chosen one
						if( (last_reader_value <= readers_unlucky_one) && (readers_unlucky_one <= reference_readers_score[i]) ){
							readers_unlucky_one = readers_arranged[i];

							if(i != 0)
								reference_readers_score[i] = reference_readers_score[i-1];
							else
								reference_readers_score[i] = 0;


							readers_done = true;
						}
						else {

							// Otherwise, prepare to keep searching
							last_reader_value = reference_readers_score[i];
						}
					}
					
				}

				// If both values were found, we don't need to search the remainig ones
				if(readers_done && writers_done)
					break;

			}

			// We also need to choose parents for the unlucky ones' substitutes
			int writer_father = writers_arranged[dist_the_better_half(my_rand)],
				writer_mother = writers_arranged[dist_the_better_half(my_rand)],
				reader_father = readers_arranged[dist_the_better_half(my_rand)],
				reader_mother = readers_arranged[dist_the_better_half(my_rand)];

			// Now we wipe out the unlucky one's DNA from the gene pool,
			// And substitute them for new born machines
			gene_writers[writers_unlucky_one].reproduce(&gene_writers[writer_mother], &gene_writers[writer_father]);
			gene_readers[readers_unlucky_one].reproduce(&gene_readers[reader_father], &gene_readers[reader_mother]);
			
			// Now we put those machines on the play
			writers[writers_unlucky_one].clearMemory();
			writers[writers_unlucky_one].loadGene(gene_writers[writers_unlucky_one]);
			writers_score[writers_unlucky_one] = 0;

			//cout << "\t Killing readers[\t" << readers_unlucky_one << "\t]";
			readers[readers_unlucky_one].clearMemory();
			readers[readers_unlucky_one].loadGene(gene_readers[readers_unlucky_one]);
			readers_score[readers_unlucky_one] = 0;

			for(int i=0; i < 100; i++){
				readers_score[i] = 0;
				writers_score[i] = 0;
			}

		}
	}
	return 0;	
}


