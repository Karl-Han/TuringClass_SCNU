#include "Queue_Linklist.h"

Queue_p initialQueue(){
	Queue_p ins = (Queue_p)malloc(sizeof(Queue));
	ins->head = NULL;
	ins->last = NULL;
	return ins;
}

void destoryQueue(Queue_p obj){
	if(obj->head == NULL)
		return;
	node_p temp = obj->head;
	while(temp->next != NULL){
		node_p temp1 = temp->next;
		free(temp);
		temp = temp1;
		temp1 = temp1->next;
	}
}

bool isEmpty(Queue_p obj){
	return (obj->head == NULL);
}

//Insert the node in the tail instead of the head,
//because it is more easy to implement.
bool enqueue(Queue_p obj,int x){
	node_p ins = (node_p)malloc(sizeof(node));
	if(ins == NULL)
		return 0;
	ins->key = x;
	ins->next = NULL;
	if(obj->head == NULL){
		obj->head = ins;
		obj->last = ins;
		return 1;
	}
	obj->last->next = ins;
	obj->last = obj->last->next;
	return 1;
}

int dequeue(Queue_p obj){
	if(isEmpty(obj)){
		printf("ERROR, it is empty.");
		return -1;
	}
	int tar = obj->head->key;
	node_p temp = obj->head;
	obj->head = obj->head->next;
	free(temp);
	return tar;
}

int front(Queue_p obj){
	return obj->head->key;
}

int back(Queue_p obj){
	return obj->last->key;
}

//Copy obj1 to obj2
bool copy(Queue_p obj1,Queue_p obj2){
	if(obj1->head == NULL || obj1 == obj2){
		destoryQueue(obj2);
		printf("obj2 set to NULL");
		return 1;
	}
	if(obj2 != NULL)
		destoryQueue(obj2);
	printf("\n%p",&obj2);
	obj2 = initialQueue();
	node_p temp = obj1->head;
	while(temp != NULL){
		enqueue(obj2,temp->key);
		temp = temp->next;
	}
	return 1;
}

void dequeueAll(Queue_p obj){
	while(!isEmpty(obj))
		dequeue(obj);
	//node_p temp = obj->head;
	//node_p temp1 = NULL;
	//while(temp != NULL){
	//	temp1 = temp->next;
	//	free(temp);
	//	temp = temp1;
	//}
}
