#ifndef MACHINE_AI
#define MACHINE_AI

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <random>
using namespace std;

// Global variables
const int MEM_SPACE = 32; //(4096*16)
#define MEM_LEN (MEM_SPACE - 1)
const int GEN_SPACE = 32; //4096
#define  GEN_LEN (GEN_SPACE-1)
const int REGISTERS_AMOUNT = 10; //((int) pow(2,(sizeof(char)*8)-1))
#define REGISTERS_RANGE (REGISTERS_AMOUNT-1)

// This numbers are percentage, i.e.
// a 5 would mean that 5 of 100 suffers that
#define MUTATION_CHANCE 2
#define CROSSOVER_RATE 80


// Here we define which bits in FLAGS do what
#define CARRY_FLAG 1
#define PARITY_FLAG 1<<1
#define AUXILIARY_CARRY_FLAG 1<<2
#define ZERO_FLAG 1<<3
#define SIGN_FLAG 1<<4
#define TRACE_FLAG 1<<5
#define INTERRUPT_FLAG 1<<6
#define DIRECTION_FLAG 1<<7
#define OVERFLOW_FLAG 1<<8

// Macros to get, set true and set false flags
#define GETFLAG(variable, flag) (variable & (flag))
#define SETFLAG(variable, flag) (variable = (variable | flag))
#define UNSETFLAG(variable, flag) (variable = (variable) & (!flag))

// For function intercommunication
#define ERROR_SIGNAL -1
#define INTERRUPT_SIGNAL -2;

// General opcodes
#define MOV_REG_REG 0x0001
#define MOV_MEM_REG 0x0002
#define MOV_REG_MEM 0x0003
#define MOV_MEM_VALUE 0x0004
#define MOV_REG_VALUE 0x0005
#define XCHG_REG_MEM 0x0006
#define XCHG_REG_REG 0x0007
#define PUSH_REG 0x0008
#define PUSH_MEM 0x0009
#define PUSH_VALUE 0x000A
#define PUSH_FLAGS 0x000C
#define POP_REG 0x000D
#define POP_MEM 0x000E
#define POP_FLAGS 0x0010

// Arithmetic opcodes
#define ADD_REG_REG 0x0011
#define ADD_REG_MEM 0x0012
#define ADD_MEM_REG 0x0013
#define ADD_REG_VALUE 0x0014
#define ADD_MEM_VALUE 0x0015
#define INC_REG 0x0016
#define INC_MEM 0x0017
#define XADD_MEM_REG 0x0018
#define XADD_REG_REG 0x0019
#define SUB_REG_REG 0x001A
#define SUB_REG_MEM 0x001B
#define SUB_MEM_REG 0x001C
#define SUB_REG_VALUE 0x001D
#define SUB_MEM_VALUE 0x001E
#define DEC_REG 0x001F
#define DEC_MEM 0x0020
#define CMP_REG_REG 0x0021
#define CMP_REG_MEM 0x0022
#define CMP_MEM_REG 0x0023
#define CMP_REG_VALUE 0x0024
#define CMP_MEM_VALUE 0x0025
#define NEG_REG 0x0026
#define NEG_MEM 0x0027
#define MUL_REG_REG 0x0028
#define MUL_REG_MEM 0x0029
#define MUL_REG_VALUE 0x002A
#define DIV_REG_REG 0x002B
#define DIV_REG_MEM 0x002C
#define DIV_REG_VALUE 0x002E

// Boolean operators
#define AND_REG_REG 0x002F
#define AND_MEM_REG 0x0030
#define AND_REG_MEM 0x0031
#define AND_REG_VALUE 0x0032
#define AND_MEM_VALUE 0x0033
#define OR_REG_REG 0x0034
#define OR_MEM_REG 0x0035
#define OR_REG_MEM 0x0036
#define OR_REG_VALUE 0x0037
#define OR_MEM_VALUE 0x0038
#define XOR_REG_REG 0x0039
#define XOR_MEM_REG 0x003A
#define XOR_REG_MEM 0x003B
#define XOR_REG_VALUE 0x003C
#define XOR_MEM_VALUE 0x003D
#define NOT_REG 0x003E
#define NOT_MEM 0x003F

// Bitshift operations
#define SHL_REG_REG 0x0040
#define SHL_MEM_REG 0x0041
#define SHL_REG_VALUE 0x0042
#define SHL_MEM_VALUE 0x0043
#define SHR_REG_REG 0x0044
#define SHR_MEM_REG 0x0045
#define SHR_REG_VALUE 0x0046
#define SHR_MEM_VALUE 0x0047

// The following do the rotating
// bitwise operation
#define ROL_REG_REG 0x0048
#define ROL_MEM_REG 0x0049
#define ROL_REG_VALUE 0x004A
#define ROL_MEM_VALUE 0x004B
#define ROR_REG_REG 0x004C
#define ROR_MEM_REG 0x004D
#define ROR_REG_VALUE 0x004E
#define ROR_MEM_VALUE 0x004F
#define RCL_REG_REG 0x0050
#define RCL_MEM_REG 0x0051
#define RCL_REG_VALUE 0x0052
#define RCL_MEM_VALUE 0x0053
#define RCR_REG_REG 0x0054
#define RCR_MEM_REG 0x0055
#define RCR_REG_VALUE 0x0056
#define RCR_MEM_VALUE 0x0057

// The following opcodes act upon
// the FLAGS register
#define SETC_REG 0x0058
#define SETC_MEM 0x0059
#define SETNC_REG 0x005A
#define SETNC_MEM 0x005B
#define SETZ_REG 0x005C
#define SETZ_MEM 0x005D
#define SETNZ_REG 0x005E
#define SETNZ_MEM 0x005F
#define SETS_REG 0x0060
#define SETS_MEM 0x0061
#define SETNS_REG 0x0062
#define SETNS_MEM 0x0063
#define SETO_REG 0x0064
#define SETO_MEM 0x0065
#define SETNO_REG 0x0066
#define SETNO_MEM 0x0067
#define SETP_REG 0x0068
#define SETP_MEM 0x0069
#define SETPE_REG 0x006A
#define SETPE_MEM 0x006B
#define SETNP_REG 0x006C
#define SETNP_MEM 0x006D
#define SETPO_REG 0x006E
#define SETPO_MEM 0x006F

//SETcc opcodes for comparison
#define SETA_REG 0x0070
#define SETA_MEM 0x0071
#define SETNBE_REG 0x0072
#define SETNBE_MEM 0x0073
#define SETAE_REG 0x0074
#define SETAE_MEM 0x0075
#define SETNB_REG 0x0076
#define SETNB_MEM 0x0077
#define SETB_REG 0x0078
#define SETB_MEM 0x0079
#define SETNAE_REG 0x007A
#define SETNAE_MEM 0x007B
#define SETBE_REG 0x007C
#define SETBE_MEM 0x007D
#define SETNA_REG 0x007E
#define SETNA_MEM 0x007F
#define SETE_REG 0x0080
#define SETE_MEM 0x0081
#define SETNE_REG 0x0082
#define SETNE_MEM 0x0083

// Unconditional Jump
#define JUMP_REG 0x0084
#define JUMP_MEM 0x0085
#define CALL_REG 0x0086
#define CALL_MEM 0x0087
#define RET 0x0088

// Call's a system (programmer-defined) function
#define INT_VALUE 0x0089

