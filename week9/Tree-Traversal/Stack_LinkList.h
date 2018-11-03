#ifndef _LinkList
#define  _LinkList

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//Function to complete
//Basic operation: push pop
//Other useful operations.
//1. top(Stack); Access the element on the top of stack without modify.
//2. isEmpty(Stack); To know whether it is empty.
//3. isFull(Stack); To know whether it is full.
//4. copy(Stack,Stack);

typedef struct node* node_p;

typedef struct TreeNode* TreeNode_p;

typedef struct TreeNode{
	char key;
	TreeNode_p leftChild;
	TreeNode_p rightChild;
}TreeNode;

typedef struct node{
	TreeNode_p key;
	node_p next;
}node;

typedef struct {
	int capacity;
	node_p head;
}Stack,*Stack_p;

Stack_p initialStack();

void deleteStack(Stack_p);

bool isEmpty(Stack_p);

bool isFull(Stack_p);

bool push(Stack_p,TreeNode_p);

TreeNode_p pop(Stack_p);

void popAll(Stack_p);

TreeNode_p top(Stack_p);

//Copy s1 to s2
bool copy(Stack_p,Stack_p);

#endif
