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
/********************************************************************
*** FUNCTION  checkLiteral                                        ***
*********************************************************************
*** DESCRIPTION : checks weather the expression is Literal or not.***            
*** INPUT ARGS  :                                                 ***
*** OUTPUT ARGS : 												  ***
*** IN/OUT ARGS : name, value, string							  ***	 
*** RETURN      : bool, result									  ***
********************************************************************/
bool check::checkLiteral(string &name, string &value, int &length)
{
	bool result = true;;
	value=" ";
	length=0;
	string tempName = name;
	if(name[0]=='=')
	{
		if(name[2]=='\'' && name[name.length()-1]=='\'')
		{
			name[1] = toupper(name[1]);
			switch(name[1])
			{
			case 'X':
				value = name.substr(3,name.length()-4);

				if(!checkHex(name,value)){
						result = false;
						break;
				}				
				for (int i=0; i<value.length(); i++) 
	           {
		         value[i]=toupper(value[i]);
	           }
				length = value.length();
				if(length%2 != 0){
					cout << "  Error the hex literal " << tempName << "  has odd number of bytes. " << endl;
					result = false;
					break;
				}
				length = (int) length/2;
				for (int i=0; i<name.length(); i++) // converting name to uppercase
	           {
		         name[i]=toupper(name[i]);
	           }
				break;

				
			case 'C':				
				value = converttohexstr(name.substr(3, name.length()-4));
				length = (name.length()-4);
				break;
			default:
				cout<<"  ERROR - Literal: "<<name<<"  must be character or hexadecimal."<<endl;
				result = false;
			}
		} // else if statement to check bound by ' ' 
		else{
			cout << "  ERROR - Literal: " <<name << " must be enclosed by ' ' " <<endl;
			result = false;
		}
	} // out most if
	else
		result = false;
	return result;
}
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
	string strHex;
	stringstream strStream;
	strStream<<hex<<value;
	strHex = strStream.str();
	return strHex;
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

/********************************************************************
*** FUNCTION  locate                                              ***
*********************************************************************
*** DESCRIPTION : finds a char within a string.                   ***
*** INPUT ARGS  : string, char                                    ***
*** OUTPUT ARGS : 												  *** 
*** IN/OUT ARGS : 								                  ***
*** RETURN      : bool 									          ***
********************************************************************/
bool check::locate(string value, char find)
{

	for(int i = 0 ; i < value.length(); i++){

		if(value[i] == find){
			return true;
			break;
		}
	}
	
		 
	return false;

}

