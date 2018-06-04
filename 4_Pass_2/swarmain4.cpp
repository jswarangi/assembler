/**************************************************************************************************
*** NAME       : Swarangi Joshi                                                                ***
*** CLASS      : CSc 354                                                                        ***
*** ASSIGNMENT : 4                                                                             ***
*** DUE DATE   : 11-16-16                                                                      ***
*** INSTRUCTOR : Dr. George Hamer                                                                    ***
***************************************************************************************************
*** DESCRIPTION : This program is implemetation of Pass #2
***************************************************************************************************/
#include"swarbst.h"
#include"swarcheck.h"
#include"swarlit.h"
#include"swaropt.h"
#include<fstream>
#include<sstream>
#include<iostream>
#include<ostream>
#include<string>

using namespace std;
typedef BST* pointer;
    pointer symbolTable;
	treePtr treeNode, ptr,symptr1, symptr2,symbolNode;
	EXP *literalTable;
	OPT *opcodeTable;
	literalPtr literalNode,ptr1;
	OpcodeNode *opcodeptr,*opcodeNode,*op;
	int lineCount;
	string fileName, outputfile;
	string a,ch,file,Symbol,Value,RFlag,MFlag,IFlag,expression, literalValue, newRFlag = " ",errorMessage = " ",operandArray[2],oprandArray[2],ans,insLine,label,operation,operand,strLengthOfProgram,equLc,strLocCounter;
	   bool rFlag,isExpValid,xBit = false,nBit = false,iBit = false,error = false,adjustRFlag = false,isalphabet1,isalphabet2,isNum1,isNum2,isLiteral,isComment,isDump,valueUnary,equFlag = false;
       int value,literalLength,quotationCount,opcodeFormat,equlocno=0,operationCount =0,split =0,literalCount = 0, locCounter, startAddress;
	signed int num1,num2,value1 = 0,i=0; 
    char charOperator = ' ',spaceLiteral = ' ',binaryOp = ' ';
	bool checkflag,oFlag;
	string mnemonic, 
		   strOpcode, 
		   strFormat,change[2];
	int opcode,format;
	int operandAddr;
	treePtr pt,base;

	string outString,fileline,outFileName,tempLabel = " ";
		
		string objProgramName, programName;
		bool controlSection;
	int lineNo,tsize = 0,tCount = 0,programLength =0;
	string startAdd,prgrmLen;

	string strLineNo,strlocCounter,tStartAddr,tLength,tobjCode,objCode;


	stringstream strStream,objStream;
	bool tBreak = true;

	string strDRecord ="",strrRecord ="",strMRecord ="";
	
	treePtr tempTreePtr,ptr2,ptr3,ptr4;
static	string processInstruction(string opcode, string operand);
static	string formatFour(string opcode, string operand);
static	string formatThree(string opcode, string operand);
static	string formatTwo(string opcode, string operand);
static	string formatOne(string operation,string operand);
static	string processExtref(string operand);
static	string processExtdef(string operand);
static	string processWord(string operand);
static	string processByte(string operand);

