/**************************************************************************************************
*** NAME       : Swarangi Joshi                                                                ***
*** CLASS      : CSc 354                                                                        ***
*** ASSIGNMENT : 3                                                                              ***
*** DUE DATE   : 11-04-16                                                                      ***
*** INSTRUCTOR : Dr. George Hamer                                                                    ***
***************************************************************************************************
*** DESCRIPTION : This program is implemetation of Pass #1
***************************************************************************************************/
#include"swarbst.h"
#include"swarcheck.h"
#include"swarlit.h"
#include"swaropt.h"
#include<fstream>
#include<sstream>

using namespace std;
typedef BST* pointer;
    pointer symbolTable;
	TreePtr treeNode, ptr,treeNode1,symptr1, symptr2;
	EXP *literalTable;
	OPT *opcodeTable;
	literalPtr literalNode,ptr1;
	OpcodePtr opcodeptr,opcodeNode;
	int lineCount;
	string fileName;

	

int main()
{
	   
       string a,ch,file,Symbol,Value,RFlag,MFlag,IFlag,expression, literalValue, newRFlag = " ",errorMessage = " ",operandArray[2],ans,insLine,label,operation,operand,strLocCounter,strLengthOfProgram,oprandArray[2],equloc;
	   bool rFlag,isExpValid,xBit = false,nBit = false,iBit = false,error = false,adjustRFlag = false,isalphabet1,isalphabet2,isNum1,isNum2,isLiteral,isComment,valueUnary,equFlag = false;
       int value,literalLength,quotationCount,lineCount,opcodeFormat,equlocno=0,operationCount =0,split =0,literalCount = 0, locCounter, startAddress;
	signed int num1,num2,value1 = 0,i=0; 
    char charOperator = ' ',spaceLiteral = ' ',binaryOp = ' ';
	bool checkflag;
	string mnemonic, 
		   strOpcode, 
		   strFormat;
	int opcode, 
		format;

	string outString,outFileName,tempLabel = " ";
		
	
	
	TreePtr tempTreePtr,ptr2,ptr3,ptr4;

	 symbolTable= new (nothrow) BST();
			
		 ifstream inputFile;		
		
		 /*while(inputFile>>Symbol)//inserting symbols in the symbol table
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
         
		inputFile.close();*/
	    cout<<"  Enter the name for the test file : ";
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
								//cout << "  Error expression " << expression << "  indexing can only used with a resister" << endl;
							}
							else if(charOperator != '+' && charOperator != '-')
							{
								//cout << "  Error  epxpression:  " << expression<<" two values which are in symbol table but invalid operation used." << endl;
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
							//cout << "  Error - expression : " << expression << "  indexing format : Value , resister, value wasn't loacted in sym. table " << endl;

					} // else if 

						//one of them is null
					else if(ptr3 == NULL && charOperator == ',')
					{
						 if(operandArray[1] == "X"){

								
								if(treeNode->rflag)
								{
									
								}
									//cout << " RELATIVE";
								else
								{
									
								}
									//cout << "  ABSOLUTE" ;
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
									//cout << "  Error - expression : " << expression << "  improper resister used : " << operandArray[1] <<endl;
								}

						}

						else if((ptr2 == NULL || ptr3 == NULL) && charOperator != ',')
						{
							//cout << "  Error  epxpression:  " << expression<<" if binary operation with values,they should be in sym table." << endl;
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
							symbolTable->insert(treeNode1,operandArray[1],value1,false,false);
							ptr3 = symbolTable->search(treeNode1,operandArray[1]);
							
							check::RFlagValue(treeNode,treeNode1,charOperator,newRFlag,errorMessage,error);

							if(error)
								cout << errorMessage << endl;

							else
							{
								if(charOperator == '+')
								{
									value1 = (treeNode->value) + treeNode1->value;
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
									value1 = (treeNode->value) - treeNode1->value;
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

									//cout << "  ERROR - expression: " <<expression << "  Value , Number. Illegeal indexing" << endl;
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
							symbolTable->insert(treeNode,operandArray[0],value1,false,false);
							
							treeNode1 = symbolTable->search(treeNode1,operandArray[1]);
							ptr2 = symbolTable->search(treeNode,operandArray[0]);
	

							if(treeNode1 ==NULL)
							{
								//cout << "  ERROR - expression: " << expression << "  Number +/- value, but value doesn't exit in symbolTable." << endl;
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
										value1 = (signed int)(treeNode->value) + treeNode1->value;
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
										value1 = (treeNode->value) - treeNode1->value;
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
										//cout << "  ERROR - expression: " <<expression << "  Number , Value. Illegeal indexing" << endl;
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

									//cout << "  ERROR - expression: " <<expression << "  Number , Number. Illegeal indexing" << endl;
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
					//cout << "  ERROR - expression : " << expression << "  illegeal indexing,improper resister used"<<endl;
					}
					
					else{

						//cout << "  Error - expression : " << expression << " invalid operand used." <<endl;
					}


				  }
				}// adjustRFlag

				// not adjust rFlag
				else
					{

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
							//cout << "  Error -  the expression : " << expression << "   " <<operandArray[0] << "  wasn't located in symbol table" << endl;
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
                   checkflag = true;

			}// isExpValid


		
		}// else outer most expression
	}// while loop
			
	 
    inputFile.close();
	inputFile.open("instructions.txt");
    opcodeTable = new (nothrow) OPT();
	if(inputFile)
	{
		while(inputFile>>mnemonic)
		{
			for (int i=0; i<mnemonic.length(); i++) // converting symbol to uppercase
	           {
		         mnemonic[i]=toupper(mnemonic[i]);
	           } 
				inputFile>>strFormat>>strOpcode;
			
            format = check::convertstrtoint(strFormat);
			opcode = check::converthexstrtoint(strOpcode);
			
			

			opcodeTable->searchopcode(opcodeNode,mnemonic);

			if(opcodeptr==NULL)
				opcodeTable->insertopcode(opcodeNode,mnemonic,format,opcode);
		}
		inputFile.close();
		
    }

     
	inputFile.open(fileName.c_str());
	outFileName = fileName.substr(0,fileName.find('.'))+".int";
	ofstream fout(outFileName.c_str());

	//ofstream fout(outFileName);
	
	
	if(inputFile)
	{
		lineCount = 0;
		cout<<left<<setw(10)<<"LINE#"<<setw(10)<<"LOCCTR"<<setw(20)<<"LABEL"<<setw(20)<<"OPERATION"<<setw(15)<<"OPERAND"<<endl;
		fout<<left<<setw(10)<<"LINE#"<<setw(10)<<"LOCCTR"<<setw(20)<<"LABEL"<<setw(20)<<"OPERATION"<<setw(15)<<"OPERAND"<<endl;
		while(getline(inputFile, insLine))
		{
			label = "";
			operation = "";
			operand = "";
			
			isComment = check::parseInstructions(insLine, label, operation, operand);
			if(isComment==false)			
			{	
				lineCount++;
				tempLabel = label;
				for (int i=0; i<label.length(); i++) // converting symbol to uppercase
	           {
		         label[i]=toupper(label[i]);
	           } 
				for (int i=0; i<operation.length(); i++) // converting symbol to uppercase
	           {
		         operation[i]=toupper(operation[i]);
	           } 
				
				for(int i = 0 ; i < operand.length(); i++){

					if(operand[i] == '+' || operand[i] == '-')
					{
						operationCount++; 
					}
				}
				
				if(operation == "START" || operation == "END")
				{
					if(operation == "START")
					{
						locCounter = check::convertstrtoint(operand);
						startAddress = locCounter;
						label = label.substr(0,4);
						symptr1 = symbolTable->search(treeNode,label);
						if(symptr1 == NULL)
								symbolTable->insert(treeNode,label,locCounter,true,true);
					}
					strLocCounter = check::convertinttohexstr(locCounter);
					check::fiveDigitLC(strLocCounter);
					cout<<left<<setw(10)<<lineCount<<setw(10)<<strLocCounter<<setw(20)<<tempLabel<<setw(20)<<operation<<setw(15)<<operand<<endl;
					fout<<left<<setw(10)<<lineCount<<setw(10)<<strLocCounter<<setw(20)<<tempLabel<<setw(20)<<operation<<setw(15)<<operand<<endl;
					
				}
				else
				{
					if(label.size()!=0 && operation != "EQU")
					{
						label = label.substr(0,4);
						if(check::checksymbol(label)){
							symptr1 = symbolTable->search(treeNode,label);
							if(symptr1 == NULL){
								int temp = locCounter;
								symbolTable->insert(treeNode,label,locCounter,true,true);		
							}
						}
					}

					strLocCounter = check::convertinttohexstr(locCounter);
					

				    if(operation == "EQU")
					{	
						fout.close();
						equFlag = true;

						label = label.substr(0,4);
						symptr1 = symbolTable->search(treeNode,label);
						if(symptr1 == NULL)
						{
							if(operand=="*")
							{
									
								equloc = strLocCounter;
								if(check::checksymbol(label))
								{
									symbolTable->insert(treeNode,label,locCounter,true,true);
								}
								
							}

							 else
							 {

								bool n,i,x = false;
								if(check::checkExpression(operand,n,i,x,oprandArray,adjustRFlag,charOperator))
								{
									
									if(checkflag){
										bool flag ;
										if(newRFlag == "ABSOLUTE"){
											flag = false;
										}
										else if(newRFlag =="RELATIVE"){
											flag  = true;
										}
										symbolTable->insert(treeNode,label,equlocno,flag,true);
										equloc = check::convertinttohexstr(equlocno);

									}// prcoess exp
									
								}//is valid exp

							}// operand != *
						}// symptr1 == NULL, for EQU
						fout.open(outFileName.c_str(),ios::app);
					}
						
					
					
					if(equFlag)
					{
						check::fiveDigitLC(equloc);
						cout<<left<<setw(10)<<lineCount<<setw(10)<<equloc<<setw(20)<<tempLabel<<setw(20)<<operation<<setw(10)<<operand<<endl;
						fout<<left<<setw(10)<<lineCount<<setw(10)<<equloc<<setw(20)<<tempLabel<<setw(20)<<operation<<setw(10)<<operand<<endl;
					}

					else
					{
						check::fiveDigitLC(strLocCounter);
						cout<<left<<setw(10)<<lineCount<<setw(10)<<strLocCounter<<setw(20)<<tempLabel<<setw(20)<<operation<<setw(10)<<operand<<endl;
						fout<<left<<setw(10)<<lineCount<<setw(10)<<strLocCounter<<setw(20)<<tempLabel<<setw(20)<<operation<<setw(10)<<operand<<endl;
					}
					
					equFlag = false;

					if(operation == "WORD")
					{
						locCounter = locCounter + 3; 
					}
					else if(operation == "RESW")
					{
						locCounter = locCounter + (3*(check::convertstrtoint(operand)));
					}
					else if(operation == "BYTE")
					{
						if(check::checkLiteral(operand, literalValue, literalLength))
						{
							locCounter += literalLength;
						}
					}
					else if(operation == "RESB")
					{
						locCounter = locCounter + (check::convertstrtoint(operand));
					}
					else if(operation == "BASE")
					{
						locCounter += 0;

					}
					
					
					else if(operation == "EXTDEF")
					{

					}
					else if(operation == "EXTREF")
					{

					}
					else
					{
						if(operation[0]=='+'){
							opcodeptr= opcodeTable->searchopcode(opcodeNode,operation.substr(1,operation.length()));
							if(opcodeptr == NULL){
								cout << "  Error : instruction:  " <<operation <<"  is invalid. Couldn't find in opcodeTable."<<endl;
								//fout << "  Error : instruction:  " <<operation <<"  is invalid. Couldn't find in opcodeTable."<<endl;
							}

							else{

								if(opcodeNode->format == 3){
									opcodeFormat = 4;
									locCounter = locCounter + opcodeFormat;
								}

								else if(opcodeNode->format == 1 || opcodeNode->format ==2){
									cout << "  Error :  instruction " << " is invalid. Only Format 3 supports format 3 and 4."<<endl;
									//fout << "  Error :  instruction " << " is invalid. Only Format 3 supports format 3 and 4."<<endl;
								}
							}
						}
						 else
						 {   
					        opcodeptr= opcodeTable->searchopcode(opcodeNode,operation);

							// EQU command is handle in the begininng of the program so no more need to check it
							if(operation != "EQU")
							{
								if(opcodeptr == NULL){
									cout << "  Error : instruction:  " <<operation <<"  is invalid. Couldn't find in opcodeTable."<<endl;
									//fout << "  Error : instruction:  " <<operation <<"  is invalid. Couldn't find in opcodeTable."<<endl;
								}

								else {

									opcodeFormat = opcodeNode->format;
									locCounter = locCounter + opcodeFormat;	
								}
							}// except EQU command
							
						}
					}	
				
			
		
				
					
	              if(check::checkLiteral(operand, literalValue, literalLength))
						{
							ptr1 =literalTable->searchLiteral(literalNode, operand);
							if(ptr1==NULL)
							{
								literalCount++;
									literalTable->addLiteral(literalNode,operand,literalValue, literalLength,literalCount);
								
							}
					    }
					
	

				}    // else
	
			} //isComment		
}// while loop
	} // if file found 


	 else{
		cout<<"  ERROR: Couldn't open file: "+fileName<<endl;
		}

		inputFile.close();
		fout.close();
		//opcodeTable->destroyopcode(opcodeNode);
		//fout<<outString;
		strLengthOfProgram = check::convertinttohexstr(locCounter-startAddress);
		fout.open(outFileName.c_str(),ios::app);

		cout<<endl;
		fout<<endl;

		cout<<"LENGTH OF PROGRAM: "<<strLengthOfProgram<<endl;
		fout<<"LENGTH OF PROGRAM: "<<strLengthOfProgram<<endl;
		cout<<endl;
		fout<<endl;
	
	cout<<"\n\t\t  LITERAL TABLE"<<endl;
	cout<<left<<setw(12)<<"  NAME"<<setw(10)<<"VALUE"<<setw(7)<<"LENGTH"<<setw(7)<<"ADDRESS"<<endl;
	literalTable->viewLiteral(literalNode);
	/*cout<<"\n\t\t  Opcode TABLE"<<endl;
	cout<<setw(9)<<"mnemonic"<<setw(10)<<"format"<<setw(7)<<"opcode"<<endl;
	opcodeTable->viewopcode(opcodeNode);*/
	
	cout<<"\t\tSymbol Table:"<<endl;
		cout<<setw(12)<<"Symbol"<<setw(10)<<"Value"<<setw(7)<<"RFlag"<<setw(7) << "IFlag"<<setw(7)<<"MFlag"<<endl;
		symbolTable->view(treeNode); // displaying the symbol table using in-order traversal
	
		symbolTable->destroy(treeNode);// destroying the symbol table
}
