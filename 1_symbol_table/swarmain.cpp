/**************************************************************************************************
*** NAME       : Swarangi Joshi                                                                ***
*** CLASS      : CSc 354                                                                        ***
*** ASSIGNMENT : 1                                                                              ***
*** DUE DATE   : 9-14-16                                                                      ***
*** INSTRUCTOR : Dr. George Hamer                                                                    ***
***************************************************************************************************
*** DESCRIPTION : This program reads from the input file label.txt and inserts symbols into the symbol
                  table. It then searches from another file and displays the symbol table.
***************************************************************************************************/

#include"swarbst.h"
#include"swarcheck.h"
#include<fstream>
#include<sstream>

using namespace std;
typedef BST* pointer;
    pointer symbolTable;
	TreePtr treeNode, ptr;

int main()
{
	   
       string a,ch,file,Symbol,Value,RFlag,MFlag,IFlag;
	   bool rFlag;
       int value;

	 symbolTable= new (nothrow) BST();
			
		 ifstream inputFile("label.txt");		
		
		 while(inputFile>>Symbol)//inserting symbols in the symbol table
		 {
               
			 for (int i=0; i<Symbol.length(); i++) // cconverting symbol to uppercase
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
	
	 cout<<"\n\n\nEnter the name for the search file : ";
		cin>>file;
		inputFile.open(file.c_str());

			while(inputFile>>Symbol)//searching the symbol in the symbol table 
			{
                                     
                 for (int k=0; k<Symbol.length(); k++) // converting symbol to upper case
	              {
		            Symbol[k]=toupper(Symbol[k]);
	              }             
				if(check::checksymbol(Symbol))
				{	
					ptr = symbolTable->search(treeNode,Symbol);

					if(ptr!= NULL)
					{						
						cout<<"  Found - "<<"Symbol: "<<setw(6)<<ptr->symbol<<setw(8)<<"Value:"<<setw(8)<<ptr->value
							<<setw(8)<<" rflag:"<<setw(3)<< ptr->rflag<<setw(8)<< " iflag:"<<setw(3)<<ptr->iflag
							<<setw(8)<<" mflag:"<<setw(3)<<ptr->mflag<<endl;
					}
					else
					{
						cout<<"  Error - "<<Symbol<<" not found in Symbol Table."<<endl;
					}
				}
			}
		cout << endl<< "Press any key to continue: " <<endl;
		cin >> a;

		cout<<"\t\tSymbol Table:"<<endl;
		cout<<setw(12)<<"Symbol"<<setw(10)<<"Value"<<setw(7)<<"RFlag"<<setw(7) << "IFlag"<<setw(7)<<"MFlag"<<endl;
		symbolTable->view(treeNode); // displaying the symbol table using in-order traversal
		symbolTable->destroy(treeNode);// destroying the symbol table

 }



