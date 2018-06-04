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


#include "swarbst.h"


using namespace std;



/***********************************************************************
*** FUNCTION    : BST                                                ***
************************************************************************
*** DESCRIPTION : Default constructor								 ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/

BST::BST() : root(NULL)
{
	
}
/***********************************************************************
*** FUNCTION    : BST                                                ***
************************************************************************
*** DESCRIPTION : desstructor										 ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
BST::~BST() 
{
   destroy(root);
}
/********************************************************************
*** FUNCTION destroy                                              ***
*********************************************************************
*** DESCRIPTION : Destroy whole Binary Search Tree.               ***
*** INPUT ARGS  : tree                                            ***
*** OUTPUT ARGS : none											  ***
*** IN/OUT ARGS : none			              			          ***
*** RETURN      : none			              			          ***
********************************************************************/
void BST::destroy( TreePtr & tree ) 
{ // post order traversal
   if ( tree != NULL ) 
   {
   destroy( tree->left ); // Go Left
   destroy( tree->right ); // Go Right
   delete tree; // Visit Current Node
   tree = NULL;
   }
return;
}
/********************************************************************
*** FUNCTION  insert                                              ***
*********************************************************************
*** DESCRIPTION : Insert node in the Binary Search Tree.          ***
*** INPUT ARGS  : tree, symbol, value, rflag                      ***
*** OUTPUT ARGS : none											  ***
*** IN/OUT ARGS : none              			                  ***
*** RETURN      : none   										  ***
********************************************************************/
void BST::insert( TreePtr & tree, string symbol, signed int value, bool rflag, bool viewt )
 {
	if ( tree == NULL ) 
	{
		tree = new(nothrow)TreeNode; // Exception Handling Not Used
		if ( tree == NULL ) 
		{
			cout<< "Tree FULL – No Insertion" << endl;
		}
		else
		{
			tree->symbol = symbol;
			tree->value = value;
			tree->rflag = rflag;
			tree->iflag = true;
			tree->mflag = false;
			tree->viewt = viewt;
			tree->left = NULL;
			tree->right = NULL;
		}
   }
   else if ( tree->symbol > symbol ) 
   {
		insert( tree->left, symbol,value, rflag,viewt );
   }
   else 
   {
		insert(tree->right, symbol, value, rflag, viewt);
   }
return;
}
/********************************************************************
*** FUNCTION  search                                              ***
*********************************************************************
*** DESCRIPTION : Search a node with specific symbol              ***
*** INPUT ARGS  : tree, symbol                                    ***
*** OUTPUT ARGS : none											  **
*** IN/OUT ARGS : none              							  ***
*** RETURN      : none 									          ***
********************************************************************/
TreePtr BST::search( TreePtr & tree, string symbol ) 
{
	if ( tree == NULL )
	{
		return tree; // return NULL;
	}
    else if ( tree->symbol == symbol ) 
	{
        return tree;
    }
    else if ( tree->symbol > symbol ) 
	{
      return search( tree->left, symbol );
    }
    else 
    {
      return search( tree->right, symbol );
    }
}
/********************************************************************
*** FUNCTION  view                                              ***
/*********************************************************************
*** DESCRIPTION : Display in oder traversal of the Binary Search Tree.
*** INPUT ARGS  : tree                                            ***
*** OUTPUT ARGS : none											  ***
*** IN/OUT ARGS : none             								  ***
*** RETURN      : none              							  ***
********************************************************************/
void BST::view( TreePtr tree ) 
{ // in order traversal
    int Count = 0;
	char a; 
    if ( tree != NULL ) 
	{
     view( tree->left ); // Go Left
	 
	 Count++;
		cout<<setw(12)<<tree->symbol<<setw(10)<<tree->value<<setw(7)
			<<tree->rflag<<setw(7) <<tree->iflag<<setw(7)<<tree->mflag<<endl;

		if(Count==20)
				{
			        cout << endl << "output paused press any key to continue ";
				   cin >> a;
				   Count = 0;
		        }
     view( tree->right ); // Go Right
	 
    }
return;
}