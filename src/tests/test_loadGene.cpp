#include <iostream>
#include "../ai.h"

int main(){

	gene genes[100];
	machine machines[100];

	for(int i=0; i<100; i++){
		machines[i].loadGene(genes[i]);
	}

	cout << "Test ok!";
	return 0;
}