/**************************************************************************************************
*** NAME       : Swarangi Joshi                                                                ***
*** CLASS      : CSc 354                                                                        ***
*** ASSIGNMENT : 3                                                                              ***
*** DUE DATE   : 11-4-16                                                                       ***
*** INSTRUCTOR : Dr. George Hamer                                                                    ***
***************************************************************************************************
*** DESCRIPTION : This program is the Binary search tree implementation. It includes the basic 
                  functions of creating and destroying the binary search tree along with 
				  insert,search and view functionsfor opcode table
***************************************************************************************************/


#ifndef _SWAROPT_H
#define _SWAROPT_H

#include<iostream>
#include<iomanip>
#include<string>


using namespace std;

struct OpcodeNode
{
	string mnemonic;
	int opcode,
		format,		
		iflag;
	bool oFlag;
	OpcodeNode *left; 
	OpcodeNode *right; 
};
class OPT
{
	OpcodeNode *root;
	void insert(OpcodeNode *&, OpcodeNode *&);
	void viewNode(OpcodeNode*);
	void destroy(OpcodeNode* &);
	OpcodeNode* search(string key, OpcodeNode*&);
public:

/***********************************************************************
*** FUNCTION    : OPT	                                              ***
************************************************************************
*** DESCRIPTION : Default constructor								 ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
	OPT(void);
/***********************************************************************
*** FUNCTION    : ~OPT		                                         ***
************************************************************************
*** DESCRIPTION : Default constructor								 ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
	~OPT(void);
/***********************************************************************
*** FUNCTION    : insertOpcode                                       ***
************************************************************************
*** DESCRIPTION : Inserts opcode									 ***
*** INPUT ARGS  : string,int,int					                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
	void insertOpcode(string mnemonic, int opcode, int format,bool);
/***********************************************************************
*** FUNCTION    : searchOpcode                                       ***
************************************************************************
*** DESCRIPTION : Preforms serch in BST								 ***
*** INPUT ARGS  : string							                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
	OpcodeNode* searchOpcode(string key);
/***********************************************************************
*** FUNCTION    : viewTree                                           ***
************************************************************************
*** DESCRIPTION : Displays the content								 ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
	void viewTree();
};
#endif
