#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Stack_LinkList_char.h"
#include "Queue_Linklist.h"

/*
 * I have consider that if we use int to represent both operators and operands,
 * it might cause confusion. But it could be solved by using notations.
*/

/*
 * When there is only + and -, we do not need to consider the priority of the
 * evaluation.
 */

//Input format: 1 + 2 * 3 - (4 + 5 * 6 ) / 7

bool isNum(char* str){
	return (str[0] > 47 || strlen(str) > 1);
}

Stack_p Mid2RPN_PlusAndMinus(char** seq,int length){
	Stack_p s = initialStack();
	Stack_p num = initialStack();
	Stack_p out = initialStack();
	for(int i = 0;i < length;i++){
		if(isNum(seq[i])){
			push(num,seq[i]);
			//char* op1 = pop(num);
			//push(out,op1);
		}
		else {
			if(isEmpty_stack(s)){
				char *op1 = pop(num);
				push(out,op1);
				push(s,seq[i]);
			}
			else {
				char* op2 = pop(num);
				push(out,op2);
				push(out,pop(s));
				push(s,seq[i]);
			}
		}
	}
	while(!isEmpty_stack(s)){
		if(!isEmpty_stack(num))
			push(out,pop(num));
		push(out,pop(s));
	}
	deleteStack(s);
	deleteStack(num);
	return out;
}

//No () edition
int getPriority_NoBranket(char* op){
	switch(*op){
		case '*': case'/':
			return 1;
		case '+': case'-':
			return 0;
		default: return 0;
	}
}

Queue_p Mid2RPN_Multiply(char** seq,int length){
	Stack_p s = initialStack();
	Stack_p num = initialStack();
	//Stack_p out = initialStack();
	Queue_p out = initialQueue();
	for(int i = 0;i < length;i++){
		if(isNum(seq[i])){
			push(num,seq[i]);
			//char* op1 = pop(num);
			//push(out,op1);
		}
		else {
			if(isEmpty_stack(s) || getPriority_NoBranket(seq[i]) > getPriority_NoBranket(top(s))){
				if(!isEmpty_stack(num)){
					char *op1 = pop(num);
					enqueue(out,op1);
				}
				push(s,seq[i]);
			}
			else {
				while(!isEmpty_stack(s) && !(getPriority_NoBranket(seq[i]) > getPriority_NoBranket(top(s)))){
					if(!isEmpty_stack(num)){
						char* op2 = pop(num);
						enqueue(out,op2);
					}
					enqueue(out,pop(s));
				}
				push(s,seq[i]);
			}
		}
	}
	while(!isEmpty_stack(s)){
		if(!isEmpty_stack(num))
			enqueue(out,pop(num));
		enqueue(out,pop(s));
	}
	deleteStack(s);
	deleteStack(num);
	return out;
}

char**  parse(char *str,int *length){
	int i = 0;
	int count = 0;
	char **strA = (char**)malloc(sizeof(char*)*20);
	do{
		int start = i;
		while(str[i] != ' ' && str[i] != '\0') i++;
		strA[count] = (char*)malloc(sizeof(char)*(i-start));
		for(int j = 0;j < (i-start);j++){
			strA[count][j] = str[start + j];
		}
	}while(count++,str[i++] != '\0');
	*length = count;
	return strA;
}

int getPriority(char* op){
	switch(*op){
		case '*': case'/':
			return 4;
		case '+': case'-':
			return 3;
		case ')': return 2;
		case '(': return 1;
		default: return 0;
	}
}

Queue_p Mid2RPN_Complete(char** seq,int length){
	Stack_p s = initialStack();
	Stack_p num = initialStack();
	Queue_p out = initialQueue();
	for(int i = 0;i < length;i++){
		if(isNum(seq[i])){
			push(num,seq[i]);
			//char* op1 = pop(num);
			//push(out,op1);
		}
		else {
			//Resolve the left bracket
			if(isEmpty_stack(s) || seq[i][0] == '('|| getPriority(seq[i]) > getPriority(top(s))){
				if(!isEmpty_stack(num)){
					char *op1 = pop(num);
					enqueue(out,op1);
				}
				push(s,seq[i]);
			}
			else {
				while(!isEmpty_stack(s) && !(getPriority(seq[i]) > getPriority(top(s)))){
					if(!isEmpty_stack(num)){
						char* op2 = pop(num);
						enqueue(out,op2);
					}
					enqueue(out,pop(s));
				}
				if(seq[i][0] == ')'){
					pop(s);
					continue;
				}
				push(s,seq[i]);
			}
		}
	}
	while(!isEmpty_stack(s)){
		if(!isEmpty_stack(num))
			enqueue(out,pop(num));
		enqueue(out,pop(s));
	}
	deleteStack(s);
	deleteStack(num);
	return out;
}

int main(){
	char str[50];
	int i = 0;
	//char ch;
	gets(str);
	//while((ch = getchar()) != EOF){
	//	str[i++] = ch;
	//}
	//i is aborted
	int *length = &i;
	char **seq = parse(str,length);
	//Done with plus and minus
	//Test case : 1 + 2 - 3
	//Stack_p ins = Mid2RPN_PlusAndMinus(seq,i);
	//Test case : 1 + 2 * 3 / 4 - 5 * 6 + 7
	//Stack_p ins = Mid2RPN_Multiply(seq,i);
	Queue_p ins = Mid2RPN_Complete(seq,i);
	dequeueAll(ins);
	return 0;
}
