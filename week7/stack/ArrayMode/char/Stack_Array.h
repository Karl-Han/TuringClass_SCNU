#ifndef _stack
#define  _stack

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to complete
//Basic operation: push pop
//Other useful operations.
//1. top(Stack); Access the element on the top of stack without modify.
//2. isEmpty(Stack); To know whether it is empty.
//3. isFull(Stack); To know whether it is full.
//4. copy(Stack,Stack);
//

typedef struct {
	int last;
	int size;
	char contain[];
}Stack,*Stack_p;

Stack_p initialStack(int);

void deleteStack(Stack_p);

bool isEmpty(Stack_p);

bool isFull(Stack_p);

bool push(Stack_p,char x);

char pop(Stack_p);

void popAll(Stack_p);

char top(Stack_p);

//Copy s1 to s2
bool copy(Stack_p,Stack_p);

#endif
