/**************************************************************************************************
*** NAME       : Swarangi Joshi                                                                ***
*** CLASS      : CSc 354                                                                        ***
*** ASSIGNMENT : 2                                                                              ***
*** DUE DATE   : 10-05-16                                                                      ***
*** INSTRUCTOR : Dr. George Hamer                                                                    ***
***************************************************************************************************
*** DESCRIPTION :Implementation of Expression. functions addliteral,searchliteral and viewliteral
***************************************************************************************************/
#ifndef _SWARLIT_H
#define _SWARLIT_H
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct Literal; 
typedef Literal* literalPtr;

struct Literal
	{
		string name;		
		string value;
		int length;
		int address;
		literalPtr right; 
	};



class EXP
{

public:
/***********************************************************************
*** FUNCTION    : EXP	                                             ***
************************************************************************
*** DESCRIPTION : Default constructor								 ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
	EXP();
/***********************************************************************
*** FUNCTION    : EXP	                                              ***
************************************************************************
*** DESCRIPTION : Default destructor								 ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
	~EXP();
/***********************************************************************
*** FUNCTION    : insertLiteral                                         ***
************************************************************************
*** DESCRIPTION : Adds lietral in the linked list				     ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
	void addLiteral(literalPtr &, string name, string value, int length, int address);
/***********************************************************************
*** FUNCTION    : searchLiteral                                      ***
************************************************************************
*** DESCRIPTION : Searches for the literals in the linked list     	 ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
	literalPtr searchLiteral(literalPtr &, string name);
/***********************************************************************
*** FUNCTION    : viewLiteral                                         ***
************************************************************************
*** DESCRIPTION : Displays the contents of linked list				 ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
	void viewLiteral(literalPtr);
private:
	literalPtr head;
};
#endif