#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include "strf.h"
#include "tcol.h"


void test_u32 (char const * buf, int base)
{
	printf (TCOL (TCOL_NORMAL, TCOL_MAGENTA, TCOL_WHITE) "%s" TCOL_RST " => ", buf);
	uint32_t num = str_to_u32 (&buf, base);
	printf ("%i %c\n", (int) num, *buf);
}

void test_i32 (char const * buf, int base)
{
	printf (TCOL (TCOL_NORMAL, TCOL_MAGENTA, TCOL_WHITE) "%s" TCOL_RST " => ", buf);
	int32_t num = str_to_i32 (&buf, base);
	printf ("%i %c\n", (int) num, *buf);
}


int main (int argc, char * argv [])
{
	//char des [100] = {};
	//char format [] = "(%u32)";
	
	//memset (des, '.', sizeof (des));
	//strformat (des, sizeof (des), format, 123);
	//fwrite (des, sizeof (char), sizeof (des), stderr);


	test_i32 ("", 10);
	test_i32 ("   ", 10);
	test_i32 ("1234", 10);
	test_i32 ("-123", 10);
	test_u32 ("!#%&", 10);
	test_i32 ("AB", 16);
	test_i32 ("CD", 16);
	test_i32 ("FF", 16);

	test_u32 ("", 10);
	test_u32 ("   ", 10);
	test_u32 ("1234", 10);
	test_u32 ("-123", 10);
	test_u32 ("!#%&", 10);

	return 0;
}