int main()
{
	   

	 symbolTable= new (nothrow) BST();
			
		 ifstream inputFile;		
		
		
	    cout<<"  Enter the name for the test file : ";
		cin>>fileName;	
		
		

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
			if(strOpcode[0] == '0'){
				oFlag = true;
			}
            format = check::convertstrtoint(strFormat);
			opcode = check::converthexstrtoint(strOpcode);
			
			

			opcodeptr = opcodeTable->searchOpcode(mnemonic);

			if(opcodeptr==NULL)
				opcodeTable->insertOpcode(mnemonic,format,opcode,oFlag);
		}
		inputFile.close();
		//opcodeTable->viewopcode(opcodeNode);
		
    }

     ofstream fout;
	inputFile.open(fileName.c_str());
	outFileName = fileName.substr(0,fileName.find('.'))+".int";
	fout.open(outFileName.c_str());

	//ofstream fout(outFileName);
	literalTable = new (nothrow) EXP();
	int lineC=0;
	if(inputFile)
	{
		lineCount = 0;
		cout<<left<<setw(8)<<"LINE#"<<setw(8)<<"LOCCTR"<<setw(12)<<"LABEL"<<setw(12)<<"OPERATION"<<setw(12)<<"OPERAND"<<endl;
		fout<<left<<setw(8)<<"LINE#"<<setw(8)<<"LOCCTR"<<setw(12)<<"LABEL"<<setw(12)<<"OPERATION"<<setw(12)<<"OPERAND"<<endl;
		while(getline(inputFile, insLine))
		{
			
			label = "";
			operation = "";
			operand = "";
			
			
			isComment = check::parseInstructions(insLine, label, operation, operand);
			if(isComment==false)			
			{	
					
				lineC++;
				lineCount++;
				tempLabel = label;
				//cout<<operand<<endl;
				if(check::checkLiteral(operand, literalValue, literalLength))
						{    operand = operand.substr(0,operand.length()-1);
							literalNode = literalTable->searchLiteral(operand);
							if(literalNode==NULL){
								literalCount++;
									literalTable->addLiteral(operand,literalValue, literalLength,literalCount);
								
							}
					}
				for(int i = 0 ; i < operand.length(); i++){

					if(operand[i] == '+' || operand[i] == '-'){
						operationCount++; 
					}
				}
				
				if(operation == "START" || operation == "END"|| lineC ==1)
				{
					if(operation == "START"||lineC ==1 )
					{
						if(operand == "\0"){
							locCounter = 0;
						}
						else{
							locCounter = check::convertstrtoint(operand);
						}
						startAddress = locCounter;
						label = label.substr(0,4);
						symbolNode = symbolTable->search(label);
						if(symbolNode == NULL)
								symbolTable->insert(label, locCounter,true,true);
					}
					strLocCounter = check::convertinttohexstr(locCounter);
					check::fiveDigitLC(strLocCounter);
					cout<<left<<setw(8)<<lineCount<<setw(8)<<strLocCounter<<setw(12)<<tempLabel<<setw(12)<<operation<<setw(12)<<operand<<endl;
					fout<<left<<setw(8)<<lineCount<<setw(8)<<strLocCounter<<setw(12)<<tempLabel<<setw(12)<<operation<<setw(12)<<operand<<endl;
				}
				else
				{
					if(label.size()!=0 && operation != "EQU")
					{
						label = label.substr(0,4);
						if(check::checksymbol(label)){
							symbolNode = symbolTable->search(label);
							if(symbolNode == NULL){
								int temp = locCounter;
								symbolTable->insert(label, locCounter, true,true);		
							}
						}
					}

					strLocCounter = check::convertinttohexstr(locCounter);
					

				    if(operation == "EQU")
					{	
						fout.close();
						equFlag = true;

						label = label.substr(0,4);
						symbolNode = symbolTable->search(label);
						if(symbolNode == NULL)
						{
							if(operand=="*"){
									
								equLc = strLocCounter;
								if(check::checksymbol(label)){
									symbolTable->insert(label,locCounter,true,true);
								}
								
							}

							 else{

								bool n,i,x = false;
								if(check::checkExpression(operand,n,i,x,oprandArray,adjustRFlag,charOperator)){
									
									if(EXP::processExp(outFileName,symbolTable,adjustRFlag,oprandArray,operand,equlocno,charOperator,newRFlag)){
										bool flag ;
										if(newRFlag == "ABSOLUTE"){
											flag = false;
										}
										else if(newRFlag =="RELATIVE"){
											flag  = true;
										}
										symbolTable->insert(label,equlocno,flag,true);
										equLc = check::convertinttohexstr(equlocno);

									}// prcoess exp
									
								}//is valid exp

							}// operand != *
						}// symbolNode == NULL, for EQU
						fout.open(outFileName.c_str(),ios::app);
					}
						
					
					
					if(equFlag){
						check::fiveDigitLC(equLc);
						cout<<left<<setw(8)<<lineCount<<setw(8)<<equLc<<setw(12)<<tempLabel<<setw(12)<<operation<<setw(12)<<operand<<endl;
						fout<<left<<setw(8)<<lineCount<<setw(8)<<equLc<<setw(12)<<tempLabel<<setw(12)<<operation<<setw(12)<<operand<<endl;
					}

					else{
						check::fiveDigitLC(strLocCounter);
						cout<<left<<setw(8)<<lineCount<<setw(8)<<strLocCounter<<setw(12)<<tempLabel<<setw(12)<<operation<<setw(12)<<operand<<endl;
						fout<<left<<setw(8)<<lineCount<<setw(8)<<strLocCounter<<setw(12)<<tempLabel<<setw(12)<<operation<<setw(12)<<operand<<endl;
					}

					
					
					equFlag = false;

					if(operation == "WORD")
					{
						locCounter = locCounter + 3; 
					}
					else if(operation == "RESW")
					{
						locCounter = locCounter + 3*check::convertstrtoint(operand);
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
						locCounter = locCounter + check::convertstrtoint(operand);
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
							opcodeNode = opcodeTable->searchOpcode(operation.substr(1,operation.length()));
							if(opcodeNode == NULL){
								cout << "  Error : instruction:  " <<operation <<"  is invalid. Couldn't find in opcodeTable."<<endl;
								fout << "  Error : instruction:  " <<operation <<"  is invalid. Couldn't find in opcodeTable."<<endl;
							}

							else{

								if(opcodeNode->format == 3){
									opcodeFormat = 4;
									locCounter = locCounter + opcodeFormat;
								}

								else if(opcodeNode->format == 1 || opcodeNode->format ==2){
									cout << "  Error :  instruction " << " is invalid. Only Format 3 supports format 3 and 4."<<endl;
									fout << "  Error :  instruction " << " is invalid. Only Format 3 supports format 3 and 4."<<endl;
								}
							}
						}
						 else
						 {
							opcodeNode = opcodeTable->searchOpcode(operation);

							// EQU command is handle in the begininng of the program so no more need to check it
							if(operation != "EQU"){
								if(opcodeNode == NULL){
									cout << "  Error : instruction:  " <<operation <<"  is invalid. Couldn't find in opcodeTable."<<endl;
									fout << "  Error : instruction:  " <<operation <<"  is invalid. Couldn't find in opcodeTable."<<endl;
								}

								else {

									opcodeFormat = opcodeNode->format;
									locCounter = locCounter + opcodeFormat;	
								}
							}// except EQU command
							
						}
						
				     }	

					/*if(check::checkLiteral(operand, literalValue, literalLength))
						{    operand = operand.substr(0,operand.length()-1);
							literalNode = literalTable->searchLiteral(operand);
							if(literalNode==NULL){
								literalCount++;
									literalTable->addLiteral(operand,literalValue, literalLength,literalCount);
								
							}
					}*/
					


				  } // else

			 }//isComment		
			}// while loop
		 }//if file Found

	 else{
		cout<<"  ERROR: Couldn't open file: "+fileName<<endl;
		}

		inputFile.close();
		fout.close();
		literalTable->dumpLiteral(lineCount, locCounter, outFileName);
		//fout<<outString;
		programLength = locCounter-startAddress;
		strLengthOfProgram = check::convertinttohexstr(locCounter-startAddress);
		fout.open(outFileName.c_str(),ios::app);

		cout<<endl;
		fout<<endl;

		cout<<"LENGTH OF PROGRAM: "<<strLengthOfProgram<<endl;
		fout<<"LENGTH OF PROGRAM: "<<strLengthOfProgram<<endl;
		cout<<endl;
		fout<<endl;
		
		
		
		cout<<endl;
		fout<<endl;

		
		
		fout.close();	
		

	//outputfile = fileName+".txt";
	objProgramName = fileName.substr(0,fileName.find('.'))+".o";
	string input = fileName.substr(0,fileName.find('.'))+".int";
	//cout<<input;
	string outfile = fileName.substr(0,fileName.find('.'))+".txt";
	fout.open(outfile.c_str());
	ofstream objOutput(objProgramName.c_str());
	 ifstream intermediateFile;
	 intermediateFile.open(input.c_str());
	
	if(intermediateFile)
	{
		getline(intermediateFile, insLine);
		fout<<insLine<<left<<setw(12)<<"OBJCODE"<<endl;
		cout <<insLine<<left<<setw(12)<<"OBJCODE"<<endl;
		while(getline(intermediateFile, insLine))
		{   
	          
			   if(check::parse(insLine, strLineNo, strLocCounter, label, strOpcode, operand))
			   {
				change[0] = " ";
				change[1] = " ";
				locCounter = check::converthexstrtoint(strLocCounter);
				lineNo = check::convertstrtoint(strLineNo);

				if(check::convertstrtoint(strLineNo) ==1){

						programName = label.substr(0,4);
						startAdd = check::convertinttohexstr(startAddress);
						prgrmLen = check::convertinttohexstr(programLength);
						while(startAdd.size()<6)
							startAdd = "0" + startAdd;
						while(prgrmLen.size()<6)
							prgrmLen = "0" + prgrmLen;
						objStream<<left<<"H^"<<setw(7)<<label<<"^"<<startAdd<<"^"<<prgrmLen<<endl;
				
				}
				
				if((strOpcode == "START" || strOpcode == "END"))
				{
					
					objCode = " ";
				}
				else if(strOpcode == "WORD")
				{
					objCode = processWord(operand);
					if(change[0] != " "){
							strMRecord += change[0] + '\n';
						}
					if(change[1] != " "){
							strMRecord += change[1] + '\n';

						}
					
				}
				else if(strOpcode == "RESW")
				{
					objCode = " ";
				}
				else if(strOpcode == "BYTE")
				{
					objCode	= processByte(operand);
				}
				else if(strOpcode == "RESB")
				{
					objCode = " ";
				}
				else if(strOpcode == "BASE")
				{
					objCode	= " ";
					
					base = symbolTable->search(operand.substr(0,4));
					
					if(base == NULL){
						strStream << "  Error:  instructions base consists operand  "<< operand <<" which is not found in sym table."<<endl;
					}
				}
				
				else if(strOpcode == "EQU")
				{						
					objCode = " ";
				}
				else if(strOpcode == "EXTDEF")
				{
					objCode = " ";
					strDRecord = processExtdef(operand);
					objStream<<strDRecord<<endl;
				}
				else if(strOpcode == "EXTREF")
				{
					controlSection = true;
					strrRecord = processExtref(operand);
					objStream<<strrRecord;
				}
				else if(strOpcode[0] == '=')
				{     
					objCode = literalTable->searchLiteral(strOpcode)->value;
				}
				else
				{								
					objCode = processInstruction(strOpcode, operand);
					if(strOpcode[0] == '+'){
						if(change[0] != " "){
							strMRecord += change[0] + '\n';
						}
						if(change[1] != " "){
							strMRecord += change[1] + '\n';

						}
					}
						
				}
				cout << left<<setw(8)<<strLineNo<<setw(8)<<strLocCounter<<setw(12)<<label<<setw(12)<<strOpcode<<setw(12)<<operand<<setw(12)<<objCode<<endl;
				strStream<<left<<setw(8)<<strLineNo<<setw(8)<<strLocCounter<<setw(12)<<label<<setw(12)<<strOpcode<<setw(12)<<operand<<setw(12)<<objCode<<endl;
				
				if(objCode != " ")
				{
					if(tBreak){
						tStartAddr = check::convertinttohexstr(locCounter);
						tsize = objCode.length() /2;						
						while(tStartAddr.size()<6)
							tStartAddr = "0" + tStartAddr;						
						tBreak = false;

						tobjCode = objCode;
						tCount++;
					}
					else{
						tsize += objCode.length() /2;
						tobjCode += "^"+objCode;
						tCount++;

					}

					if(tCount ==10){
						tLength = check::convertinttohexstr(tsize);
						while(tLength.size()<2)
							tLength = "0" + tLength;
						objStream<<"T^"<<tStartAddr<<"^"<<tLength<<"^"<<tobjCode<<endl;
						tBreak = true;
						tsize  = 0;
						tStartAddr ="\0";
						tobjCode="\0";
						tCount = 0;
					}
					//objStream<<"T^"<<tStartAddr<<"^"<<tLength<<"^"<<objCode<<endl;
				}

				else{
					if(tsize !=0){
						tLength = check::convertinttohexstr(tsize);
						while(tLength.size()<2)
							tLength = "0" + tLength;
						objStream<<"T^"<<tStartAddr<<"^"<<tLength<<"^"<<tobjCode<<endl;
						tBreak = true;
						tsize  = 0;
						tStartAddr ="\0";
						tobjCode="\0";
						tCount = 0;
					}
				}

			}
		
		
		}
		objStream<<strMRecord;
		objStream<<"E^"<<startAdd;
		strStream<<endl;
		cout << "LENGTH OF PROGRAM: "<<check::convertinttohexstr(programLength)<<endl;
		strStream<<"LENGTH OF PROGRAM: "<<check::convertinttohexstr(programLength)<<endl;	
		strStream<<endl;
		fout<<strStream.str();
		fout.close();		
		
		cout<<"OBJECT PROGRAM"<<endl;
		cout<<objStream.str();
		objOutput<<objStream.str();
		inputFile.close();
		fout.close();
		objOutput.close();
	}
	
	else
		cout<<"  ERROR:Can't open file "+fileName<<endl;
	symbolTable->view(outfile);
		
	literalTable->viewLiteral(outfile);

}
   

