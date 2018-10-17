#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

Stack_p initialStack(int length){
	Stack_p s_p = (Stack*) malloc(sizeof(Stack) + sizeof(int)*length);
	s_p->last = -1;
	s_p->size = length;
	return s_p;
}

void deleteStack(Stack_p s){
	if(s != NULL)
		free(s);
}

bool isEmpty(Stack_p s){
	return (s->last == -1);
}

bool isFull(Stack_p s){
	return (s->last == s->size-1);
}

bool push(Stack_p s, int x){
	if(isFull(s))
		return false;
	int pos = ++(s->last);
	s->contain[pos] = x;
	return true;
}

int pop(Stack_p s){
	if(isEmpty(s)){
		printf("ERROR, Stack is empty.");
		return -1;
	}
	s->last--;
	return s->contain[s->last+1];
}

void popAll(Stack_p s){
	while(!isEmpty(s)){
		printf("%d\t",pop(s));
	}
}

int top(Stack_p s){
	return s->contain[s->last];
}

bool copy(Stack_p s1,Stack_p s2){
	if(s1 == s2)
		return false;
	for(int i = 0; i <= s1->last; i++){
		s2->contain[i] = s1->contain[i];
	}
	s2->last = s1->last;
	return true;
}
