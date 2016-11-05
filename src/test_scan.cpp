#include "ai_scan.h"




int main(){
	gene gene_a;
	machine machine_a;
	machine_a.loadGene(gene_a);

	for(int i=0; i<10; i++){
		printMemory(machine_a.getMemory()+*machine_a.getRegisters(), 6, *machine_a.getRegisters());
		machine_a.getTicket();
	}
}

