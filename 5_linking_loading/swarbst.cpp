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
#include "swarcheck.h"


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
*** FUNCTION  insert	                                          ***
*********************************************************************
*** DESCRIPTION : Insert node in the Binary Search Tree.          ***
*** INPUT ARGS  : symbol, value, rFlag                            ***
*** OUTPUT ARGS : none											  ***
*** IN/OUT ARGS : none             								  ***
*** RETURN      : none  										  ***
********************************************************************/
	void BST::insert(string csect, string symbol, int addr, int csaddar,int ldaddr, int length,bool islable)
	{
	TreePtr treenewNode;

	treenewNode = new(nothrow) TreeNode;

	if(!treenewNode){

		cout << "  ERROR: Could not allocate the requred memory." << endl;
	}

	else {

	treenewNode->SYMBOL = symbol;
	treenewNode->ADDR = addr;
	treenewNode->CSADDR = csaddar;
	treenewNode->CSECT = csect;
	treenewNode->LDADDR = ldaddr;
	treenewNode->LENGTH = length;
	treenewNode->isLabel = islable;
	treenewNode->left = treenewNode->right = NULL;
	treenewNode->isDump = false;
	this->insert(root, treenewNode);
	}

	return;
}
/**********************************************************************
*** FUNCTION  search                                            ***
***********************************************************************
*** DESCRIPTION : Search a node with specific key and returns node. ***
*** INPUT ARGS  : key                                               ***
*** OUTPUT ARGS : none					            ***
*** IN/OUT ARGS : none              			            ***
*** RETURN      : treePtr  				            ***
**********************************************************************/
TreePtr BST::search(string key){ 

	return this->search(key, this->root);
}
void BST::view(string outputFileName){	
	this->view(root,outputFileName);
	return;
}
/********************************************************************
*** FUNCTION  insert                                              ***
*********************************************************************
*** DESCRIPTION : Insert function which gets called by public function								
*** INPUT ARGS  : treenodePtr, treenewNode                                ***
*** OUTPUT ARGS : none											  ***
*** IN/OUT ARGS : none              							  ***
*** RETURN      : void   										  ***
********************************************************************/
void BST::insert(TreePtr &treenodePtr, TreePtr &treenewNode){

	 if (treenodePtr == NULL)
		treenodePtr = treenewNode;

	 else if (treenewNode->SYMBOL< treenodePtr->SYMBOL)
		insert(treenodePtr->left, treenewNode);

	else
		insert(treenodePtr->right, treenewNode);

	 return;
}
/********************************************************************
*** FUNCTION  search                                              ***
*********************************************************************
*** DESCRIPTION : Search function which gets called by public function
*** INPUT ARGS  : key, treenodePtr                                    ***
*** OUTPUT ARGS : none									          ***
*** IN/OUT ARGS : none			              			          ***
*** RETURN      : treePtr	 							          ***
********************************************************************/
TreePtr BST::search(string key, TreePtr &treenodePtr){

	if(treenodePtr == NULL || treenodePtr->SYMBOL == key || treenodePtr->CSECT == key)
	{
		return treenodePtr;
	}

	else if (key < treenodePtr->SYMBOL)
		return this->search(key, treenodePtr->left);
	else
		return this->search(key, treenodePtr->right);

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
void BST::view( TreePtr tree, string file ) 
{ static int viewCount = 0;
	char ans;
	string addar,
		   csaddr,
		   laddar,
		   length;

	if(tree != NULL)
    	{
		if(tree->left) 
		  view(tree->left,file);
		
		viewCount++;
		if(tree->isLabel){
			addar = check::convertinttohexstr(tree->ADDR);
			laddar = check::convertinttohexstr(tree->LDADDR);

			while(addar.length() < 5){
				addar = "0"+addar;
			}
			while(laddar.length() < 5){
				laddar = "0"+laddar;
			}
			if(tree->isDump == false){
				cout << setw(6) << tree->CSECT << setw(7) << tree->SYMBOL << setw(6) << addar << setw(7) << " "<< setw(7) << laddar << setw(8) << " " <<endl;
				addar = "\0";
				laddar = "\0";
				tree->isDump = true;
			}
		}

		else{

			csaddr = check::convertinttohexstr(tree->CSADDR);
			length = check::convertinttohexstr(tree->LENGTH);

			while(csaddr.length() < 5){
				csaddr = "0"+csaddr;
			}
			while(length.length() < 5){
				length = "0"+length;
			}
			
			if(tree->isDump == false){
				cout << setw(6) << tree->CSECT << setw(7) << tree->SYMBOL << setw(6) << " " << setw(7) << csaddr << setw(7) << " " << setw(8) << length <<endl;
				csaddr = "\0";
				length = "\0";
				tree->isDump = true;
			}
		}

		if(viewCount==20)
				{
			cout << endl << "press any key and then hit enter to continue: ";
				cin >> ans;
				cin.clear();
				viewCount = 0;
		}

		if(tree->right) 
			view(tree->right,file);
    	}

    	else {
			return;
		}
return;
}