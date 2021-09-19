#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "address.h"

#define INSTRUCTIONS 56
#define OPCODES 142

#define INST(x,y,z,a,b) ((Instruction){.mode=x,.label=y,.code=z,.bytes=a,.cycles=b})

typedef unsigned char byte;

typedef enum Label {
	ADC, // add with carry
	AND, // and with acc
	ASL, // arithmetic shift left
	BCC, // branch on carry clear
	BCS, // branch on carry set
	BEQ, // branch on equal
	BIT, // bit test
	BMI, // branch on minus
	BNE, // branch on not equal
	BPL, // branch on plus
	BRK, // break
	BVC, // branch on overflow clear
	BVS, // branch on overflow set
	CLC, // carry clear
	CLD, // clear decimal
	CLI, // clear interrupt disable
	CLV, // clear overflow
	CMP, // compare with acc
	CPX, // compary with x
	CPY, // compary with y
	DEC, // decrement
	DEX, // dec x
	DEY, // dec y
	EOR, // exclusive or w\ acc
	INC, // inc
	INX, // inc x
	INY, // inc y
	JMP, // jump
	JSR, // jump subroutine
	LDA, // load acc
	LDX, // load x
	LDY, // load y
	LSR, // logical shift right
	NOP, // no op
	ORA, // or with acc
	PHA, // push acc
	PHP, // push status
	PLA, // pull acc
	PLP, // pull status
	ROL, // rotate left
	ROR, // rotate right
	RTI, // return from interrupt
	RTS, // return from subroutine
	SBC, // subtract with carry
	SEC, // set carry
	SED, // set decimal
	SEI, // set interupt enable
	STA, // store accumulator
	STX, // store x
	STY, // store y
	TAX, // a -> x
	TAY, // a -> y
	TSX, // stack -> x
	TXA, // x -> a
	TXS, // x -> stack
	TYA // y -> a
} Label;


const char* instruction_text[] = {
	"ADC",
	"AND",
	"ASL",
	"BCC",
	"BCS",
	"BEQ",
	"BIT",
	"BMI",
	"BNE",
	"BPL",
	"BRK",
	"BVC",
	"BVS",
	"CLC",
	"CLD",
	"CLI",
	"CLV",
	"CMP",
	"CPX",
	"CPY",
	"DEC",
	"DEX",
	"DEY",
	"EOR",
	"INC",
	"INX",
	"INY",
	"JMP",
	"JSR",
	"LDA",
	"LDX",
	"LDY",
	"LSR",
	"NOP",
	"ORA",
	"PHA",
	"PHP",
	"PLA",
	"PLP",
	"ROL",
	"ROR",
	"RTI",
	"RTS",
	"SBC",
	"SEC",
	"SED",
	"SEI",
	"STA",
	"STX",
	"STY",
	"TAX",
	"TAY",
	"TSX",
	"TXA",
	"TXS",
	"TYA"
};

typedef struct Instruction {
	Address mode;
	Label label;
	byte code;
	byte bytes;
	byte cycles;
} Instruction;

Instruction* instruction_map[INSTRUCTIONS][ADDRESS_MODES];
Instruction* inverse_instruction_map[0xFF];

