#ifndef AI_GROUP
#define AI_GROUP

#include "machine.h"
#include "gene.h"

class machine:public Machine{
	using Machine::Machine;
		
	public:
		void loadGene(gene genome);		

		machine() : machine(32, 8) {} // Some default values

};

// This one need to go here,
// after the declaration of genome and machine classes
void machine::loadGene(gene genome){
	this->loadOnMemory(genome.getMemory(), (int) genome.memory_limit());
}


mt19937 mt(1792 + time(NULL));
uniform_int_distribution<int> dist2(0,1);
uniform_int_distribution<int> dist100(0,100);
uniform_int_distribution<int> distchar(0,(int)(pow(2,sizeof(char)*8)-1));

#endif
