/*
To test yourself remove everything in this document and rewrite from scratch.
This is only one possible solution.
*/
#include "LLStack.h"

LLStack::LLStack()
{

}
LLStack::~LLStack()
{

}

int LLStack::top() const
{
	return first->getData();
}

void LLStack::pop()
{
	if (numberOfElements != 0)
	{
		//Make current equal to first
		Node*current = first;
		//Shift first
		first = first->getNextLink();
		//delete current
		first->setPrevLink(NULL);
		--numberOfElements;
	}
	else
		cerr << "There are no elements that exist" << endl;



}

void LLStack::push(int theData)
{
	if (numberOfElements == 0)
	{
		first = new Node(theData, NULL, NULL);
		last = NULL;
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
		Node*current = first;
		current = first;
		first = new Node(theData, NULL, current);
		current->setPrevLink(first);
		++numberOfElements;
	}
}

void LLStack::print() const
{
	Node*current = first;
	while (current != NULL)
	{
		cout << current->getData() << " ";
		current = current->getNextLink();
	}
}

void LLStack::convert()
{
	//Create a place holder pointer
	Node* placeholder = last;
	//Have a counter
	int counter = numberOfElements;
	//Have a last choice
	int sum = 0;
	//Check 3 items as long as the pointers don't overlap.
	while (counter >= 3)
	{
		for (int i = 0; i < 3; i++)
		{
			sum += top();
			//Pop 3 elements.
			pop();
			--counter;
		}
		//Are the values the same then add that value after the end either 3 or 0
		if (sum == 3)
		{
			Node* current = last;
			last = new Node(1, current, NULL);
			current->setNextLink(last);
			++numberOfElements;
			
		}
		else if (sum == 0)
		{
			Node* current = last;
			last = new Node(0, current, NULL);
			current->setNextLink(last);
			++numberOfElements;
		}
		//Reset Sum
		sum = 0;
	}
	//Clean up loose ends.
	while (counter != 0)
	{
		pop();
		--counter;
	}
}
