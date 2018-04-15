#include <stdlib.h>
#include <stdint.h>
#include "string_tools.h"
#include "util.h"


#define NUMBER_REP     "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBER_REP_REV "ZYXWVUTSRQPONMLKJIHGFEDCBA9876543210"


void Reverse (char * Buffer, size_t Length)
{
	char *L = Buffer;
	char *R = Buffer + Length - 1;
	while (L < R) 
	{
		SWAP (char, *L, *R);
		L = L + 1;
		R = R - 1;
	}
}


int String_From_u32 
(
	char * Buffer, 
	char ** First, 
	size_t Length, 
	uint32_t Number, 
	uint_fast8_t Base, 
	char Pad
)
{
	if (Base >= sizeof (NUMBER_REP)) {return -1;}
	*First = Buffer + Length - 1;
	while (1)
	{
		if (*First < Buffer) {break;}
		**First = NUMBER_REP [Number % Base];
		*First = *First - 1;
		Number /= Base;
		if (Number == 0) {break;}
	}
	while (1)
	{
		if (*First < Buffer) {break;}
		**First = Pad;
		*First = *First - 1;
	}
	return 0;
}


int String_To_u32 
(
	char const * Buffer, 
	char const ** Last, 
	size_t Length, 
	uint32_t * Number, 
	uint_fast8_t Base
)
{
	if (Base >= sizeof (NUMBER_REP)) {return -1;}
	*Number = 0;
	*Last = Buffer;
	char const * const End = Buffer + Length;
	while (1)
	{
		if (**Last == '\0') {break;}
		if (*Last == End) {break;}
		if (!IN_RANGE (**Last, '0', '9')) {break;}
		*Number = (*Number * 10) + (**Last - '0');
		*Last = *Last + 1;
	}
	return 0;
}