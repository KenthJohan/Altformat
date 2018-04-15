#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "format.h"









int main (int argc, char * argv [])
{
	char Buffer [100] = {};
	char Format [] = "(%6u14) (%u9_16) (%b) (%b)";
	
	memset (Buffer, '.', sizeof (Buffer));
	Format_Text (sizeof (Buffer), Buffer, sizeof (Format), Format, 123, 123, 1, 0);
	//Convert (Buffer, 10, 123, 16);
	fwrite (Buffer, sizeof (char), sizeof (Buffer), stderr);
  return 0;
}
