#include "Stack_LinkList_char.h"

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

/*
* Free the memory allocated for the key.
*/
void deleteStack(Stack_p obj){
	if(obj->head == NULL)
		return;
	node *temp = obj->head->next;
	node *temp1;
	free(obj->head->key);
	free(obj->head);
	while(temp->next!= NULL){
		temp1 = temp->next;
		free(temp->key);
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

//Use strcpy to copy string
bool push(Stack_p obj,char* x){
	node_p newNode = (node_p)malloc(sizeof(node));
	newNode->next = obj->head;
	newNode->key = (char*) malloc(sizeof(x));
	strcpy(newNode->key,x);
	//newNode->key = x;
	obj->head = newNode;
	return 1;
}

//Result in memory leak.
char* pop(Stack_p obj){
	if(obj->head == NULL){
		printf("ERROR, Stack is empty.");
		return NULL;
	}
	char* key = obj->head->key;
	node_p temp = obj->head->next;
	free(obj->head);
	obj->head = temp;
	return key;
}

//Resolve memory leak to some extent.
void popAll(Stack_p obj){
	while(!isEmpty(obj)){
		char* temp = pop(obj);
		printf("%s  ",temp);
		free(temp);
	}
}

char* top(Stack_p obj){
	return obj->head->key;
}
