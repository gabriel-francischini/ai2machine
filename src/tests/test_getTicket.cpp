#include <iostream>
#include "../ai.h"

int main(){
	/*srand(time(NULL));

	for(int i=0; i<50; i++){
		cout << " " << dist100(mt) << " ";
	}*/

	cout <<"\n Test started, loading machine and genes ... \n";

	gene genes[100];
	machine machines[100];

	for(int i=0; i<100; i++){
		cout << "Loading gene " << i << " to machine " << i << "\n";
		machines[i].loadGene(genes[i]);
	}


	cout << "Machines loaded ...\n";
	cout << "Starting to get tickets... \n\n";

	for(int j=0; j<100; j++){

		for(int i=0; i<100; i++){
			int ip = machines[j].registers[0];
			int sp = machines[j].registers[1];
			int flags = machines[j].registers[2];
			int instruction = (int) machines[j].memory[ip];
			int result = machines[j].getTicket();
			cout << "MACH: " << j <<"\tIP: " << ip << "\tSP: " << sp << "\tINST: " << instruction << "\tRESULT: "; 
			if(result == -1)
				cout << "ERROR_SIGNAL\n";
			else
				cout << "OK\n";
		}

	}

	cout << "Test ok!\n";
	cout << "Now we are going to test ALL instructions! :D\n";

	for(int k=0;k < 10000;k++){
		//cout << "Replacing old variable with a new one! :D\n";
		genes[0] = gene();
		cout << "\n\t\t\t\tNEW MEMORY nº " << k << "\n";
		
		char *memory = genes[0].memory;

		for(int i=0; i<(genes[0].memory_limit());i++){
			memory[i] = distchar(mt);
		}

		machines[0].loadGene(genes[0]);

		int ip = machines[0].registers[0];
		int sp = machines[0].registers[1];
		int flags = machines[0].registers[2];
		int instruction = (int) machines[0].memory[ip];
		int result = machines[0].getTicket();
		cout << "TRY: " << k <<"\tIP: " << ip << "\tSP: " << sp << "\tINST: " << instruction << "\tRESULT: "; 
		if(result == -1)
			cout << "ERROR_SIGNAL\n";
		else
			cout << "OK\n";


	}

	return 0;
}