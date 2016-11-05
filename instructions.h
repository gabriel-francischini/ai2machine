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







