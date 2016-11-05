#ifndef AI_SCAN
#define AI_SAN

#include "ai.h"
#include <string.h>


void getCommandName(char *command, char *array){

	unsigned char instruction = *command;

	switch(instruction){

		case MOV_REG_REG:
			strcpy(array, "MOV_REG_REG");

		break;


		case MOV_MEM_REG:
			strcpy(array, "MOV_MEM_REG");

		break;


		case MOV_REG_MEM:
			strcpy(array, "MOV_REG_MEM");

		break;


		case MOV_MEM_VALUE:
			strcpy(array, "MOV_MEM_VALUE");

		break;


		case MOV_REG_VALUE:
			strcpy(array, "MOV_REG_VALUE");

		break;


		case XCHG_REG_MEM:
			strcpy(array, "XCHG_REG_MEM");

		break;


		case XCHG_REG_REG:
			strcpy(array, "XCHG_REG_REG");

		break;


		case PUSH_REG:
			strcpy(array, "PUSH_REG");

		break;


		case PUSH_MEM:
			strcpy(array, "PUSH_MEM");

		break;


		case PUSH_VALUE:
			strcpy(array, "PUSH_VALUE");

		break;


		case PUSH_FLAGS:
			strcpy(array, "PUSH_FLAGS");

		break;


		case POP_REG:
			strcpy(array, "POP_REG");

		break;


		case POP_MEM:
			strcpy(array, "POP_MEM");

		break;


		case POP_FLAGS:
			strcpy(array, "POP_FLAGS");

		break;



		case ADD_REG_REG:
			strcpy(array, "ADD_REG_REG");

		break;


		case ADD_REG_MEM:
			strcpy(array, "ADD_REG_MEM");

		break;


		case ADD_MEM_REG:
			strcpy(array, "ADD_MEM_REG");

		break;


		case ADD_REG_VALUE:
			strcpy(array, "ADD_REG_VALUE");

		break;


		case ADD_MEM_VALUE:
			strcpy(array, "ADD_MEM_VALUE");

		break;


		case INC_REG:
			strcpy(array, "INC_REG");

		break;


		case INC_MEM:
			strcpy(array, "INC_MEM");

		break;


		case XADD_MEM_REG:
			strcpy(array, "XADD_MEM_REG");

		break;


		case XADD_REG_REG:
			strcpy(array, "XADD_REG_REG");

		break;


		case SUB_REG_REG:
			strcpy(array, "SUB_REG_REG");

		break;


		case SUB_REG_MEM:
			strcpy(array, "SUB_REG_MEM");

		break;


		case SUB_MEM_REG:
			strcpy(array, "SUB_MEM_REG");

		break;


		case SUB_REG_VALUE:
			strcpy(array, "SUB_REG_VALUE");

		break;


		case SUB_MEM_VALUE:
			strcpy(array, "SUB_MEM_VALUE");

		break;


		case DEC_REG:
			strcpy(array, "DEC_REG");

		break;


		case DEC_MEM:
			strcpy(array, "DEC_MEM");

		break;


		case CMP_REG_REG:
			strcpy(array, "CMP_REG_REG");

		break;


		case CMP_REG_MEM:
			strcpy(array, "CMP_REG_MEM");

		break;


		case CMP_MEM_REG:
			strcpy(array, "CMP_MEM_REG");

		break;


		case CMP_REG_VALUE:
			strcpy(array, "CMP_REG_VALUE");

		break;


		case CMP_MEM_VALUE:
			strcpy(array, "CMP_MEM_VALUE");

		break;


		case NEG_REG:
			strcpy(array, "NEG_REG");

		break;


		case NEG_MEM:
			strcpy(array, "NEG_MEM");

		break;


		case MUL_REG_REG:
			strcpy(array, "MUL_REG_REG");

		break;


		case MUL_REG_MEM:
			strcpy(array, "MUL_REG_MEM");

		break;


		case MUL_REG_VALUE:
			strcpy(array, "MUL_REG_VALUE");

		break;


		case DIV_REG_REG:
			strcpy(array, "DIV_REG_REG");

		break;


		case DIV_REG_MEM:
			strcpy(array, "DIV_REG_MEM");

		break;


		case DIV_REG_VALUE:
			strcpy(array, "DIV_REG_VALUE");

		break;



		case AND_REG_REG:
			strcpy(array, "AND_REG_REG");

		break;


		case AND_MEM_REG:
			strcpy(array, "AND_MEM_REG");

		break;


		case AND_REG_MEM:
			strcpy(array, "AND_REG_MEM");

		break;


		case AND_REG_VALUE:
			strcpy(array, "AND_REG_VALUE");

		break;


		case AND_MEM_VALUE:
			strcpy(array, "AND_MEM_VALUE");

		break;


		case OR_REG_REG:
			strcpy(array, "OR_REG_REG");

		break;


		case OR_MEM_REG:
			strcpy(array, "OR_MEM_REG");

		break;


		case OR_REG_MEM:
			strcpy(array, "OR_REG_MEM");

		break;


		case OR_REG_VALUE:
			strcpy(array, "OR_REG_VALUE");

		break;


		case OR_MEM_VALUE:
			strcpy(array, "OR_MEM_VALUE");

		break;


		case XOR_REG_REG:
			strcpy(array, "XOR_REG_REG");

		break;


		case XOR_MEM_REG:
			strcpy(array, "XOR_MEM_REG");

		break;


		case XOR_REG_MEM:
			strcpy(array, "XOR_REG_MEM");

		break;


		case XOR_REG_VALUE:
			strcpy(array, "XOR_REG_VALUE");

		break;


		case XOR_MEM_VALUE:
			strcpy(array, "XOR_MEM_VALUE");

		break;


		case NOT_REG:
			strcpy(array, "NOT_REG");

		break;


		case NOT_MEM:
			strcpy(array, "NOT_MEM");

		break;



		case SHL_REG_REG:
			strcpy(array, "SHL_REG_REG");

		break;


		case SHL_MEM_REG:
			strcpy(array, "SHL_MEM_REG");

		break;


		case SHL_REG_VALUE:
			strcpy(array, "SHL_REG_VALUE");

		break;


		case SHL_MEM_VALUE:
			strcpy(array, "SHL_MEM_VALUE");

		break;


		case SHR_REG_REG:
			strcpy(array, "SHR_REG_REG");

		break;


		case SHR_MEM_REG:
			strcpy(array, "SHR_MEM_REG");

		break;


		case SHR_REG_VALUE:
			strcpy(array, "SHR_REG_VALUE");

		break;


		case SHR_MEM_VALUE:
			strcpy(array, "SHR_MEM_VALUE");

		break;



		case ROL_REG_REG:
			strcpy(array, "ROL_REG_REG");

		break;


		case ROL_MEM_REG:
			strcpy(array, "ROL_MEM_REG");

		break;


		case ROL_REG_VALUE:
			strcpy(array, "ROL_REG_VALUE");

		break;


		case ROL_MEM_VALUE:
			strcpy(array, "ROL_MEM_VALUE");

		break;


		case ROR_REG_REG:
			strcpy(array, "ROR_REG_REG");

		break;


		case ROR_MEM_REG:
			strcpy(array, "ROR_MEM_REG");

		break;


		case ROR_REG_VALUE:
			strcpy(array, "ROR_REG_VALUE");

		break;


		case ROR_MEM_VALUE:
			strcpy(array, "ROR_MEM_VALUE");

		break;


		case RCL_REG_REG:
			strcpy(array, "RCL_REG_REG");

		break;


		case RCL_MEM_REG:
			strcpy(array, "RCL_MEM_REG");

		break;


		case RCL_REG_VALUE:
			strcpy(array, "RCL_REG_VALUE");

		break;


		case RCL_MEM_VALUE:
			strcpy(array, "RCL_MEM_VALUE");

		break;


		case RCR_REG_REG:
			strcpy(array, "RCR_REG_REG");

		break;


		case RCR_MEM_REG:
			strcpy(array, "RCR_MEM_REG");

		break;


		case RCR_REG_VALUE:
			strcpy(array, "RCR_REG_VALUE");

		break;


		case RCR_MEM_VALUE:
			strcpy(array, "RCR_MEM_VALUE");

		break;



		case SETC_REG:
			strcpy(array, "SETC_REG");

		break;


		case SETC_MEM:
			strcpy(array, "SETC_MEM");

		break;


		case SETNC_REG:
			strcpy(array, "SETNC_REG");

		break;


		case SETNC_MEM:
			strcpy(array, "SETNC_MEM");

		break;


		case SETZ_REG:
			strcpy(array, "SETZ_REG");

		break;


		case SETZ_MEM:
			strcpy(array, "SETZ_MEM");

		break;


		case SETNZ_REG:
			strcpy(array, "SETNZ_REG");

		break;


		case SETNZ_MEM:
			strcpy(array, "SETNZ_MEM");

		break;


		case SETS_REG:
			strcpy(array, "SETS_REG");

		break;


		case SETS_MEM:
			strcpy(array, "SETS_MEM");

		break;


		case SETNS_REG:
			strcpy(array, "SETNS_REG");

		break;


		case SETNS_MEM:
			strcpy(array, "SETNS_MEM");

		break;


		case SETO_REG:
			strcpy(array, "SETO_REG");

		break;


		case SETO_MEM:
			strcpy(array, "SETO_MEM");

		break;


		case SETNO_REG:
			strcpy(array, "SETNO_REG");

		break;


		case SETNO_MEM:
			strcpy(array, "SETNO_MEM");

		break;


		case SETP_REG:
			strcpy(array, "SETP_REG");

		break;


		case SETP_MEM:
			strcpy(array, "SETP_MEM");

		break;


		case SETPE_REG:
			strcpy(array, "SETPE_REG");

		break;


		case SETPE_MEM:
			strcpy(array, "SETPE_MEM");

		break;


		case SETNP_REG:
			strcpy(array, "SETNP_REG");

		break;


		case SETNP_MEM:
			strcpy(array, "SETNP_MEM");

		break;


		case SETPO_REG:
			strcpy(array, "SETPO_REG");

		break;


		case SETPO_MEM:
			strcpy(array, "SETPO_MEM");

		break;



		case SETA_REG:
			strcpy(array, "SETA_REG");

		break;


		case SETA_MEM:
			strcpy(array, "SETA_MEM");

		break;


		case SETNBE_REG:
			strcpy(array, "SETNBE_REG");

		break;


		case SETNBE_MEM:
			strcpy(array, "SETNBE_MEM");

		break;


		case SETAE_REG:
			strcpy(array, "SETAE_REG");

		break;


		case SETAE_MEM:
			strcpy(array, "SETAE_MEM");

		break;


		case SETNB_REG:
			strcpy(array, "SETNB_REG");

		break;


		case SETNB_MEM:
			strcpy(array, "SETNB_MEM");

		break;


		case SETB_REG:
			strcpy(array, "SETB_REG");

		break;


		case SETB_MEM:
			strcpy(array, "SETB_MEM");

		break;


		case SETNAE_REG:
			strcpy(array, "SETNAE_REG");

		break;


		case SETNAE_MEM:
			strcpy(array, "SETNAE_MEM");

		break;


		case SETBE_REG:
			strcpy(array, "SETBE_REG");

		break;


		case SETBE_MEM:
			strcpy(array, "SETBE_MEM");

		break;


		case SETNA_REG:
			strcpy(array, "SETNA_REG");

		break;


		case SETNA_MEM:
			strcpy(array, "SETNA_MEM");

		break;


		case SETE_REG:
			strcpy(array, "SETE_REG");

		break;


		case SETE_MEM:
			strcpy(array, "SETE_MEM");

		break;


		case SETNE_REG:
			strcpy(array, "SETNE_REG");

		break;


		case SETNE_MEM:
			strcpy(array, "SETNE_MEM");

		break;



		case JUMP_REG:
			strcpy(array, "JUMP_REG");

		break;


		case JUMP_MEM:
			strcpy(array, "JUMP_MEM");

		break;


		case CALL_REG:
			strcpy(array, "CALL_REG");

		break;


		case CALL_MEM:
			strcpy(array, "CALL_MEM");

		break;


		case RET:
			strcpy(array, "RET");

		break;



		case INT_VALUE:
			strcpy(array, "INT_VALUE");

		break;



		case JC_MEM:
			strcpy(array, "JC_MEM");

		break;


		case JC_VALUE:
			strcpy(array, "JC_VALUE");

		break;


		case JNC_MEM:
			strcpy(array, "JNC_MEM");

		break;


		case JNC_VALUE:
			strcpy(array, "JNC_VALUE");

		break;


		case JZ_MEM:
			strcpy(array, "JZ_MEM");

		break;


		case JZ_VALUE:
			strcpy(array, "JZ_VALUE");

		break;


		case JNZ_MEM:
			strcpy(array, "JNZ_MEM");

		break;


		case JNZ_VALUE:
			strcpy(array, "JNZ_VALUE");

		break;


		case JS_MEM:
			strcpy(array, "JS_MEM");

		break;


		case JS_VALUE:
			strcpy(array, "JS_VALUE");

		break;


		case JNS_MEM:
			strcpy(array, "JNS_MEM");

		break;


		case JNS_VALUE:
			strcpy(array, "JNS_VALUE");

		break;


		case JO_MEM:
			strcpy(array, "JO_MEM");

		break;


		case JO_VALUE:
			strcpy(array, "JO_VALUE");

		break;


		case JNO_MEM:
			strcpy(array, "JNO_MEM");

		break;


		case JNO_VALUE:
			strcpy(array, "JNO_VALUE");

		break;


		case JP_MEM:
			strcpy(array, "JP_MEM");

		break;


		case JP_VALUE:
			strcpy(array, "JP_VALUE");

		break;


		case JPE_MEM:
			strcpy(array, "JPE_MEM");

		break;


		case JPE_VALUE:
			strcpy(array, "JPE_VALUE");

		break;


		case JNP_MEM:
			strcpy(array, "JNP_MEM");

		break;


		case JNP_VALUE:
			strcpy(array, "JNP_VALUE");

		break;


		case JPO_MEM:
			strcpy(array, "JPO_MEM");

		break;


		case JPO_VALUE:
			strcpy(array, "JPO_VALUE");

		break;



		case JA_MEM:
			strcpy(array, "JA_MEM");

		break;


		case JA_VALUE:
			strcpy(array, "JA_VALUE");

		break;


		case JNBE_MEM:
			strcpy(array, "JNBE_MEM");

		break;


		case JNBE_VALUE:
			strcpy(array, "JNBE_VALUE");

		break;


		case JAE_MEM:
			strcpy(array, "JAE_MEM");

		break;


		case JAE_VALUE:
			strcpy(array, "JAE_VALUE");

		break;


		case JNB_MEM:
			strcpy(array, "JNB_MEM");

		break;


		case JNB_VALUE:
			strcpy(array, "JNB_VALUE");

		break;


		case JB_MEM:
			strcpy(array, "JB_MEM");

		break;


		case JB_VALUE:
			strcpy(array, "JB_VALUE");

		break;


		case JNAE_MEM:
			strcpy(array, "JNAE_MEM");

		break;


		case JNAE_VALUE:
			strcpy(array, "JNAE_VALUE");

		break;


		case JBE_MEM:
			strcpy(array, "JBE_MEM");

		break;


		case JBE_VALUE:
			strcpy(array, "JBE_VALUE");

		break;


		case JNA_MEM:
			strcpy(array, "JNA_MEM");

		break;


		case JNA_VALUE:
			strcpy(array, "JNA_VALUE");

		break;


		case JE_MEM:
			strcpy(array, "JE_MEM");

		break;


		case JE_VALUE:
			strcpy(array, "JE_VALUE");

		break;


		case JNE_MEM:
			strcpy(array, "JNE_MEM");

		break;


		case JNE_VALUE:
			strcpy(array, "JNE_VALUE");

		break;


		default:
			strcpy(array, "NOP");
		break;
	}

}



