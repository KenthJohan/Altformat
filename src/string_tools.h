#pragma once
#include <stdlib.h>
#include <stdint.h>

#define NUMBER_REP     "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBER_REP_REV "ZYXWVUTSRQPONMLKJIHGFEDCBA9876543210"


void Reverse (char * Buffer, size_t Length);


//Returns 0 on success.
//Returns -1 on error.
int String_From_u32 
(
	char * Buffer, 
	char ** First, 
	size_t Length, 
	uint32_t Number, 
	uint_fast8_t Base, 
	char Pad
);


//Returns 0 on success.
//Returns -1 on error.
int String_To_u32 
(
	char const * Buffer, 
	char const ** Last, 
	size_t Length, 
	uint32_t * Number, 
	uint_fast8_t Base
);