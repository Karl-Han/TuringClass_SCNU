#ifndef _Queue
#define _Queue

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>


typedef struct Queue{
	int capacity;
	int head;
	int last;
	int count;
	int contain[0];
}Queue,*Queue_p;

Queue_p initialQueue(int);

bool isEmpty(Queue_p);

bool isFull(Queue_p);

bool enqueue(Queue_p,int);

int dequeue(Queue_p);

int front(Queue_p);

int back(Queue_p);

bool copy(Queue_p,Queue_p);

#endif
