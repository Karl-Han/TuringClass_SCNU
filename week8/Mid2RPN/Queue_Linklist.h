#ifndef _Queue
#define _Queue

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

typedef struct node* node_p;

typedef struct node{
	char* key;
	node_p next;
}node;

typedef struct Queue{
	node_p head;
	node_p last;
}Queue,*Queue_p;

Queue_p initialQueue();

void destoryQueue(Queue_p);

bool isEmpty(Queue_p);

bool enqueue(Queue_p,char*);

char* dequeue(Queue_p);

char* front(Queue_p);

char* back(Queue_p);

Queue_p copy(Queue_p);

void dequeueAll(Queue_p);

#endif