/********************************************************************
*** FUNCTION processInstruction                                   ***
*********************************************************************
*** DESCRIPTION : It processes the instruction    				  ***
*** INPUT ARGS  : string				                           ***
*** OUTPUT ARGS : none   										  ***
*** IN/OUT ARGS :		 										  ***
*** RETURN      : string									  ***
********************************************************************/
string processInstruction(string strOpcode, string operand)
{
	string objCode = " ";
	int addressingMode;
	OpcodeNode* opcodeNode;
	int opcodeValue;
	if(strOpcode[0]=='+')
		{
			
			opcodeNode = opcodeTable->searchOpcode(strOpcode.substr(1));
		}
	else {
		opcodeNode = opcodeTable->searchOpcode(strOpcode);
		}

	if(opcodeNode){
		if((opcodeNode->format == 1 ||opcodeNode->format == 2) && strOpcode[0] =='+'){

			cout << "  Error : instruction " << strOpcode << " isn't compatible for format 4" <<endl;
			return objCode;
		}

		if(strOpcode[0]=='+')
		{
		
			objCode = formatFour(strOpcode.substr(1),operand);
		}
		else
		{
		
			if(opcodeNode->format==3)
			{
				objCode = formatThree(strOpcode,operand);
			}
			else if(opcodeNode->format ==2)
			{
				objCode = formatTwo(strOpcode,operand);
			}
			else if(opcodeNode->format ==1){
				objCode = formatOne(strOpcode,operand);
			}
		}
	}
	else{
		cout << " Error : " << strOpcode << " wasn't found in opcode table." <<endl;		
	}
	return objCode;
}

