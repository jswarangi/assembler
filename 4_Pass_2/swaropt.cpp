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
*** FUNCTION    : OPT	                                              ***
************************************************************************
*** DESCRIPTION : Default constructor								 ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
OPT::OPT()
{
	this->root = NULL;
	return;
}
/***********************************************************************
*** FUNCTION    : ~OPT		                                         ***
************************************************************************
*** DESCRIPTION : Default constructor								 ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
OPT::~OPT(void)
{
	this->destroy(this->root);
	return;
}
/***********************************************************************
*** FUNCTION    : insertOpcode                                       ***
************************************************************************
*** DESCRIPTION : Inserts opcode									 ***
*** INPUT ARGS  : string,int,int					                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
void OPT::insertOpcode(string mnemonic, int format, int opcode,bool oFlag)
{
	OpcodeNode *newNode;
	newNode = new(nothrow) OpcodeNode;
	if(!newNode){
		cout << "  Error: Can't allocate memmory."<<endl;
	}

	newNode->oFlag = oFlag;
	newNode->mnemonic = mnemonic;
	newNode->opcode = opcode;
	newNode->format = format;
	newNode->iflag = 1;
	newNode->left = newNode->right = NULL;

	this->insert(root, newNode);
	return;
}
/***********************************************************************
*** FUNCTION    : searchOpcode                                       ***
************************************************************************
*** DESCRIPTION : Preforms serch in BST								 ***
*** INPUT ARGS  : string							                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
OpcodeNode* OPT::searchOpcode(string key)
{ 
	return this->search(key,root);
}
/***********************************************************************
*** FUNCTION    : viewTree                                           ***
************************************************************************
*** DESCRIPTION : Displays the content								 ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
void OPT::viewTree()
{	
	cout<<"SYMBOL TABLE"<<endl;
	cout<<left<<setw(9)<<"LABEL"<<setw(10)<<"VALUE"<<setw(7)<<"RFLAG"<<setw(7)<<"IFLAG"<<setw(7)<<"MFLAG"<<endl;
	this->viewNode(root);
}
/********************************************************************
*** FUNCTION  insert                                              ***
*********************************************************************
*** DESCRIPTION : Non-exportable/recursive version insert function***
*** INPUT ARGS  : nodePtr, newNode                                ***
*** OUTPUT ARGS : 												  ***
*** IN/OUT ARGS :               								 ***
*** RETURN      : void   										  ***
********************************************************************/
void OPT::insert(OpcodeNode* &nodePtr, OpcodeNode* &newNode)
{
	 if (nodePtr == NULL)
		nodePtr = newNode;
	 else if (newNode->mnemonic< nodePtr->mnemonic)
		insert(nodePtr->left, newNode);
	else
		insert(nodePtr->right, newNode);

}
/********************************************************************
*** FUNCTION  search                                              ***
*********************************************************************
*** DESCRIPTION : Non-exportable/recursive version search function***
*** INPUT ARGS  : key, nodePtr                                    ***
*** OUTPUT ARGS : 												  ***
*** IN/OUT ARGS :               							      ***
*** RETURN      : TreeNode*  								      ***
********************************************************************/
OpcodeNode* OPT::search(string key, OpcodeNode* &nodePtr)
{
	if(nodePtr == NULL || nodePtr->mnemonic == key)
	{
		return nodePtr;
	}
	else if (key < nodePtr->mnemonic)
		return this->search(key, nodePtr->left);
	else
		return this->search(key, nodePtr->right);

}
/********************************************************************
*** FUNCTION  viewNode                                            ***
*********************************************************************
*** DESCRIPTION : Non-exportable/recursive version view function. ***
*** INPUT ARGS  : nodePtr                                         ***
*** OUTPUT ARGS : 												  ***
*** IN/OUT ARGS :               						          ***
*** RETURN      : TreeNode*  							          ***
********************************************************************/
void OPT::viewNode(OpcodeNode* nodePtr)
{
	if(nodePtr != NULL)
    	{
		if(nodePtr->left) 
				this->viewNode(nodePtr->left);
		cout<<setw(9)<<nodePtr->mnemonic<<setw(10)<<nodePtr->format<<setw(7)<<nodePtr->opcode<<endl;
		if(nodePtr->right) 
				this->viewNode(nodePtr->right);
    	}
}
/********************************************************************
*** FUNCTION destroy                                              ***
*********************************************************************
*** DESCRIPTION : Distroy whole Binary Search Tree.               ***
*** INPUT ARGS  : nodePtr                                         ***
*** OUTPUT ARGS : 												  ***
*** IN/OUT ARGS :               						          ***
*** RETURN      : void              					          ***
********************************************************************/
void OPT::destroy(OpcodeNode* &nodePtr)
{
        if (nodePtr != NULL)
        {
                destroy(nodePtr->left);
                destroy(nodePtr->right);
                delete nodePtr;
        }
}