int getCommandArgsNumber(char *command){

	unsigned char instruction = *command;
	int args;

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
			args = 3;
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
			args = 3;
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
			args = 3;
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
			args = 3;
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
			args = 3;
		break;

		case PUSH_REG:
			args = 2;
		break;

		case PUSH_MEM:
			args = 2;
		break;

		case PUSH_VALUE:
			args = 2;
		break;

		case PUSH_FLAGS:
			args = 2;
		break;

		case POP_REG:
			args = 2;
		break;

		case POP_MEM:
			args = 2;
		break;

		case POP_FLAGS:
			args = 2;
		break;

		case INC_REG:
		case DEC_REG:
		case NEG_REG:
		case NOT_REG:
			args = 2;
		break;

		case INC_MEM:
		case DEC_MEM:
		case NEG_MEM:
		case NOT_MEM:
			args = 2;
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
			args = 2;
		break;

		case CALL_REG:
			args = 2;
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
			args = 2;
		break;

		case CALL_MEM:
			args = 2;
		break;

		case RET:
			args = 1;
		break;

		case INT_VALUE:
			args = 2;
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
			args = 2;
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
			args = 2;
		break;




		default:
			args = 1;
		break;


	}

	return (args-1);
}


void getHexFromChar(char *value, char *array){

	char result[3] = "00";
	char hex[17] = "0123456789ABCDEF";

	result[0] = hex[((unsigned char) *value / 16)];
	result[1] = hex[((unsigned char) *value % 16)];

	strcpy(array, result);

	return;

}


void printMemory(char *memory, int bytesToPrint, int markedByte){
	
	for(int i=0; i<bytesToPrint; i++){

		char marker[2];
		char command[20];


		if(i == markedByte)
			strcpy(&marker[0], "*");
		else
			strcpy(&marker[0], " ");

		cout << marker;

		getCommandName((memory+i), command);

		cout << command << marker << " ";

		int arg_num = getCommandArgsNumber((memory+i));

		for(int j=0; j<arg_num; j++){
			i++;

			char value[3];
			getHexFromChar((memory+i), &value[0]);
			cout << value;

			if(j == (arg_num-1))
				cout << "h ";
			else
				cout << "h,";
		}

		cout << "\t";


	}

	cout << "\n";

}

#endif 