// Conditional JUMPS that tests flags:
#define JC_MEM 0x0090
#define JC_VALUE 0x0091
#define JNC_MEM 0x0092
#define JNC_VALUE 0x0093
#define JZ_MEM 0x0094
#define JZ_VALUE 0x0095
#define JNZ_MEM 0x0096
#define JNZ_VALUE 0x0097
#define JS_MEM 0x0098
#define JS_VALUE 0x0099
#define JNS_MEM 0x009A
#define JNS_VALUE 0x009B
#define JO_MEM 0x009C
#define JO_VALUE 0x009D
#define JNO_MEM 0x009E
#define JNO_VALUE 0x009F
#define JP_MEM 0x00A0
#define JP_VALUE 0x00A1
#define JPE_MEM 0x00A2
#define JPE_VALUE 0x00A3
#define JNP_MEM 0x00A4
#define JNP_VALUE 0x00A5
#define JPO_MEM 0x00A6
#define JPO_VALUE 0x00A7

// Jump instructions for unsigned comparisons
#define JA_MEM 0x00A8
#define JA_VALUE 0x00A9
#define JNBE_MEM 0x00AA
#define JNBE_VALUE 0x00AB
#define JAE_MEM 0x00AC
#define JAE_VALUE 0x00AD
#define JNB_MEM 0x00AE
#define JNB_VALUE 0x00AF
#define JB_MEM 0x00B0
#define JB_VALUE 0x00B1
#define JNAE_MEM 0x00B2
#define JNAE_VALUE 0x00B3
#define JBE_MEM 0x00B4
#define JBE_VALUE 0x00B5
#define JNA_MEM 0x00B6
#define JNA_VALUE 0x00B7
#define JE_MEM 0x00B8
#define JE_VALUE 0x00B9
#define JNE_MEM 0x00BA
#define JNE_VALUE 0x00BB



mt19937 mt(1792 + time(NULL));
uniform_int_distribution<int> dist2(0,1);
uniform_int_distribution<int> dist100(0,100);
uniform_int_distribution<int> distint(0,(int)(pow(2,sizeof(int)*8)-1));
uniform_int_distribution<int> distchar(0,(int)(pow(2,sizeof(char)*8)-1));


class machine;
class gene;

// Machine is a class that
// implements a processor-like
// machine (a turing machine)
class machine{
	
	public:
	char memory[MEM_SPACE];
	
	// The size of a char is (in my machine) one byte,
	// so here we have an amount of registers
	// that can be represented in one byte
	int registers[REGISTERS_AMOUNT];

	
	public:
		int getTicket(int number);
		int getTicket();
		int execute(unsigned char instruction, char *value1, char *value2, 
					bool isValue1Int = false, bool isValue2Int = false);
		bool chkm(long int address);
		bool chkr(long int address);
		void printMemory();
		void loadGene(char *memory, int length);
		void loadGene(gene genome);		
		void clearMemory();		
		int memory_limit;
		int registers_limit;
		char *getMemory();
		int *getRegisters();
		void saveChanges(unsigned char instruction, int value_1, int value_2, char *value1, char *value2);
		
		virtual int interrupt(int interrupt_code, int parameter){
			return INTERRUPT_SIGNAL;
		}

		machine(){
			this->memory_limit = (int) (MEM_SPACE-1);
			this->registers_limit = (int) (REGISTERS_AMOUNT-1);

			for(int i=0; i<REGISTERS_AMOUNT; i++)
				registers[i] = 0;

		}
		
};



// This function returns a pointer to
// the starting of the memory,
// so one could read it and find
// anything that it wants
char *machine::getMemory(){
	return &this->memory[0];
	
}


int *machine::getRegisters(){
	return &this->registers[0];
}


// Function to print the memory
// to the output
void machine::printMemory(){
	
	// First we print the registers
	for(int i=0; i<=this->memory_limit; i++)
		cout << this->registers[i];
	
	// then we print the real memory
	cout.write(&this->memory[0], MEM_SPACE);
}


// Function to execute int number of
// "machine" instructions
int machine::getTicket(int number){
	for(int i=0;i<=number;i++){
		if(this->getTicket() == ERROR_SIGNAL)
			return ERROR_SIGNAL;	
	}
	return 0;
}









