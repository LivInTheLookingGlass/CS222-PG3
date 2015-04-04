//Gabe Appleton, CS222
//This is the header file for the Linked List Node used in this program
#ifndef _node_
#define _node_

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class LLN	{
private:
	int content;
	LLN *next;
public:
	LLN(int i, LLN* n);
	~LLN();
	int get();
	LLN *getNext();
	void setNext(LLN *n);
};

#endif
