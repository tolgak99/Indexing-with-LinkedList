 #pragma once
#include "FileNameNode.h"
#include "WordTypeNode.h"





class IndexLinkedList {
private:
	WordTypeNode *head;
public:
	IndexLinkedList() :head(NULL) {}
	
	void addWord(const string &word, const string &fileName) {
		
		WordTypeNode *wordNode = new WordTypeNode(word);

		if (head == NULL) {
			head = wordNode;
		}
		else {
			WordTypeNode *walk = head;
			while (walk->next != NULL) {
				
				walk = walk->next;
				
			}
			
			walk->next = wordNode;
		}
		addFileName(word, fileName);
		
	}

	void addFileName(string word, string fileName)
	{
		
		WordTypeNode *wordWalk = head;
		FileNameNode *file1 = new FileNameNode(fileName);

	   if(head == NULL)
	  {
	     return;
	  }
	   else
	   {
	    
	     while(wordWalk != NULL)
		 {
		 
			 if(wordWalk->word == word)
			 {
			 
				 if(wordWalk->FileNameHead == NULL)
				 {
					 wordWalk->FileNameHead = file1;
					 break;
				 }
				 else
				 {
					 FileNameNode *fileWalk = wordWalk->FileNameHead;
					 while (fileWalk ->next != NULL) {
						 // wordWalk->wordFreq++;
						 fileWalk = fileWalk->next;
						 
					 }

					 fileWalk->next = file1;
					  break;
				 
				 }
				 
			 }
		 wordWalk = wordWalk->next;
		 
		 }



	   }
	
	}

	void printListOfFiles(const string &singleWordQuery) {
	
		WordTypeNode *walk = head;
		//walk->wordFreq=0;

	
		while (walk != NULL)
		{
		FileNameNode *walk2 = walk->FileNameHead;
			
			if(walk->word == singleWordQuery)
			{
			while(walk2 != NULL)
			{
				
				walk->wordFreq++;
				walk2 = walk2->next;
			}
			 cout <<"Word:" <<singleWordQuery <<" "<<walk->wordFreq <<" times."<<endl;
			break;
			}
	
			walk = walk->next;
			
			
		}
		
		
	}
	void printMostFrequentWords(int topWhat) {
		
		int first,second,third,i;
		int arr[10];
		int max=0;
		string word;

		WordTypeNode *walk = head;
		//walk->wordFreq=0;

	
		while (walk != NULL)
		{
		FileNameNode *walk2 = walk->FileNameHead;
		
		int second = topWhat;
			
			while(walk2 != NULL)
			{
				
				walk->wordFreq++;
				walk2 = walk2->next;
			}

			if(walk->wordFreq > max)
			{
				max = walk->wordFreq; 
				word = walk->word;
			}
			walk = walk->next;

		}
		
		cout << "Most repeating word: " <<"'"<< word << "' "<< max <<" times."<<endl;

	
	}
	void printLeastFrequentWords(int topWhat) {

		int min = 50;
		string word;

		WordTypeNode *walk = head;
		//walk->wordFreq=0;

	
		while (walk != NULL)
		{
		FileNameNode *walk2 = walk->FileNameHead;
		
		int second = topWhat;
			
			while(walk2 != NULL)
			{
				
				walk->wordFreq++;
				walk2 = walk2->next;
			}

			if(walk->wordFreq < min)
			{
				if(walk->wordFreq!=0)
				{
				min = walk->wordFreq; 
				word = walk->word;
				}
			}
			walk = walk->next;

		}

		cout << "Least repeating word: " <<"'"<< word << "' "<< min <<" times."<<endl;
	}
	
	

};