/********************************************************************
*** FUNCTION formatFour                                   ***
*********************************************************************
*** DESCRIPTION : It preforms format four operation				  ***
*** INPUT ARGS  : string				                           ***
*** OUTPUT ARGS : none   										  ***
*** IN/OUT ARGS :		 										  ***
*** RETURN      : string									  ***
********************************************************************/
string formatFour(string strOpcode, string operand)
{ string objCode = " ";
	bool n = false,
		i = false,
		x = false,
		rFlag = false,
		isDump = false;
	string newRFlag, value;
	char charOp = ' ';
	string expression[2]= {" " , " "};
	int firstPart = 0 , 
		temp = 0,
		secondPart = 0,
		length = 0;
	string firstString= " " , 
		   secondString = " " ;

	OpcodeNode* opcodeNode = opcodeTable->searchOpcode(strOpcode);

	firstPart  = opcodeNode->opcode;

	if(operand!="\0")	
	{
		if(check::checkExpression(operand,n,i,x,expression,rFlag,charOp)){
			if( n && i)
				firstPart += 3;
			else if(n)
				firstPart += 2; 
			else if(i)
				firstPart += 1;
			
			if(charOp == ','){				
					string temp = expression[1];
						if(toupper(temp[0]) != 'X'){
							cout << "  Error: On operand " << operand << " Only X resister can be used as indexing. " <<endl;
					return objCode;
					}				
			}

			if(x){
				temp = 9;
			}
			else{
				temp = 1;
			}

			if(EXP::processExp("error",symbolTable,rFlag,expression,operand,secondPart,charOp,newRFlag)){
				treePtr pt0 = symbolTable->search(expression[0]);
				treePtr pt1 = symbolTable->search(expression[1]);
				if(controlSection){	

					

					if(pt0){

						change[0] = "M^";
						string t = check::convertinttohexstr(locCounter+1);

						while(t.length() < 6){
							t = '0' + t;
						}
						change[0] += t + "^05^" ;

						
							change[0] += '+' + expression[0].substr(0,4);
						
					}
					if(pt1){

						change[1] = "M^";
						string t = check::convertinttohexstr(locCounter+1);

						while(t.length() < 6){
							t = '0' + t;
						}
						change[1] += t + "^05^" ;

						
						
							change[1] += charOp + expression[1].substr(0,4);
						
					}	
				
				}
				else{
					
					if(pt0){
						secondPart = pt0->VALUE;
						change[0] = "M^";
						string t = check::convertinttohexstr(locCounter+1);

						while(t.length() < 6){
							t = '0' + t;
						}
						change[0] += t + "^05^" ;

					}
					else if(pt1){
						secondPart = pt1->VALUE;
						
						change[1] = "M^";
						string t = check::convertinttohexstr(locCounter+1);

						while(t.length() < 6){
							t = '0' + t;
						}
						change[1] += t + "^05^" ;

						
					}
					else{

						 cout << "  Error: operand :  " << operand << " wasn't located in symbol table."<<endl;
						return objCode;			  
					 }
				}
			}
		}

		else if(check::checkLiteral(operand,value,length)){
			
			firstPart += 3;
			temp = 1;
			literalPtr ptr = literalTable->searchLiteral(operand);

			if(ptr){
				secondPart = ptr->address; 
			}

			else{

				cout << "  Error: Literal: " << operand << "  wasn't located in literal table" <<endl;
			}
			
		}
	}
	else
	{
		secondPart = 0;
		temp = 1;
		firstPart += 3;
	}
			
	
	firstString = check::convertinttohexstr(firstPart)+ check::convertinttohexstr(temp);
	if(opcodeNode->oFlag){
		firstString = '0'+firstString;
	}
	secondString = check::convertinttohexstr(secondPart);
	while(firstString.size()<3)
		firstString = firstString + '0';
	while(secondString.size()<5)
		secondString = '0' + secondString;
	if(secondString.length() >5){
		secondString = secondString.substr(secondString.length()-5,secondString.length()-1);
	}
	
	objCode = firstString + secondString;
	
	
	return objCode;
}

