/**************************************************************************************************
*** NAME       : Swarangi Joshi                                                                ***
*** CLASS      : CSc 354                                                                        ***
*** ASSIGNMENT : 2                                                                              ***
*** DUE DATE   : 10-05-16                                                                      ***
*** INSTRUCTOR : Dr. George Hamer                                                                    ***
***************************************************************************************************
*** DESCRIPTION : Implementation of Expression. functions addliteral,searchliteral and viewliteral
***************************************************************************************************/

#include "swarlit.h"
#include"swarbst.h"
#include"swarcheck.h"
/********************************************************************
*** FUNCTION  EXP()	                                              ***
*********************************************************************
*** DESCRIPTION : Constructor of the Class EXP                    ***
*** INPUT ARGS  : 												  ***
*** OUTPUT ARGS : 											      ***
*** IN/OUT ARGS :               			                      ***
*** RETURN      : void   				                          ***
********************************************************************/
EXP::EXP() :head(NULL)
{

}
/********************************************************************
*** FUNCTION  ~EXP                                                ***
*********************************************************************
*** DESCRIPTION : Destructor of the Class EXP                     ***
*** INPUT ARGS  : 		                                          ***
*** OUTPUT ARGS : 					                              ***
*** IN/OUT ARGS :               			                      ***
*** RETURN      : void   				                          ***
********************************************************************/
EXP::~EXP()
{	
	literalPtr temp = head;
	literalPtr literal;
	literal = head;

  while(literal != NULL)
  {
	  literal = literal->right;
	  delete temp;
      temp = literal;
  }	
}
/********************************************************************
*** FUNCTION  addLiteral                                          ***
*********************************************************************
*** DESCRIPTION : add a Literal to a Linked List                  ***
*** INPUT ARGS  : &literal,name, value, length, address		      ***                  
*** OUTPUT ARGS : 					                              ***
*** IN/OUT ARGS :               			                      ***
*** RETURN      : void   				                          ***
********************************************************************/
void EXP::addLiteral(literalPtr &literal, string name, string value, int length, int address)
{
	literalPtr newlitNode;  
	newlitNode = new Literal();
	
	newlitNode->name = name;
	newlitNode->value = value;
	newlitNode->length = length;
	newlitNode->address = address;
	newlitNode->right = NULL;

	if (head==NULL)
		head = newlitNode;
	else
	{
		literal = head;
		while (literal->right!=NULL)
		{
			literal = literal->right;
		}
		literal->right = newlitNode;
	}
}
/********************************************************************
*** FUNCTION  searchLiteral                                       ***   
*********************************************************************
*** DESCRIPTION : search the Literal in Linked List               ***
*** INPUT ARGS  : &literal,name                                   ***
*** OUTPUT ARGS : 					                              ***
*** IN/OUT ARGS :               			                      ***
*** RETURN      : 				                                  ***
********************************************************************/
literalPtr EXP::searchLiteral(literalPtr &literal, string name)
{
	literal = head;
	if(literal == NULL)
		return literal;
	else
	{		
		while (literal != NULL && literal->name != name)
		{			
			literal=literal->right;
		}
		return literal;
	}
}
/********************************************************************
*** FUNCTION  ViewLiteral                                         *** 
*********************************************************************
*** DESCRIPTION : displays the Literal Stored in Linked List      ***    
*** INPUT ARGS  : literal                                         ***                                
*** OUTPUT ARGS : 					                              ***
*** IN/OUT ARGS :               			                      ***
*** RETURN      : void   				                          ***
********************************************************************/
void EXP::viewLiteral(literalPtr literal)
{
	//literalPtr iniNode;	
	//iniNode = head;
	
	if(literal!=NULL)
	{
		viewLiteral(literal->right);
	   
		   cout<<left<<setw(20)<<literal->name<<setw(20)<<literal->value<<setw(10)<<literal->length<<setw(10)<<literal->address<<endl;
		   //literal = literal->right;
	   
	}
}