// Executes one instruction
// (this maybe is the most complex one)
int machine::getTicket(){

	// For most operations, we'll need to know
	// the currently instruction and the current stack position
	// Also, we need to know the flags
	int *instruction_pointer = &(this->registers[0]);

	//cout << " INS_P:" << (int) *instruction_pointer << " ";

	int *stack_pointer = &this->registers[1];
	char *ip = (char *) &(*(instruction_pointer));
	// No need to declare the commented variable (unused variable)	
	//int *stack_pointer = &this->registers[1];
	char *flags = (char *) ((int *) &(this->registers[2]));	


	
	// We look what is the stack and what is the code
	// Also, we need to know if the next values are
	// valid memory locations or valid registers
	// (it will ever be a valid number if it exists)
	bool  sp[3], ins[7], reg[7], mem[7];
	char *vins[7], *vmem[7];
	char *vreg[7], *vsp[3];

	
	
	
	// We need to analyze the current instruction and next instructions
	for(int i=0; i < 7; i++){
		
		// First we discover if the current/next instruction(s) do exist
		ins[i] = this->chkm((*instruction_pointer)+i);
		
		// If the current/next instruction(s)/value(s) DO exists...
		if(ins[i]){
			
			// ... we discover it's value
			vins[i]=&this->memory[(*instruction_pointer)+i];
			
			// We also need to know if the value is a valid memory
			// location or a valid register
			reg[i] = this->chkr(*vins[i]);
			mem[i] = this->chkm(*vins[i]);
			
			// If the value IS a valid register, we store the register for later use
			if(reg[i])
				vreg[i] = (char *) &this->registers[(int) *vins[i]];
			
			// If the value is a valid memory, we store that memory for later use
			if(mem[i])
				vmem[i] = (char *) &this->memory[((int) (*vins[i]))];
		}
	}

	//cout << "!";
	
	// We need to analyze the current stack
	for(int i=-1;i<2; i++){
		
		// (the stack grows from the last memory position to the first)	
		int stack_position = (int) (this->memory_limit) - ( (*stack_pointer) + i );	
		
		// We discover if current, last or next stack position exists or not
		sp[i] = this->chkm(stack_position);
		
		// If it do exists, we store it's value
		if(sp[i])
			vsp[i] = &( this->memory[stack_position] );
	}

	
	//cout << "@";
	
	
	// If the actual instruction doesn't exists, put the instruction position
	// to somewhere valid
	if((ins[0] == false) || ( ((*ip) +3 ) > this->memory_limit) ){
		*ip = 0;
		return ERROR_SIGNAL;
	}
	
	else{
		//cout << "#";

		unsigned char instruction = (unsigned char) *vins[0];

		//cout << " INS:" << (int) instruction << " ";
		switch(instruction){
		
		
			case MOV_REG_REG:
			case XCHG_REG_REG:
			case ADD_REG_REG:
			case SUB_REG_REG:
			case CMP_REG_REG:
			case MUL_REG_REG:
			case DIV_REG_REG:
			case XADD_REG_REG:
			case AND_REG_REG:
			case OR_REG_REG:
			case XOR_REG_REG:
			case SHL_REG_REG:
			case SHR_REG_REG:
			case ROL_REG_REG:
			case ROR_REG_REG:
			case RCL_REG_REG:
			case RCR_REG_REG:
				*ip += 3;
				if(reg[1] && reg[2]){
					return this->execute(instruction, (char *) &( *(vreg[1])), (char *) &( *(vreg[2])), true, true);
				}
				else
					return ERROR_SIGNAL;
			break;

			case MOV_REG_MEM:
			case XCHG_REG_MEM:
			case ADD_REG_MEM:
			case SUB_REG_MEM:
			case CMP_REG_MEM:
			case MUL_REG_MEM:
			case DIV_REG_MEM:
			case AND_REG_MEM:
			case OR_REG_MEM:
			case XOR_REG_MEM:
				*ip += 3;
				if(reg[1] && mem[2]){
					return this->execute(instruction, (char *) &( *(vreg[1])), vmem[2], true);
				}
				else
					return ERROR_SIGNAL;
			break;

			case MOV_MEM_REG:
			case ADD_MEM_REG:
			case SUB_MEM_REG:
			case CMP_MEM_REG:
			case XADD_MEM_REG:
			case AND_MEM_REG:
			case OR_MEM_REG:
			case XOR_MEM_REG:
			case SHL_MEM_REG:
			case SHR_MEM_REG:
			case ROL_MEM_REG:
			case ROR_MEM_REG:
			case RCL_MEM_REG:
			case RCR_MEM_REG:
				*ip += 3;
				if(mem[1] && reg[2]){
					return this->execute(instruction, vmem[1], (char *) &( *(vreg[2])), false, true);
				}
				else
					return ERROR_SIGNAL;
			break;

			case MOV_REG_VALUE:
			case ADD_REG_VALUE:
			case SUB_REG_VALUE:
			case CMP_REG_VALUE:
			case MUL_REG_VALUE:
			case DIV_REG_VALUE:
			case AND_REG_VALUE:
			case OR_REG_VALUE:
			case XOR_REG_VALUE:
			case SHL_REG_VALUE:
			case SHR_REG_VALUE:
			case ROL_REG_VALUE:
			case ROR_REG_VALUE:
			case RCL_REG_VALUE:
			case RCR_REG_VALUE:
				*ip += 3;
				if(reg[1] && ins[2]){
					return this->execute(instruction, (char *) &( *(vreg[1])), vins[2], true);
				}
				else
					return ERROR_SIGNAL;
			break;

			case MOV_MEM_VALUE:
			case ADD_MEM_VALUE:
			case SUB_MEM_VALUE:
			case CMP_MEM_VALUE:
			case AND_MEM_VALUE:
			case OR_MEM_VALUE:
			case XOR_MEM_VALUE:
			case SHL_MEM_VALUE:
			case SHR_MEM_VALUE:
			case ROL_MEM_VALUE:
			case ROR_MEM_VALUE:
			case RCL_MEM_VALUE:
			case RCR_MEM_VALUE:
				*ip += 3;
				if(mem[1] && ins[2]){
					return this->execute(instruction, vmem[1], vins[2]);
				}
				else
					return ERROR_SIGNAL;
			break;

			case PUSH_REG:
				*ip += 3;
				if(sp[1] && reg[1]){
					return this->execute(instruction, (char *) &( *(vsp[1])), (char *) &( *(vreg[1])), true, true);
					*stack_pointer += 1;
				}
				else
					return ERROR_SIGNAL;
			break;

			case PUSH_MEM:
				*ip += 3;
				if(sp[1] && mem[1]){
					return this->execute(instruction, (char *) &( *(vsp[1])), vmem[1], true);
					*stack_pointer += 1;
				}
				else
					return ERROR_SIGNAL;
			break;

			case PUSH_VALUE:
				*ip += 3;
				if(sp[1] && ins[1]){
					return this->execute(instruction, (char *) &( *(vsp[1])), vins[1], true);
					*stack_pointer += 1;
				}
				else
					return ERROR_SIGNAL;
			break;

			case PUSH_FLAGS:
				*ip += 3;
				if(sp[1]){
					return this->execute(instruction, (char *) &( *(vsp[1])), (char *) ((int *) &(this->registers[2])), true, true);
					*stack_pointer += 1;
				}
				else
					return ERROR_SIGNAL;
			break;

			case POP_REG:
				*ip += 3;
				if(sp[0] && reg[1]){
					return this->execute(instruction, (char *) &( *(vreg[1])), (char *) &( *(vsp[0])), true, true);
					*stack_pointer -= 1;
				}
				else
					return ERROR_SIGNAL;
			break;

			case POP_MEM:
				*ip += 3;
				if(sp[0] && mem[1]){
					return this->execute(instruction, vmem[1], (char *) &( *(vsp[0])), false, true);
					*stack_pointer -= 1;
				}
				else
					return ERROR_SIGNAL;
			break;

			case POP_FLAGS:
				*ip += 3;
				if(sp[0]){
					return this->execute(instruction, (char *) ((int *) &(this->registers[2])), (char *) &( *(vsp[0])), true, true);
					*stack_pointer -= 1;
				}
				else
					return ERROR_SIGNAL;
			break;

			case INC_REG:
			case DEC_REG:
			case NEG_REG:
			case NOT_REG:
				*ip += 3;
				if(reg[1]){
					int value2 = 1;
					if(instruction == NEG_REG)
						value2 = -1;
					return this->execute(instruction, (char *) &( *(vreg[1])), (char *) &( *(&value2)), true, true);
				}
				else
					return ERROR_SIGNAL;
			break;

			case INC_MEM:
			case DEC_MEM:
			case NEG_MEM:
			case NOT_MEM:
				*ip += 3;
				if(mem[1]){
					int value2 = 1;
					if(instruction == NEG_MEM)
						value2 = -1;
					return this->execute(instruction, vmem[1], (char *) &( *(&value2)), false, true);
				}
				else
					return ERROR_SIGNAL;
			break;

			case SETC_REG:
			case SETNC_REG:
			case SETZ_REG:
			case SETNZ_REG:
			case SETS_REG:
			case SETNS_REG:
			case SETO_REG:
			case SETNO_REG:
			case SETP_REG:
			case SETPE_REG:
			case SETNP_REG:
			case SETPO_REG:

			case SETA_REG:
			case SETNBE_REG:
			case SETAE_REG:
			case SETNB_REG:
			case SETB_REG:
			case SETNAE_REG:
			case SETBE_REG:
			case SETNA_REG:
			case SETE_REG:
			case SETNE_REG:

			case JUMP_REG:
				*ip += 3;
				if(reg[1]){
					if( instruction == JUMP_REG )
						return this->execute(instruction, (char *) &( *(vreg[1])), (char *) &( *(ip)), true, true);
					else
						return this->execute(instruction, (char *) &( *(vreg[1])), (char *) &( *(vreg[1])), true, true);
				}
				else
					return ERROR_SIGNAL;
			break;

			case CALL_REG:
				*ip += 3;
				if(reg[1] && sp[1]){
					return this->execute(instruction, (char *) &( *(vsp[1])), (char *) &( *(vreg[1])), true, true);
					*stack_pointer += 1;
				}
				else
					return ERROR_SIGNAL;
			break;

			case SETC_MEM:
			case SETNC_MEM:
			case SETZ_MEM:
			case SETNZ_MEM:
			case SETS_MEM:
			case SETNS_MEM:
			case SETO_MEM:
			case SETNO_MEM:
			case SETP_MEM:
			case SETPE_MEM:
			case SETNP_MEM:
			case SETPO_MEM:

			case SETA_MEM:
			case SETNBE_MEM:
			case SETAE_MEM:
			case SETNB_MEM:
			case SETB_MEM:
			case SETNAE_MEM:
			case SETBE_MEM:
			case SETNA_MEM:
			case SETE_MEM:
			case SETNE_MEM:

			case JUMP_MEM:
				*ip += 3;
				if(mem[1]){
					if( instruction == JUMP_MEM )
						return this->execute(instruction, vmem[1], (char *) &( *(ip)), false, true);
					else
						return this->execute(instruction, vmem[1], vmem[1]);
				}
				else
					return ERROR_SIGNAL;
			break;

			case CALL_MEM:
				*ip += 3;
				if(mem[1] && sp[1]){
					return this->execute(instruction, (char *) &( *(vsp[1])), vmem[1], true);
					*stack_pointer += 1;
				}
				else
					return ERROR_SIGNAL;
			break;

			case RET:
				*ip += 3;
				if(sp[0]){
					return this->execute(RET, (char *) &( *(vsp[0])), (char *) &( *(ip)), true, true);
					*stack_pointer -= 1;
				}
				else
					return ERROR_SIGNAL;
			break;

			case INT_VALUE:
				*ip += 3;
				if(ins[1] && ins[2]){
					return this->execute(INT_VALUE, vins[1], vins[2]);
				}
				else
					return ERROR_SIGNAL;
			break;

			case JC_MEM:
			case JNC_MEM:
			case JZ_MEM:
			case JNZ_MEM:
			case JS_MEM:
			case JNS_MEM:
			case JO_MEM:
			case JNO_MEM:
			case JP_MEM:
			case JPE_MEM:
			case JNP_MEM:
			case JPO_MEM:

			case JA_MEM:
			case JNBE_MEM:
			case JAE_MEM:
			case JNB_MEM:
			case JB_MEM:
			case JNAE_MEM:
			case JBE_MEM:
			case JNA_MEM:
			case JE_MEM:
			case JNE_MEM:
				ip += 3;
				if(mem[1]){
					return this->execute(instruction, vmem[1], (char *) &( *(ip)), false, true);
				}
				else
					return ERROR_SIGNAL;
			break;


			case JC_VALUE:
			case JNC_VALUE:
			case JZ_VALUE:
			case JNZ_VALUE:
			case JS_VALUE:
			case JNS_VALUE:
			case JO_VALUE:
			case JNO_VALUE:
			case JP_VALUE:
			case JPE_VALUE:
			case JNP_VALUE:
			case JPO_VALUE:

			case JA_VALUE:
			case JNBE_VALUE:
			case JAE_VALUE:
			case JNB_VALUE:
			case JB_VALUE:
			case JNAE_VALUE:
			case JBE_VALUE:
			case JNA_VALUE:
			case JE_VALUE:
			case JNE_VALUE:
				ip += 3;
				if(ins[1]){
					return this->execute(instruction, vins[1], (char *) &( *(ip)), false, true);
				}
				else
					return ERROR_SIGNAL;
			break;




			default:
				//cout << " NOP@ " << (int) instruction << " ";
				*ip += 3;
			break;
		}
	}

	return 0;	
}


