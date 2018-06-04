/**************************************************************************************************
*** NAME       : Swarangi Joshi                                                                ***
*** CLASS      : CSc 354                                                                        ***
*** ASSIGNMENT : 2                                                                              ***
*** DUE DATE   : 10-05-16                                                                      ***
*** INSTRUCTOR : Dr. George Hamer                                                                    ***
***************************************************************************************************
*** DESCRIPTION : This program is processes expressions and literals. Displays the symbolTable and 
                   LiteralTable 
***************************************************************************************************/
#include"swarbst.h"
#include"swarcheck.h"
#include"swarlit.h"
#include<fstream>
#include<sstream>

using namespace std;
typedef BST* pointer;
    pointer symbolTable;
	TreePtr treeNode, ptr,treeNode1;
	EXP *literalTable;
	literalPtr literalNode,ptr1;
	int lineCount;
	string fileName;

int main()
{
	   
       string a,ch,file,Symbol,Value,RFlag,MFlag,IFlag,expression, literalValue, newRFlag = " ",errorMessage = " ",operandArray[2],ans ;
	   bool rFlag,isExpValid,xBit = false,nBit = false,iBit = false,error = false,adjustRFlag = false,isalphabet1,isalphabet2,isNum1,isNum2,isLiteral;
       int value, literalCount,literalLength,quotationCount;
	signed int num1,num2,value1 = 0,i=0; 
    char charOperator = ' ',spaceLiteral = ' ';

	
	
	TreePtr tempTreePtr,ptr2,ptr3,ptr4;

	 symbolTable= new (nothrow) BST();
			
		 ifstream inputFile("label.txt");		
		
		 while(inputFile>>Symbol)//inserting symbols in the symbol table
		 {
               
			 for (int i=0; i<Symbol.length(); i++) // converting symbol to uppercase
	           {
		         Symbol[i]=toupper(Symbol[i]);
	           } 
			  inputFile>>Value>>RFlag;
			for (int j=0; j<RFlag.length(); j++) //converting the rflag to uppercase
	           {
		         RFlag[j]=toupper(RFlag[j]);
	           } 
     		if((check::checkvalue(Value)) && (check::checkrflag(RFlag)) && (check::checksymbol(Symbol)))
			 {

				ptr = symbolTable->search(treeNode,Symbol);
				if(ptr!=NULL)
				{
					ptr->mflag = true;
					cout<<Symbol<<" :Error - symbol is previously defined "<<endl;
				}
				else
				{
                     stringstream strStream(Value); //converting value from string to integer
	                 strStream >> value;					
					
					if(RFlag=="TRUE") //conerting the rflag to numerical 1 or 0
						rFlag = true;
					else
						rFlag = false;

					symbolTable->insert(treeNode,Symbol,value,rFlag);
					
				}
			 }	
		}
         
		inputFile.close();
	cout<<"  Enter the name for the expression file : ";
		cin>>fileName;	
		inputFile.open(fileName.c_str());
		literalTable = new (nothrow) EXP();
	if(!inputFile)
	{
		cout<<"File "<<fileName<<" could not found!"<<endl;
		return 0;
	}
	
	literalCount = 0;	
	cout << "\n\t\t  EXPRESSIONS" <<endl;
	cout<<setw(20)<<"  EXPRESSION"<<setw(10)<<"value"<<setw(13)<<"RELOCATABLE"<<setw(6)<<"N-BIT"<<setw(6)<<"I-BIT"<<setw(6)<<"X-BIT"<<endl;
	while(inputFile>>expression)
	{		
		quotationCount = 0;

		if(expression.length() >2)
		{

			if(expression[2] =='\'')
			{
			for(int i = 0; i<expression.length();i++)
			{
				if(expression[i] =='\'')
				{
					quotationCount++;
				}
			}
			if(quotationCount != 2)
			{
					spaceLiteral = inputFile.get();
					while(( spaceLiteral != '\n') && (spaceLiteral  != EOF)){
						expression  += spaceLiteral;
						spaceLiteral = inputFile.get();
						
					}
					

			}
			
		  }
		}
	 
		isLiteral=check::checkLiteral(expression, literalValue, literalLength);
		num1 = num2 = 0;
		if(isLiteral)
		{
			
			ptr1 = literalTable->searchLiteral(literalNode,expression);
			if(ptr1==NULL)
			{
				literalCount ++;
				literalTable->addLiteral(literalNode,expression, literalValue, literalLength, literalCount);
			}
		}
		else
		{		
	         
				for (i; i<expression.length(); i++)
					{
						expression[i]=toupper(expression[i]);
					} 
			isExpValid = check::checkExpression(expression,nBit, iBit, xBit, operandArray, adjustRFlag, charOperator);

			if(isExpValid)
			{

				if(adjustRFlag)
				{

					if(operandArray[0].length()>4)
					{
						operandArray[0] = operandArray[0].substr(0,4);
						//isalphabet1=check::checkalphabet(operandArray[0]);
						//isNum1=check::checkNum(operandArray[0]);
					}
					if(operandArray[1].length()>4)
					{
						operandArray[1] = operandArray[1].substr(0,4);
						//isalphabet2=check::checkalphabet(operandArray[1]);
						//isNum2=check::checkNum(operandArray[1]);
					}
					 ptr2 = symbolTable->search(treeNode,operandArray[0]); 
					 ptr3 = symbolTable->search(treeNode1,operandArray[1]);
					// if both operands are value 0 0 
					if(check::checkalphabet(operandArray[0]) &&check::checkalphabet(operandArray[1]))
					{					
					
							//if both of them are value in symbol table
						if(ptr2 != NULL && ptr3 != NULL)
						{

							if (charOperator == ',')
							{
								cout << "  Error expression " << expression << "  indexing can only used with a resister" << endl;
							}
							else if(charOperator != '+' && charOperator != '-')
							{
								cout << "  Error  epxpression:  " << expression<<" two values which are in symbol table but invalid operation used." << endl;
								  lineCount++; 
									if(lineCount == 20)
										{
											cout << "  Enter any key to continue:  " ;
											cin >> a;
											cin.clear();
											lineCount = 1;
										} 
							}

							else
							{

								check::RFlagValue(treeNode,treeNode1,charOperator,newRFlag,errorMessage,error);

								if(error)
								{
									cout << errorMessage << endl;
								}

								else{
									if(charOperator == '+')
									{
									 value1 = (treeNode->value) + treeNode1->value;

									}

									else if(charOperator == '-')
									{
										value1 = (treeNode->value) - treeNode1->value;
									}
										
									cout << setw(20) << expression  << setw(10) << value1 << setw(13) << newRFlag << setw(6)<< nBit << setw(6) << iBit 
									<< setw(6) << xBit << endl;		
									  lineCount++; 
										if(lineCount == 20)
											{
												cout << "  Enter any key to continue:  " ;
												cin >> a;
												cin.clear();
												lineCount = 1;
											}
								}

							}					
						} // if both of them are value in symbol table						
						 
						// one of them is null 
					else if(ptr2 == NULL && charOperator == ',')
					{
							cout << "  Error - expression : " << expression << "  indexing format : Value , resister, value wasn't loacted in sym. table " << endl;

					} // else if 

						//one of them is null
					else if(ptr3 == NULL && charOperator == ',')
					{
						 if(operandArray[1] == "X"){

								cout << setw(20) << expression << setw(10) << treeNode->value << setw(13) ;
								if(treeNode->rflag)
									cout << " RELATIVE";
								else
									cout << "  ABSOLUTE" ;
								cout << setw(6)<< nBit << setw(6) << iBit << setw(6) << xBit << endl;
								  lineCount++; 
											if(lineCount == 20)
												{
													cout << "  Enter any key to continue:  " ;
													cin >> a;
													cin.clear();
													lineCount = 1;
												}
							}
							else 
								{
									cout << "  Error - expression : " << expression << "  improper resister used : " << operandArray[1] <<endl;
								}

						}

						else if((ptr2 == NULL || ptr3 == NULL) && charOperator != ',')
						{
							cout << "  Error  epxpression:  " << expression<<" if binary operation with values,they should be in sym table." << endl;
							lineCount++; 
											if(lineCount == 20)
												{
													cout << "  Enter any key to continue:  " ;
													cin >> a;
													cin.clear();
													lineCount = 1;
												}
						}
							


					}// just value

				// if one the operands is number 0 1
				else if(check::checkalphabet(operandArray[0])  && check::checkNum(operandArray[1]))
				{
							
							value1 = check::convertstrtoint(operandArray[1]);
							symbolTable->insert(treeNode1,operandArray[1],value1,false);
							ptr3 = symbolTable->search(treeNode1,operandArray[1]);
							
							check::RFlagValue(treeNode,treeNode1,charOperator,newRFlag,errorMessage,error);

							if(error)
								cout << errorMessage << endl;

							else
							{
								if(charOperator == '+')
								{
									//value1 = (treeNode->value) + treeNode1->value;
									cout << setw(20) << expression  << setw(10) << (treeNode->value) + treeNode1->value << setw(13) << newRFlag << setw(6)<< nBit << setw(6) << iBit 
									<< setw(6) << xBit << endl;
									lineCount++; 
											if(lineCount == 20)
												{
													cout << "  Enter any key to continue:  " ;
													cin >> a;
													cin.clear();
													lineCount = 1;
												}
									 //ptr4 = symbolTable->search(tempTreePtr,operandArray[1]);
									 //tempTreePtr->symbol = " ";
								}
								else if(charOperator == '-')
								{
									//value1 = (treeNode->value) - treeNode1->value;
									cout << setw(20) << expression  << setw(10) << (treeNode->value) - treeNode1->value << setw(13) << newRFlag << setw(6)<< nBit << setw(6) << iBit 
									<< setw(6) << xBit << endl;
									lineCount++; 
											if(lineCount == 20)
												{
													cout << "  Enter any key to continue:  " ;
													cin >> a;
													cin.clear();
													lineCount = 1;
												}
									//ptr4  = symbolTable->search(tempTreePtr,operandArray[1]);
								   //tempTreePtr->symbol = " ";
								}

								else if(charOperator == ',')
								{

									cout << "  ERROR - expression: " <<expression << "  Value , Number. Illegeal indexing" << endl;
									lineCount++; 
											if(lineCount == 20)
												{
													cout << "  Enter any key to continue:  " ;
													cin >> a;
													cin.clear();
													lineCount = 1;
												}
								}																						
						}
					}

					//  if one of the operands is number 1 0 
				else if(check::checkalphabet(operandArray[1]) &&check::checkNum(operandArray[0]))
				{							
							value1 = check::convertstrtoint(operandArray[0]);
							symbolTable->insert(treeNode,operandArray[0],value1,false);
							
							treeNode1 = symbolTable->search(treeNode1,operandArray[1]);
							ptr2 = symbolTable->search(treeNode,operandArray[0]);
	

							if(treeNode1 ==NULL)
							{
								cout << "  ERROR - expression: " << expression << "  Number +/- value, but value doesn't exit in symbolTable." << endl;
								lineCount++; 
											if(lineCount == 20)
												{
													cout << "  Enter any key to continue:  " ;
													cin >> a;
													cin.clear();
													lineCount = 1;
												}
							}

							
							else
							{							
								check::RFlagValue(treeNode,treeNode1,charOperator,newRFlag,errorMessage,error);
								if(error){
									cout << errorMessage << endl;
									lineCount++; 
											if(lineCount == 20)
												{
													cout << "  Enter any key to continue:  " ;
													cin >> a;
													cin.clear();
													lineCount = 1;
												}
								}
								else
								{
									if(charOperator == '+')
									{
										//value1 = (signed int)(treeNode->value) + treeNode1->value;
										cout << setw(20) << expression  << setw(10) << (signed int)(treeNode->value) + treeNode1->value << setw(13) << newRFlag << setw(6)<< nBit << setw(6) << iBit 
										<< setw(6) << xBit << endl;
										lineCount++; 
											if(lineCount == 20)
												{
													cout << "  Enter any key to continue:  " ;
													cin >> a;
													cin.clear();
													lineCount = 1;
												}
										//ptr4 = symbolTable->search(tempTreePtr,operandArray[1]);
										//tempTreePtr->symbol = " ";
									}
									else if(charOperator == '-')
									{
										//value1 = (treeNode->value) - treeNode1->value;
										cout << setw(20) << expression  << setw(10) << (treeNode->value) - treeNode1->value << setw(13) << newRFlag << setw(6)<< nBit << setw(6) << iBit 
										<< setw(6) << xBit << endl;
										lineCount++; 
											if(lineCount == 20)
												{
													cout << "  Enter any key to continue:  " ;
													cin >> a;
													cin.clear();
													lineCount = 1;
												}
										//ptr4 = symbolTable->search(tempTreePtr,operandArray[1]);
										//tempTreePtr->symbol = " ";
									}

									else if(charOperator == ',')
									{
										cout << "  ERROR - expression: " <<expression << "  Number , Value. Illegeal indexing" << endl;
										lineCount++; 
											if(lineCount == 20)
												{
													cout << "  Enter any key to continue:  " ;
													cin >> a;
													cin.clear();
													lineCount = 1;
												}
									}									
								}
							}
					}

					// if both are number  1 1
				else if(check::checkNum(operandArray[1]) && check::checkNum(operandArray[0]))
				{
						num1 = (signed int) check::convertstrtoint(operandArray[0]);							
						num2 = (signed int) check::convertstrtoint(operandArray[1]);
						
								if(charOperator == '+'){
									value1 = num1 + num2;
									cout << setw(20) << expression  << setw(10) << value1 << setw(13) << " ABSOLUTE" << setw(6)<< nBit << setw(6) << iBit 
									<< setw(6) << xBit << endl;
									lineCount++; 
										if(lineCount == 20)
											{
												cout << "  Enter any key to continue:  " ;
												cin >> a;
												cin.clear();
												lineCount = 1;
											}
								}
								else if(charOperator == '-'){
									value1 = num1 - num2;
									cout << setw(20) << expression  << setw(10) << value1 << setw(13) << " ABSOLUTE" << setw(6)<< nBit << setw(6) << iBit 
									<< setw(6) << xBit << endl;
									lineCount++; 
										if(lineCount == 20)
											{
												cout << "  Enter any key to continue:  " ;
												cin >> a;
												cin.clear();
												lineCount = 1;
											}
									}

								else if(charOperator == ','){

									cout << "  ERROR - expression: " <<expression << "  Number , Number. Illegeal indexing" << endl;
									lineCount++; 
										if(lineCount == 20)
											{
												cout << "  Enter any key to continue:  " ;
												cin >> a;
												cin.clear();
												lineCount = 1;
											}
									}	
							
					}// ajustred RFlag both are  1 1 (number)

				else{

					if(charOperator == ','){
					cout << "  ERROR - expression : " << expression << "  illegeal indexing,improper resister used"<<endl;
					}
					
					else{

						cout << "  Error - expression : " << expression << " invalid operand used." <<endl;
					}


				  }
				}// adjustRFlag

				// not adjust rFlag
				else {

					if(operandArray[0].length()>6){
						operandArray[0] = operandArray[0].substr(0,6);
					}
					if(operandArray[1].length()>6){
						operandArray[0] = operandArray[1].substr(0,6);
					}
                         isNum1=check::checkNum(operandArray[0]);
					if(check::checkNum(operandArray[0])){

						cout << setw(20) << expression  << setw(10) << operandArray[0] << setw(13) << "  ABSOLUTE" << setw(6)<< nBit << setw(6) << iBit 
							<< setw(6) << xBit << endl;
						lineCount++; 
							if(lineCount == 20)
								{
									cout << "  Enter any key to continue:  " ;
									cin >> a;
									cin.clear();
									lineCount = 1;
								}

					}// expression is just a number w/o operators

					// if it string 
					else
					{		
						ptr2 = symbolTable->search(treeNode,operandArray[0]);

						//if it is in sym table
						if(ptr2 != NULL)
						{
							cout << setw(20) << expression  << setw(10) << treeNode->value << setw(13) ;
							if(treeNode->rflag)
								cout << " RELATIVE";
							else
								cout << "  ABSOLUTE" ;
							cout << setw(6)<< nBit << setw(6) << iBit << setw(6) << xBit << endl;
							lineCount++; 
								if(lineCount == 20)
									{
										cout << "  Enter any key to continue:  " ;
										cin >> a;
										cin.clear();
										lineCount = 1;
									}
						} 

						// not in symTable
						else
						{
							cout << "  Error -  the expression : " << expression << "   " <<operandArray[0] << "  wasn't located in symbol table" << endl;
							lineCount++; 
								if(lineCount == 20)
									{
										cout << "  Enter any key to continue:  " ;
										cin >> a;
										cin.clear();
										lineCount = 1;
									}
						}
					}	
				}// no ajustment required in rflag


			}// isExpValid


		
		}// else outer most expression
	}// while loop
			
	inputFile.close();
	
	cout<<"\n\t\t  LITERAL TABLE"<<endl;
	cout<<left<<setw(20)<<"  NAME"<<setw(20)<<"VALUE"<<setw(10)<<"LENGTH"<<setw(10)<<"ADDRESS"<<endl;
	literalTable->viewLiteral(literalNode);
	
	cout<<"\t\tSymbol Table:"<<endl;
		cout<<setw(12)<<"Symbol"<<setw(10)<<"Value"<<setw(7)<<"RFlag"<<setw(7) << "IFlag"<<setw(7)<<"MFlag"<<endl;
		symbolTable->view(treeNode); // displaying the symbol table using in-order traversal
	
		symbolTable->destroy(treeNode);// destroying the symbol table
 }



