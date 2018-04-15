#pragma once
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

//Returns 0 on success.
//Returns -1 on error.
int String_From_u32 (char * Buffer, char ** First, size_t Length, uint32_t Number, uint_fast8_t Base, char Pad);


//Returns 0 on success.
//Returns -1 on error.
int String_To_u32 (char const * Buffer, char const ** Last, size_t Length, uint32_t * Number, uint_fast8_t Base);



void Format_Text (size_t Buffer_Length, char * Buffer, size_t Format_Length, char const * Format, ...);