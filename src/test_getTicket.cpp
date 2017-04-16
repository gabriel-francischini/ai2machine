#include <iostream>
#include "ai.h"

int main(){
	/*srand(time(NULL));

	for(int i=0; i<50; i++){
		cout << " " << dist100(mt) << " ";
	}*/

	cout <<"\n Test started, loading machine and genes ... \n";

	gene genes[100];
	machine machines[100];

	for(int i=0; i<100; i++)
		machines[i].loadGene(genes[i]);


	cout << "Machines loaded ...\n";
	cout << "Print first 5 characters of each machine memory... \n\n";

	for(int i=0; i<100;i++){
		char *start = machines[i].getMemory();

		for(char j=0; j<5; j++)
			cout << (int) *(start+j) << " ";

		cout << " | ";
	}

	cout << "\n\nStarting to get tickets... \n\n";

	for(int j=0; j<100; j++){

		for(int i=0; i<100; i++)
			cout << " " << machines[j].getTicket();

	}

	cout << "\nTest ok! ";

	cout << "\n\n Now we are going to test ALL instructions! :D \n\n";

	for(;;){
		genes[0] = gene();
		char *memory = genes[0].getMemory();

		cout << "&";

		for(int i=-1; i<(MEM_SPACE);i++){
			*(memory+i) = distchar(mt);
		}

		cout << "*";

		for(int i=0; i<15000; i++)
			cout << "\n\t\t\t\tNEW MEMORY";
		
		cout << "\n";
		
		machines[0].loadGene(genes[0]);

		cout << "^";

		for(long int i=0; i<(MEM_SPACE); i++){
			cout << "§";
			int *machine_memory = machines[0].getRegisters();
			cout << "~";

			for(int j=0; j<3; j++)
				cout << " " << i << "\'" << GEN_SPACE <<" REG[" << j << "]:" << *(machine_memory+j);
			cout << "\t| ";
			cout << " " << machines[0].getTicket() << ":RES \n";
		}


	}

	return 0;
}