int machine::execute(unsigned char instruction, char *value1, char *value2,
					 bool isValue1Int, bool isValue2Int){

	int *flags = &this->registers[2];
	int *ip = &this->registers[0];

	int value_1;
	int value_2;

	if(isValue1Int)
		value_1 = (int) *((unsigned int *) value1);
	else
		value_1 = (int) *value1;

	if(isValue2Int)
		value_2 = (int) *((unsigned int *) value2);
	else
		value_2 = (int) *value2;
	

	//cout << "$[" << value_1 << "," << value_2 << "]";

	switch(instruction){

		case MOV_REG_REG:
		case MOV_MEM_REG:
		case MOV_REG_MEM:
		case MOV_MEM_VALUE:
		case MOV_REG_VALUE:
		case PUSH_REG:
		case PUSH_MEM:
		case PUSH_VALUE:
		case PUSH_FLAGS:
		case POP_REG:
		case POP_MEM:
		case POP_FLAGS:
			value_1 = value_2;
		break;

		case XCHG_REG_MEM:
		case XCHG_REG_REG:	
		{
			int temp = value_1;
			value_1 = value_2;
			value_2 = temp;
		}
		break;

		case ADD_REG_REG:
		case ADD_REG_MEM:
		case ADD_MEM_REG:
		case ADD_REG_VALUE:
		case ADD_MEM_VALUE:
		case INC_REG:
		case INC_MEM:
		case XADD_REG_REG:
		case XADD_MEM_REG:
		{
			char temp = value_1 + value_2;
			int value_1_copy = value_1;
			if (temp < (value_1 + value_2))
				if((instruction != INC_REG) && (instruction != INC_MEM))
					SETFLAG(*flags, CARRY_FLAG);
			unsigned char temp2 = value_1 + value_2;
			
			if(temp2 < temp)
				SETFLAG(*flags, OVERFLOW_FLAG);
			else
				UNSETFLAG(*flags, OVERFLOW_FLAG);

			if(temp < 0)
				SETFLAG(*flags, SIGN_FLAG);
			else
				UNSETFLAG(*flags, SIGN_FLAG);

			if(temp == 0)
				SETFLAG(*flags, ZERO_FLAG);
			else
				UNSETFLAG(*flags, ZERO_FLAG);

			if((temp%16) > 10)
				SETFLAG(*flags, AUXILIARY_CARRY_FLAG);
			else
				UNSETFLAG(*flags, AUXILIARY_CARRY_FLAG);


			int parity = 0;
			for(int i=0; i<8;i++){
				if(temp & (1<<i)) 
					parity += 1;
			}

			if(parity%2)
				SETFLAG(*flags, PARITY_FLAG);
			else
				UNSETFLAG(*flags, PARITY_FLAG);

			value_1 += value_2;
			if((instruction == XADD_REG_REG) || (instruction == XADD_MEM_REG))
				value_2 = value_1_copy;
		}

		break;


		case SUB_REG_REG:
		case SUB_REG_MEM:
		case SUB_MEM_REG:
		case SUB_REG_VALUE:
		case SUB_MEM_VALUE:
		case DEC_REG:
		case DEC_MEM:
		case CMP_REG_REG:
		case CMP_REG_MEM:
		case CMP_MEM_REG:
		case CMP_REG_VALUE:
		case CMP_MEM_VALUE:
		{
			int result = value_1 - value_2;
			signed char result_char = (char) (value_1 - value_2);
			unsigned char unsigned_result_char = (unsigned char) (value_1 - value_2);

			if(result == 0)
				SETFLAG(*flags, ZERO_FLAG);
			else
				UNSETFLAG(*flags, ZERO_FLAG);

			if(result_char < 0)
				SETFLAG(*flags, SIGN_FLAG);
			else
				UNSETFLAG(*flags, SIGN_FLAG);

			if(result != result_char)
				SETFLAG(*flags, OVERFLOW_FLAG);
			else
				UNSETFLAG(*flags, OVERFLOW_FLAG);

			if((result_char & 0xF) > 9)
				SETFLAG(*flags, AUXILIARY_CARRY_FLAG);
			else
				UNSETFLAG(*flags, AUXILIARY_CARRY_FLAG);

			int parity = 0;
			int temp = result;
			for(int i=0; i<8;i++){
				if(temp & (1<<i)) 
					parity += 1;
			}

			if(parity%2)
				SETFLAG(*flags, PARITY_FLAG);
			else
				UNSETFLAG(*flags, PARITY_FLAG);


			if(unsigned_result_char != result_char)
				SETFLAG(*flags, CARRY_FLAG);
			else
				UNSETFLAG(*flags, CARRY_FLAG);

			if((instruction != CMP_REG_REG) || 
			   (instruction != CMP_REG_MEM) ||
			   (instruction != CMP_MEM_REG)	||
			   (instruction != CMP_REG_VALUE) ||
			   (instruction != CMP_MEM_VALUE))
				value_1 = result;

		}

		break;


		case NEG_REG:
		case NEG_MEM:
		{
			int result = 0 - value_1;

			if(value_1 == 0)
				UNSETFLAG(*flags, CARRY_FLAG);
			else
				SETFLAG(*flags, CARRY_FLAG);

			if((!value_1) == 0)
				SETFLAG(*flags, OVERFLOW_FLAG);
			else
				UNSETFLAG(*flags, OVERFLOW_FLAG);

			if(result == 0)
				SETFLAG(*flags, ZERO_FLAG);
			else
				UNSETFLAG(*flags, ZERO_FLAG);

			if(result < 0)
				SETFLAG(*flags, SIGN_FLAG);
			else
				UNSETFLAG(*flags, SIGN_FLAG);

			int parity = 0;
			int temp = result;
			for(int i=0; i<8;i++){
				if(temp & (1<<i)) 
					parity += 1;
			}

			if(parity%2)
				SETFLAG(*flags, PARITY_FLAG);
			else
				UNSETFLAG(*flags, PARITY_FLAG);

			if((result & 0xF) > 9)
				SETFLAG(*flags, AUXILIARY_CARRY_FLAG);
			else
				UNSETFLAG(*flags, AUXILIARY_CARRY_FLAG);


			value_1 = result;
		}

		break;


		case MUL_REG_MEM:
		case MUL_REG_REG:
		case MUL_REG_VALUE:
		{
			value_1 = value_1 * value_2;

			if(dist2(mt))
				SETFLAG(*flags, AUXILIARY_CARRY_FLAG);
			else
				UNSETFLAG(*flags, AUXILIARY_CARRY_FLAG);

			if(dist2(mt))
				SETFLAG(*flags, PARITY_FLAG);
			else
				UNSETFLAG(*flags, PARITY_FLAG);

			if(dist2(mt))
				SETFLAG(*flags, SIGN_FLAG);
			else
				UNSETFLAG(*flags, SIGN_FLAG);

			if(dist2(mt))
				SETFLAG(*flags, ZERO_FLAG);
			else
				UNSETFLAG(*flags, ZERO_FLAG);



		}

		break;



		case DIV_REG_REG:
		case DIV_REG_MEM:
		case DIV_REG_VALUE:
		{
			if(value_2 == 0)
				return ERROR_SIGNAL;
			else{
				int result = value_1/value_2;
				int remainder = value_1%value_2;

				value_1 = result;
				value_2 = remainder;

			if(dist2(mt))
				SETFLAG(*flags, AUXILIARY_CARRY_FLAG);
			else
				UNSETFLAG(*flags, AUXILIARY_CARRY_FLAG);

			if(dist2(mt))
				SETFLAG(*flags, PARITY_FLAG);
			else
				UNSETFLAG(*flags, PARITY_FLAG);

			if(dist2(mt))
				SETFLAG(*flags, SIGN_FLAG);
			else
				UNSETFLAG(*flags, SIGN_FLAG);

			if(dist2(mt))
				SETFLAG(*flags, ZERO_FLAG);
			else
				UNSETFLAG(*flags, ZERO_FLAG);

			if(dist2(mt))
				SETFLAG(*flags, OVERFLOW_FLAG);
			else
				UNSETFLAG(*flags, OVERFLOW_FLAG);

			if(dist2(mt))
				SETFLAG(*flags, CARRY_FLAG);
			else
				UNSETFLAG(*flags, CARRY_FLAG);

			}
		}

		break;




		case AND_REG_REG:
		case AND_REG_MEM:
		case AND_MEM_REG:
		case AND_REG_VALUE:
		case AND_MEM_VALUE:
		{
			unsigned int result = ((unsigned int) value_1) & ((unsigned int) value_2);
			value_1 = result;

			UNSETFLAG(*flags, CARRY_FLAG);
			UNSETFLAG(*flags, OVERFLOW_FLAG);
			if(result)
				UNSETFLAG(*flags, ZERO_FLAG);
			else
				SETFLAG(*flags, ZERO_FLAG);

			if((result >> 7))
				SETFLAG(*flags, SIGN_FLAG);
			else
				UNSETFLAG(*flags, SIGN_FLAG);

			int parity = 0;
			int temp = result;
			for(int i=0; i<8;i++){
				if(temp & (1<<i)) 
					parity += 1;
			}

			if(parity%2)
				SETFLAG(*flags, PARITY_FLAG);
			else
				UNSETFLAG(*flags, PARITY_FLAG);

			if(dist2(mt))
				SETFLAG(*flags, AUXILIARY_CARRY_FLAG);
			else
				UNSETFLAG(*flags, AUXILIARY_CARRY_FLAG);


		}

		break;


		case OR_REG_REG:
		case OR_REG_MEM:
		case OR_MEM_REG:
		case OR_REG_VALUE:
		case OR_MEM_VALUE:
		{
			unsigned int result = ((unsigned int) value_1) || ((unsigned int) value_2);
			value_1 = result;

			UNSETFLAG(*flags, CARRY_FLAG);
			UNSETFLAG(*flags, OVERFLOW_FLAG);
			if(result)
				UNSETFLAG(*flags, ZERO_FLAG);
			else
				SETFLAG(*flags, ZERO_FLAG);

			if((result >> 7))
				SETFLAG(*flags, SIGN_FLAG);
			else
				UNSETFLAG(*flags, SIGN_FLAG);

			int parity = 0;
			int temp = result;
			for(int i=0; i<8;i++){
				if(temp & (1<<i)) 
					parity += 1;
			}

			if(parity%2)
				SETFLAG(*flags, PARITY_FLAG);
			else
				UNSETFLAG(*flags, PARITY_FLAG);

			if(dist2(mt))
				SETFLAG(*flags, AUXILIARY_CARRY_FLAG);
			else
				UNSETFLAG(*flags, AUXILIARY_CARRY_FLAG);


		}

		break;


		case XOR_REG_REG:
		case XOR_REG_MEM:
		case XOR_MEM_REG:
		case XOR_REG_VALUE:
		case XOR_MEM_VALUE:
		{
			unsigned int result = ((unsigned int) value_1) ^ ((unsigned int) value_2);
			value_1 = result;

			UNSETFLAG(*flags, CARRY_FLAG);
			UNSETFLAG(*flags, OVERFLOW_FLAG);
			if(result)
				UNSETFLAG(*flags, ZERO_FLAG);
			else
				SETFLAG(*flags, ZERO_FLAG);

			if((result >> 7))
				SETFLAG(*flags, SIGN_FLAG);
			else
				UNSETFLAG(*flags, SIGN_FLAG);

			int parity = 0;
			int temp = result;
			for(int i=0; i<8;i++){
				if(temp & (1<<i)) 
					parity += 1;
			}

			if(parity%2)
				SETFLAG(*flags, PARITY_FLAG);
			else
				UNSETFLAG(*flags, PARITY_FLAG);

			if(dist2(mt))
				SETFLAG(*flags, AUXILIARY_CARRY_FLAG);
			else
				UNSETFLAG(*flags, AUXILIARY_CARRY_FLAG);


		}

		break;




		case NOT_REG:
		case NOT_MEM:
		{
			unsigned int result = !((unsigned int) value_1);
			value_1 = result;


		}

		break;


		case SHL_REG_REG:
		case SHL_MEM_REG:
		case SHL_REG_VALUE:
		case SHL_MEM_VALUE:
		{

			int result = value_1;
			int last_bit_shifted;

			for(int i=0; i<value_2; i++){
				last_bit_shifted = result & (1<<7);
				result = result << 1;
			}


			if(last_bit_shifted)
				SETFLAG(*flags, CARRY_FLAG);
			else
				UNSETFLAG(*flags, CARRY_FLAG);

			if( ((result > 0) && (value_1 < 0)) || ((result<0) && (value_1 > 0)) )
				SETFLAG(*flags, OVERFLOW_FLAG);
			else
				UNSETFLAG(*flags, OVERFLOW_FLAG);

			if(result)
				UNSETFLAG(*flags, ZERO_FLAG);
			else
				SETFLAG(*flags, ZERO_FLAG);

			if(result < 0)
				SETFLAG(*flags, SIGN_FLAG);
			else
				UNSETFLAG(*flags, SIGN_FLAG);

			int parity = 0;
			int temp = result;
			for(int i=0; i<8;i++){
				if(temp & (1<<i)) 
					parity += 1;
			}

			if(parity%2)
				SETFLAG(*flags, PARITY_FLAG);
			else
				UNSETFLAG(*flags, PARITY_FLAG);

			if(dist2(mt))
				SETFLAG(*flags, AUXILIARY_CARRY_FLAG);
			else
				UNSETFLAG(*flags, AUXILIARY_CARRY_FLAG);

		}

		break;



		case SHR_REG_REG:
		case SHR_MEM_REG:
		case SHR_REG_VALUE:
		case SHR_MEM_VALUE:
		{

			int result = value_1;
			int last_bit_shifted;

			for(int i=0; i<value_2; i++){
				last_bit_shifted = result & (0x1);
				result = result >> 1;
			}

			if(last_bit_shifted)
				SETFLAG(*flags, CARRY_FLAG);
			else
				UNSETFLAG(*flags, CARRY_FLAG);

			if( ((result > 0) && (value_1 < 0)) || ((result<0) && (value_1 > 0)) )
				SETFLAG(*flags, OVERFLOW_FLAG);
			else
				UNSETFLAG(*flags, OVERFLOW_FLAG);

			if(result)
				UNSETFLAG(*flags, ZERO_FLAG);
			else
				SETFLAG(*flags, ZERO_FLAG);

			if(result < 0)
				SETFLAG(*flags, SIGN_FLAG);
			else
				UNSETFLAG(*flags, SIGN_FLAG);

			int parity = 0;
			int temp = result;
			for(int i=0; i<8;i++){
				if(temp & (1<<i)) 
					parity += 1;
			}

			if(parity%2)
				SETFLAG(*flags, PARITY_FLAG);
			else
				UNSETFLAG(*flags, PARITY_FLAG);

			if(dist2(mt))
				SETFLAG(*flags, AUXILIARY_CARRY_FLAG);
			else
				UNSETFLAG(*flags, AUXILIARY_CARRY_FLAG);

		}


		break;

		case RCL_REG_REG:
		case RCL_MEM_REG:
		case RCL_REG_VALUE:
		case RCL_MEM_VALUE:
		{
			int result = value_1;
			int last_bit_shifted;

			for(int i=0; i<value_2; i++){
				last_bit_shifted = result & (1<<7);
				result = result << 1;
				result += GETFLAG(*flags, CARRY_FLAG);

				if(last_bit_shifted)
					SETFLAG(*flags, CARRY_FLAG);
				else
					UNSETFLAG(*flags, CARRY_FLAG);
			}

			if(last_bit_shifted)
				SETFLAG(*flags, CARRY_FLAG);
			else
				UNSETFLAG(*flags, CARRY_FLAG);

			if(value_2 == 1){
				if( ((result > 0) && (value_1 < 0)) || ((result<0) && (value_1 > 0)) )
					SETFLAG(*flags, OVERFLOW_FLAG);
				else
					UNSETFLAG(*flags, OVERFLOW_FLAG);
			}
			else{
			if(dist2(mt))
				SETFLAG(*flags, OVERFLOW_FLAG);
			else
				UNSETFLAG(*flags, OVERFLOW_FLAG);			
			}



		}

		break;


		case RCR_REG_REG:
		case RCR_MEM_REG:
		case RCR_REG_VALUE:
		case RCR_MEM_VALUE:
		{
			int result = value_1;
			int last_bit_shifted;

			for(int i=0; i<value_2; i++){
				last_bit_shifted = result & (0x1);
				result = result >> 1;
				result += (GETFLAG(*flags, CARRY_FLAG) << 7);

				if(last_bit_shifted)
					SETFLAG(*flags, CARRY_FLAG);
				else
					UNSETFLAG(*flags, CARRY_FLAG);
			}

			if(last_bit_shifted)
				SETFLAG(*flags, CARRY_FLAG);
			else
				UNSETFLAG(*flags, CARRY_FLAG);

			if(value_2 == 1){
				if( ((result > 0) && (value_1 < 0)) || ((result<0) && (value_1 > 0)) )
					SETFLAG(*flags, OVERFLOW_FLAG);
				else
					UNSETFLAG(*flags, OVERFLOW_FLAG);
			}
			else{
			if(dist2(mt))
				SETFLAG(*flags, OVERFLOW_FLAG);
			else
				UNSETFLAG(*flags, OVERFLOW_FLAG);			
			}



		}

		break;










		case ROL_REG_REG:
		case ROL_MEM_REG:
		case ROL_REG_VALUE:
		case ROL_MEM_VALUE:
		{
			int result = value_1;
			int last_bit_shifted;

			for(int i=0; i<value_2; i++){
				last_bit_shifted = result & (1<<7);
				result = result << 1;
				result += last_bit_shifted;
			}

			if(last_bit_shifted)
				SETFLAG(*flags, CARRY_FLAG);
			else
				UNSETFLAG(*flags, CARRY_FLAG);

			if(value_2 == 1){
				if( ((result > 0) && (value_1 < 0)) || ((result<0) && (value_1 > 0)) )
					SETFLAG(*flags, OVERFLOW_FLAG);
				else
					UNSETFLAG(*flags, OVERFLOW_FLAG);
			}
			else{
			if(dist2(mt))
				SETFLAG(*flags, OVERFLOW_FLAG);
			else
				UNSETFLAG(*flags, OVERFLOW_FLAG);			
			}



		}

		break;


		case ROR_REG_REG:
		case ROR_MEM_REG:
		case ROR_REG_VALUE:
		case ROR_MEM_VALUE:
		{
			int result = value_1;
			int last_bit_shifted;

			for(int i=0; i<value_2; i++){
				last_bit_shifted = result & (0x1);
				result = result >> 1;
				result += (last_bit_shifted << 7);
			}

			if(last_bit_shifted)
				SETFLAG(*flags, CARRY_FLAG);
			else
				UNSETFLAG(*flags, CARRY_FLAG);

			if(value_2 == 1){
				if( ((result > 0) && (value_1 < 0)) || ((result<0) && (value_1 > 0)) )
					SETFLAG(*flags, OVERFLOW_FLAG);
				else
					UNSETFLAG(*flags, OVERFLOW_FLAG);
			}
			else{
			if(dist2(mt))
				SETFLAG(*flags, OVERFLOW_FLAG);
			else
				UNSETFLAG(*flags, OVERFLOW_FLAG);			
			}



		}

		break;




		case SETC_REG:
		case SETC_MEM:
		case SETB_REG:
		case SETB_MEM:
		case SETNAE_REG:
		case SETNAE_MEM:
		{
			value_1 = GETFLAG(*flags, CARRY_FLAG);
		}

		break;



		case SETNC_REG:
		case SETNC_MEM:
		case SETNB_REG:
		case SETNB_MEM:
		case SETAE_REG:
		case SETAE_MEM:
		{
			value_1 = (!GETFLAG(*flags, CARRY_FLAG)) & 0x01;
		}

		break;


		case SETZ_REG:
		case SETZ_MEM:
		case SETE_REG:
		case SETE_MEM:
		{
			value_1 = GETFLAG(*flags, ZERO_FLAG);
		}

		break;




		case SETNZ_REG:
		case SETNZ_MEM:
		case SETNE_REG:
		case SETNE_MEM:
		{
			value_1 = (!GETFLAG(*flags, ZERO_FLAG)) & 0x01;
		}

		break;



		case SETS_REG:
		case SETS_MEM:
		{
			value_1 = GETFLAG(*flags, SIGN_FLAG);
		}

		break;



		case SETNS_REG:
		case SETNS_MEM:
		{
			value_1 = (!GETFLAG(*flags, SIGN_FLAG)) & 0x01;
		}

		break;



		case SETO_REG:
		case SETO_MEM:
		{
			value_1 = GETFLAG(*flags, OVERFLOW_FLAG);
		}

		break;


		case SETNO_REG:
		case SETNO_MEM:
		{
			value_1 = (!GETFLAG(*flags, OVERFLOW_FLAG)) & 0x01;
		}

		break;



		case SETP_REG:
		case SETP_MEM:
		case SETPE_REG:
		case SETPE_MEM:
		{
			value_1 = GETFLAG(*flags, PARITY_FLAG);
		}

		break;


		case SETNP_REG:
		case SETNP_MEM:
		case SETPO_REG:
		case SETPO_MEM:
		{
			value_1 = (!GETFLAG(*flags, PARITY_FLAG)) & 0x01;
		}

		break;


		case SETA_REG:
		case SETA_MEM:
		case SETNBE_REG:
		case SETNBE_MEM:
		{
			if( (!GETFLAG(*flags, CARRY_FLAG))  &&  (!GETFLAG(*flags, ZERO_FLAG)) )
				value_1 = 1;
			else
				value_1 = 0;
		}

		break;



		case SETBE_REG:
		case SETBE_MEM:
		case SETNA_REG:
		case SETNA_MEM:
		{
			if( (GETFLAG(*flags, CARRY_FLAG))  &&   (GETFLAG(*flags, ZERO_FLAG)) )
				value_1 = 1;
			else
				value_1 = 0;
		}

		break;





		case JUMP_REG:
		{
			*ip = value_1;
		}

		break;


		case JUMP_MEM:
		{
			*ip += value_1;
		}

		break;


		case CALL_REG:
		{
			value_1 = *ip;
			*ip = value_2;
		}

		break;


		case CALL_MEM:
		{
			value_1 = *ip;
			*ip += value_2;
		}

		break;


		case RET:
		{
			*ip = value_1;
		}

		break;


		case INT_VALUE:
		{
			return this->interrupt(value_1, value_2);
		}

		break;


		case JC_MEM:
		case JC_VALUE:
		case JB_MEM:
		case JB_VALUE:
		case JNAE_MEM:
		case JNAE_VALUE:
		{
			if(GETFLAG(*flags, CARRY_FLAG))
				*ip += value_1;
		}

		break;


		case JNC_MEM:
		case JNC_VALUE:
		case JNB_MEM:
		case JNB_VALUE:
		case JAE_MEM:
		case JAE_VALUE:
		{
			if(!GETFLAG(*flags, CARRY_FLAG))
				*ip += value_1;
		}

		break;


		case JZ_MEM:
		case JZ_VALUE:
		case JE_MEM:
		case JE_VALUE:
		{
			if(GETFLAG(*flags, ZERO_FLAG))
				*ip += value_1;
		}

		break;


		case JNZ_MEM:
		case JNZ_VALUE:
		case JNE_MEM:
		case JNE_VALUE:
		{
			if(!GETFLAG(*flags, ZERO_FLAG))
				*ip += value_1;			
		}

		break;


		case JS_MEM:
		case JS_VALUE:
		{
			if(GETFLAG(*flags, SIGN_FLAG))
				*ip += value_1;
		}

		break;



		case JNS_MEM:
		case JNS_VALUE:
		{
				if(!GETFLAG(*flags, SIGN_FLAG))
				*ip += value_1;
		}

		break;



		case JO_MEM:
		case JO_VALUE:
		{
			if(GETFLAG(*flags, OVERFLOW_FLAG))
				*ip += value_1;
		}
		break;


		case JNO_MEM:
		case JNO_VALUE:
		{
			if(!GETFLAG(*flags, OVERFLOW_FLAG))
				*ip += value_1;
		}

		break;


		case JP_MEM:
		case JP_VALUE:
		case JPE_MEM:
		case JPE_VALUE:
		{
			if(GETFLAG(*flags, PARITY_FLAG))
				*ip += value_1;
		}

		break;


		case JNP_MEM:
		case JNP_VALUE:
		case JPO_MEM:
		case JPO_VALUE:
		{
			if(!GETFLAG(*flags, PARITY_FLAG))
				*ip += value_1;
		}

		break;


		case JA_MEM:
		case JA_VALUE:
		case JNBE_MEM:
		case JNBE_VALUE:
		{
			if( (GETFLAG(*flags, CARRY_FLAG) == 0)  &&   (GETFLAG(*flags, ZERO_FLAG) == 0) )
				*ip += value_1;
		}

		break;

		case JBE_MEM:
		case JBE_VALUE:
		case JNA_MEM:
		case JNA_VALUE:
		{
			if( (GETFLAG(*flags, CARRY_FLAG))  &&   (GETFLAG(*flags, ZERO_FLAG)) )
				*ip += value_1;
		}
		break;


		default:
		cout << "\nError(2) at instrucion " << (int) instruction << " .\n";

		break;

	}


	this->saveChanges(instruction, value_1, value_2, value1, value2);
	return 0;
}


