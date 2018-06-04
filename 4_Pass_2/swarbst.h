/**************************************************************************************************
*** NAME       : Swarangi Joshi                                                                ***
*** CLASS      : CSc 354                                                                        ***
*** ASSIGNMENT : 1                                                                              ***
*** DUE DATE   : 9-14-16                                                                       ***
*** INSTRUCTOR : Dr. George Hamer                                                                    ***
***************************************************************************************************
*** DESCRIPTION : This program is the Binary search tree implementation. It includes the basic 
                  functions of creating and destroying the binary search tree along with 
				  insert,search and view functions.
***************************************************************************************************/


#ifndef _SWARBST_H
#define _SWARBST_H

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<sstream>


using namespace std;

struct treeNode{

	string SYMBOL;
	signed int VALUE;
	bool RFLAG,
		 MFLAG,
		 display,
		 IFLAG;

	treeNode *left; 
	treeNode *right; 
};

typedef treeNode* treePtr;

class BST{

public:

	

/***********************************************************************
*** FUNCTION    : BST                                                ***
************************************************************************
*** DESCRIPTION : Default constructor								 ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
	 BST();

/***********************************************************************
*** FUNCTION    : BST                                                ***
************************************************************************
*** DESCRIPTION : desstructor										 ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
	~BST();
/********************************************************************
*** FUNCTION  insertNode                                          ***
*********************************************************************
*** DESCRIPTION : Insert node in the Binary Search Tree.          ***
*** INPUT ARGS  : symbol, value, rFlag,                            ***
*** OUTPUT ARGS : none											  ***
*** IN/OUT ARGS : none              			                  ***
*** RETURN      : none   										  ***
********************************************************************/
	void insert(string symbol, signed int value,bool rFlag,bool display);
/********************************************************************
*** FUNCTION  searchNode                                          ***
*********************************************************************
*** DESCRIPTION : Search a node with specific key and return node.***
*** INPUT ARGS  : key                                             ***
*** OUTPUT ARGS : none											  **
*** IN/OUT ARGS : none              							  ***
*** RETURN      : none 									          ***
********************************************************************/
	treePtr search(string key);
/********************************************************************
*** FUNCTION  viewTreeNode                                        ***
*********************************************************************
*** DESCRIPTION : Display in oder traversal of the Binary Search Tree.
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none											  ***
*** IN/OUT ARGS : none             								  ***
*** RETURN      : none              							  ***
********************************************************************/
	void view(string);


private:	
	treePtr	root;
	void insert(treePtr &, treePtr &);
	void view(treePtr,string);
	void destroy(treePtr &);
	treePtr search(string key, treePtr &);
	
};
#endif