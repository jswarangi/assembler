/**************************************************************************************************
*** NAME       : Swarangi Joshi                                                                ***
*** CLASS      : CSc 354                                                                        ***
*** ASSIGNMENT : 5                                                                              ***
*** DUE DATE   : 12-14-16                                                                      ***
*** INSTRUCTOR : Dr. George Hamer                                                                    ***
**************************************************************************************************
*** DESCRIPTION : Header file for the Linker/Loader module. Variable and their operation are   ***
***				: declared and operation are process object files and save in layout.dat file  *** 
**************************************************************************************************/
#ifndef _SWARLINK_H
#define _SWARLINK_H

#include <string>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstdlib>

#include "swarcheck.h"
#include "swarbst.h"

using namespace std;


class LINK

{
private:
    BST *symbolTable;
	int csAddr,cslth,progaddr,execaddr,adjustCsAddr,noOfFiles,addrPreviousCS;
	bool primaryCST;
	TreePtr treeNode;
		 
	string memory;

	
public:
/********************************************************************
*** FUNCTION  LINK                                         ***
*********************************************************************
*** DESCRIPTION : Consructor.***
*** INPUT ARGS  : string, int                                     ***
*** OUTPUT ARGS : none											  **
*** IN/OUT ARGS : none              							  ***
*** RETURN      : none 									          ***
********************************************************************/
	LINK(string,int );
/********************************************************************
*** FUNCTION  passOne                                         ***
*********************************************************************
*** DESCRIPTION : process external sym tabel	***
*** INPUT ARGS  : char* []                                     ***
*** OUTPUT ARGS : none											  **
*** IN/OUT ARGS : none              							  ***
*** RETURN      : none 									          ***
********************************************************************/
	void passOne(char*[]);
/********************************************************************
*** FUNCTION  passTwo	                                  ***
*********************************************************************
*** DESCRIPTION : generates memeory layout	***
*** INPUT ARGS  : char* []                                    ***
*** OUTPUT ARGS : none											  **
*** IN/OUT ARGS : none              							  ***
*** RETURN      : none 									          ***
********************************************************************/
	void passTwo(char* [],int);

};
#endif

