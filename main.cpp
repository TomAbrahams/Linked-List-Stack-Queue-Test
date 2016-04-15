#include<iostream>

#include "LLStack.h"
//#include "LLQueue.h"


using namespace std;

int main()
{
	LLStack list1;
	//List 1 = {1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1}
	list1.insertFirst(1);
	list1.insertFirst(1);
	list1.insertFirst(1);
	list1.insertFirst(0);
	list1.insertFirst(0);
	list1.insertFirst(1);
	list1.insertFirst(1);
	list1.insertFirst(0);
	list1.insertFirst(1);
	list1.insertFirst(1);
	list1.insertFirst(1);
	list1.insertFirst(1);
	list1.print();
	cout << "\nLet's test convert" << endl;
	cout << "Expected: 1 1" << endl;
	list1.convert();
	cout << "Result  :";
	list1.print();
	cout << endl << "Wait" << endl;

	//List 2 = {1, 0, 0 | ,0 ,0, 0, | 1, 1 ,1 | 1 ,1, 0}
	LLStack list2;
	list2.insertLast(1);
	list2.insertLast(0);
	list2.insertLast(0);
	list2.insertLast(0);
	list2.insertLast(0);
	list2.insertLast(0);
	list2.insertLast(1);
	list2.insertLast(1);
	list2.insertLast(1);
	list2.insertLast(1);
	list2.insertLast(1);
	list2.insertLast(0);
	cout << "List2 :";
	list2.print();
	cout << "\nLet's test convert" << endl;
	cout << "Expected: 0 1" << endl;
	list2.convert();
	cout << "Result  :";
	list2.print();
	cout << endl << "Wait" << endl;
 	system("Pause");
	

	

	return 0;
}
