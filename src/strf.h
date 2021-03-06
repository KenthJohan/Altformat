#pragma once
#include <stdint.h>
#include <assert.h>
#include <stdio.h>

#define STR_MAX(a,b) ((a)>(b)?(a):(b))
#define STR_MIN(a,b) ((a)<(b)?(a):(b))
#define STR_SET  "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define STR_SETR "ZYXWVUTSRQPONMLKJIHGFEDCBA9876543210"
#define STR_INRANGE(x, a, b) ((a) <= (x) && (x) <= (b))
#define STR_INRANGEB(x, a, b, base) STR_INRANGE ((x), (a), STR_MIN ((base) + (a), (b)))


uint32_t str_to_u32 (char const ** f, int base)
{
	uint32_t a = 0;
	int c;
	while (1)
	{
		c = (**f);
		if (c == '\0') {break;}
		else if (STR_INRANGEB (c, '0', '9', abs(base))) {return c - '0';}
		else if (abs(base) > 10 && STR_INRANGEB (c, 'a', 'z', abs(base))) {return c - ('a' - 10);}
		else if (abs(base) > 10 && STR_INRANGEB (c, 'A', 'Z', abs(base))) {return c - ('A' - 10);}
		else {break;}
		a *= (uint32_t) base;
		a += (uint32_t) c;
		(*f) ++;
	}
	return a;
}

int32_t str_to_i32 (char const ** f, int base)
{
	int32_t a = 0;
	int c;
	int neg = 0;
	c = (**f);
	if (c == '-') {neg = 1; (*f) ++;}
	else if (c == '+') {neg = 0; (*f) ++;}
	while (1)
	{
		c = (**f);
		if (c == '\0') {break;}
		else if (STR_INRANGEB (c, '0', '9', abs(base))) {c -= '0';}
		else if (abs(base) > 10 && STR_INRANGEB (c, 'a', 'z', abs(base))) {c -= ('a' - 10);}
		else if (abs(base) > 10 && STR_INRANGEB (c, 'A', 'Z', abs(base))) {c -= ('A' - 10);}
		else {break;};
		a *= (int32_t) base;
		a += (int32_t) c;
		(*f) ++;
	}
	if (neg) {return -a;}
	else {return a;}
}


void strf 
(
	char * d,
	uint32_t n,
	char const * f,
	...
)
{
	va_list vl;
	va_start (vl, f);
	uint32_t base = 0;
	while (1)
	{
		if (*f == NULL) {goto end;}
		if (*f != '%') {f ++; continue;}
		switch (*f)
		{
			case 'u':
			f ++;
			//strtoi (&f, &base, 10);
			if (*f == NULL) {goto end;}
			break;
		}
		f ++;
	}
	va_end (vl);
end:
	return;
}
