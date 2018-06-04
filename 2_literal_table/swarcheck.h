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
#include"swarbst.h"



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
/********************************************************************
*** FUNCTION  checkLiteral                                        ***
*********************************************************************
*** DESCRIPTION : checks weather the expression is Literal or not.***            
*** INPUT ARGS  :                                                 ***
*** OUTPUT ARGS : 												  ***
*** IN/OUT ARGS : name, value, string							  ***	 
*** RETURN      : bool, result									  ***
********************************************************************/
static bool checkLiteral(string &name, string &value, int &length);
/********************************************************************
*** FUNCTION  convertstrtoint                                     ***  
*********************************************************************
*** DESCRIPTION : convert string to Integer.                      ***
*** INPUT ARGS  : strValue                                        ***
*** OUTPUT ARGS : 												  *** 
*** IN/OUT ARGS : 								                  ***
*** RETURN      :int, value									      ***
********************************************************************/
static int convertstrtoint(string strValue);
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
*** FUNCTION  locate                                              ***
*********************************************************************
*** DESCRIPTION : finds a char within a string.                   ***
*** INPUT ARGS  : string, char                                    ***
*** OUTPUT ARGS : 												  *** 
*** IN/OUT ARGS : 								                  ***
*** RETURN      : bool 									          ***
********************************************************************/
static bool locate(string value, char find);
/********************************************************************
*** FUNCTION  locatechar                                          ***
*********************************************************************
*** DESCRIPTION : finds the location of a char within a string    ***
*** INPUT ARGS  : char , string                                   ***
*** OUTPUT ARGS : 												  *** 
*** IN/OUT ARGS : 								                  ***
*** RETURN      : int  									          ***
********************************************************************/
static int locatechar(char find,string lookInto);
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
/********************************************************************
*** FUNCTION: checkBinary 										  ***
*********************************************************************
*** DESCRIPTION : checks the epression for binary operators       ***
*** INPUT ARGS : N/A                                              ***
*** OUTPUT ARGS : bool                                            ***
*** IN/OUT ARGS : string bool                                     ***
*** RETURN : N/A                                                  ***
********************************************************************/
static char checkBinary(string value, bool &check);
/*********************************************************************
*** FUNCTION: checkNum                                             ***
**********************************************************************
*** DESCRIPTION : checks the epression for numbers	     		   ***
*** INPUT ARGS : N/A 											   ***
*** OUTPUT ARGS : bool 											   ***
*** IN/OUT ARGS : string 										   ***
*** RETURN : N/A  												   ***
*********************************************************************/
static bool checkNum(string value);
/********************************************************************
*** FUNCTION: checkalphabet                                       ***
*********************************************************************
*** DESCRIPTION : checks the epression for alphabets              ***
*** INPUT ARGS : N/A                                              ***
*** OUTPUT ARGS : bool                                            ***
*** IN/OUT ARGS : string                                          ***
*** RETURN : N/A                                                  ***
********************************************************************/
static bool checkalphabet(string value);
/********************************************************************
*** FUNCTION  RFlagValue                                          ***
*********************************************************************
*** DESCRIPTION : finds the reallocateability                     ***
*** INPUT ARGS  : treePtr,treePtr,char,string&,stinr&,bool*       ***                         
*** OUTPUT ARGS : 												  ***
*** IN/OUT ARGS : 								                  ***
*** RETURN      : void								              ***
********************************************************************/
static void RFlagValue(TreePtr ptr1,TreePtr ptr2, char op, string& newRFlag, string& errorMessage, bool& error);
/******************************************************************************
*** FUNCTION  checkExpression                                          ***
*******************************************************************************
*** DESCRIPTION : checks weather the expression is Valid or not.            ***
*** INPUT ARGS  : expression                                                ***
*** OUTPUT ARGS : 											                ***
*** IN/OUT ARGS : assressingType, OprandArray[], opTypeArray[], charOperator***							 
*** RETURN      : bool, result									            ***
******************************************************************************/
static bool checkExpression(string expression, bool& nBit,bool& iBit, bool& xBit, string oprandArray[], bool & adjustRFlag, char &charOperator);

	
};
#endif