/********************************************************************
*** FUNCTION formatThree                                   ***
*********************************************************************
*** DESCRIPTION : It preforms format three operation				  ***
*** INPUT ARGS  : string				                           ***
*** OUTPUT ARGS : none   										  ***
*** IN/OUT ARGS :		 										  ***
*** RETURN      : string									  ***
********************************************************************/
string formatThree(string stropcode, string operand)
{
	string objCode = " ";
	bool n = false,
		i = false,
		x = false,
		rFlag = false,
		isDump = false;
	char charOp = ' ';
	string value;
	int length = 0;
	string expression[2]= {" " , " "};
	int firstPart = 0 , 
		temp = 0,
		secondPart = 0;
	string firstString= " " , 
		   secondString = " " ;
	OpcodeNode* opcodeNode = opcodeTable->searchOpcode(strOpcode);
	firstPart  = opcodeNode->opcode;
	if(operand!="\0")	
	{
		if(check::checkExpression(operand,n,i,x,expression,rFlag,charOp))
		{
			if( n && i)
				firstPart += 3;
			else if(n)
				firstPart += 2; 
			else if(i)
				firstPart += 1;
			
			if(charOp == ','){				
					string temp = expression[1];
						if(toupper(temp[0]) != 'X'){
						cout << "  Error: On operand " << operand << " Only X resister can be used as indexing. " <<endl;
					return objCode;
					}
				
			}

			string Temp = expression[0];
			if(isdigit(Temp[0] )){
				secondPart= check::convertstrtoint(Temp);			
			}

			else{
				treePtr symPtr = symbolTable->search(expression[0].substr(0,4));
				if(symPtr){

					if(!symPtr->IFLAG){
					cout << "  Error: Only format 4 instruction can handle label with false i-flag"<< endl;
					return objCode;
					}
				// x bit
				if(x){
					if(symPtr->VALUE > 2047){
						temp = 12;
						if(base){
							secondPart = symPtr->VALUE - (base->VALUE);
						}
						else{
							cout << "  Error: instruction and operand " << strOpcode << "  " << operand << " memory out of range and no base used" << endl;
							return objCode;
						}
						
					}
					else {
						temp = 10;
						secondPart = symPtr->VALUE - (locCounter + opcodeNode->format);
					}

				}
				// with out x bit
				else{
					if(symPtr->VALUE > 2047){
						temp = 4;
						if(base){
							secondPart = symPtr->VALUE - (base->VALUE);
						}
						else{
							cout << "  Error: instruction and operand " << strOpcode << "  " << operand << " memory out of range and no base used" << endl;
							return objCode;
						}
						

					}
					else {
						temp = 2;
						secondPart = symPtr->VALUE - (locCounter + opcodeNode->format);
					}
				}


		  }
		else{

			    cout << "  Error: operand :  " << expression[0] << " wasn't located in symbol table."<<endl;
				return objCode;
			  
		  }
		}
		  
		
		}
		else if(check::checkLiteral(operand,value,length)){
			
			firstPart += 3;
			temp = 2;
			literalPtr ptr = literalTable->searchLiteral(operand);

			if(ptr){

				if(ptr->address > 2047){

					if(base){
						temp = 4;
						secondPart = ptr->address - (base->VALUE); 
					}
					else{
							cout << "  Error: instruction and operand " << strOpcode << "  " << operand << " memory out of range and no base used" << endl;
							return objCode;
					}
				}

				else{

					secondPart = ptr->address - (locCounter + opcodeNode->format);
				}
				 
			}
			else{

				cout << "  Error: Literal: " << operand << "  wasn't located in literal table" <<endl;
				return objCode;
			}
					
		}

		
	}
	else
	{
		firstPart += 3;
		temp = 0;
		secondPart = 0;
		
	}

	firstString = check::convertinttohexstr(firstPart)+ check::convertinttohexstr(temp);
	if(opcodeNode->oFlag){
		firstString = '0'+firstString;
	}
	secondString = check::convertinttohexstr(secondPart);
	while(firstString.size()<3)
		firstString = firstString + '0';
	while(secondString.size()<3)
		secondString = '0' + secondString;

	if(secondString.length() >3){
		secondString =secondString.substr(secondString.length()-3,secondString.length()-1);
	}
	
	objCode = firstString + secondString;
	

	
	return objCode;
}

