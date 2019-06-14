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


	test_i32 ("-10101", 2);
	test_i32 ("+10101", 2);
	test_i32 ("-90807", 2);
	test_i32 ("+90807", 2);
	test_i32 ("-7F", 16);
	test_i32 ("+7F", 16);

	test_i32 ("+7F", -16);

	return 0;
}
