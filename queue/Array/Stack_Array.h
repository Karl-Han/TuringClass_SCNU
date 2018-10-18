#ifndef _Stack
#define _Stack

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

/*
 * Functions to implement:
 * Basic operation: enqueue dequeue
 * 1. front(); Access the first element
 * 2. back(); Access the last element
 * 3. isEmpty(); Judge whether it is empty
 * 4. isFull(); Judge whether it is full
 * 5. copy(); Copy one to another
 */

typedef struct Queue{
	int capacity;
	int head;
	int last;
	int count;
	int contain[0];
}Queue,*Queue_p;

Queue_p initialQueue(int size){
	Queue_p ins = (Queue_p)malloc(sizeof(Queue) + sizeof(int)*size);
	ins->capacity = size;
	ins->head = 0;
	ins->last = 0;
	ins->count = 0;
	return ins;
}

bool isEmpty(Queue_p obj){
	return (obj->count == 0);
}

bool isFull(Queue_p obj){
	return (obj->capacity-1 == obj->count);
}

bool enqueue(Queue_p obj,int x){
	if(isFull(obj)){
		printf("ERROR, it is full.");
		return 0;
	}
	int pos = obj->last % obj->capacity;
	obj->last++;
	obj->count++;
	obj->contain[pos] = x;
	return 1;
}

int dequeue(Queue_p obj){
	if(isEmpty(obj)){
		printf("ERROR, it is empty.");
		assert(0);
	}
	int pos = obj->head;
	obj->head++;
	return obj->contain[pos];
}

int front(Queue_p obj){
	if(isEmpty(obj)){
		printf("ERROR, it is empty.");
		assert(0);
	}
	return obj->contain[obj->head];
}

#endif
