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
BST::BST(){
	this->root = NULL;
	return;
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
	BST::~BST(){

		this->destroy(this->root);
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
	void BST::insert(string symbol, signed int value,bool rFlag,bool display){

	treePtr newNode;

	newNode = new(nothrow) treeNode;

	if(!newNode){

		cout << "  ERROR: Could not allocate the requred memory." << endl;
	}

	else {

	newNode->SYMBOL = symbol;
	newNode->VALUE = value;
	newNode->RFLAG = rFlag;
	newNode->IFLAG = true;
	newNode->MFLAG = false;
	newNode->display = display;
	newNode->left = newNode->right = NULL;
	this->insert(root, newNode);
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
treePtr BST::search(string key){ 

	return this->search(key, this->root);
}
/*********************************************************************
*** DESCRIPTION : Display in oder traversal of the Binary Search Tree.
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none											  ***
*** IN/OUT ARGS : none             								  ***
*** RETURN      : none              							  ***
********************************************************************/
void BST::view(string outputFileName){	

	ofstream fout;
	fout.open(outputFileName.c_str(),ios::app);

	cout << "\t\t  SYMBOLTABLE"<<endl;
	fout << "\t\t  SYMBOLTABLE"<<endl;

	fout<<setw(12)<<"Symbol"<<setw(12)<<"Value"<<setw(6)<<"RFlag"<<setw(6) << "IFLAG"<<setw(6)<<"MFlag"<<endl;
	cout<<setw(12)<<"Symbol"<<setw(12)<<"Value"<<setw(6)<<"RFlag"<<setw(6) << "IFLAG"<<setw(6)<<"MFlag"<<endl;
	this->view(root,outputFileName);
	fout.close();
	return;
}

/********************************************************************
*** FUNCTION  insert                                              ***
*********************************************************************
*** DESCRIPTION : Insert function which gets called by public function								
*** INPUT ARGS  : nodePtr, newNode                                ***
*** OUTPUT ARGS : none											  ***
*** IN/OUT ARGS : none              							  ***
*** RETURN      : void   										  ***
********************************************************************/
void BST::insert(treePtr &nodePtr, treePtr &newNode){

	 if (nodePtr == NULL)
		nodePtr = newNode;

	 else if (newNode->SYMBOL< nodePtr->SYMBOL)
		insert(nodePtr->left, newNode);

	else
		insert(nodePtr->right, newNode);

	 return;
}
/********************************************************************
*** FUNCTION  search                                              ***
*********************************************************************
*** DESCRIPTION : Search function which gets called by public function
*** INPUT ARGS  : key, nodePtr                                    ***
*** OUTPUT ARGS : none									          ***
*** IN/OUT ARGS : none			              			          ***
*** RETURN      : treePtr	 							          ***
********************************************************************/
treePtr BST::search(string key, treePtr &nodePtr){

	if(nodePtr == NULL || nodePtr->SYMBOL == key)
	{
		return nodePtr;
	}

	else if (key < nodePtr->SYMBOL)
		return this->search(key, nodePtr->left);
	else
		return this->search(key, nodePtr->right);

}
/********************************************************************
*** FUNCTION  view                                            ***
*********************************************************************
*** DESCRIPTION : View function which gets called by public function
*** INPUT ARGS  : nodePtr                                         ***
*** OUTPUT ARGS : none									          ***
*** IN/OUT ARGS : none			              			          ***
*** RETURN      : treePtr  							          ***
********************************************************************/
void BST::view(treePtr nodePtr,string outputFileName){

	static int viewCount = 0;
	ofstream fout;
	fout.open(outputFileName.c_str(),ios::app);

	char ans;

	if(nodePtr != NULL)
    	{
		if(nodePtr->left) 
			this->view(nodePtr->left,outputFileName);
		
		viewCount++;
		
		if(nodePtr->display){
			cout<<setw(12)<<nodePtr->SYMBOL<<setw(12)<<nodePtr->VALUE<<setw(6)
				<<nodePtr->RFLAG<<setw(6) <<nodePtr->IFLAG<<setw(6)<<nodePtr->MFLAG<<endl;
			fout<<setw(12)<<nodePtr->SYMBOL<<setw(12)<<nodePtr->VALUE<<setw(6)
				<<nodePtr->RFLAG<<setw(6) <<nodePtr->IFLAG<<setw(6)<<nodePtr->MFLAG<<endl;
		}
		if(viewCount==20)
				{
			cout << endl << "Paused... press any key and then hit enter to continue: ";
				cin >> ans;
				cin.clear();
				viewCount = 0;
		}

		if(nodePtr->right) 
			this->view(nodePtr->right,outputFileName);
    	}

    	else {
			fout.close();
			return;
		}
}
/********************************************************************
*** FUNCTION destroy                                              ***
*********************************************************************
*** DESCRIPTION : Distroy whole Binary Search Tree.               ***
*** INPUT ARGS  : nodePtr                                         ***
*** OUTPUT ARGS : none											  ***
*** IN/OUT ARGS : none			              			          ***
*** RETURN      : none			              			          ***
********************************************************************/
void BST::destroy(treePtr &nodePtr){

        if (nodePtr != NULL){
                destroy(nodePtr->left);
                destroy(nodePtr->right);
				nodePtr = NULL;
                delete nodePtr;
				
        }

		return;
}