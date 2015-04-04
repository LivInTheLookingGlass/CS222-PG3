//Gabe Appleton, CS222
//This is the header file for the stack used in this program
#ifndef _stack_
#define _stack_

#include <cstdlib>
#include <string>
#include <iostream>
#include "LLN.h"

using namespace std;

class LLN;

class Stack	{
private:
	LLN* top;
public:
	Stack();
	~Stack();
	int pop();
	int push(int i);
	int look();
};

#endif