void machine::saveChanges(unsigned char instruction, int value_1, int value_2, char *value1, char* value2){

	//cout << "¨(" << value_1 << "," << value_2 << ")";

	switch(instruction){

			case MOV_REG_REG:
			case XCHG_REG_REG:
			case ADD_REG_REG:
			case SUB_REG_REG:
			case CMP_REG_REG:
			case MUL_REG_REG:
			case DIV_REG_REG:
			case XADD_REG_REG:
			case AND_REG_REG:
			case OR_REG_REG:
			case XOR_REG_REG:
			case SHL_REG_REG:
			case SHR_REG_REG:
			case ROL_REG_REG:
			case ROR_REG_REG:
			case RCL_REG_REG:
			case RCR_REG_REG:
				*value1 = value_1;
				*value2 = value_2;

			break;


			case MOV_REG_MEM:
			case XCHG_REG_MEM:
			case ADD_REG_MEM:
			case SUB_REG_MEM:
			case CMP_REG_MEM:
			case MUL_REG_MEM:
			case DIV_REG_MEM:
			case AND_REG_MEM:
			case OR_REG_MEM:
			case XOR_REG_MEM:
				*value1 = value_1;
				*value2 = (char) value_2;

			break;


			case MOV_MEM_REG:
			case ADD_MEM_REG:
			case SUB_MEM_REG:
			case CMP_MEM_REG:
			case XADD_MEM_REG:
			case AND_MEM_REG:
			case OR_MEM_REG:
			case XOR_MEM_REG:
			case SHL_MEM_REG:
			case SHR_MEM_REG:
			case ROL_MEM_REG:
			case ROR_MEM_REG:
			case RCL_MEM_REG:
			case RCR_MEM_REG:
				*value1 = (char) value_1;
				*value2 = value_2;

			break;											

			
			case MOV_REG_VALUE:
			case ADD_REG_VALUE:
			case SUB_REG_VALUE:
			case CMP_REG_VALUE:
			case MUL_REG_VALUE:
			case DIV_REG_VALUE:
			case AND_REG_VALUE:
			case OR_REG_VALUE:
			case XOR_REG_VALUE:
			case SHL_REG_VALUE:
			case SHR_REG_VALUE:
			case ROL_REG_VALUE:
			case ROR_REG_VALUE:
			case RCL_REG_VALUE:
			case RCR_REG_VALUE:

			case POP_REG:
			case POP_FLAGS:

			case INC_REG:
			case DEC_REG:
			case NEG_REG:
			case NOT_REG:			

			case SETC_REG:
			case SETNC_REG:
			case SETZ_REG:
			case SETNZ_REG:
			case SETS_REG:
			case SETNS_REG:
			case SETO_REG:
			case SETNO_REG:
			case SETP_REG:
			case SETPE_REG:
			case SETNP_REG:
			case SETPO_REG:

			case SETA_REG:
			case SETNBE_REG:
			case SETAE_REG:
			case SETNB_REG:
			case SETB_REG:
			case SETNAE_REG:
			case SETBE_REG:
			case SETNA_REG:
			case SETE_REG:
			case SETNE_REG:

			case JUMP_REG:
			case CALL_REG:			
				*value1 = value_1;

			break;


			case MOV_MEM_VALUE:
			case ADD_MEM_VALUE:
			case SUB_MEM_VALUE:
			case CMP_MEM_VALUE:
			case AND_MEM_VALUE:
			case OR_MEM_VALUE:
			case XOR_MEM_VALUE:
			case SHL_MEM_VALUE:
			case SHR_MEM_VALUE:
			case ROL_MEM_VALUE:
			case ROR_MEM_VALUE:
			case RCL_MEM_VALUE:
			case RCR_MEM_VALUE:

			case PUSH_REG:
			case PUSH_MEM:
			case PUSH_VALUE:
			case PUSH_FLAGS:

			case INC_MEM:
			case DEC_MEM:
			case NEG_MEM:
			case NOT_MEM:

			case POP_MEM:

			case SETC_MEM:
			case SETNC_MEM:
			case SETZ_MEM:
			case SETNZ_MEM:
			case SETS_MEM:
			case SETNS_MEM:
			case SETO_MEM:
			case SETNO_MEM:
			case SETP_MEM:
			case SETPE_MEM:
			case SETNP_MEM:
			case SETPO_MEM:

			case SETA_MEM:
			case SETNBE_MEM:
			case SETAE_MEM:
			case SETNB_MEM:
			case SETB_MEM:
			case SETNAE_MEM:
			case SETBE_MEM:
			case SETNA_MEM:
			case SETE_MEM:
			case SETNE_MEM:

			case JUMP_MEM:
			case CALL_MEM:


			case JC_MEM:
			case JNC_MEM:
			case JZ_MEM:
			case JNZ_MEM:
			case JS_MEM:
			case JNS_MEM:
			case JO_MEM:
			case JNO_MEM:
			case JP_MEM:
			case JPE_MEM:
			case JNP_MEM:
			case JPO_MEM:

			case JA_MEM:
			case JNBE_MEM:
			case JAE_MEM:
			case JNB_MEM:
			case JB_MEM:
			case JNAE_MEM:
			case JBE_MEM:
			case JNA_MEM:
			case JE_MEM:
			case JNE_MEM:

			case JC_VALUE:
			case JNC_VALUE:
			case JZ_VALUE:
			case JNZ_VALUE:
			case JS_VALUE:
			case JNS_VALUE:
			case JO_VALUE:
			case JNO_VALUE:
			case JP_VALUE:
			case JPE_VALUE:
			case JNP_VALUE:
			case JPO_VALUE:

			case JA_VALUE:
			case JNBE_VALUE:
			case JAE_VALUE:
			case JNB_VALUE:
			case JB_VALUE:
			case JNAE_VALUE:
			case JBE_VALUE:
			case JNA_VALUE:
			case JE_VALUE:
			case JNE_VALUE:

			case RET:
				*value1 = (char) value_1;

			break;


									
			default:
			cout << "\nError(3) at instrucion " << (int) instruction << " .\n";

			break;


	}

}




