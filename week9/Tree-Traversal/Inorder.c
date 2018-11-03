#include <stdio.h>
#include <stdlib.h>
#include "Stack_LinkList.h"

void visit(TreeNode_p now){
	if(now != NULL)
		printf("%c ",now->key);
}

void inorderTraversal(TreeNode_p root){
	Stack_p ins = initialStack();
	push(ins,root);
	while(!isEmpty(ins)){
		TreeNode_p n = pop(ins);
		if(n == NULL){
			n = pop(ins);
			if(n == NULL)
				return;
			visit(n);
			push(ins,n->rightChild);
		}
		else {
			push(ins,n);
			push(ins,n->leftChild);
		}
	}
}

TreeNode_p initialTreeNode(char x){
	TreeNode_p newN = (TreeNode_p)malloc(sizeof(TreeNode));
	newN->key = x;
	newN->leftChild = NULL; 
	newN->rightChild = NULL;
	return newN;
}

TreeNode_p setChild(TreeNode_p root,char left,char right){
	root->leftChild = initialTreeNode(left);
	root->rightChild = initialTreeNode(right);
	return root;
}

TreeNode_p setChildNode(TreeNode_p root,TreeNode_p left,TreeNode_p right){
	root->leftChild = left;
	root->rightChild = right;
	return root;
}

int main(){
	TreeNode_p root = initialTreeNode('F');
	TreeNode_p L = initialTreeNode('B');
	TreeNode_p LL = initialTreeNode('A');
	TreeNode_p LR = initialTreeNode('D');
	setChildNode(L,LL,LR);
	setChild(LR,'C','E');
	TreeNode_p RRL = initialTreeNode('H');
	TreeNode_p RR = initialTreeNode('I');
	TreeNode_p R = initialTreeNode('G');
	setChildNode(RR,RRL,NULL);
	setChildNode(R,NULL,RR);
	setChildNode(root,L,R);
	inorderTraversal(root);
	return 0;
}
