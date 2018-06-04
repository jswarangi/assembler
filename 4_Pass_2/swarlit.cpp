/**************************************************************************************************
*** NAME       : Swarangi Joshi                                                                ***
*** CLASS      : CSc 354                                                                        ***
*** ASSIGNMENT : 2                                                                              ***
*** DUE DATE   : 10-05-16                                                                      ***
*** INSTRUCTOR : Dr. George Hamer                                                                    ***
***************************************************************************************************
*** DESCRIPTION : Implementation of Expression. functions addliteral,searchliteral and viewliteral
***************************************************************************************************/

#include "swarlit.h"
#include"swarbst.h"
#include"swarcheck.h"
/********************************************************************
*** FUNCTION  EXP()	                                         ***
*********************************************************************
*** DESCRIPTION : Constructor of the Class EXP                   ***
*** INPUT ARGS  : 												 ***
*** OUTPUT ARGS : 											     ***
*** IN/OUT ARGS :               			                    ***
*** RETURN      : void   				                        ***
********************************************************************/
EXP::EXP()
{
	this->head = NULL;
}
/********************************************************************
*** FUNCTION  ~EXP                                         ***
*********************************************************************
*** DESCRIPTION : Destructor of the Class EXP            ***
*** INPUT ARGS  : 		                                  ***
*** OUTPUT ARGS : 					          ***
*** IN/OUT ARGS :               			          ***
*** RETURN      : void   				          ***
********************************************************************/
EXP::~EXP()
{	
	literalPtr temp = this->head;
	literalPtr nodePtr;;
	nodePtr = this->head;

  while(nodePtr != NULL)
  {
	  nodePtr = nodePtr->next;
	  delete temp;
      temp = nodePtr;
  }	
}
/***********************************************************************
*** FUNCTION    : addLiteral                                         ***
************************************************************************
*** DESCRIPTION : Adds lietral in the link list						 ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/
void EXP::addLiteral(string name, string value, int length, int address)
{
	Literal *newNode; 
	Literal *nodePtr; 
	newNode = new Literal();
	
	newNode->name = name;
	newNode->value = value;
	newNode->length = length;
	newNode->address = address;
	newNode->next = NULL;

	if (this->head==NULL)
		this->head = newNode;
	else
	{
		nodePtr = this->head;
		while (nodePtr->next!=NULL)
			nodePtr = nodePtr->next;
		nodePtr->next = newNode;
	}
	return;
}
/********************************************************************
*** FUNCTION  searchLiteral                                          
*********************************************************************
*** DESCRIPTION : search the Literal in Linked List           
*** INPUT ARGS  : name                                
*** OUTPUT ARGS : 					       
*** IN/OUT ARGS :               			        
*** RETURN      :Literal*, nodePtr 				         
********************************************************************/
literalPtr EXP::searchLiteral(string name)
{
	Literal *nodePtr;
	nodePtr = this->head;
	if(nodePtr == NULL)
		return nodePtr;
	else
	{		
		while (nodePtr != NULL && nodePtr->name != name)
		{			
			nodePtr=nodePtr->next;
		}
		return nodePtr;
	}
}
/********************************************************************
*** FUNCTION  ViewLiteral                                          
*********************************************************************
*** DESCRIPTION : displays the Literal Stored in Linked List          
*** INPUT ARGS  : 	                                
*** OUTPUT ARGS : 					       
*** IN/OUT ARGS :               			        
*** RETURN      : void   				         
********************************************************************/
void EXP::viewLiteral(string outputFileName)
{
	Literal *currNode;	
	currNode = this->head;
	ofstream fout;
	fout.open(outputFileName.c_str(),ios::app);
	cout<<"\n\t\t  LITERAL TABLE"<<endl;
	fout<<"\n\t\t  LITERAL TABLE"<<endl;
	cout<<left<<setw(20)<<"  NAME"<<setw(20)<<"VALUE"<<setw(20)<<"LENGTH"<<setw(20)<<"ADDRESS"<<endl;
	fout<<left<<setw(20)<<"  NAME"<<setw(20)<<"VALUE"<<setw(20)<<"LENGTH"<<setw(20)<<"ADDRESS"<<endl;
	if(currNode!=NULL)
	{
		while (currNode != NULL)
	   {
		  
		   cout<<left<<setw(20)<<currNode->name<<setw(20)<<currNode->value<<setw(10)<<currNode->length<<setw(10)<<check::convertinttohexstr(currNode->address)<<endl;
		   fout<<left<<setw(20)<<currNode->name<<setw(20)<<currNode->value<<setw(10)<<currNode->length<<setw(10)<<check::convertinttohexstr(currNode->address)<<endl;
		   
		   
		   currNode = currNode->next;

	   }
	}

	fout.close();
}


/***********************************************************************
*** FUNCTION    : dumpLiteral                                        ***
************************************************************************
*** DESCRIPTION : 				 ***
*** INPUT ARGS  : none								                 ***
*** OUTPUT ARGS : none                                               ***
*** IN/OUT ARGS : none                                               ***
*** RETURN      : none                                               ***
***********************************************************************/

