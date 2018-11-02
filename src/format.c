#include <string.h>
#include "format.h"
#include "string_tools.h"
#include "util.h"


#define BOOLEAN_REP_TRUE "TRUE"
#define BOOLEAN_REP_FALSE "FALSE"
#define BOOLEAN  1
#define UNSIGNED 2
#define SIGNED   3


struct Formata
{
	size_t Buffer_Length;
	size_t Buffer_Remaining;
	char * Buffer;
	char * B;
	size_t Format_Length;
	size_t Format_Remaining;
	char const * Format;
	char const * F;
	char Pad;
	char Pad_Default;
	uint32_t Type;
	uint32_t Base;
	uint32_t Base_Default;
	uint32_t Size;
	uint32_t Size_Default;
	uint32_t Width;
	uint32_t Width_Default;
};


void Buffer_Next (struct Formata * X, size_t N)
{
	X->B = X->B + N;
	//fprintf (stderr, "Buffer_Next: ");
	//fwrite (X->B, sizeof (char), N, stderr);
	//fprintf (stderr, "\n");
}

void Format_Next (struct Formata * X, size_t N)
{
	X->F = X->F + N;
	//fprintf (stderr, "Format_Next: ");
	//fwrite (X->F, sizeof (char), N, stderr);
	//fprintf (stderr, "\n");
}

void Handle_Type (struct Formata * X)
{
	switch (*X->F)
	{
		case 'b':
		X->Type = BOOLEAN;
		break;
		case 'u':
		X->Type = UNSIGNED;
		break;
		case 'i':
		X->Type = SIGNED;
		break;
	}
	Format_Next (X, 1);
}


void Handle_Size (struct Formata * X)
{
	X->Size = X->Size_Default;
	if (!IN_RANGE (*X->F, '0', '9')) {return;}
	char const * Last;
	String_To_u32 (X->F, &Last, 2, &X->Size, 10);
	X->F = Last;
	//printf ("Size: %i\n", X->Size);
}


void Handle_Base (struct Formata * X)
{
	X->Base = X->Base_Default;
	if (*X->F != '_') {return;}
	Format_Next (X, 1);
	char const * Last;
	String_To_u32 (X->F, &Last, 2, &X->Base, 10);
	X->F = Last;
	//printf ("Base: %i\n", X->Base);
}


void Handle_Width (struct Formata * X)
{
	X->Width = X->Width_Default;
	if (!IN_RANGE (*X->F, '0', '9')) {return;}
	char const * Last;
	String_To_u32 (X->F, &Last, 2, &X->Width, 10);
	X->F = Last;
	//printf ("Width: %i\n", X->Width);
}


void Append_Text (struct Formata * X, char const * Buffer)
{
	char const * B = Buffer;
	char const * E = X->B + X->Width;
	while (1)
	{
		if (X->B == E) {break;}
		if (*X->B == '\0') {break;}
		if (*B == '\0') 
		{
			*X->B = X->Pad;
		}
		else
		{
			*X->B = *B;
			B = B + 1;
		}
		Buffer_Next (X, 1);
	}
}


void F1 (struct Formata * X, va_list List)
{
	while (1)
	{
		if (*X->F == '\0') {break;}
		if (*X->F != '%')
		{
			*X->B = *X->F;
			Buffer_Next (X, 1);
			Format_Next (X, 1);
			continue;
		}
		Format_Next (X, 1);
		Handle_Width (X);
		Handle_Type (X);
		Handle_Size (X);
		Handle_Base (X);
		switch (X->Type)
		{
			case SIGNED:
			break;
			case UNSIGNED:
			{
				unsigned int V = va_arg (List, unsigned int);
				char * Last;
				String_From_u32 (X->B, &Last, X->Width, V, X->Base, X->Pad);
				Buffer_Next (X, X->Width);
			}
			break;
			case BOOLEAN:
			{
				int V = va_arg (List, int);
				if (V){Append_Text (X, BOOLEAN_REP_TRUE);}
				else  {Append_Text (X, BOOLEAN_REP_FALSE);}
			}
			break;
		}
		
	}
}


void Format_Text (size_t Buffer_Length, char * Buffer, size_t Format_Length, char const * Format, ...)
{
	va_list List;
	va_start (List, Format);
	struct Formata X;
	
	X.Buffer_Remaining = Buffer_Length;
	X.Buffer_Length = Buffer_Length;
	X.Buffer = Buffer;
	X.B = Buffer;
	
	X.Format_Length = Format_Length;
	X.Format_Remaining = Format_Length;
	X.Format = Format;
	X.F = Format;
	
	X.Pad = '@';
	X.Pad_Default = '@';
	X.Base = 10;
	X.Base_Default = 10;
	X.Width = 10;
	X.Width_Default = 10;
	X.Size = 32;
	X.Size_Default = 32;
	
	F1 (&X, List);
	
	va_end (List);
}


/*
d or i	Signed decimal integer	392
u	Unsigned decimal integer	7235
o	Unsigned octal	610
x	Unsigned hexadecimal integer	7fa
X	Unsigned hexadecimal integer (uppercase)	7FA
f	Decimal floating point, lowercase	392.65
F	Decimal floating point, uppercase	392.65
e	Scientific notation (mantissa/exponent), lowercase	3.9265e+2
E	Scientific notation (mantissa/exponent), uppercase	3.9265E+2
g	Use the shortest representation: %e or %f	392.65
G	Use the shortest representation: %E or %F	392.65
a	Hexadecimal floating point, lowercase	-0xc.90fep-2
A	Hexadecimal floating point, uppercase	-0XC.90FEP-2
c	Character	a
s	String of characters	sample
p	Pointer address	b8000000
n	Nothing printed.
The corresponding argument must be a pointer to a signed int.
The number of characters written so far is stored in the pointed location.	
%	A % followed by another % character will write a single % to the stream.	%
*/


#define SIGNED_DECIMAL_INTEGER 'd'
#define SIGNED_DECIMAL_INTEGER 'u'
#define UNSIGEND_OCTAL_INTEGER 'o'
#include <inttypes.h>

struct FF_Template
{
	char const * Specifier;
	uint32_t Size;
	uint32_t Type;
	uint32_t Width;
};

void Compile (struct FF_Template * X, char const * Buffer, size_t Length)
{
	switch (X->Size)
	{
		case 16:
		X->
		break;
	}
}

