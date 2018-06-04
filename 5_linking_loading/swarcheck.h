
/**************************************************************************************************
*** NAME       : Swarangi Joshi                                                                ***
*** CLASS      : CSc 354                                                                        ***
*** ASSIGNMENT : 2                                                                              ***
*** DUE DATE   : 10-05-16                                                                      ***
*** INSTRUCTOR : Dr. George Hamer                                                               ***
***************************************************************************************************
*** DESCRIPTION : This file contains the necessary error checking functions checksymbol,chekvalue etc
***************************************************************************************************/
#ifndef _SWARCHECK_H
#define _SWARCHECK_H

#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<cstring>
#include<string>
#include<sstream>





using namespace std;

class check
{
	
public:


 static void Hold(int& );
 /********************************************************************
*** FUNCTION  convertstrtoint                                     
*********************************************************************
*** DESCRIPTION : convert string to int value           
*** INPUT ARGS  : value                                    
*** OUTPUT ARGS : 												  
*** IN/OUT ARGS : 								 
*** RETURN      : string, strValue									  
********************************************************************/
 
static int convertstrtoint(string strValue);
/********************************************************************
*** FUNCTION  converthexstrtoint                                     
*********************************************************************
*** DESCRIPTION : convert hex string to int value           
*** INPUT ARGS  : value                                    
*** OUTPUT ARGS : 												  
*** IN/OUT ARGS : 								 
*** RETURN      : string, strValue									  
********************************************************************/
static int converthexstrtoint(string strValue);
/********************************************************************
*** FUNCTION  convertinttostr                                     ***  
*********************************************************************
*** DESCRIPTION : convert Integer to String.                      ***
*** INPUT ARGS  : value                                           ***
*** OUTPUT ARGS : 												  ***
*** IN/OUT ARGS : 								                  ***
*** RETURN      : string, strValue								  ***	  
********************************************************************/
static string convertinttostr(int value);
/********************************************************************
*** FUNCTION  convertinttohexstr                                  ***    
*********************************************************************
*** DESCRIPTION : convert Integer to Hexadecimel value String.    ***        
*** INPUT ARGS  : value                                           ***
*** OUTPUT ARGS : 												  ***
*** IN/OUT ARGS : 								                  ***
*** RETURN      : string, strHex								  ***  
********************************************************************/
static string convertinttohexstr(int value);
/****************************************************************************
*** FUNCTION  converttohexstr                                             ***
*****************************************************************************
*** DESCRIPTION : convert character of string to Hexadecimel value String.***            
*** INPUT ARGS  : value                                                   ***
*** OUTPUT ARGS : 												          ***
*** IN/OUT ARGS : 								                          ***
*** RETURN      : string, strHex									      ***
****************************************************************************/
static string converttohexstr(string value);
/********************************************************************
*** FUNCTION: checkHex                                           ***
*********************************************************************
*** DESCRIPTION : performs validation                             ***
*** INPUT ARGS : N/A                                              ***
*** OUTPUT ARGS : bool                                            ***
*** IN/OUT ARGS : string                                          ***
*** RETURN : N/A                                                  ***
********************************************************************/
static bool checkHex(string name, string value);
;
	
};
#endif