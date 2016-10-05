#ifndef MACHINE_AI
#define MACHINE_AI

#define MEM_SPACE 4096
#define MEM_LEN MEM_SPACE-1
#define GEN_SPACE 4096
#define GEN_LEN GEN_SPACE-1

#define REGISTERS_AMOUNT sizeof(char)
#define REGISTERS_RANGE REGISTERS_AMOUNT-1

class machine{
	char memory[MEM_SPACE];
	
	// The size of a char is one byte,
	// so here we have an amount of registers
	// that can be represented in one byte
	int registers[REGISTERS_AMOUNT];
	
	public:
		void getTicket(int number);
		void getTicket();
		void printMemory();
		void loadGene(gene genome);
	
}


class gene{
	char memory[GEN_SPACE];
	
	public:
	
}


#endif

