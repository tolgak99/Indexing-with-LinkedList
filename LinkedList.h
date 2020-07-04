/* #pragma once
#include "Node.h"
#include "Book.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;
class LinkedList {
private:
	Node *head;
public:
	LinkedList() :head(NULL) {

	} 

	void traverse()const
	{
		ofstream writeFile ("course.txt");
		Node *walk = head;
		
		while (walk != NULL)
		{
			writeFile <<walk->data.getNameBook()<<";"<< walk->data.getNameAuthor()<<"."<<endl;
			walk = walk->next;
		}
		

		writeFile.close();
	}

	void print()
	{
	Node *walk = head;
		cout << "\nLinkedList:"<<endl;
		while (walk != NULL)
		{
			cout <<walk->data.getNameBook()<<";"<< walk->data.getNameAuthor()<<endl;
			walk = walk->next;
		}
		cout << "NULL" << endl;
	}
	
	int getSize()const { 
		int cnt = 0;
		Node *walk = head;
		while (walk != NULL)
		{
			cnt++;
			walk = walk->next;
		}
		return cnt;
	}
		void deleteData(int data)//to be completed by students
	{
	}

		void deleteFirst()
	{
		if (head != NULL) {
			Node *p = head;
			head = head->next;
			delete p;
		}
	}
	void insertFirst(Book &data) {
		Node *p = new Node(data);
		p->next = head;
		head = p;
	}
	void insertLast(Book dat) {
		Node *newNode = new Node(dat);
		if (head == NULL) {
			head = newNode;
		}
		else {
			Node *walk = head;
			while (walk != NULL) {
				if (walk->next == NULL)
					break;
				walk = walk->next;
			}
			walk->next = newNode;
		}
	}
	void insertAt(Book dat, int pos) {

		if (pos == 0)//insert at first
		{
			Node *newNode = new Node(dat);
			newNode->next = head;
			head = newNode;
		}
		else {
			Node *prev = NULL, *walk = head;
			int cnt = 0;
			while (walk != NULL) {
				if (cnt == pos)
					break;
				prev = walk;
				walk = walk->next;
				cnt++;
			}
			if (cnt == pos) {
				Node *newNode = new Node(dat);
				prev->next = newNode;
				newNode->next = walk;
			}
		}
	}

	void deleteAt(int pos)
	{
		if ((pos<0) || (head == NULL)) return;
		if (pos == 0)
		{
			Node *oldHead = head;
			head = head->next;
			delete oldHead;
		}
		else {

			Node*walk = head, *prev = NULL;
			int cnt = 0;
			while (walk != NULL) {
				if (pos == cnt)
					break;
				prev = walk;
				walk = walk->next;
				cnt++;
			}//end of while
			if (pos == cnt)
			{
				prev->next = walk->next;
				delete walk;
			}
		}
	}

	void deleteAt_data(Book data)//to be completed by students
	{
		Node *walk = head;
		while(walk!=NULL)
		{
			if((walk->data.getNameBook()) == (data.getNameBook()))
			{
				cout << "Data siliniyor!"<<endl;
			}
			walk=walk->next;
		}
	}

	bool checkListEmpty(){
	
		if(head == NULL)
			return(true);
		else
			return(false);
	}

	int searchByBookname(string name){
	   int count=0;
	  Node *walk = head;

	  while(walk!=NULL)
	  {
		  if(walk->data.getNameBook() == name)
		    return(count);
		  else
			  count++;
	  
		  walk=walk->next;
	  
	  }
	
	}

	void update (string book_name,string book_update,int chose)
	{
	
	 Node *walk = head;

	  while(walk!=NULL)
	  {
		  if(walk->data.getNameBook() == book_name)
		  {
		      if(chose == 1)
			  {
				  walk->data.setNameBook(book_update);
			  }
			  else if(chose == 2)
			  {
				  walk->data.setNameAuthor(book_update);
				  cout << "Updated!"<<endl;
				  break;
			  }
			  
		  }
		  else
		  walk=walk->next;
	  
	  }
	
	}
};//end of Node 
*/