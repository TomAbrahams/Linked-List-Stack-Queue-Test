/*
Linked List Stack header. Implement the functions in a separate cpp.
*/

#pragma once
#ifndef LLSTACK_H
#define LLSTACK_H

#include "LinkedList.h"

using namespace std;

class LLStack : public LinkedList
{
public:

	//Top
	int top() const;
	//Pop
	void pop();
	//Push
	void push(int theData);
	//Convert for every 3 same objects make only one of that object, else destroy
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
	void convert();
	//Print
	void print() const;




};

#endif
