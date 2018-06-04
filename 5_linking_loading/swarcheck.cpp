/**************************************************************************************************
*** NAME       : Swarangi Joshi                                                                ***
*** CLASS      : CSc 354                                                                        ***
*** ASSIGNMENT : 2                                                                              ***
*** DUE DATE   : 10-05-16                                                                      ***
*** INSTRUCTOR : Dr. George Hamer                                                                    ***
***************************************************************************************************
*** DESCRIPTION : This file contains the necessary error checking functions checksymbol,chekvalue etc*** 
***************************************************************************************************/
#include "swarcheck.h"

using namespace std;


/********************************************************************
*** FUNCTION  convertstrtoint                                     ***  
*********************************************************************
*** DESCRIPTION : convert string to Integer.                      ***
*** INPUT ARGS  : strValue                                        ***
*** OUTPUT ARGS : 												  *** 
*** IN/OUT ARGS : 								                  ***
*** RETURN      :int, value									      ***
********************************************************************/
int check::convertstrtoint(string strValue)
{
	int value;
	stringstream strStream(strValue);
	strStream >> value;
	return value;
}

/********************************************************************
*** FUNCTION  convertinttostr                                     ***  
*********************************************************************
*** DESCRIPTION : convert Integer to String.                      ***
*** INPUT ARGS  : value                                           ***
*** OUTPUT ARGS : 												  ***
*** IN/OUT ARGS : 								                  ***
*** RETURN      : string, strValue								  ***	  
********************************************************************/
string check::convertinttostr(int value)
{
	
	string strValue;
	stringstream strStream;
	strStream<<value;
	strValue =strStream.str();
	return strValue;
}

/********************************************************************
*** FUNCTION  convertinttohexstr                                  ***    
*********************************************************************
*** DESCRIPTION : convert Integer to Hexadecimel value String.    ***        
*** INPUT ARGS  : value                                           ***
*** OUTPUT ARGS : 												  ***
*** IN/OUT ARGS : 								                  ***
*** RETURN      : string, strHex								  ***  
********************************************************************/
string check::convertinttohexstr(int value)
{
	stringstream stream;
  stream  << std::hex << value;
  return stream.str();
}
/****************************************************************************
*** FUNCTION  converttohexstr                                             ***
*****************************************************************************
*** DESCRIPTION : convert character of string to Hexadecimel value String.***            
*** INPUT ARGS  : value                                                   ***
*** OUTPUT ARGS : 												          ***
*** IN/OUT ARGS : 								                          ***
*** RETURN      : string, strHex									      ***
****************************************************************************/
string check::converttohexstr(string value)
{	
	string strHex="";
	for(int i = 0; i< value.length(); ++i)
	{
		strHex += convertinttohexstr((int)(value[i]));
	}
	return strHex;
}

