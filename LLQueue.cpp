/*
Erase this and start from scratch in order to do the assignment
*/

#include "LLQueue.h"

using namespace std;


void LLQueue::enqueue(int theData)
{
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
		Node * current = last;
		last = new Node(theData, current, NULL);
		current->setNextLink(last);
		++numberOfElements;
	}
}
void LLQueue::dequeue()
{
	if (numberOfElements == 0)
		cerr << "The list is empty" << endl;
	else if (numberOfElements == 1)
	{
		delete first;
		numberOfElements--;
		first = NULL;
		last = NULL;
	}
	else
	{
		Node* current = first;
		first = first->getNextLink();
		delete current;
		current = NULL;
		numberOfElements--;
	}
}
int LLQueue::top() const
{
	if (numberOfElements == 0){
		cerr << "The List is empty" << endl;
		return -999;
	}
	else
	{
		return first->getData();
	}
}
//Convert looks at 3 numbers at a time for your doubly linked list.
//And converts it to either a 1 or a 0 if all three are a 1 or 0.
//For Example:
//Input: 1 1 1 0 0 0 1 0 1
//Conversion:
// 1 1 1 = 1
// 0 0 0 = 0
// 1 0 1 = Nothing.
// Final output should be 1 0

void LLQueue::convert()
{
	//Convert
	//If three 1 then add to the end
	//If three 0 add to the end
	int counter = numberOfElements;
	int sum = 0;
	while (counter >= 3)
	{
		for (int i = 0; i < 3; i++)
		{
			sum += top();
			dequeue();
			counter--;
		}
		if (sum == 3)
		{
			enqueue(1);
		}
		else if (sum == 0)
		{
			enqueue(0);
		}
		//Reset counter.
		sum = 0;
	}
	while (counter != 0)
	{
		dequeue();
		counter--;
	}
}

void LLQueue::print() const
{
	Node* traverse = first;
	while(traverse != NULL)
	{
		cout << traverse->getData() << " ";
		traverse = traverse->getNextLink();
	}
	
}