Instruction instructions[] = {
	// ADC
	INST(IMM,ADC,0x69,2,2),
	INST(ZPG,ADC,0x65,2,3),
	INST(ZPGX,ADC,0x75,2,4),
	INST(ABS,ADC,0x6D,3,4),
	INST(ABSX,ADC,0x7D,3,4),
	INST(ABSY,ADC,0x79,3,4),
	INST(INDX,ADC,0x61,2,6),
	INST(INDY,ADC,0x71,2,5),
	// AND
	INST(IMM,AND,0x29,2,2),
	INST(ZPG,AND,0x25,2,3),
	INST(ZPGX,AND,0x35,2,4),
	INST(ABS,AND,0x2D,3,4),
	INST(ABSX,AND,0x3D,3,4),
	INST(ABSY,AND,0x39,3,4),
	INST(INDX,AND,0x21,2,6),
	INST(INDY,AND,0x31,2,5),
	// ASL
	INST(ACC,ASL,0x0A,1,2),
	INST(ZPG,ASL,0x06,2,5),
	INST(ZPGX,ASL,0x16,2,6),
	INST(ABS,ASL,0x0E,3,6),
	INST(ABSX,ASL,0x1E,3,7),
	// BCC
	INST(REL,BCC,0x90,2,2),
	// BCS
	INST(REL,BCS,0xF0,2,2),
	// BIT
	INST(ZPG,BIT,0x24,2,3),
	INST(ABS,BIT,0x2C,3,4),
	// BMI
	INST(REL,BMI,0x30,2,2),
	// BNE
	INST(REL,BNE,0xD0,2,2),
	// BPL
	INST(REL,BPL,0x10,2,2),
	// BRK
	INST(IMP,BRK,0x00,1,7),
	// BVC
	INST(REL,BVC,0x50,2,2),
	// BCS
	INST(REL,BVS,0x70,2,2),
	// CLC
	INST(IMP,CLC,0x18,1,2),
	// CLD
	INST(IMP,CLD,0xD8,1,2),
	// CLI
	INST(IMP,CLI,0x58,1,2),
	// CLV
	INST(IMP,CLV,0xB8,1,2),
	// CMP
	INST(IMM,CMP,0xC9,2,2),
	INST(ZPG,CMP,0xC5,2,3),
	INST(ZPGX,CMP,0xD5,2,4),
	INST(ABS,CMP,0xCD,3,4),
	INST(ABSX,CMP,0xDD,3,4),
	INST(ABSY,CMP,0xD9,3,4),
	INST(INDX,CMP,0xC1,2,6),
	INST(INDY,CMP,0xD1,2,5),
	// CPX
	INST(IMM,CPX,0xE0,2,2),
	INST(ZPG,CPX,0xE4,2,3),
	INST(ABS,CPX,0xEC,3,4),
	// CPY
	INST(IMM,CPY,0xC0,2,2),
	INST(ZPG,CPY,0xC4,2,3),
	INST(ABS,CPY,0xCC,3,4),
	// DEC
	INST(ZPG,DEC,0xC6,2,5),
	INST(ZPGX,DEC,0xD6,2,6),
	INST(ABS,DEC,0xCE,3,3),
	INST(ABSX,DEC,0xDE,3,7),
	// DEX
	INST(IMP,DEX,0xCA,1,2),
	// DEY
	INST(IMP,DEY,0x88,1,2),
	// EOR
	INST(IMM,EOR,0x49,2,2),
	INST(ZPG,EOR,0x45,2,3),
	INST(ZPGX,EOR,0x55,2,4),
	INST(ABS,EOR,0x4D,3,4),
	INST(ABSX,EOR,0x5D,3,4),
	INST(ABSY,EOR,0x59,3,4),
	INST(INDX,EOR,0x41,2,6),
	INST(INDY,EOR,0x51,2,5),
	// INC
	INST(ZPG,INC,0xE6,2,5),
	INST(ZPGX,INC,0xF6,2,6),
	INST(ABS,INC,0xEE,3,6),
	INST(ABSX,INC,0xFE,3,7),
	// INX
	INST(IMP,INX,0xE8,1,2),
	// INY
	INST(IMP,INY,0xC8,1,2),
	// JMP
	INST(ABS,JMP,0x4C,3,3),
	INST(IND,JMP,0x6C,3,5),
	// JSR
	INST(ABS,JSR,0x20,3,6),
	// LDA
	INST(IMM,LDA,0xA9,2,2),
	INST(ZPG,LDA,0xA5,2,3),
	INST(ZPGX,LDA,0xB5,2,4),
	INST(ABS,LDA,0xAD,3,4),
	INST(ABSX,LDA,0xBD,3,4),
	INST(ABSY,LDA,0xB9,3,4),
	INST(INDX,LDA,0xA1,2,6),
	INST(INDY,LDA,0xB1,2,5),
	// LDX
	INST(IMM,LDX,0xA2,2,2),
	INST(ZPG,LDX,0xA6,2,3),
	INST(ZPGY,LDX,0xB6,2,4),
	INST(ABS,LDX,0xAE,3,4),
	INST(ABSY,LDX,0xBE,3,4),
	// LDY
	INST(IMM,LDY,0xA0,2,2),
	INST(ZPG,LDY,0xA4,2,3),
	INST(ZPGX,LDY,0xB4,2,4),
	INST(ABS,LDY,0xAC,3,4),
	INST(ABSX,LDY,0xBC,3,4),
	// LSR
	INST(ACC,LSR,0x4A,1,2),
	INST(ZPG,LSR,0x46,2,5),
	INST(ZPGX,LSR,0x56,2,6),
	INST(ABS,LSR,0x4E,3,6),
	INST(ABSX,LSR,0x5E,3,7),
	// NOP
	INST(IMP,NOP,0xEA,1,2),
	// ORA
	INST(IMM,ORA,0x09,2,2),
	INST(ZPG,ORA,0x05,2,3),
	INST(ZPGX,ORA,0x15,2,4),
	INST(ABS,ORA,0x0D,3,4),
	INST(ABSX,ORA,0x1D,3,4),
	INST(ABSY,ORA,0x19,3,4),
	INST(INDX,ORA,0x01,2,6),
	INST(INDY,ORA,0x11,2,5),
	// PHA
	INST(IMP,PHA,0x48,1,3),
	// PHP
	INST(IMP,PHP,0x08,1,3),
	// PLA
	INST(IMP,PHA,0x68,1,4),
	// ROL
	INST(ACC,ROL,0x2A,1,2),
	INST(ZPG,ROL,0x26,2,5),
	INST(ZPGX,ROL,0x36,2,6),
	INST(ABS,ROL,0x2E,3,6),
	INST(ABSX,ROL,0x3E,3,7),
	// ROR
	INST(ACC,ROR,0x6A,1,2),
	INST(ZPG,ROR,0x66,2,5),
	INST(ZPGX,ROR,0x76,2,6),
	INST(ABS,ROR,0x6E,3,6),
	INST(ABSX,ROR,0x7E,3,7),
	// RTI
	INST(IMP,RTI,0x40,1,6),
	// RTS
	INST(IMP,RTS,0x60,1,6),
	//SBC
	INST(IMM,SBC,0xE9,2,2),
	// SEC
	INST(IMP,SEC,0x38,1,2),
	// SED
	INST(IMP,SED,0xF8,1,2),
	// SEI
	INST(IMP,SEI,0x78,1,2),
	// STA
	INST(ZPG,STA,0x85,2,3),
	INST(ZPGX,STA,0x95,2,4),
	INST(ABS,STA,0x8D,3,4),
	INST(ABSX,STA,0x9D,3,5),
	INST(ABSY,STA,0x99,3,5),
	INST(INDX,STA,0x81,2,6),
	INST(INDY,STA,0x91,2,6),
	// STX
	INST(ZPG,STX,0x86,2,3),
	INST(ZPGY,STX,0x96,2,4),
	INST(ABS,STX,0x8E,3,4),
	// STY
	INST(ZPG,STY,0x84,2,3),
	INST(ZPGX,STY,0x94,2,4),
	INST(ABS,STY,0x8C,3,4),
	// TAX
	INST(IMP,TAX,0xAA,1,2),
	// TAY
	INST(IMP,TAY,0xA8,1,2),
	// TSX
	INST(IMP,TSX,0xBA,1,2),
	// TXA
	INST(IMP,TXA,0x8A,1,2),
	// TXS
	INST(IMP,TXS,0x9A,1,2),
	// TYA
	INST(IMP,TYA,0x98,1,2)
};

void init_instruction_map() {
	for (int i = 0; i < OPCODES; i++) {
		Instruction* inst = &instructions[i];
		instruction_map[inst->label][inst->mode] = inst;
		inverse_instruction_map[inst->code] = inst;
	}
}



#endif
