#include "Stack_LinkList.h"

Stack_p initialStack(){
	Stack_p ins = (Stack_p)malloc(sizeof(Stack));
	if(ins == NULL){
		printf("Malloc memory failed");
		assert(0);
	}
	ins->capacity = 0;
	ins->head = NULL;
	return ins;
}

void deleteStack(Stack_p obj){
	if(obj->head == NULL)
		return;
	node *temp = obj->head->next;
	node *temp1;
	free(obj->head);
	while(temp->next!= NULL){
		temp1 = temp->next;
		free(temp);
		temp = temp1;
	}
}

bool isEmpty(Stack_p obj){
	return (obj->head == NULL);
}

bool isFull(Stack_p obj){
	return false;
}

bool push(Stack_p obj,int x){
	node_p newNode = (node_p)malloc(sizeof(node));
	newNode->next = obj->head;
	newNode->key = x;
	obj->head = newNode;
	return 1;
}

int pop(Stack_p obj){
	if(obj->head == NULL){
		printf("ERROR, Stack is empty.");
		return -1;
	}
	int key = obj->head->key;
	node_p temp = obj->head->next;
	free(obj->head);
	obj->head = temp;
	return key;
}

void popAll(Stack_p obj){
	while(!isEmpty(obj))
		printf("%d  ",pop(obj));
}

int top(Stack_p obj){
	return obj->head->key;
}
