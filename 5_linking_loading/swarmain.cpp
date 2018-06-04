/**************************************************************************************************
*** NAME       : Swarangi Joshi                                                                ***
*** CLASS      : CSc 354                                                                        ***
*** ASSIGNMENT : 5                                                                            ***
*** DUE DATE   : 12-14-16                                                                      ***
*** INSTRUCTOR : Dr. George Hamer                                                                    ***
**************************************************************************************************
*** DESCRIPTION :Inplementation of Linker/Loader module. Text record processing, mordification ***
***				: record proceesing, printMemory operations are done in this file.             *** 
**************************************************************************************************/
#include "swarlink.h"
#include<string>

int main(int argc, char *argv[])
{
		
		LINK linkerloader("03860",argc);
		linkerloader.passOne(argv);
		linkerloader.passTwo(argv,argc);
	
	return 0;
}
