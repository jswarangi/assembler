/**************************************************************************************************
*** NAME       : Swarangi Joshi                                                                ***
*** CLASS      : CSc 354                                                                        ***
*** ASSIGNMENT : 5                                                                              ***
*** DUE DATE   : 12-14-16                                                                     ***
*** INSTRUCTOR : Dr. George Hamer                                                                    ***
**************************************************************************************************
*** DESCRIPTION :Inplementation of Linker/Loader module. Text record processing, mordification ***
***				: record proceesing, printMemory operations are done in this file.             *** 
**************************************************************************************************/
#include "swarlink.h"
#include <fstream>



/********************************************************************
*** FUNCTION  LINK                                          ***
*********************************************************************
*** DESCRIPTION : Consructor.***
*** INPUT ARGS  : string, int                                     ***
*** OUTPUT ARGS : none											  **
*** IN/OUT ARGS : none              							  ***
*** RETURN      : none 									          ***
********************************************************************/
LINK::LINK(string loadAddress,int argc)
{
     string temp1;
	 temp1 = loadAddress;
	 if(loadAddress[4]='X')
	 {  temp1[4]='0';
	this->progaddr = strtoul(temp1.substr(0,temp1.length()).c_str(), NULL, 16);
	 }
	symbolTable = new(std::nothrow) BST;
	if(!symbolTable){
		cout << " Error :  Memory allocation fault." <<endl;
	}
	this->csAddr = progaddr;
	this->cslth = 0;
	this->execaddr = 0;
	this->noOfFiles = argc;
	this->primaryCST = true;
	this->adjustCsAddr = 0;
	this->addrPreviousCS = 0;
	
}

/********************************************************************
*** FUNCTION  passOne                                         ***
*********************************************************************
*** DESCRIPTION : process external sym tabel	***
*** INPUT ARGS  : char* []                                     ***
*** OUTPUT ARGS : none											  **
*** IN/OUT ARGS : none              							  ***
*** RETURN      : none 									          ***
********************************************************************/
void LINK::passOne(char* argv[]){

	string fileName,
		   line; 
	int count = 0,
		i = 0;
		TreePtr symPtr;
		
	
		cout<<"processing pass one of linker and loader"<<endl;
	cout << "\t\t  EXTERNAL SYMBOLTABLE"<<endl;
	cout<<setw(6)<<"CSECT"<<setw(7)<<"SYMBOL"<<setw(6)<<"ADDR"<<setw(7) << "CSADRR"<<setw(7)<<"LDADDR"<< setw(8) << " LENGTH"<<endl;
	while(this->noOfFiles != 0)
	{

		// file name as the first argument
		fileName = argv[count]; 

		ifstream readFile(fileName.c_str());
		//reading from the file
		if(readFile){
            
			while(getline(readFile,line))
			{
                
				if(line[0] == 'H')
				{       string progName, 
						startAddr,
						endAddr;
						int i = 5;
						progName = line.substr(1,4);
						startAddr = line.substr(5,6);
						endAddr = line.substr(11,6);
						
						
						this->cslth = strtoul(line.substr(11, line.length()).c_str(), NULL, 16);;			
						TreePtr symPtr =  this->symbolTable->search(progName);
						 
						if(symPtr == NULL){		 
							this->symbolTable->insert(progName,"",0,this->csAddr,0,this->cslth,false);
							}
					
				}
				else if(line[0] =='D')
				{
					string label,temp;
					temp = line.substr(1,line.length());
					while(temp[1] != '\0' && temp[1] !='\n'){
					label = temp.substr(0,4);
					int address = strtoul(temp.substr(4,6).c_str(), NULL, 16);;
					symPtr = this->symbolTable->search(label);
						if(symPtr == NULL){
							this->symbolTable->insert("",label,address,0,(this->csAddr + address),0,true);
						}
						temp = temp.substr(10,line.length());
				}
				}
				else if(line[0] == 'E'){
					int eRecordAddr = strtoul(line.substr(1,line.length()).c_str(), NULL, 16);
	                  this->execaddr = this->progaddr + eRecordAddr;
					this->symbolTable->view("symbol.txt");
				}
				else{
				}
			}
			readFile.close();
			this->primaryCST = false;
		}
		else{
			cout << "  Error : File: " << fileName <<" not found!" <<endl;
			this->primaryCST  = true;
		}
		
		count++;
		this->noOfFiles--;
		this->csAddr = this->csAddr+this->cslth;		
	}	
}