/********************************************************************
*** FUNCTION formatTwo                                 ***
*********************************************************************
*** DESCRIPTION : It preforms format Two operation				  ***
*** INPUT ARGS  : string				                           ***
*** OUTPUT ARGS : none   										  ***
*** IN/OUT ARGS :		 										  ***
*** RETURN      : string									  ***
********************************************************************/
string formatTwo(string stropcode, string operand)
{string objCode = " ";
	bool n,i,x,rFlag;
	char charOperator =' ';
	string splitResister[2];
	int firstPart = 0 ,	secondPart = 0;
	string firstString = " ",
		   secondString = " ";
	OpcodeNode* opcodeNode = opcodeTable->searchOpcode(strOpcode);
	firstPart = opcodeNode->opcode;
	
	if(check::locate(operand,'@')||check::locate(operand,'#')){
		cout << "  Error :  instruction : " <<strOpcode << " addresing is only allowed in format3/4" <<endl;
		return objCode;
	}

	if(check::locate(operand,'+')||check::locate(operand,'-')){
		cout << "  Error: insturction : " << strOpcode << " uniary/binary operation  is allowed in format3/4" <<endl;
		return objCode;
	}
	
	if(check::locate(operand,','))
	{
		

		if(check::checkExpression(operand,n,i,x,splitResister,rFlag,charOperator)){

			if((splitResister[0]) == "A"){
				firstString = check::convertinttohexstr(firstPart);
				while(firstString.size()<2)
					firstString =  firstString + "0";
				objCode = firstString+'0'+check::convertinttostr(check::check::findRegisterValue(splitResister[1]));
				return objCode;
			}
			else{		
				secondString = check::convertinttostr(check::findRegisterValue(splitResister[0])) + check::convertinttostr(check::findRegisterValue(splitResister[1]));
			}
		}
	}
	else
	{
		if(check::checkExpression(operand,n,i,x,splitResister,rFlag,charOperator)){

			secondString = check::convertinttostr(check::findRegisterValue(splitResister[0]));
		}
		
	}
	firstString = check::convertinttohexstr(firstPart);
	//secondString = check::convertinttohexstr(check::convertstrtoint(secondString));
	while(firstString.size()<2)
		firstString =  firstString + "0";
	while(secondString.size()<2)
		secondString =  secondString + "0";
	objCode = firstString + secondString;
	return objCode;
}

