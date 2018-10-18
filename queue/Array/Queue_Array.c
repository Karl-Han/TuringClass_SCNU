#include "Queue_Array.h"

/*
 * Functions to implement:
 * Basic operation: enqueue dequeue
 * 1. front(); Access the first element
 * 2. back(); Access the last element
 * 3. isEmpty(); Judge whether it is empty
 * 4. isFull(); Judge whether it is full
 * 5. copy(); Copy one to another
 */

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
		return -1;
	}
	int pos = obj->head;
	obj->head++;
	obj->count--;
	return obj->contain[pos];
}

int front(Queue_p obj){
	if(isEmpty(obj)){
		printf("ERROR, it is empty.");
		assert(0);
	}
	return obj->contain[obj->head];
}

int back(Queue_p obj){
	if(isEmpty(obj)){
		printf("ERROR, it is empty.");
		assert(0);
	}
	return obj->contain[obj->last];
}

//Copy obj1 to obj2
bool copy(Queue_p obj1,Queue_p obj2){
	if(obj1 == obj2)
		return 1;
	if(obj2 != NULL)
		free(obj2);
	obj2 = initialQueue(obj1->capacity);
	int ptr = obj1->head;
	while(ptr != obj1->last){
		obj2->contain[ptr] = obj1->contain[ptr];
		ptr = ptr + 1 % obj1->capacity;
	}
	return 1;
}

