/**************************************************************************************************
*** NAME       : Swarangi Joshi                                                                ***
*** CLASS      : CSc 354                                                                        ***
*** ASSIGNMENT : 1                                                                              ***
*** DUE DATE   : 9-14-16                                                                      ***
*** INSTRUCTOR : Dr. George Hamer                                                                    ***
***************************************************************************************************
*** DESCRIPTION : This program checks whether the symbol,value and rflag are valid or invalid.
***************************************************************************************************/
#ifndef _SWARCHECK_H
#define _SWARCHECK_H

#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<cstring>
#include<string>



using namespace std;

class check
{
	
public:
/********************************************************************
*** FUNCTION  checksymbol		                                  ***
*********************************************************************
*** DESCRIPTION : Checks the symbol whether it is valid or not	 ***
*** INPUT ARGS  : symbol     							         ***
*** OUTPUT ARGS : none											 ***
*** IN/OUT ARGS :        										 ***
*** RETURN      : result									     ***
********************************************************************/
	static bool checksymbol(string &symbol);
/********************************************************************
*** FUNCTION  checkvalue	                                       ***
*********************************************************************
*** DESCRIPTION : Checks the value is signed integer or not.       ***
*** INPUT ARGS  : value 									       ***
*** OUTPUT ARGS : 												   ***
*** IN/OUT ARGS :       										   ***
*** RETURN      : result							               ***
********************************************************************/
    static bool checkvalue(string &value);
/********************************************************************
*** FUNCTION  checkRFlag                                          ***
*********************************************************************
*** DESCRIPTION : Checks the rFlag is in correct format or not.   ***
*** INPUT ARGS  : rflag											  ***
*** OUTPUT ARGS : 												  ***
*** IN/OUT ARGS :  										          ***
*** RETURN      : result									      ***
********************************************************************/
	static bool checkrflag(string &rflag);
	
};
#endif