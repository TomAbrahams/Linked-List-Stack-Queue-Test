/*
Implement the functions in a separate cpp file. Solutions are provided.
*/
#ifndef LLQUEUE_H
#define LLQUEUE_H

#include "LinkedList.h"

using namespace std;

class LLQueue : public LinkedList
{
public:

	//Top
	int top() const;
	//DeQueue
	void dequeue();
	//Enqueue
	void enqueue(int theData);
	//Convert
	//Convert looks at 3 numbers at a time for your doubly linked list.
	//And converts it to either a 1 or a 0 if all three are a 1 or 0.
	//For Example:
	//Input: 1 1 1 0 0 0 1 0 1
	//Conversion:
	// 1 1 1 = 1
	// 0 0 0 = 0
	// 1 0 1 = Nothing.
	// Final output should be 1 0
	void convert();
	//Print
	void print() const;




};

#endif
