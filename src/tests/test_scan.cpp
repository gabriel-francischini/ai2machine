#include "../ai_scan.h"




int main(){
	gene gene_a;
	machine machine_a;
	machine_a.loadGene(gene_a);

	int memory_limit = machine_a.memory_limit();

	for(int i=0; i<memory_limit; i++){
		char hex_i[9] = {0, 0, 0, 0, 0, 0, 0, 0};
		char char_i;
		for(int j=0; j<4; j++){
			char_i = (char) (i >> (8 * (3-j) ) );
			getHexFromChar(&char_i, &hex_i[j*2]);
		}
		cout << " " << hex_i << ": ";
		printMemory( (machine_a.getMemory()+i) , 1, 5);
		cout << "\n";
		//machine_a.getTicket();
	}
}