/********************************************************************
*** FUNCTION formatOne                                 ***
*********************************************************************
*** DESCRIPTION : It preforms format One operation				  ***
*** INPUT ARGS  : string				                           ***
*** OUTPUT ARGS : none   										  ***
*** IN/OUT ARGS :		 										  ***
*** RETURN      : string									  ***
********************************************************************/
string formatOne(string operation, string operand){

	string objcode = " ";
	if(operand !=" "){
		cout << "  Error : Format1 instruction " << operation << " can't have operand" <<endl;
	}

	else{

		OpcodeNode* opcodeNode = opcodeTable->searchOpcode(operation);

		if(opcodeNode){
			objcode =  check::convertinttohexstr(opcodeNode->opcode);
			while(objcode.length() <2){
				objcode += '0';
			}
		}
		else{
			cout << "  Error: instruction " << operation << " wasn't located in op code table " <<endl;
		}
	}
		
	 return objcode ;  
}


/********************************************************************
*** FUNCTION processExtref                                   ***
*********************************************************************
*** DESCRIPTION : It preforms extref 			  ***
*** INPUT ARGS  : string				                           ***
*** OUTPUT ARGS : none   										  ***
*** IN/OUT ARGS :		 										  ***
*** RETURN      : string									  ***
********************************************************************/
string processExtref(string operand)
{
	string rRecord;
	stringstream srtStream;
	int commaPos;
	string temp = "\0";
	
	srtStream<<left<<"R^";

	int count = check::charCount(operand,',');

	if(count == 0){
		symbolTable->insert(operand.substr(0,4),0,0,1);		
		treePtr ptr = symbolTable->search(operand.substr(0,4));

		if(ptr){
			ptr->IFLAG = 0;
		}

		srtStream << operand.substr(0,4) <<endl;
	}
	else{

		for(int i = 0 ; i < operand.length(); i++){

			if( operand[i] == ','){
				 
				srtStream << temp.substr(0,4) << "^";
				symbolTable->insert(temp.substr(0,4),0,0,1);
				treePtr ptr = symbolTable->search(temp.substr(0,4));

				if(ptr){
					ptr->IFLAG = 0;
				}
				temp = "\0";
			
			}

			else{
				temp += operand[i];
			}

		}
		srtStream << temp.substr(0,4) <<endl;
		symbolTable->insert(temp.substr(0,4),0,0,1);		
		treePtr ptr = symbolTable->search(temp.substr(0,4));

		if(ptr){
				ptr->IFLAG = 0;
		 }

	}
	
	rRecord = srtStream.str();
	return rRecord;
}

