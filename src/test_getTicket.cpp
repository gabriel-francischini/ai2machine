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

		for(int i=0; i<100; i++);
			cout << " " << machines[j].getTicket();

	}

	cout << "\nTest ok! ";

	cout << "\n\n Now we are going to test ALL instructions! :D \n\n";

	for(;;){
		char *memory = genes[0].getMemory();

		for(int i=0; i<GEN_SPACE;i++){
			*(memory+i) = distchar(mt);
		}

		for(int i=0; i<15000; i++)
			cout << "\n\t\t\t\tNEW MEMORY";
		
		cout << "\n";
		
		machines[0].loadGene(genes[0]);

		for(int i=0; i<(GEN_SPACE*4); i++){
			int *machine_memory = machines[0].getRegisters();
			
			for(int j=0; j<2; j++)
				cout << " " << *(machine_memory+j);
			cout << " | ";
			cout << "\n " << machines[0].getTicket();
			*machine_memory = i%GEN_SPACE;
		}


	}

	return 0;
}