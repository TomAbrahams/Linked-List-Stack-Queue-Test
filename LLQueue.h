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
	void convert();
	//Print
	void print() const;




};

#endif
