#ifndef ADDRESS_H
#define ADDRESS_H

#include <stdio.h>

#define ADDRESS_MODES 12

typedef enum Address {
	ACC,
	ABS,
	ABSX,
	ABSY,
	IMM,
	IMP,
	IND,
	INDX,
	INDY,
	REL,
	ZPG,
	ZPGX,
	ZPGY
} Address;

const char* address_text[] = {
	"Accumulator",
	"Absolute",
	"Absolute X",
	"Absolute Y",
	"Immediate",
	"Implied",
	"Indirect",
	"Indirect X",
	"Indirect Y",
	"Relative",
	"Zero Page",
	"Zero Page X",
	"Zero Page Y"
};

#endif
