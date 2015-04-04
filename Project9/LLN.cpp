//Gabe Appleton, CS222
//This is the source file for the Linked List Node used in this program
#include <cstdlib>
#include <string>
#include <iostream>
#include "LLN.h"

using namespace std;

//constructor
LLN::LLN(int i, LLN* n)	{
	content = i;
	next = n;
}

//destructor
LLN::~LLN()	{
	delete next;
}

//returns the content of the node
int LLN::get()	{
	return content;
}

//returns the next node in the list
LLN *LLN::getNext()	{
	return next;
}

//sets the next node in the list
void LLN::setNext(LLN *n)	{
	next = n;
}
