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
#include<fstream>
#include"swarbst.h"
using namespace std;

struct Literal; 
typedef Literal* literalPtr;

struct Literal
	{
		string name;		
		string value;
		int length;
		int address;
		literalPtr next; 
		bool isDumped;
	};



class EXP
{
private:
	literalPtr head;
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
*** FUNCTION    : addLiteral                                         ***
************************************************************************
*** DESCRIPTION : Adds lietral in the link list						 ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
	void addLiteral(string name, string value, int length, int address);
/***********************************************************************
*** FUNCTION    : searchLiteral                                      ***
************************************************************************
*** DESCRIPTION : Searches for the literals in the link list     	 ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
	 literalPtr searchLiteral(string name);
/***********************************************************************
*** FUNCTION    : viewLiteral                                         ***
************************************************************************
*** DESCRIPTION : Displays the contents of link list				 ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
	void viewLiteral(string);

/***********************************************************************
*** FUNCTION    : dumpLiteral                                        ***
************************************************************************
*** DESCRIPTION : 				 ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/

void dumpLiteral(int &lineNo,int &locCounter, string fileName);

bool static processExp(string fileName, BST *stPtr,bool adjustRFLag,string operandArray[],string expression,int &value,char charOperator,string& newRFlag);
};
#endif