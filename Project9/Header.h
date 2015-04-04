//Gabe Appleton, CS222
//This is the header file for the program which will solve the Towers of Hanoi puzzle
#ifndef _head_
#define _head_

#include <cstdlib>
#include <string>
#include <iostream>
#include "Stack.h"

using namespace std;

int main(int argc, char *argv[]);
int power (int base, int exponent);
void hanoi(int sz);
void move(Stack *list[], int prev, int next, int num);
void move(Stack *prev, Stack *next);
void otherMove(Stack *list[], int num);
void rechanoi(int sz, int inpole, int outpole);

#endif