// Checks if memory position _address_ exists
// return true if it exists, else return false
bool machine::chkm(long int address){
	if( (address < this->memory_limit) && (address >= 0) )
		return true;
	else
		return false;
}


// Checks if register _address_ exists
// if it do then return true, else return false
bool machine::chkr(long int address){
	if((address < this->registers_limit) && (address >= 0))
		return true;
	else
		return false;
}


// Loads (i.e. copy) a gene's memory inside a machine's memory
void machine::loadGene(char *memory, int length){
	
	// We must be careful to not write values
	// beyond the last char of machine's memory
	int limit = 0;
	if((length) < this->memory_limit)
		limit = length;
	else
		limit = this->memory_limit;
	
	// Knowing when to stop, we just copy it
	for(int i=0; i < limit; i++)
		this->memory[i] = *(memory + i);
}

// This one should only be used
// when a machine dies
void machine::clearMemory(){
	for(int i=0; i <= this->memory_limit;i++)
		this->memory[i]= 0;//distchar(mt);
	for(int i=0; i < REGISTERS_AMOUNT; i++)
		registers[i] = 0;//distchar(mt);
	for(int i=0; i < 3; i++)
		registers[i] = 0;
}



// gene  is a class that implements
// genetic logic, almost like a DNA
class gene{
	public:
		char memory[GEN_SPACE];	

	
		void checkMutations();
		void reproduce(gene *father, gene *mother);

