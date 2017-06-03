#ifndef AI_SCAN
#define AI_SAN

#include "ai.h"
#include <string.h>

#define VALUE_TYPE 2
#define MEM_TYPE 1
#define REG_TYPE 0


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


int getOpcodeFromName(char *name){
	if(strcmp(name, "MOV_REG_REG") == 0){return MOV_REG_REG}
	if(strcmp(name, "MOV_MEM_REG") == 0){return MOV_MEM_REG}
	if(strcmp(name, "MOV_REG_MEM") == 0){return MOV_REG_MEM}
	if(strcmp(name, "MOV_MEM_VALUE") == 0){return MOV_MEM_VALUE}
	if(strcmp(name, "MOV_REG_VALUE") == 0){return MOV_REG_VALUE}
	if(strcmp(name, "XCHG_REG_MEM") == 0){return XCHG_REG_MEM}
	if(strcmp(name, "XCHG_REG_REG") == 0){return XCHG_REG_REG}
	if(strcmp(name, "PUSH_REG") == 0){return PUSH_REG}
	if(strcmp(name, "PUSH_MEM") == 0){return PUSH_MEM}
	if(strcmp(name, "PUSH_VALUE") == 0){return PUSH_VALUE}
	if(strcmp(name, "PUSH_FLAGS") == 0){return PUSH_FLAGS}
	if(strcmp(name, "POP_REG") == 0){return POP_REG}
	if(strcmp(name, "POP_MEM") == 0){return POP_MEM}
	if(strcmp(name, "POP_FLAGS") == 0){return POP_FLAGS}
	if(strcmp(name, "ADD_REG_REG") == 0){return ADD_REG_REG}
	if(strcmp(name, "ADD_REG_MEM") == 0){return ADD_REG_MEM}
	if(strcmp(name, "ADD_MEM_REG") == 0){return ADD_MEM_REG}
	if(strcmp(name, "ADD_REG_VALUE") == 0){return ADD_REG_VALUE}
	if(strcmp(name, "ADD_MEM_VALUE") == 0){return ADD_MEM_VALUE}
	if(strcmp(name, "INC_REG") == 0){return INC_REG}
	if(strcmp(name, "INC_MEM") == 0){return INC_MEM}
	if(strcmp(name, "XADD_MEM_REG") == 0){return XADD_MEM_REG}
	if(strcmp(name, "XADD_REG_REG") == 0){return XADD_REG_REG}
	if(strcmp(name, "SUB_REG_REG") == 0){return SUB_REG_REG}
	if(strcmp(name, "SUB_REG_MEM") == 0){return SUB_REG_MEM}
	if(strcmp(name, "SUB_MEM_REG") == 0){return SUB_MEM_REG}
	if(strcmp(name, "SUB_REG_VALUE") == 0){return SUB_REG_VALUE}
	if(strcmp(name, "SUB_MEM_VALUE") == 0){return SUB_MEM_VALUE}
	if(strcmp(name, "DEC_REG") == 0){return DEC_REG}
	if(strcmp(name, "DEC_MEM") == 0){return DEC_MEM}
	if(strcmp(name, "CMP_REG_REG") == 0){return CMP_REG_REG}
	if(strcmp(name, "CMP_REG_MEM") == 0){return CMP_REG_MEM}
	if(strcmp(name, "CMP_MEM_REG") == 0){return CMP_MEM_REG}
	if(strcmp(name, "CMP_REG_VALUE") == 0){return CMP_REG_VALUE}
	if(strcmp(name, "CMP_MEM_VALUE") == 0){return CMP_MEM_VALUE}
	if(strcmp(name, "NEG_REG") == 0){return NEG_REG}
	if(strcmp(name, "NEG_MEM") == 0){return NEG_MEM}
	if(strcmp(name, "MUL_REG_REG") == 0){return MUL_REG_REG}
	if(strcmp(name, "MUL_REG_MEM") == 0){return MUL_REG_MEM}
	if(strcmp(name, "MUL_REG_VALUE") == 0){return MUL_REG_VALUE}
	if(strcmp(name, "DIV_REG_REG") == 0){return DIV_REG_REG}
	if(strcmp(name, "DIV_REG_MEM") == 0){return DIV_REG_MEM}
	if(strcmp(name, "DIV_REG_VALUE") == 0){return DIV_REG_VALUE}
	if(strcmp(name, "AND_REG_REG") == 0){return AND_REG_REG}
	if(strcmp(name, "AND_MEM_REG") == 0){return AND_MEM_REG}
	if(strcmp(name, "AND_REG_MEM") == 0){return AND_REG_MEM}
	if(strcmp(name, "AND_REG_VALUE") == 0){return AND_REG_VALUE}
	if(strcmp(name, "AND_MEM_VALUE") == 0){return AND_MEM_VALUE}
	if(strcmp(name, "OR_REG_REG") == 0){return OR_REG_REG}
	if(strcmp(name, "OR_MEM_REG") == 0){return OR_MEM_REG}
	if(strcmp(name, "OR_REG_MEM") == 0){return OR_REG_MEM}
	if(strcmp(name, "OR_REG_VALUE") == 0){return OR_REG_VALUE}
	if(strcmp(name, "OR_MEM_VALUE") == 0){return OR_MEM_VALUE}
	if(strcmp(name, "XOR_REG_REG") == 0){return XOR_REG_REG}
	if(strcmp(name, "XOR_MEM_REG") == 0){return XOR_MEM_REG}
	if(strcmp(name, "XOR_REG_MEM") == 0){return XOR_REG_MEM}
	if(strcmp(name, "XOR_REG_VALUE") == 0){return XOR_REG_VALUE}
	if(strcmp(name, "XOR_MEM_VALUE") == 0){return XOR_MEM_VALUE}
	if(strcmp(name, "NOT_REG") == 0){return NOT_REG}
	if(strcmp(name, "NOT_MEM") == 0){return NOT_MEM}
	if(strcmp(name, "SHL_REG_REG") == 0){return SHL_REG_REG}
	if(strcmp(name, "SHL_MEM_REG") == 0){return SHL_MEM_REG}
	if(strcmp(name, "SHL_REG_VALUE") == 0){return SHL_REG_VALUE}
	if(strcmp(name, "SHL_MEM_VALUE") == 0){return SHL_MEM_VALUE}
	if(strcmp(name, "SHR_REG_REG") == 0){return SHR_REG_REG}
	if(strcmp(name, "SHR_MEM_REG") == 0){return SHR_MEM_REG}
	if(strcmp(name, "SHR_REG_VALUE") == 0){return SHR_REG_VALUE}
	if(strcmp(name, "SHR_MEM_VALUE") == 0){return SHR_MEM_VALUE}
	if(strcmp(name, "ROL_REG_REG") == 0){return ROL_REG_REG}
	if(strcmp(name, "ROL_MEM_REG") == 0){return ROL_MEM_REG}
	if(strcmp(name, "ROL_REG_VALUE") == 0){return ROL_REG_VALUE}
	if(strcmp(name, "ROL_MEM_VALUE") == 0){return ROL_MEM_VALUE}
	if(strcmp(name, "ROR_REG_REG") == 0){return ROR_REG_REG}
	if(strcmp(name, "ROR_MEM_REG") == 0){return ROR_MEM_REG}
	if(strcmp(name, "ROR_REG_VALUE") == 0){return ROR_REG_VALUE}
	if(strcmp(name, "ROR_MEM_VALUE") == 0){return ROR_MEM_VALUE}
	if(strcmp(name, "RCL_REG_REG") == 0){return RCL_REG_REG}
	if(strcmp(name, "RCL_MEM_REG") == 0){return RCL_MEM_REG}
	if(strcmp(name, "RCL_REG_VALUE") == 0){return RCL_REG_VALUE}
	if(strcmp(name, "RCL_MEM_VALUE") == 0){return RCL_MEM_VALUE}
	if(strcmp(name, "RCR_REG_REG") == 0){return RCR_REG_REG}
	if(strcmp(name, "RCR_MEM_REG") == 0){return RCR_MEM_REG}
	if(strcmp(name, "RCR_REG_VALUE") == 0){return RCR_REG_VALUE}
	if(strcmp(name, "RCR_MEM_VALUE") == 0){return RCR_MEM_VALUE}
	if(strcmp(name, "SETC_REG") == 0){return SETC_REG}
	if(strcmp(name, "SETC_MEM") == 0){return SETC_MEM}
	if(strcmp(name, "SETNC_REG") == 0){return SETNC_REG}
	if(strcmp(name, "SETNC_MEM") == 0){return SETNC_MEM}
	if(strcmp(name, "SETZ_REG") == 0){return SETZ_REG}
	if(strcmp(name, "SETZ_MEM") == 0){return SETZ_MEM}
	if(strcmp(name, "SETNZ_REG") == 0){return SETNZ_REG}
	if(strcmp(name, "SETNZ_MEM") == 0){return SETNZ_MEM}
	if(strcmp(name, "SETS_REG") == 0){return SETS_REG}
	if(strcmp(name, "SETS_MEM") == 0){return SETS_MEM}
	if(strcmp(name, "SETNS_REG") == 0){return SETNS_REG}
	if(strcmp(name, "SETNS_MEM") == 0){return SETNS_MEM}
	if(strcmp(name, "SETO_REG") == 0){return SETO_REG}
	if(strcmp(name, "SETO_MEM") == 0){return SETO_MEM}
	if(strcmp(name, "SETNO_REG") == 0){return SETNO_REG}
	if(strcmp(name, "SETNO_MEM") == 0){return SETNO_MEM}
	if(strcmp(name, "SETP_REG") == 0){return SETP_REG}
	if(strcmp(name, "SETP_MEM") == 0){return SETP_MEM}
	if(strcmp(name, "SETPE_REG") == 0){return SETPE_REG}
	if(strcmp(name, "SETPE_MEM") == 0){return SETPE_MEM}
	if(strcmp(name, "SETNP_REG") == 0){return SETNP_REG}
	if(strcmp(name, "SETNP_MEM") == 0){return SETNP_MEM}
	if(strcmp(name, "SETPO_REG") == 0){return SETPO_REG}
	if(strcmp(name, "SETPO_MEM") == 0){return SETPO_MEM}
	if(strcmp(name, "SETA_REG") == 0){return SETA_REG}
	if(strcmp(name, "SETA_MEM") == 0){return SETA_MEM}
	if(strcmp(name, "SETNBE_REG") == 0){return SETNBE_REG}
	if(strcmp(name, "SETNBE_MEM") == 0){return SETNBE_MEM}
	if(strcmp(name, "SETAE_REG") == 0){return SETAE_REG}
	if(strcmp(name, "SETAE_MEM") == 0){return SETAE_MEM}
	if(strcmp(name, "SETNB_REG") == 0){return SETNB_REG}
	if(strcmp(name, "SETNB_MEM") == 0){return SETNB_MEM}
	if(strcmp(name, "SETB_REG") == 0){return SETB_REG}
	if(strcmp(name, "SETB_MEM") == 0){return SETB_MEM}
	if(strcmp(name, "SETNAE_REG") == 0){return SETNAE_REG}
	if(strcmp(name, "SETNAE_MEM") == 0){return SETNAE_MEM}
	if(strcmp(name, "SETBE_REG") == 0){return SETBE_REG}
	if(strcmp(name, "SETBE_MEM") == 0){return SETBE_MEM}
	if(strcmp(name, "SETNA_REG") == 0){return SETNA_REG}
	if(strcmp(name, "SETNA_MEM") == 0){return SETNA_MEM}
	if(strcmp(name, "SETE_REG") == 0){return SETE_REG}
	if(strcmp(name, "SETE_MEM") == 0){return SETE_MEM}
	if(strcmp(name, "SETNE_REG") == 0){return SETNE_REG}
	if(strcmp(name, "SETNE_MEM") == 0){return SETNE_MEM}
	if(strcmp(name, "JUMP_REG") == 0){return JUMP_REG}
	if(strcmp(name, "JUMP_MEM") == 0){return JUMP_MEM}
	if(strcmp(name, "CALL_REG") == 0){return CALL_REG}
	if(strcmp(name, "CALL_MEM") == 0){return CALL_MEM}
	if(strcmp(name, "RET") == 0){return RET}
	if(strcmp(name, "INT_VALUE") == 0){return INT_VALUE}
	if(strcmp(name, "JC_MEM") == 0){return JC_MEM}
	if(strcmp(name, "JC_VALUE") == 0){return JC_VALUE}
	if(strcmp(name, "JNC_MEM") == 0){return JNC_MEM}
	if(strcmp(name, "JNC_VALUE") == 0){return JNC_VALUE}
	if(strcmp(name, "JZ_MEM") == 0){return JZ_MEM}
	if(strcmp(name, "JZ_VALUE") == 0){return JZ_VALUE}
	if(strcmp(name, "JNZ_MEM") == 0){return JNZ_MEM}
	if(strcmp(name, "JNZ_VALUE") == 0){return JNZ_VALUE}
	if(strcmp(name, "JS_MEM") == 0){return JS_MEM}
	if(strcmp(name, "JS_VALUE") == 0){return JS_VALUE}
	if(strcmp(name, "JNS_MEM") == 0){return JNS_MEM}
	if(strcmp(name, "JNS_VALUE") == 0){return JNS_VALUE}
	if(strcmp(name, "JO_MEM") == 0){return JO_MEM}
	if(strcmp(name, "JO_VALUE") == 0){return JO_VALUE}
	if(strcmp(name, "JNO_MEM") == 0){return JNO_MEM}
	if(strcmp(name, "JNO_VALUE") == 0){return JNO_VALUE}
	if(strcmp(name, "JP_MEM") == 0){return JP_MEM}
	if(strcmp(name, "JP_VALUE") == 0){return JP_VALUE}
	if(strcmp(name, "JPE_MEM") == 0){return JPE_MEM}
	if(strcmp(name, "JPE_VALUE") == 0){return JPE_VALUE}
	if(strcmp(name, "JNP_MEM") == 0){return JNP_MEM}
	if(strcmp(name, "JNP_VALUE") == 0){return JNP_VALUE}
	if(strcmp(name, "JPO_MEM") == 0){return JPO_MEM}
	if(strcmp(name, "JPO_VALUE") == 0){return JPO_VALUE}
	if(strcmp(name, "JA_MEM") == 0){return JA_MEM}
	if(strcmp(name, "JA_VALUE") == 0){return JA_VALUE}
	if(strcmp(name, "JNBE_MEM") == 0){return JNBE_MEM}
	if(strcmp(name, "JNBE_VALUE") == 0){return JNBE_VALUE}
	if(strcmp(name, "JAE_MEM") == 0){return JAE_MEM}
	if(strcmp(name, "JAE_VALUE") == 0){return JAE_VALUE}
	if(strcmp(name, "JNB_MEM") == 0){return JNB_MEM}
	if(strcmp(name, "JNB_VALUE") == 0){return JNB_VALUE}
	if(strcmp(name, "JB_MEM") == 0){return JB_MEM}
	if(strcmp(name, "JB_VALUE") == 0){return JB_VALUE}
	if(strcmp(name, "JNAE_MEM") == 0){return JNAE_MEM}
	if(strcmp(name, "JNAE_VALUE") == 0){return JNAE_VALUE}
	if(strcmp(name, "JBE_MEM") == 0){return JBE_MEM}
	if(strcmp(name, "JBE_VALUE") == 0){return JBE_VALUE}
	if(strcmp(name, "JNA_MEM") == 0){return JNA_MEM}
	if(strcmp(name, "JNA_VALUE") == 0){return JNA_VALUE}
	if(strcmp(name, "JE_MEM") == 0){return JE_MEM}
	if(strcmp(name, "JE_VALUE") == 0){return JE_VALUE}
	if(strcmp(name, "JNE_MEM") == 0){return JNE_MEM}
	if(strcmp(name, "JNE_VALUE") == 0){return JNE_VALUE}

	// Impossible opcode
	return 0xFFFF;
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


void getArgsTypes(char *command, int *buffer){

	int buff_index = 0;
	for(int i=0; *(command+i) != '\0'; i++){

		if(*(command+i) == '_'){

			switch(*(command+i+1)){

				case 'R':
					*(buffer+buff_index) = REG_TYPE;
				break;

				case 'M':
					*(buffer+buff_index) = MEM_TYPE;
				break;

				case 'V':
					*(buffer+buff_index) = VALUE_TYPE;


				default:
				break;
			}


			buff_index++;

		}

	}


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
		
		for(int i=0; (*(command+i) != '_') && (*(command+i) != '\0'); i++){
		
		cout << (char) *(command+i);
		
		}

		cout << marker << " ";

		int arg_num = getCommandArgsNumber((memory+i));
		int arg_type[arg_num];

		getArgsTypes(command, &arg_type[0]);

		for(int j=0; j<arg_num; j++){
			i++;

			char value[3];
			getHexFromChar((memory+i), &value[0]);
			//cout << value;

			char value_marker[5];

			if(arg_type[j] == REG_TYPE)
				strcpy(value_marker,"$$");
			if(arg_type[j] == MEM_TYPE)
				strcpy(value_marker, "[]");
			if(arg_type[j] == VALUE_TYPE)
				strcpy(value_marker, "  ");
				
				
			cout << (char) value_marker[0];
			cout << value << 'h';
			if(value_marker[1] != ' ')
				cout << (char) value_marker[1];



			if(j == (arg_num-1))
				cout << "";
			else
				cout << ", ";
				
		}

		cout << ";\n\t";


	}

	cout << "\n";

}

#endif
