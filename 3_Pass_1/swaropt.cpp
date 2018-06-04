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


#include"swaropt.h"

#include<iostream>
#include<iomanip>
#include<string>


using namespace std;

/***********************************************************************
*** FUNCTION    : OPT                                                ***
************************************************************************
*** DESCRIPTION : Default constructor								 ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
OPT::OPT()  : root(NULL)
{
	
}
/***********************************************************************
*** FUNCTION    : OPT                                                ***
************************************************************************
*** DESCRIPTION : desstructor										 ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
OPT::~OPT()
{
	OpcodePtr temp = root;
	OpcodePtr Opcode;
	Opcode = root;

  while(Opcode != NULL)
  {
	  Opcode = Opcode->right;
	  delete temp;
      temp = Opcode;
  }	
}
/********************************************************************
*** FUNCTION  insertopcode                                              ***
*********************************************************************
*** DESCRIPTION : Insert node in the Binary Search Tree.          ***
*** INPUT ARGS  : mnemonic, opcode, format                        ***
*** OUTPUT ARGS : none											  ***
*** IN/OUT ARGS : none              			                  ***
*** RETURN      : none   										  ***
********************************************************************/
void OPT::insertopcode( OpcodePtr &tree,string mnemonic,int format,int opcode )
{
	if ( tree == NULL ) 
	{
		tree = new(nothrow)OpcodeNode; // Exception Handling Not Used
		if ( tree == NULL ) 
		{
			cout<< "Tree FULL – No Insertion" << endl;
		}
		else
		{   
	        tree->mnemonic = mnemonic;
			tree->opcode = opcode;
			tree->format = format;
			tree->iflag = 1;
			tree->left = NULL;
			tree->right = NULL;
		}
   }
   else if ( tree->mnemonic > mnemonic ) 
   {
		insertopcode( tree->left, mnemonic,format,opcode );
   }
   else 
   {
		insertopcode( tree->right, mnemonic,format,opcode );
   }
return;
}
/********************************************************************
*** FUNCTION  searchopcode                                              ***
*********************************************************************
*** DESCRIPTION : Search a node with specific symbol              ***
*** INPUT ARGS  : opcodeptr, opcode                                    ***
*** OUTPUT ARGS : none											  **
*** IN/OUT ARGS : none              							  ***
*** RETURN      : none 									          ***
********************************************************************/
OpcodePtr OPT::searchopcode( OpcodePtr &tree, string key )
{
	if ( tree == NULL )
	{
		return tree; // return NULL;
	}
    else if ( tree->mnemonic == key ) 
	{
        return tree;
    }
    else if ( tree->mnemonic > key ) 
	{
      return searchopcode( tree->left, key );
    }
    else 
    {
      return searchopcode( tree->right, key );
    }
}
/********************************************************************
*** FUNCTION  view                                              ***
/*********************************************************************
*** DESCRIPTION : Display in oder traversal of the Binary Search Tree.
*** INPUT ARGS  : opcodeptr                                       ***
*** OUTPUT ARGS : none											  ***
*** IN/OUT ARGS : none             								  ***
*** RETURN      : none              							  ***
********************************************************************/
void OPT::viewopcode(OpcodePtr tree)
{
	int Count = 0;
	char a; 
    if ( tree != NULL ) 
	{
     viewopcode( tree->left ); // Go Left
	 
	 Count++;
		cout<<setw(9)<<tree->mnemonic<<setw(10)<<tree->format<<setw(7)<<tree->opcode<<endl;

		if(Count==20)
				{
			        cout << endl << "output paused press any key to continue ";
				   cin >> a;
				   Count = 0;
		        }
     viewopcode( tree->right ); // Go Right
	 
    }
return;
}