		char *getMemory();
		int memory_limit;
		
		// At time construction, we
		// generate a random genome
		gene(){
			this->memory_limit = GEN_LEN;

			for(int i=0; i<= memory_limit;i++)
				this->memory[i] = distchar(mt);
			
		}

};

char* gene::getMemory(){
	return &this->memory[0];
}

void gene::checkMutations(){
	for(int i=0; i < this->memory_limit; i++){
		if((dist100(mt)) <= MUTATION_CHANCE)
			this->memory[i] = distchar(mt);
	}
}


void gene::reproduce(gene *father, gene *mother){
	if((dist100(mt)) <= CROSSOVER_RATE){

		uniform_int_distribution<int> distplace(0, GEN_SPACE-1);
		
		int crossover_place = distplace(mt);
		
		gene *copy=father;
		
		for(int i=0;i < this->memory_limit; i++){
			if(i==crossover_place)
				copy=mother;
			this->memory[i]=*(copy->getMemory()+i);
		}
		
	}
	else {
		gene *copy;
		if((dist2(mt))==0)
			copy = father;
		else
			copy = mother;
		
		for(int i=0; i < this->memory_limit;i++)
			this->memory[i]= copy->memory[i];
	}

	this->checkMutations();
}



// This one need to go here,
// after the declaration of genome and machine classes
void machine::loadGene(gene genome){
	this->loadGene(genome.getMemory(), genome.memory_limit);
}

#endif

