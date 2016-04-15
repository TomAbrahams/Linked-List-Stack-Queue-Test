/*
Needed as a header file for the test item.
This is done in C++
Header files (LinkedList.h, LLStack.h, LLQueue.h)
Source files (LLStack.cpp, LLQueue.cpp, main.cpp)
*/
#pragma once
#include<iostream>
#include<stdio.h>

using namespace std;

class Node{

public:
	Node() { data = 0; prevLink = NULL; nextLink = NULL; }
	Node(int theData, Node*previous, Node*next) {
		data = theData; prevLink = previous;
		nextLink = next;
	}
	//Getter functions
	Node* getPrevLink() const { return prevLink; }
	Node* getNextLink() const { return nextLink; }
	int getData() const { return data; }
	//Setter functions
	void setPrevLink(Node* prev) { prevLink = prev; }
	void setNextLink(Node* next) { nextLink = next; }
	void setData(int theData) { data = theData; }
	~Node(){ data = 0; prevLink = NULL; nextLink = NULL; }
protected:
	int data;
	Node* prevLink;
	Node* nextLink;

};

class LinkedList{

public:
	LinkedList() { first = NULL; last = NULL; numberOfElements = 0; }
	int getNumberOfElements() { return numberOfElements; }
	Node* getFirst() { return first; }
	Node* getLast() { return last; }
	//Insert First
	void insertFirst(int theData){
		if (numberOfElements == 0)
		{
			first = new Node(theData, NULL, NULL);
			last = first;
			++numberOfElements;
		}
		else if (numberOfElements == 1)
		{
			last = first;
			first = new Node(theData, NULL, last);
			last->setPrevLink(first);
			++numberOfElements;
		}
		else
		{
			Node* current = first;
			first = new Node(theData, NULL, current);
			current->setPrevLink(first);
			++numberOfElements;
		}
	}
	void insertLast(int theData){
		if (numberOfElements == 0)
		{
			first = new Node(theData, NULL, NULL);
			last = first;
			++numberOfElements;
		}
		else if (numberOfElements == 1)
		{
			
			last = new Node(theData, first, NULL);
			first->setNextLink(last);
			++numberOfElements;
		}
		else
		{
			Node* current = last;
			last = new Node(theData, current, NULL);
			current->setNextLink(last);
			++numberOfElements;
		}
	}

	//Destroy List for Destructor
	void destroyList() {
		Node * current = first;
		while (first != NULL)
		{
			first = first->getNextLink();
			delete current;
			current = first;
			--numberOfElements;
		}
	}
	//Print
	void print() const{
		Node* current = first;
		while (current != NULL)
		{
			cout << current->getData() << " ";
			current = current->getNextLink();
		}
		cout << endl;
	}

	//Destructor
	~LinkedList() { destroyList(); }

protected:
	Node* first;
	Node* last;
	int numberOfElements;
};