/********************************************************************
*** FUNCTION  passTwo	                                  ***
*********************************************************************
*** DESCRIPTION : generates memeory layout	***
*** INPUT ARGS  : char* []                                    ***
*** OUTPUT ARGS : none											  **
*** IN/OUT ARGS : none              							  ***
*** RETURN      : none 									          ***
********************************************************************/
void LINK::passTwo(char* argv[],int argc){
	string fileName,line; 
	
	int count = 0,
		i = 0;
	this->primaryCST = true;
	this->csAddr = this->progaddr;
	this->execaddr = this->progaddr;
	this->cslth = 0;
	this->noOfFiles = argc;
	cout<<"processing pass two of linker and loader"<<endl;
	while(this->noOfFiles != 0)
	{

		// file name as the first argument
		fileName = argv[count]; 

		ifstream readFile(fileName.c_str());
		//reading from the file
		if(readFile)
		{
            
			while(getline(readFile,line))
			{

				if(line[0] =='H')
				{	
						this->cslth = strtoul(line.substr(11, line.length()).c_str(), NULL, 16);			
						
						for(int i = 0; i <=this->cslth ; i++)
						{
						this->memory += "??";
						}
					
				}
				else if(line[0] == 'T')
				{
					string address,
						leng,
						objcode;
						int adjustedAddr;
						int add = strtoul(line.substr(1,6).c_str(), NULL, 16);
						int len = strtoul(line.substr(7,2).c_str(), NULL, 16);
						int add1 = 2*add;
						int len1 = 2*len;
							objcode = line.substr(9,line.length()-1);
	                if(this->primaryCST){//int j = 0;
		
		            for(int i = 0 ; i  < len1; i++)
					{
			            if(objcode[i] != '\0' && objcode[i] != '\n')
						{
							memory[add1 + i] = objcode[i];
							i++;
							if(objcode[i] != '\0' && objcode[i] != '\n')
							{
								memory[add1 + i] = objcode[i];
							}
						}
					}
				}
				else
				{

					for(int i = 0 ; i  < len1; i++)
					{
						if(objcode[i] != '\0' && objcode[i] != '\n')
						{
							memory[(2*this->addrPreviousCS)+ add1 + i] = objcode[i];
							i++;
							if(objcode[i] != '\0' && objcode[i] != '\n')
							{
								memory[(2*this->addrPreviousCS)+add1 + i] = objcode[i];
							}
						}
					}
		
				}
			}
				else if(line[0] =='M')
				{
					     string newAddr,label;
						char charOp;
						int mem;
						int add = strtoul(line.substr(1,6).c_str(), NULL, 16);
						int len = strtoul(line.substr(7,2).c_str(), NULL, 16);
						charOp = line[9];
						int i = 10,
						tempAddress,
						location =0;
					while(line[i] != '\0' && line[i] != '\n' && i != 14){
					label += line[i];
					i++;
					}

					while(label.length() <4){
						label += " ";
					}

						int adjustAdress;
						if(this->primaryCST)
							adjustAdress = 0;
						else
							adjustAdress = 2*this->addrPreviousCS;

						TreePtr ptr = this->symbolTable->search(label);

						if(ptr){

							if(ptr->isLabel){
								tempAddress = ptr->LDADDR;
							}
							else
								tempAddress = ptr->CSADDR;		
                                 int temp = strtoul(line.substr(1,6).c_str(), NULL, 16);
								location = 2*temp ;

						if(len == 5 || len == 6){
							location++;
									if(charOp == '+'){
											string memorySub = memory.substr(location+adjustAdress,5);
											mem = strtoul(memory.substr(location+adjustAdress,5).c_str(), NULL, 16);
											tempAddress = tempAddress +mem;
											newAddr = check::convertinttohexstr(tempAddress);
									}
									else if(charOp == '-'){
											string memorySub = memory.substr(location+adjustAdress,5);
											mem = strtoul(memory.substr(location+adjustAdress,5).c_str(), NULL, 16);
											tempAddress = tempAddress - mem;
											newAddr = check::convertinttohexstr(tempAddress);
			                        }
									else{
									}
								while(newAddr.length() < 5){
									newAddr = '0' +newAddr;
								}
								for( int j = 0 ; j <5; j++){				
									memory[location+adjustAdress+j] = newAddr[j];
								}
						}
					
					}
                }
				else if( line[0] =='E')
				{
					  int  eRecordAddr = strtoul(line.substr(1,6).c_str(), NULL, 16);
	                  this->execaddr = this->progaddr + eRecordAddr;
					  cout << endl;
					  this->addrPreviousCS += this->cslth;
				}	
}
			
			
			readFile.close();
			this->primaryCST = false;
		}
		else{

			cout << "  Error: File: " << fileName << " not found" <<endl;
			this->primaryCST = true;
		}
		count++;
		this->noOfFiles--;
		this->csAddr = this->csAddr +this->cslth;
	}
				fileName = "memload.txt";
				string	location;
					ofstream fout(fileName.c_str());

					int address =  this->progaddr;
					location = check::convertinttohexstr(address);

					while(location.length()< 5){
						location = "0"+location;
						}

					 count = 0;

					cout << setw(10) << "  ADDR" << setw(3)<< "0"<< setw(3)<< "1" << setw(3)<< "2" << setw(3)<< "3" << setw(3)<< "4" << setw(3)<< "5" << setw(3)<< "6" 
					<< setw(3)<< "7" << setw(3)<< "8" << setw(3)<< "9" << setw(3)<< "A" << setw(3)<< "B" << setw(3)<< "C"<< setw(3)<< "D" << setw(3)<< "E" << setw(3)<< "F" 
					<<endl;
					fout << setw(10) << "  ADDR" << setw(3)<< "0" << setw(3)<< "1" << setw(3)<< "2" << setw(3)<< "3" << setw(3)<< "4" << setw(3)<< "5" << setw(3)<< "6" 
					<< setw(3)<< "7" << setw(3)<< "8" << setw(3)<< "9" << setw(3)<< "A" << setw(3)<< "B" << setw(3)<< "C" << setw(3) << setw(3)<< "D"<<  "E" << setw(3)<< "F" 
					<<endl;

					for(int i = 0 ; i < memory.length() ; i += 2){

						if(count == 0){
							cout << setw(10) << location;
							fout << setw(10) << location;
						}

						if(memory[i] != '\0' && memory[i] != '\n')
						{
							cout <<setw(2)<< memory[i] ;
							fout <<setw(2) << memory[i];
						if(memory[i] != '\0' && memory[i] != '\n'){
							cout << memory[i+1];
							fout << memory[i+1];
						}

							count++;

							if(count == 16)
							{
							   address += 16;
								location = check::convertinttohexstr(address);

						while(location.length()< 5){
								location = "0"+location;
					
							}
						cout << endl;
						fout << endl;
						count = 0;
								
					}
				
					}
					
					
				}
   cout<<endl;				
}
