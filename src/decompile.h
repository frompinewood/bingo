#ifndef DECOMPILE_H
#define DECOMPILE_H

const char* address_formats[] = {
	"%s A",           // Accumulator
	"%s $%02X%02X",   // Absolute
	"%s $%02X%02X,X", // Absolute X
	"%s $%02X%02X,Y", // Absolute Y
	"%s #$02X",       // Immediate
	"%s",             // Implied
	"%s ($%02X%02X)", // Indirect
	"%s ($%02X,X)",   // Indirect X
	"%s ($%02X),Y",   // Indirect Y
	"%s $%02X",       // Relative
	"%s $%02X",       // Zero Page
	"%s $%02X,X",     // Zero Page X
	"%s $%02X,Y",     // Zero Page Y
};

#endif
