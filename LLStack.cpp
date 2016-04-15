/*
To test yourself remove everything in this document and rewrite from scratch.
This is only one possible solution.
*/
#include "LLStack.h"

int LLStack::top() const
{
	if (numberOfElements == 0)
		cerr << "Stack is empty.";
	else
		return first->getData();
}
void LLStack::pop()
{
	if (numberOfElements == 0)
		cerr << "Stack is empty.";
	else
	{
		Node *temp = first;
		first = first->getNextLink();
		delete temp;
		numberOfElements--;
	}
}
void LLStack::push(int theData)
{
	
	//num 0
	if (numberOfElements == 0)
	{
		Node *theNode = new Node(theData, NULL, NULL);
		first = theNode;
		last = theNode;
		numberOfElements++;
	}
	//num 1
	else if (numberOfElements == 1)
	{
		
		first->setPrevLink(new Node(theData, NULL, last));
		first = first->getPrevLink();
		numberOfElements++;
	}
	//num > 1
	else
	{
		Node *current = first;
		current->setPrevLink(new Node(theData, NULL, first));
		first = current->getPrevLink();
		numberOfElements++;
	}

}
//Convert looks at 3 numbers at a time for your doubly linked list.
//And converts it to either a 1 or a 0 if all three are a 1 or 0.
//For Example:
//Input: 1 1 1 0 0 0 1 0 1
//Conversion:
// 1 1 1 = 1
//Store as top of stack version of Linked List
// 0 0 0 = 0
//Store as top of stack version of Linked List
// 1 0 1 = Nothing.
//Stack looks as follows
// | 0 |
// | 1 |
// -----
// Final output should be 1 0
// You can make an array in this case.
void LLStack::convert()
{
	int* arrHold = new int[numberOfElements];
	int arrCounter = 0;
	if (numberOfElements == 0)
		cerr << "The Stack is empty.";
	else
	{
		//check 3 elements
		int tracker = numberOfElements;		int sum = 0;
		
		while (tracker >= 3)
		{
			for (int i = 0; i < 3; i++)
			{
				sum += top();
				pop();
				--tracker;
			}
			if (sum == 0)
			{
				arrHold[arrCounter] = 0;
				arrCounter++;
				/*
				last->setNextLink(new Node(0, last, NULL));
				last = last->getNextLink();
				numberOfElements++;
				*/
			}
			else if (sum == 3)
			{
				arrHold[arrCounter] = 1;
				arrCounter++;
				/*
				last->setNextLink(new Node(1, last, NULL));
				last = last->getNextLink();
				numberOfElements++;
				*/
			}
			sum = 0;
		}
		while (tracker != 0)
		{
			pop();
			tracker--;
		}
		for (int i = 0; i < arrCounter; i++)
			push(arrHold[i]);
		delete [] arrHold;
	}
	
	//pop everything
	//push
}
void LLStack::print()const
{
	if (numberOfElements == 0)
		cerr <<  "The stack is empty.";
	else
	{
		Node *current = first;
		while (current != NULL)
		{
			cout << current->getData() << " ";
			current = current->getNextLink();
		}
	}
	
}
