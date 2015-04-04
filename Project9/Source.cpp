//Gabe Appleton, CS222
//This is the main file for the program which will solve the Towers of Hanoi puzzle
#include <cstdlib>
#include <string>
#include <iostream>
#include "Header.h"

using namespace std;

//this is the main method, which calls all others
int main(int argc, char *argv[])	{
	string input;
	getline(cin,input);
	int in = stoi(input);
	hanoi(in);
	system("pause");
	return 0;
}

//this allows you to see the top item of a stack without disturbing it
int look(Stack *input)	{
	int i = input->pop();
	input->push(i);
	return i;
}

//this returns an exponential result, based off input
int power(int base,int exponent)	{
	int result = 1;
	for (int i = 1, j = base; i <= exponent; i++)
		result *= j;
	return result;
}

//this is the method which processes the Hanoi logic, and calls others accordingly
void hanoi (int sz)	{
	int Top_Current = 0;
	bool dir = sz % 2;
	Stack *towers[3] = {new Stack(), new Stack(), new Stack()};
	for (int i = sz; i>0; i--)
		towers[0]->push(i);
	int moves = power(2,sz);
	for (int i = 1; i < moves; i++) {
		if (i % 2)	{
			if (dir)	{
				int tmp = Top_Current;
				Top_Current = (Top_Current>=1)?Top_Current-1:2;
				move(towers,tmp,Top_Current,i);
			}
			else	{
				int tmp = Top_Current;
				Top_Current = (Top_Current + 1) % 3;
				move(towers,tmp,Top_Current,i);
			}
		}
		else
			otherMove(towers,i);
	}
	for (int i = 0; i < 3; i++)
		delete towers[i];
	cout << "Solved in " << moves-1 << " moves!" << endl;
}

//This method moves a disk from one pole to another
void move(Stack *list[], int prev, int next, int num)	{
	if (list[prev] && look(list[prev]))	{
		cout << "Moving disk " << look(list[prev]) << " from pole " << prev << " to pole " << next << '\t' << "Move: " << num << endl;
		list[next]->push(list[prev]->pop());
	}
}

//this is the deprecated version of the method above
void move(Stack *prev, Stack *next) {
	if (prev && look(prev))
		next->push(prev->pop());
}

//this method calculates the needed move for moving the smallest disk
void otherMove(Stack *list[], int num)     {
	int top=3, other=3, other2=3;
	for (int i = 0; i < 3; i++)	{
		if (look(list[i]) == 1)
			top = i;
		else if (other % 3 != other)
			other = i;
		else
			other2 = i;
	}
	if (look(list[other2]) && look(list[other]) > look(list[other2]) || !look(list[other]))	{
		other = other + other2;
		other2 = other - other2;
		other = other - other2;
	}
	cout << "Moving disk " << look(list[other]) << " from pole " << other << " to pole " << other2 << '\t' << "Move: " << num << endl;
	list[other2]->push(list[other]->pop());
}

//this is the sample method used in class, it is not used by me.
void rechanoi (int sz, int inpole, int outpole)	{
	 if (sz==0) return;
	 int midpole = 6-(inpole+outpole);
	 rechanoi (sz-1,inpole,midpole);
	 cout << "Move disk " << sz << " from pole " << inpole << " to pole " << outpole << "." << endl;
	 rechanoi (sz-1,midpole,outpole);
}