void EXP::dumpLiteral(int &lineNo,int &locCounter,string fileName)
{
	Literal *currNode;	
	currNode = this->head;
	string strLocCounter = " ";
	ofstream fout;
	fout.open(fileName.c_str(),ios::app);

	if(currNode!=NULL)
	{
	   while (currNode != NULL)
	   {
		   if(currNode->isDumped==true)
		   {
			   lineNo++;
			   strLocCounter = check::convertinttohexstr(locCounter);
			   if(strLocCounter.length() ==1){
						strLocCounter = "0000"+ strLocCounter;
					}
					else if (strLocCounter.length() ==2){
						strLocCounter = "000"+ strLocCounter;
					}
					else if(strLocCounter.length() ==3){
						strLocCounter = "00"+ strLocCounter;
					}
					else if(strLocCounter.length() ==4){
						strLocCounter = "0"+ strLocCounter;
					}
					else {
					}
			   cout<<left<<setw(8)<<lineNo<<setw(8)<<strLocCounter<<setw(12)<<"*"<<setw(12)<<currNode->name<<endl;
			   fout<<left<<setw(8)<<lineNo<<setw(8)<<strLocCounter<<setw(12)<<"*"<<setw(12)<<currNode->name<<endl; 
			   currNode->address = locCounter;
			   locCounter+=currNode->length;
			   
		   }
		   currNode = currNode->next;
	   }
	}

	fout.close();
	return;
}

bool EXP::processExp(string fileName,BST *stPtr,bool adjustRFLag,string operandArray[],string expression,int &value,char charOperator,string& newRFlag){

	
	fstream fout;
	fout.open(fileName.c_str(),ios::app);
	treePtr treeNode,
			treeNode1,
			tempTreePtr;
		treeNode;
	int num1 = 0,
		num2 = 0;
	bool error = false;
	string errorMessage = " ";
	if(adjustRFLag){

					if(operandArray[0].length()>4){
						operandArray[0] = operandArray[0].substr(0,4);
					}
					if(operandArray[1].length()>4){
						operandArray[1] = operandArray[1].substr(0,4);
					}
					
					if(check::checkalphabet(operandArray[0]) && (check::checkalphabet(operandArray[1])))
					{					
					        treeNode = stPtr->search(operandArray[0]); 
							treeNode1 = stPtr->search(operandArray[1]);
							//if both of them are VALUE in symbol table
						if(treeNode != NULL && treeNode1 != NULL){

							if (charOperator == ',')
							{
								fout << "  Error expression " << expression << "  indexing can only used with a resister" << endl;
								cout << "  Error expression " << expression << "  indexing can only used with a resister" << endl;
								return false;
							}
							else if(charOperator != '+' && charOperator != '-'){
								fout << "  Error  epxpression:  " << expression<<" two values which are in symbol table but invalid operation used." << endl;
								cout << "  Error  epxpression:  " << expression<<" two values which are in symbol table but invalid operation used." << endl;
								return false;
							}

							else{

								check::RFlagValue(treeNode,treeNode1,charOperator,newRFlag,errorMessage,error);

								if(error){
									fout << errorMessage<<endl;
									cout << errorMessage << endl;
									return false;
								}

								else{
									if(charOperator == '+'){
									 value = (treeNode->VALUE) + treeNode1->VALUE;

									}

									else if(charOperator == '-'){
										value = (treeNode->VALUE) - treeNode1->VALUE;
									}
									
								}

							}					
						} 
					}// just value

				// if one the operands is number 0 1
				else if(check::checkalphabet(operandArray[0] ) && (check::checkNum(operandArray[1])))
				{        treeNode = stPtr->search(operandArray[0]); 
							
							value = check::convertstrtoint(operandArray[1]);
							stPtr->insert(operandArray[1],value,false,false);

							treeNode1 = stPtr->search(operandArray[1]);
							
							check::RFlagValue(treeNode,treeNode1,charOperator,newRFlag,errorMessage,error);
							
							if(error){

								cout << errorMessage << endl;
								return false;
							}

							else{
								if(charOperator == '+'){
									value = (treeNode->VALUE) + value;
									tempTreePtr = stPtr->search(operandArray[1]);
									tempTreePtr->SYMBOL = "\0";
								}
								else if(charOperator == '-'){
									value = (treeNode->VALUE) - value;
									tempTreePtr = stPtr->search(operandArray[1]);
								    tempTreePtr->SYMBOL = "\0";
								}

															
							
						}
				}

				else{

					if(charOperator == ','){
					fout << "  ERROR - expression : " << expression << "  illegeal indexing,improper resister used"<<endl;
					cout << "  ERROR - expression : " << expression << "  illegeal indexing,improper resister used"<<endl;
					return false;
					}
					


				  }
				}// adjustRFlag

				// not adjust rFlag
				else {

					if(operandArray[0].length()>4){
						operandArray[0] = operandArray[0].substr(0,4);
					}
					if(operandArray[1].length()>4){
						operandArray[1] = operandArray[1].substr(0,4);
					}

					if(check::checkNum(operandArray[0])){

						value = check::convertstrtoint(operandArray[0]);
						newRFlag = "ABSOLUTE";
					}// expression is just a number w/o operators

					// if it string 
					else{
						
											

						treeNode = stPtr->search(operandArray[0]);

						//if it is in sym table
						if(treeNode != NULL){
							value = treeNode->VALUE;
							newRFlag = treeNode->RFLAG;
							
						} 

						// not in symTable
						
					}	
				}


			fout.close();
			return true;
			}// isExpValid