/********************************************************************
*** FUNCTION  locatechar                                          ***
*********************************************************************
*** DESCRIPTION : finds the location of a char within a string    ***
*** INPUT ARGS  : char , string                                   ***
*** OUTPUT ARGS : 												  *** 
*** IN/OUT ARGS : 								                  ***
*** RETURN      : int  									          ***
********************************************************************/
int check::locatechar(char find,string lookInto)
{
	int i = 0;
	for (i ; i < lookInto.length();i++)
	{
		if(lookInto[i] == find)
		{
			break;
		}

		
	}
	return i;
}
/********************************************************************
*** FUNCTION: checkHex                                           ***
*********************************************************************
*** DESCRIPTION : performs validation                             ***
*** INPUT ARGS : N/A                                              ***
*** OUTPUT ARGS : bool                                            ***
*** IN/OUT ARGS : string                                          ***
*** RETURN : N/A                                                  ***
********************************************************************/
bool check::checkHex(string name, string value)
{
	bool check = true;

	//converting to upper

	for (int i=0; i<value.length(); i++) 
	           {
		         value[i]=toupper(value[i]);
	           }

	if (value[0] == '-' || value[0] == '+' || (value[0] >= '0' && value[0] <= '9') || (value[0] >= 'A' || value[0] <= 'F'))
	{
		for (int a = 1; a < value.size(); a++)
		{
			if ((value[a] < '0' || value[a] > '9') && (value[a] < 'A' || value[a] > 'F'))
			{
				check = false;

				cout << " ERROR - Invalid Hex Literal(invalid content): " << value[a] << endl;

				return check;

			}

		}// end for
	} // end if
	else if (value[0] == ' ')
	{
		check = false;

		cout << " ERROR - Invalid Hex Literal(no space requred) : " << value[0] << endl;

	}
	else
	{
		check = false;
	}
	return check;
}
/********************************************************************
*** FUNCTION: checkBinary 										  ***
*********************************************************************
*** DESCRIPTION : checks the epression for binary operators       ***
*** INPUT ARGS : N/A                                              ***
*** OUTPUT ARGS : bool                                            ***
*** IN/OUT ARGS : string bool                                     ***
*** RETURN : N/A                                                  ***
********************************************************************/
char check::checkBinary(string value, bool &check)
{
	string temp = value;
	char nil = '\0';

	if (value[0] == '@' || value[0] == '#')
	{
		if (value[1] == '+' || value[1] == '-')
		{
			if (isalpha(value[2]))
			{
				check = false;
				return nil;
			}
			temp = value.substr(2, value.length() - 1);
		}


		for (int i = 0; i < temp.length(); i++)
		{
			if (temp[i] == '+')	 return '+';
			else if (temp[i] == '-') return '-';

		}
	}
	else if (isdigit(value[0]) || isalpha(value[0]))
	{
		for (int i = 0; i < value.length(); i++)
		{
			if (value[i] == '+') return '+';
			else if (value[i] == '-') return '-';

		}
	}
	else if (value[0] == '+' || value[0] == '-')
	{
		for (int i = 1; i < temp.length(); i++)
		{
			if (temp[i] == '+')  return '+';
			else if (temp[i] == '-') return '-';
		}
    }
	return nil;
}
/*********************************************************************
*** FUNCTION: checkNum                                             ***
**********************************************************************
*** DESCRIPTION : checks the epression for numbers	     		   ***
*** INPUT ARGS : N/A 											   ***
*** OUTPUT ARGS : bool 											   ***
*** IN/OUT ARGS : string 										   ***
*** RETURN : N/A  												   ***
*********************************************************************/
bool check::checkNum(string value)
{
	bool result;
	result = true;
	if (value[0] == '-' || value[0] == '+' || isdigit(value[0]))
	{
		for (int i = 1; i < value.size(); ++i)
		{
			if (!isdigit(value[i]))
			{
				result = false;
				break;
			}
		}
	}
	else
		result = false;
	return result;
}
/********************************************************************
*** FUNCTION: checkalphabet                                       ***
*********************************************************************
*** DESCRIPTION : checks the epression for alphabets              ***
*** INPUT ARGS : N/A                                              ***
*** OUTPUT ARGS : bool                                            ***
*** IN/OUT ARGS : string                                          ***
*** RETURN : N/A                                                  ***
********************************************************************/
bool check::checkalphabet(string value)
{
	bool result;
	result = true;
	if(value[0]=='_' || isalpha(value[0]))
	{
		for(int i = 1; i < value.size(); ++i)
		{
			if(!isalpha(value[0]) || value[0]=='_'  )
			{
				result = false;
				break;
			}
		}
	}
	else
		result = false;

	return result;
}
/********************************************************************
*** FUNCTION  RFlagValue                                          ***
*********************************************************************
*** DESCRIPTION : finds the reallocateability                     ***
*** INPUT ARGS  : treePtr,treePtr,char,string&,stinr&,bool*       ***                         
*** OUTPUT ARGS : 												  ***
*** IN/OUT ARGS : 								                  ***
*** RETURN      : void								              ***
********************************************************************/
void check::RFlagValue(TreePtr ptr1,TreePtr ptr2, char op, string& newRFlag, string& errorMessage, bool& error){

	bool a = ptr1->rflag; 
	bool b = ptr2->rflag;

	switch(op)
	{

		case '+':
			if( ptr1->rflag == 0 && ptr2->rflag == 0)
				newRFlag  = " ABSOLUTE";
			else if( ptr1->rflag == 0 && ptr2->rflag ==1)
				newRFlag = " RELATIVE";
			else if( ptr1->rflag == 1 && ptr2->rflag == 0)
				newRFlag = " RELATIVE";
			else if( ptr1->rflag == 1 && ptr2->rflag== 1){
				error = true ; 
				errorMessage = "  Error : " + ptr1->symbol + " + " + ptr2->symbol + "  Relative + Relative" ;
			}

			break;

		case '-':
			if( a == 0 && b == 0)
				newRFlag  = " ABSOLUTE";
			else if( a == 0 && b ==1){				
				error = true ; 
				errorMessage = "  Error : " + ptr1->symbol + " - " + ptr2->symbol + "  Absolute - Relative" ;
			}
			else if( a == 1 && b == 0)
				newRFlag = " RELATIVE";
			else if( a == 1 && b== 1)
				newRFlag = " ABSOLUTE";
			break;

		case ',':
			break;

		default:

			cout << "  ERROR : Invalid operatore used : " << op << endl;


			  
	}
}
/******************************************************************************
*** FUNCTION  checkExpression                                          ***
*******************************************************************************
*** DESCRIPTION : checks weather the expression is Valid or not.            ***
*** INPUT ARGS  : expression                                                ***
*** OUTPUT ARGS : 											                ***
*** IN/OUT ARGS : assressingType, OprandArray[], opTypeArray[], charOperator***							 
*** RETURN      : bool, result									            ***
******************************************************************************/
bool check::checkExpression(string expression, bool& nBit,bool& iBit, bool& xBit, string oprandArray[], bool & adjustRFlag, char &charOperator)
{
	bool result = true,
		 valueUnary = true;
	char binaryOperator = ' ';
	int divide = 0;
	int operands = 0;
	int comma = 0;
	int addressing = 0;
	char a;
	int line;
	

	// to assing correct value if two value are presented and to remove @ #
	string tempExp = " ",
		   unsignedExp = " ";

	 if( result)
	 {

		for(int i = 0 ; i < expression.length(); i++){

			if(expression[i] == '+' || expression[i] == '-'){
					operands++; 
			}
			if(expression[i] == ','){
				comma++;
			}
			if(expression[i] == '@'||expression[i]=='#'){
				addressing++;
			}
		}

		if(addressing>1)
		{

			result = false;
			cout << "  Error - expression: " << expression << " can't combine addressing mode." <<endl;
			 line++;
			if(line == 20)
			   {   
		           cout << "  Input any key  to continue:  " ;
					cin >> a;
					cin.clear();
					line = 1;
			   }
	}
		}

		else if(operands > 3){

			result = false; 
			cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
			  line++;
			   if(line == 20)
			   {   
		           cout << "  Input any key  to continue:  " ;
					cin >> a;
					cin.clear();
					line = 1;
			   }

		}

		else if( operands > 0 && comma > 0)
		{

			result = false;
			cout << "  Error - expression: " << expression << " can't combine indexing with uniary/binary operations. " << endl;
			    line++;
			   if(line == 20)
			   {   
		           cout << "  Input any key to continue:  " ;
					cin >> a;
					cin.clear();
					line = 1;
			   }
	}
			

		

	 // only if two operands per expersiion
  if(result)
  {
   
	 if((locate(expression,'*'))||(locate(expression,'/'))||(locate(expression,'%')))
	 {
			cout << "  Error - expression: " << expression <<" only supports + and - operation"<<endl;
			line++;
			   if(line == 20)
			   {   
		           cout << "  Input any key to continue:  " ;
					cin >> a;
					cin.clear();
					line = 1;
			   }
			result = false;			
	}
	

	 else if(expression[0] == '@')
	 {
		nBit = true;	
		tempExp = expression.substr(divide+1,(expression.length()-1));

		binaryOperator = checkBinary(expression,valueUnary);
		
		if(!valueUnary)
		{
			result = false;
			cout << "  Error- expression: " << expression << "  uniary operation can't be used with value."<<endl;
			
		}

		else if(binaryOperator =='+')
		{

			adjustRFlag = true;
			charOperator = '+';
			
			if(tempExp[0] == '+'||tempExp[0] =='-')
			{
				
				divide = locatechar(charOperator, tempExp.substr(1,tempExp.length()-1));
				oprandArray[0] = tempExp.substr(0,divide+1) ;				
				oprandArray[1] = tempExp.substr(divide+2,(tempExp.length()-1));
			}

			else
			{
			divide = locatechar(charOperator,tempExp);
			oprandArray[0] = tempExp.substr(0,divide) ;				
			oprandArray[1] = tempExp.substr(divide+1,(tempExp.length()-1));
			}
			
			if((locate(oprandArray[1],',')))
			{
				result = false; 
				std::cout << "  Error - expression: " << expression << " indexing can't be done with immediate addressing" << endl;
				
			}

			// unary operation present
			else if((locate(oprandArray[1],'+'))||(locate(oprandArray[1],'-')))
			{
				string temp  = " " ; 
				temp = oprandArray[1]; 
				

				if(locate(temp,'+'))
				{
					int loc = locatechar('+',temp);
					if(loc == 0){
						if(isalpha(temp[1]))
						{
							result = false;
							cout << "  Error - expression: " <<expression << " unary operation used with value" <<endl;
							
						}

						else if(isdigit(temp[1]))
						{
							temp = temp.substr(1,temp.length()-1);

							if(locate(temp,'+')||locate(temp,'-'))
							{

								result = false; 
								cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
								
							}

							else if(locate(temp,','))
							{
								result = false; 
								cout << "  Error - expression: " << expression << " improper indexing" << endl;
								
							}

						}
						else
						{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
						}
					} // if unary operation is used loc ==o

					// not a unary opeartion
					else
					{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
					}

				}

				// if found -ve sign with in divide value/number
				else if(locate(temp,'-'))
				{
					int loc = locatechar('-',temp);
					if(loc == 0){
						if(isalpha(temp[1]))
						{
							result = false;
							cout << "  Error - expression: " <<expression << " unary operation used with value" <<endl;
							
						}

						else if(isdigit(temp[1]))
						{
							temp = temp.substr(1,temp.length()-1);

							if(locate(temp,'+')||locate(temp,'-'))
							{

								result = false; 
								cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
								
							}

						else if(locate(temp,','))
						{
								result = false; 
								cout << "  Error - expression: " << expression << " improper indexing" << endl;
								
						}

						}
						else
						{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
						}
					} // if unary operation is used

					// not a unary opeartion
					else
					{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
					}

				}
			}// unary operation is present in divide expression		
			

		}
		else if(binaryOperator == '-')
		{
			charOperator = '-';
			adjustRFlag = true;			
			
			if(tempExp[0] == '+'||tempExp[0] =='-')
			{
				
				divide = locatechar(charOperator, tempExp.substr(1,tempExp.length()-1));
				oprandArray[0] = tempExp.substr(0,divide+1) ;				
				oprandArray[1] = tempExp.substr(divide+2,(tempExp.length()-1));
			}

			else
			{
			divide = locatechar(charOperator,tempExp);
			oprandArray[0] = tempExp.substr(0,divide) ;				
			oprandArray[1] = tempExp.substr(divide+1,(tempExp.length()-1));
			}
			
			if((locate(oprandArray[1],',')))
			{
				result = false; 
				std::cout << "  Error - expression: " << expression << " indexing can't be done with immediate addressing" << endl;
				
			}

			// unary operation present
			else if((locate(oprandArray[1],'+'))||(locate(oprandArray[1],'-')))
			{
				string temp  = " " ; 
				temp = oprandArray[1]; 
				

				if(locate(temp,'+'))
				{
					int loc = locatechar('+',temp);
					if(loc == 0)
					{
						if(isalpha(temp[1]))
						{
							result = false;
							cout << "  Error - expression: " <<expression << " unary operation used with value" <<endl;
							
						}

						else if(isdigit(temp[1]))
						{
							temp = temp.substr(1,temp.length()-1);

							if(locate(temp,'+')||locate(temp,'-'))
							{

								result = false; 
								cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
								
							}

							else if(locate(temp,','))
							{
								result = false; 
								cout << "  Error - expression: " << expression << " improper indexing" << endl;
								
							}

						}
						else
						{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
						}
					} // if unary operation is used loc ==o

					// not a unary opeartion
					else
					{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
					}

				}

				// if found -ve sign with in divide value/number
				else if(locate(temp,'-'))
				{
					int loc = locatechar('-',temp);
					if(loc == 0){
						if(isalpha(temp[1]))
						{
							result = false;
							cout << "  Error - expression: " <<expression << " unary operation used with value" <<endl;
							
						}

						else if(isdigit(temp[1]))
						{
							temp = temp.substr(1,temp.length()-1);

							if(locate(temp,'+')||locate(temp,'-'))
							{

								result = false; 
								cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
								
							}

							else if(locate(temp,','))
							{
								result = false; 
								cout << "  Error - expression: " << expression << " improper indexing" << endl;
								
							}

						}
						else
						{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
						}
					} // if unary operation is used

					// not a unary opeartion
					else
					{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
					}

				}
			}// unary operation is present in divide expression		
		}

		else if((locate(tempExp,',')))
		{
			
			cout << "  Error - expression : " << expression << "  indirect addressing can't be done with indexing. " <<endl;
			result = false;
			
			

		}		

		else
			{
				oprandArray[0] = tempExp;
		}
	 }
		
	// indirect

	else if(expression[0] == '#')
	{
		iBit = true;
		tempExp = expression.substr(divide+1,(expression.length()-1));
		binaryOperator = checkBinary(expression,valueUnary);

		if(!valueUnary){
			result = false;
			cout << "  Error- expression: " << expression << "  uniary operation can't be used with value."<<endl;
			
		}

		else if(binaryOperator == '+'){
			adjustRFlag = true;
			charOperator = '+';

			if(tempExp[0] == '+'||tempExp[0] =='-'){
				
				divide = locatechar(charOperator, tempExp.substr(1,tempExp.length()-1));
				oprandArray[0] = tempExp.substr(0,divide+1) ;				
				oprandArray[1] = tempExp.substr(divide+2,(tempExp.length()-1));
			}

			else{
			divide = locatechar(charOperator,tempExp);
			oprandArray[0] = tempExp.substr(0,divide) ;				
			oprandArray[1] = tempExp.substr(divide+1,(tempExp.length()-1));
			}

			if((locate(oprandArray[1],','))){
				result = false; 
				std::cout << "  Error - expression: " << expression << " indexing can't be done with immediate addressing" << endl;
				
			}

			// unary operation present
			else if((locate(oprandArray[1],'+'))||(locate(oprandArray[1],'-'))){
				string temp  = " " ; 
				temp = oprandArray[1]; 
				

				if(locate(temp,'+')){
					int loc = locatechar('+',temp);
					if(loc == 0){
						if(isalpha(temp[1])){
							result = false;
							cout << "  Error - expression: " <<expression << " unary operation used with value" <<endl;
							
						}

						else if(isdigit(temp[1])){
							temp = temp.substr(1,temp.length()-1);

							if(locate(temp,'+')||locate(temp,'-')){

								result = false; 
								cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
								
							}

						else if(locate(temp,',')){
								result = false; 
								cout << "  Error - expression: " << expression << " improper indexing" << endl;
								
							}

						}
						else{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
						}
					} // if unary operation is used loc ==o

					// not a unary opeartion
					else{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
					}

				}

				// if found -ve sign with in divide value/number
				else if(locate(temp,'-')){
					int loc = locatechar('-',temp);
					if(loc == 0){
						if(isalpha(temp[1])){
							result = false;
							cout << "  Error - expression: " <<expression << " unary operation used with value" <<endl;
							
						}

						else if(isdigit(temp[1])){
							temp = temp.substr(1,temp.length()-1);

							if(locate(temp,'+')||locate(temp,'-')){

								result = false; 
								cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
								
							}

						else if(locate(temp,',')){
								result = false; 
								cout << "  Error - expression: " << expression << " improper indexing" << endl;
								
							}

						}
						else{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
						}
					} // if unary operation is used

					// not a unary opeartion
					else{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
					}

				}
			}// unary operation is present in divide expression		
		}

		else if((binaryOperator=='-')){
			charOperator = '-';
			adjustRFlag = true;

			
			if(tempExp[0] == '+'||tempExp[0] =='-'){
				
				divide = locatechar(charOperator, tempExp.substr(1,tempExp.length()-1));
				oprandArray[0] = tempExp.substr(0,divide+1) ;				
				oprandArray[1] = tempExp.substr(divide+2,(tempExp.length()-1));
			}

			else{
			divide = locatechar(charOperator,tempExp);
			oprandArray[0] = tempExp.substr(0,divide) ;				
			oprandArray[1] = tempExp.substr(divide+1,(tempExp.length()-1));
			}
			

			if((locate(oprandArray[1],','))){
				result = false; 
				std::cout << "  Error - expression: " << expression << " indexing can't be done with immediate addressing" << endl;
				
			}

			// unary operation present
			else if((locate(oprandArray[1],'+'))||(locate(oprandArray[1],'-'))){
				string temp  = " " ; 
				temp = oprandArray[1]; 
				

				if(locate(temp,'+')){
					int loc = locatechar('+',temp);
					if(loc == 0){
						if(isalpha(temp[1])){
							result = false;
							cout << "  Error - expression: " <<expression << " unary operation used with value" <<endl;
							
						}

						else if(isdigit(temp[1])){
							temp = temp.substr(1,temp.length()-1);

							if(locate(temp,'+')||locate(temp,'-')){

								result = false; 
								cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
								
							}

						else if(locate(temp,',')){
								result = false; 
								cout << "  Error - expression: " << expression << " improper indexing" << endl;
								
							}

						}
						else{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
						}
					} // if unary operation is used loc ==o

					// not a unary opeartion
					else{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
					}

				}

				// if found -ve sign with in divide value/number
				else if(locate(temp,'-')){
					int loc = locatechar('-',temp);
					if(loc == 0){
						if(isalpha(temp[1])){
							result = false;
							cout << "  Error - expression: " <<expression << " unary operation used with value" <<endl;
							
						}

						else if(isdigit(temp[1])){
							temp = temp.substr(1,temp.length()-1);

							if(locate(temp,'+')||locate(temp,'-')){

								result = false; 
								cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
								
							}

						else if(locate(temp,',')){
								result = false; 
								cout << "  Error - expression: " << expression << " improper indexing" << endl;
								
							}

						}
						else{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
						}
					} // if unary operation is used

					// not a unary opeartion
					else{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
					}

				}
			}// unary operation is present in divide expression		
		}

		else if((locate(expression,','))){
			cout << "  Error - expression : " << expression << "  immediate addressing can't be done with indexing. " <<endl;
			result = false;
			
		}

		else
			{
			oprandArray[0] = tempExp;
		}

	}// end of immediate

	else  if(isalpha(expression[0]))
	{
		nBit = iBit = true;

		binaryOperator = checkBinary(expression,valueUnary);

		if((binaryOperator=='+'))
		{
			adjustRFlag = true;
			charOperator = '+';
			divide = locatechar(charOperator,expression);
			oprandArray[0] = expression.substr(0,divide) ;				
			oprandArray[1] = expression.substr(divide+1,(expression.length()-1));

			if((locate(oprandArray[1],'+'))||(locate(oprandArray[1],'-'))||(locate(oprandArray[1],','))){
				string temp  = " " ; 
				temp = oprandArray[1]; 

				if(locate(temp,',')){
				result = false; 
				cout << "  Error - expression: " << expression << " improper indexing" << endl;
				
				}

				else if(locate(temp,'+')){
					int loc = locatechar('+',temp);
					if(loc == 0){
						if(isalpha(temp[1])){
							result = false;
							cout << "  Error - expression: " <<expression << " unary operation used with value" <<endl;
							
						}

						else if(isdigit(temp[1])){
							temp = temp.substr(1,temp.length()-1);

							if(locate(temp,'+')||locate(temp,'-')){

								result = false; 
								cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
								
							}

						else if(locate(temp,',')){
								result = false; 
								cout << "  Error - expression: " << expression << " improper indexing" << endl;
								
							}

						}
						else{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
						}
					} // if unary operation is used

					// not a unary opeartion
					else{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
					}

				}

				else if(locate(temp,'-')){
					int loc = locatechar('-',temp);
					if(loc == 0){
						if(isalpha(temp[1])){
							result = false;
							cout << "  Error - expression: " <<expression << " unary operation used with value" <<endl;
							
						}

						else if(isdigit(temp[1])){
							temp = temp.substr(1,temp.length()-1);

							if(locate(temp,'+')||locate(temp,'-')){

								result = false; 
								cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
								
							}

						else if(locate(temp,',')){
								result = false; 
								cout << "  Error - expression: " << expression << " improper indexing" << endl;
								
							}

						}
						else{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
						}
					} // if unary operation is used

					// not a unary opeartion
					else{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
					}

				}
			}

		}
		else if((binaryOperator=='-')){
			charOperator = '-';
			adjustRFlag = true;
			divide = locatechar(charOperator,expression);
			oprandArray[0] = expression.substr(0,divide) ;				
			oprandArray[1] = expression.substr(divide+1,(expression.length()-1));

			if((locate(oprandArray[1],'+'))||(locate(oprandArray[1],'-'))||(locate(oprandArray[1],','))){
				
				string temp  = " " ; 
				temp = oprandArray[1]; 

				if(locate(temp,',')){
				result = false; 
				cout << "  Error - expression: " << expression << " improper indexing" << endl;
				
				}

				else if(locate(temp,'+')){
					int loc = locatechar('+',temp);
					if(loc == 0){
						if(isalpha(temp[1])){
							result = false;
							cout << "  Error - expression: " <<expression << " unary operation used with value" <<endl;
							
						}

						else if(isdigit(temp[1])){
							temp = temp.substr(1,temp.length()-1);

							if(locate(temp,'+')||locate(temp,'-')){

								result = false; 
								cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
								
							}

						else if(locate(temp,',')){
								result = false; 
								cout << "  Error - expression: " << expression << " improper indexing" << endl;
								
							}

						}
						else{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
						}
					} // if unary operation is used

					// not a unary opeartion
					else{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
					}

				}

				else if(locate(temp,'-')){
					int loc = locatechar('-',temp);
					if(loc == 0){
						if(isalpha(temp[1])){
							result = false;
							cout << "  Error - expression: " <<expression << " unary operation used with value" <<endl;
							
						}

						else if(isdigit(temp[1])){
							temp = temp.substr(1,temp.length()-1);

							if(locate(temp,'+')||locate(temp,'-')){

								result = false; 
								cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
								
							}

						else if(locate(temp,',')){
								result = false; 
								cout << "  Error - expression: " << expression << " improper indexing" << endl;
								
							}

						}
						else{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
						}
					} // if unary operation is used

					// not a unary opeartion
					else{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
					}

				}
			}
		}

		else if((locate(expression,','))){
			charOperator = ',';
			adjustRFlag = true;
			xBit = true;
			divide = locatechar(charOperator,expression);
			oprandArray[0] = expression.substr(0,divide) ;				
			oprandArray[1] = expression.substr((divide+1),(expression.length()-1));
			if(checkNum(oprandArray[0]) || checkNum(oprandArray[1])){

				cout << "  Error - expression : " << expression << "  illegal indexing, can't be done with number. " <<endl;
				result = false;
				
			}

			else if((locate(oprandArray[1],'+'))||(locate(oprandArray[1],'-'))||(locate(oprandArray[1],','))){
				result = false; 
				cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
				
			}
		}

		else{
			oprandArray[0] = expression;
		}
	}// end of value at first

	// expression starts with digits
	else if( isdigit(expression[0])){
		iBit = true;		

		binaryOperator = checkBinary(expression,valueUnary);

		if((binaryOperator=='+')){
			adjustRFlag = true;
			charOperator = '+';
			divide = locatechar(charOperator,expression);
			oprandArray[0] = expression.substr(0,divide) ;				
			oprandArray[1] = expression.substr(divide+1,(expression.length()-1));
			if((locate(oprandArray[1],','))){
				result = false; 
				std::cout << "  Error - expression: " << expression << " indexing can't be done with immediate addressing" << endl;
				
			}

			// unary operation present
			else if((locate(oprandArray[1],'+'))||(locate(oprandArray[1],'-'))){
				string temp  = " " ; 
				temp = oprandArray[1]; 
				

				if(locate(temp,'+')){
					int loc = locatechar('+',temp);
					if(loc == 0){
						if(isalpha(temp[1])){
							result = false;
							cout << "  Error - expression: " <<expression << " unary operation used with value" <<endl;
							
						}

						else if(isdigit(temp[1])){
							temp = temp.substr(1,temp.length()-1);

							if(locate(temp,'+')||locate(temp,'-')){

								result = false; 
								cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
								
							}

						else if(locate(temp,',')){
								result = false; 
								cout << "  Error - expression: " << expression << " improper indexing" << endl;
								
							}

						}
						else
						{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
						}
					} // if unary operation is used loc ==o

					// not a unary opeartion
					else
					{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
					}

				}

				// if found -ve sign with in divide value/number
				else if(locate(temp,'-'))
				{
					int loc = locatechar('-',temp);
					if(loc == 0)
					{
						if(isalpha(temp[1]))
						{
							result = false;
							cout << "  Error - expression: " <<expression << " unary operation used with value" <<endl;
							
						}

						else if(isdigit(temp[1]))
						{
							temp = temp.substr(1,temp.length()-1);

							if(locate(temp,'+')||locate(temp,'-'))
							{

								result = false; 
								cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
								
							}

							else if(locate(temp,','))
							{
								result = false; 
								cout << "  Error - expression: " << expression << " improper indexing" << endl;
								
							}

						}
						else
						{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
						}
					} // if unary operation is used

					// not a unary opeartion
					else
					{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
					}

				}
			}// unary operation is present in divide expression		
		}
		else if(binaryOperator=='-')
		{
			charOperator = '-';
			adjustRFlag = true;
			divide = locatechar(charOperator,expression);
			oprandArray[0] = expression.substr(0,divide) ;				
			oprandArray[1] = expression.substr(divide+1,(expression.length()-1));
			
			if((locate(oprandArray[1],',')))
			{
				result = false; 
				std::cout << "  Error - expression: " << expression << " indexing can't be done with immediate addressing" << endl;
				
			}

			// unary operation present
			else if((locate(oprandArray[1],'+'))||(locate(oprandArray[1],'-')))
			{
				string temp  = " " ; 
				temp = oprandArray[1]; 
				

				if(locate(temp,'+'))
				{
					int loc = locatechar('+',temp);
					if(loc == 0){
						if(isalpha(temp[1]))
						{
							result = false;
							cout << "  Error - expression: " <<expression << " unary operation used with value" <<endl;
							
						}

						else if(isdigit(temp[1]))
						{
							temp = temp.substr(1,temp.length()-1);

							if(locate(temp,'+')||locate(temp,'-'))
							{

								result = false; 
								cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
								
							}

							else if(locate(temp,','))
							{
								result = false; 
								cout << "  Error - expression: " << expression << " improper indexing" << endl;
								
							}

						}
						else
						{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
						}
					} // if unary operation is used loc ==o

					// not a unary opeartion
					else
					{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
					}

				}

				// if found -ve sign with in divide value/number
				else if(locate(temp,'-'))
				{
					int loc = locatechar('-',temp);
					if(loc == 0)
					{
						if(isalpha(temp[1]))
						{
							result = false;
							cout << "  Error - expression: " <<expression << " unary operation used with value" <<endl;
							
						}

						else if(isdigit(temp[1]))
						{
							temp = temp.substr(1,temp.length()-1);

							if(locate(temp,'+')||locate(temp,'-'))
							{

								result = false; 
								cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
								
							}

							else if(locate(temp,','))
							{
								result = false; 
								cout << "  Error - expression: " << expression << " improper indexing" << endl;
								
							}

						}
						else
						{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
						}
					} // if unary operation is used

					// not a unary opeartion
					else
					{
							result = false; 
							cout << "  Error - expression: " << expression << " Maximum of two values/operands per expression" << endl;
							
					}

				}
			}// unary operation is present in divide expression		
		}

		else if((locate(expression,',')))
		{
			
			cout << "  Error - expression " << expression << " Invalid indexing with a number" << endl;
			result = false;
			
		}

		else
		{
			oprandArray[0] = expression;
		}

	} // digit at first

	// invalid literal ignore 
	else if (expression[0] == '=')
	{

		result = false;
	}// invalid literal 
	

	// if signed integer in present in expression

	else if((expression[0] == '+' )||(expression[0] == '-'))
	{

		iBit = true;
		unsignedExp = expression.substr(1,expression.length()); 
		
		 if(operands == 1)
		 {
			adjustRFlag = false;
			oprandArray [0] = expression;
		
			if(isalpha(expression[1]))
			{
				result = false;
				cout << "  Error -  Invalid expression " << expression << "  a value operand can't have unary operation." <<endl;
				
			}

		 }
		

		else if(operands ==2){

			if(isalpha(expression[1]))
			{
				result = false;
				cout << "  Error -  Invalid expression " << expression << "  a value operand can't have unary operation." <<endl;
				
			}

			else
			{

			if(locate(unsignedExp,'+'))
			{

				charOperator = '+';
				adjustRFlag = true;
				divide = locatechar(charOperator,unsignedExp);
				oprandArray[0] = expression.substr(0,divide+1) ;				
				oprandArray[1] = expression.substr(divide+2,(expression.length()-1));	

				
			} // + operator

			else if(locate(unsignedExp,'-'))
			{

				charOperator = '-';
				adjustRFlag = true;
				divide = locatechar(charOperator,unsignedExp);
				oprandArray[0] = expression.substr(0,divide+1) ;				
				oprandArray[1] = expression.substr(divide+2,(expression.length()-1));			

			}// char operator == -

		  }// second char is digit 

		}// two charOperator present

		// 3 charOperator Present
		else if(operands == 3)
		{

			binaryOperator = checkBinary(expression,valueUnary);

			if(isalpha(expression[1]))
			{
				result = false;
				cout << "  Error -  Invalid expression " << expression << "  a value operand can't have unary operation." <<endl;
				
			}

			
		else
		{

			if(binaryOperator=='+')
			{

				charOperator = '+';
				adjustRFlag = true;
				divide = locatechar(charOperator,unsignedExp);
				oprandArray[0] = expression.substr(0,divide+1) ;				
				oprandArray[1] = expression.substr(divide+2,(expression.length()-1));	

				if(isalpha(expression[divide+3]))
				{
					result = false;
					cout << "  Error -  Invalid expression " << expression << "  a value operand can't have unary operation." <<endl;
					
				}
				else if(!isdigit(expression[divide+3]))
				{
					result = false; 
					cout << "  Error -  Invalid expression " << expression << " only number can follow after unary operation." <<endl;
					
				}
			} // + operator

				else if(binaryOperator=='-')
				{

				charOperator = '-';
				adjustRFlag = true;
				divide = locatechar(charOperator,unsignedExp);
				oprandArray[0] = expression.substr(0,divide+1) ;				
				oprandArray[1] = expression.substr(divide+2,(expression.length()-1));			

				if(isalpha(expression[divide+3]))
				{
					result = false;
					cout << "  Error -  Invalid expression " << expression << "  a value operand can't have unary operation." <<endl;
					
				}
				else if(!isdigit(expression[divide+3]))
				{
					result = false; 
					cout << "  Error -  Invalid expression " << expression << " only number can follow after unary operation." <<endl;
					
				}
				
			}// char operator == -
		}

	    // singed integer	
	}
	}
	else 
	{
		cout << " Error-  Invalid exprssion " << expression << " Must start with @, # digit,+/-,alphabets " <<endl;
		
		result  = false;
	} // error
  }// if there are two oparands per expression
	
	return result;
}


