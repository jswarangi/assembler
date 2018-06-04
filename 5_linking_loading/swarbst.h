/**************************************************************************************************
*** NAME       : Swarangi Joshi                                                                ***
*** CLASS      : CSc 354                                                                        ***
*** ASSIGNMENT : 1                                                                              ***
*** DUE DATE   : 9-14-16                                                                       ***
*** INSTRUCTOR : Dr. George Hamer                                                               ***
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


using namespace std;

struct TreeNode;
typedef TreeNode * TreePtr;
struct TreeNode 
{
      string CSECT, SYMBOL;
	int ADDR,
		CSADDR,
		LDADDR,
		LENGTH;
	bool isLabel,
		 isDump; 
TreePtr left, right;
};
class BST 
{
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
*** FUNCTION  insert                                              ***
*********************************************************************
*** DESCRIPTION : Insert node in the Binary Search Tree.          ***
*** INPUT ARGS  : tree, symbol, value, rflag                      ***
*** OUTPUT ARGS : none											  ***
*** IN/OUT ARGS : none              			                  ***
*** RETURN      : none   										  ***
********************************************************************/
void insert(string csect,string symbol, int addr, int csaddr,int ldaddr, int length,bool islabel);
/********************************************************************
*** FUNCTION  search                                              ***
*********************************************************************
*** DESCRIPTION : Search a node with specific symbol              ***
*** INPUT ARGS  : tree, symbol                                    ***
*** OUTPUT ARGS : none											  **
*** IN/OUT ARGS : none              							  ***
*** RETURN      : none 									          ***
********************************************************************/
TreePtr search(string symbol );
/********************************************************************
*** FUNCTION  view                                              ***
/*********************************************************************
*** DESCRIPTION : Display in oder traversal of the Binary Search Tree.
*** INPUT ARGS  : tree                                            ***
*** OUTPUT ARGS : none											  ***
*** IN/OUT ARGS : none             								  ***
*** RETURN      : none              							  ***
********************************************************************/
void view(string );
void destroy( TreePtr & );
private:
TreePtr root;
	void insert(TreePtr &, TreePtr &);
	void view(TreePtr,string);
	TreePtr search(string key, TreePtr &);

};
#endif