/********************************************************************
*** FUNCTION processExtdef                                   ***
*********************************************************************
*** DESCRIPTION : It preforms extdef 			  ***
*** INPUT ARGS  : string				                           ***
*** OUTPUT ARGS : none   										  ***
*** IN/OUT ARGS :		 										  ***
*** RETURN      : string									  ***
********************************************************************/
string processExtdef(string operand)
{
	string dRecord,temp;	
	stringstream srtStream;
	
	string address = "\0";
	
	srtStream<<left<<"D";

	int count = check::charCount(operand,',');

	if(count == 0){


		//symbolTable->insert(operand.substr(0,4),0,0,1);
		treePtr ptr = symbolTable->search(operand.substr(0,4));	
		
		if(ptr){
			srtStream << operand.substr(0,4) << "^";
			address = check::convertinttohexstr(ptr->VALUE);

			while(address.length() <6){
				address = "0"+address;
			}

			srtStream << address;
		}

		else{
			cout << "  Error:  Label : " << operand << " used with extdef instruction wasn't found in sym tabel." << endl;
			return dRecord;
		}
	}
	
	else{

		for(int i = 0 ; i < operand.length(); i++){

			if( operand[i] == ','){
				treePtr ptr = symbolTable->search(temp.substr(0,4));
				if(ptr){
					srtStream << "^" << temp.substr(0,4) << "^";
					address = check::convertinttohexstr(ptr->VALUE);

					while(address.length() <6){
						address = "0"+address;
					}

					srtStream << address;
				}

				else{
					cout << "  Error:  Label : " << operand << " used with extdef instruction wasn't found in sym tabel." << endl;
					return dRecord;
					}
				 
				 temp = "\0";
				 address = "\0";
			}

			else{
				temp += operand[i];
			}

		}
		treePtr ptr = symbolTable->search(temp.substr(0,4));
				if(ptr){
					srtStream << "^" << temp.substr(0,4) << "^";
					address = check::convertinttohexstr(ptr->VALUE);

					while(address.length() <6){
						address = "0"+address;
					}

					srtStream << address;
				}

				else{
					cout << "  Error: On operand : " << operand <<" Label : " << temp << " wasn't found in sym tabel." << endl;
					return dRecord;
					}

	}
	
	dRecord = srtStream.str();
	
	return dRecord;
}

/********************************************************************
*** FUNCTION processWord                                   ***
*********************************************************************
*** DESCRIPTION : It process Word			  ***
*** INPUT ARGS  : string				                           ***
*** OUTPUT ARGS : none   										  ***
*** IN/OUT ARGS :		 										  ***
*** RETURN      : string									  ***
********************************************************************/
string processWord(string operand)
{
	string objCode = "\0",
		expression[2] = {" "," "},
		adjustedFlag;

	bool n,i,x,rFlag;
	int value;
	char charOp;
	

	if(check::checkExpression(operand,n,i,x,expression,rFlag,charOp)){
		if(EXP::processExp("error",symbolTable,rFlag,expression,operand,value,charOp,adjustedFlag)){

				treePtr pt0 = symbolTable->search(expression[0]);
				treePtr pt1 = symbolTable->search(expression[1]);

				if(pt0){

					change[0] = "M^";
					string t = check::convertinttohexstr(locCounter);

						while(t.length() < 6){
							t = '0' + t;
						}

						
						
							change[0] = change[0] + t + "^06^" + "+"+ expression[0].substr(0,4);
						
				}

				if(pt1){

					change[1] = "M^";
					string t = check::convertinttohexstr(locCounter);

						while(t.length() < 6){
							t = '0' + t;
						}

						
					
							change[1] = change[1] + t + "^06^" + charOp+ expression[1].substr(0,4);
						
				}				
			
			objCode= check::convertinttohexstr(value);

			while(objCode.length() < 6){
				objCode = '0' + objCode;
			}
		}
	}
	return objCode;
}

/********************************************************************
*** FUNCTION processByte                                 ***
*********************************************************************
*** DESCRIPTION : It process byte			  ***
*** INPUT ARGS  : string				                           ***
*** OUTPUT ARGS : none   										  ***
*** IN/OUT ARGS :		 										  ***
*** RETURN      : string									  ***
********************************************************************/
string processByte(string operand)
{
	string objCode;
	string value;
	int length = 0;
	bool isDump;
	check::checkLiteral(operand,value,length);
	return (objCode = value);
}

