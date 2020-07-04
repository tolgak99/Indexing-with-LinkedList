//Start with the following partial program(this code is also available at webonline)
//Create a new project and copy the following code in your project
//locate the project directory and extract AllDocs.rar under this directory.

//#include "FileNameNode.h"
#include "IndexLinkedList.h"
//#include "WordTypeNode.h"
#include <fstream>
#include <chrono> 
#include <ctype.h>
/*#include<string>
#include<iostream>
using namespace std;
*/



void getValidOption(int &option) {
	do {
		cin >> option;
	} while (!(option < 5 && option>0));
}
int  printDecoratedMenu(const string &indexCreationDuration ,  int time) {
	//draw the top border with corners
	//print the Title centered
	//print indexCreationDuration
	//draw the middle border 
	//print menu options
	//print the bottom border

	cout << " ======================================================================" <<endl;
	cout << "|                                                                      |" <<endl; 
	cout << "|                  Simple Document Retrieval System                    |" <<endl; 
	cout << "|                                                                      |" <<endl; 
	cout << "|                            ("<< time <<" minutes)                               |" <<endl; 
	cout << " ======================================================================" <<endl;
	cout << "|                                                                      |" <<endl; 
	cout << "|                                                                      |" <<endl; 
	cout << "|  1.	Enter a single keyword to list the document(s)(file names)     |" <<endl; 
	cout << "|                                                                      |" <<endl; 
	cout << "|  2.	Print the top word that appeared most frequently           |" <<endl; 
	cout << "|                                                                      |" <<endl; 
	cout << "|  3.	Print the top word that appeared least frequently          |" <<endl; 
	cout << "|                                                                      |" <<endl; 
	cout << "|  4.	Exit                                                           |" <<endl; 
	cout << "|                                                                      |" <<endl; 
	cout << " ======================================================================" <<endl;

	cout << "Option:";
	int option;
	getValidOption(option);
	return option;
}

string deleteNonAlphabetChar(string word)
{
	int len = word.length();
	string newWord;
	newWord.resize(len);
	int j=0;
	

	for(int i = 0; word[i] != '\0'; ++i)
    {
        if ((word[i] >= 'a' && word[i]<='z') || (word[i] >= 'A' && word[i]<='Z'))
        {
			word[i] = tolower(word[i]);
            newWord[j++] = word[i]; 

        }
    }
    newWord[j] = '\0';

	return (newWord);

}

void getWords (IndexLinkedList &index , const string directoryOfFiles)
{
	string filename;
	string word;
	string newWord;
	ifstream myfile ;
	int size;

	cout << "Getting words and setting to linked list" << endl;
	cout << "__________"<<endl;

	for(int i=0;i<100;i++)
	{
    filename = to_string(i);
	
	if(i%10 == 0 && i<100)
		cout << (char)219;
	else if (i>=99)
		cout <<endl<<"Completed!"<<endl;


	myfile.open(directoryOfFiles +"/" + filename + ".txt");

	 while (myfile >> word) {
		newWord = deleteNonAlphabetChar(word);			
		index.addWord(newWord,filename);
	
    }
	
	
	myfile.close();
	}
	
}



void main() {
	using namespace chrono; 
	string dirName = "AllDocs";
	IndexLinkedList index;
	string idxCreationTime;
	/*Start timer to measure duriation of index creation*/
	/*stop the timer*/
	/*convert time into string and store in idxCreationTime*/
	int opt;
	auto start = high_resolution_clock::now();
	getWords(index , dirName);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<minutes>(stop - start); 
	
	opt=printDecoratedMenu(idxCreationTime, duration.count() );
	while (opt != 4)
	{
	if(opt == 1)
	{
	        string queryWord;
			cout << "Enter the word: ";
			cin >> queryWord;
			index.printListOfFiles(queryWord);
			
	}
	else if (opt == 2)
	{
	index.printMostFrequentWords(10);
	}
	else if (opt == 3)
	{
	index.printLeastFrequentWords(10);
	}
	else if (opt == 4)
	{
	exit(0);
	}
	
	printDecoratedMenu(idxCreationTime, duration.count() );
	opt=printDecoratedMenu(idxCreationTime, duration.count() );
	}
	

}