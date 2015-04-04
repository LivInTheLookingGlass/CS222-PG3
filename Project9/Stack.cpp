//Gabe Appleton, CS222
//This is the source file for the stack used in this program
#include <cstdlib>
#include <string>
#include <iostream>
#include "Stack.h"

using namespace std;

//constructor
Stack::Stack()	{
	top = NULL;
}

//destructor
Stack::~Stack()	{
	delete top;
}

//this methode returns (and removes) the top item of the stack
int Stack::pop()	{
	if (top)	{
		int t = top->get();
		LLN *tmp = top;
		top = top->getNext();
		tmp->setNext(NULL);
		delete tmp;
		return t;
	}
	else
		return NULL;
}

//this methode adds an item to the top of the stack
int Stack::push(int i)	{
	top = new LLN(i,top);
	return i;
}
