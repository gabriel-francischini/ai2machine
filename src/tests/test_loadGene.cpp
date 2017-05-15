#include <iostream>
#include "../ai.h"

int useGene(gene a){
    a.memory[0] = 0;
    return 0;
}

int main(){

    cout << "Before creating array of genes!\n";
	gene genes[100];
    cout << "After creating array of genes!\n";
	machine machines[100];
    cout << "After creating array of machines!\n";

	for(int i=0; i<100; i++){
		machines[i].loadGene(genes[i]);
        //useGene(genes[i]);
	}
    cout << "After loading all machines!\n";

	cout << "Test ok!\n";
	return 0;
}