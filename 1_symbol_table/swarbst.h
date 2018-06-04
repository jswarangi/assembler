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


using namespace std;

struct TreeNode;
typedef TreeNode * TreePtr;
struct TreeNode 
{
      string symbol;
	  signed int value;
	  bool rflag,mflag,iflag;
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
void insert( TreePtr &,string symbol,signed int value,bool rflag );
/********************************************************************
*** FUNCTION  search                                              ***
*********************************************************************
*** DESCRIPTION : Search a node with specific symbol              ***
*** INPUT ARGS  : tree, symbol                                    ***
*** OUTPUT ARGS : none											  **
*** IN/OUT ARGS : none              							  ***
*** RETURN      : none 									          ***
********************************************************************/
TreePtr search(TreePtr &,string symbol );
/********************************************************************
*** FUNCTION  view                                              ***
/*********************************************************************
*** DESCRIPTION : Display in oder traversal of the Binary Search Tree.
*** INPUT ARGS  : tree                                            ***
*** OUTPUT ARGS : none											  ***
*** IN/OUT ARGS : none             								  ***
*** RETURN      : none              							  ***
********************************************************************/
void view(TreePtr);
void destroy( TreePtr & );
private:
TreePtr root;

};
#endif