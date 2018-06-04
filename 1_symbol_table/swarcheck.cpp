/**************************************************************************************************
*** NAME       : Swarangi Joshi                                                                ***
*** CLASS      : CSc 354                                                                        ***
*** ASSIGNMENT : 1                                                                              ***
*** DUE DATE   : 9-14-16                                                                      ***
*** INSTRUCTOR : Dr. George Hamer                                                                    ***
***************************************************************************************************
*** DESCRIPTION : This program checks whether the symbol,value and rflag are valid or invalid.
***************************************************************************************************/
#include "swarcheck.h"

using namespace std;

/********************************************************************
*** FUNCTION  checksymbol		                                  ***
*********************************************************************
*** DESCRIPTION : Checks the symbol whether it is valid or not	 ***
*** INPUT ARGS  : symbol     							         ***
*** OUTPUT ARGS : none											 ***
*** IN/OUT ARGS :        										 ***
*** RETURN      : result									     ***
********************************************************************/
bool check::checksymbol(string& symbol)
{
	bool result= true;
	int i=1;

	if(symbol.length() >10)
	{
		cout << "  Error - symbol: " << symbol<< " excedds the maximum of 10 characters" <<endl;
		result = false;
		return result;
		
	}

	else
	{
       if(!isalpha(symbol[0])) 
		{
			cout << "  Error - symbol: " <<symbol<<" must start with A...Z or a...z"<<endl;
			result = false;
			return result;
			
		}
			
		for(i=1;i<symbol.length();i++)
		{
				if(!isdigit(symbol[i]) && !isalpha(symbol[i]) && symbol[i] != '_')
				{
					cout << "  Error - symbol: " << symbol<<" must be followed by alphabets,digits or _" <<endl;
						result = false;
						break;
						
				}
        }

		if(symbol.length()>4)
			symbol = symbol.substr(0,4);
   	
	}
	return result; 
}
/********************************************************************
*** FUNCTION  checkvalue	                                       ***
*********************************************************************
*** DESCRIPTION : Checks the value is signed integer or not.       ***
*** INPUT ARGS  : value 									       ***
*** OUTPUT ARGS : 												   ***
*** IN/OUT ARGS :       										   ***
*** RETURN      : result							               ***
********************************************************************/
bool check::checkvalue(string& value){
	bool result = true;
	if(value[0]=='-' || value[0]=='+' || isdigit(value[0]))
	{
		for(int i=1;i<value.length();i++)
		{
			if(!isdigit(value[i]))
			{
				if(value[i]=='.')
				{
					cout << "  Error -  value cannot be a floating point number : "<<value<<endl;
					result = false;
					break;
				}
				else if(isalpha(value[i]))
				{
					cout << "  Error - value has to be an number: " <<value<<endl;
					result = false;
					
					break;
				}
				else
				{
					cout<<"  Error - value has to be a number: "<<value<<endl;
					result = false;
					
					break;
				}
				
				
			}
		}
	}
	else
	{
		cout<<"  Error -  value has to be a signed integer"<<value<<endl;
		result = false;
		
	}
	return result;
}
/********************************************************************
*** FUNCTION  checkrflag                                          ***
*********************************************************************
*** DESCRIPTION : Checks the rFlag is in correct format or not.   ***
*** INPUT ARGS  : rflag											  ***
*** OUTPUT ARGS : 												  ***
*** IN/OUT ARGS :  										          ***
*** RETURN      : result									      ***
********************************************************************/
bool check::checkrflag(string& rflag){
	bool result;	
	if(rflag == "TRUE" || rflag == "1" || rflag =="T" || rflag == "TRU")
	{
		rflag = "TRUE";
		result = true;
	}
	else if(rflag == "FALSE" || rflag== "0"|| rflag == "F" || rflag == "FAL")
	{
		rflag = "FALSE";
		result = true;
	}
	else
	{
		result = false;
		if(isdigit(rflag[0]))
		{			
				cout << "  Error - rflag can be defined by only 1 and 0:" <<rflag<<endl;	
                 result = false;				
		}

		else if(isalpha(rflag[0]))
		{
			cout << "  Error - only true False T F can be used to define rflag."<<rflag<<endl;
			result = false;
		}
		else
		{
			cout<<"  Error - symbol has invalid rflag: "<<rflag<<endl;
			result = false;
		}
		
	}
	return result;
}