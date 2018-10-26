/*
* Aborted for the reason that it is very complicate to get seq array with its
* elements' length specified.
*/
#include <stdio.h>
#include <stdlib.h>
#include "Stack_LinkList_char.h"
#include <string.h>
#include <stdbool.h>
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
			if(isEmpty(s)){
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
	while(!isEmpty(s)){
		if(!isEmpty(num))
			push(out,pop(num));
		push(out,pop(s));
	}
	deleteStack(s);
	deleteStack(num);
	return out;
}

char**  parse(char *ch,int *length){
	int i = 0;
	int count = 0;
	char **strA = (char**)malloc(sizeof(char*)*20);
	do{
		int start = i;
		while(ch[i] != ' ' && ch[i] != '\0') i++;
		strA[count] = (char*)malloc(sizeof(char)*(i-start));
		for(int j = 0;j < (i-start);j++){
			strA[count][j] = ch[start + j];
		}
	}while(count++,ch[i++] != '\0');
	*length = count;
	return strA;
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
	Stack_p ins = Mid2RPN_PlusAndMinus(seq,i);
	popAll(ins);
	return 0;
}

/*
			//char* op1 = pop(ins);
			//char* op2 = pop(ins);
			//int operand1 = atoi(op1);
			//int operand2 = atoi(op2);
			//char operatorr = (int)seq[i][0];
			//int numLength = 0;
			//switch(operatorr){
			//		case '+':
			//		{
			//			int sum = operand2 + operand1;
			//			int tempSum = sum;
			//			while(sum){
			//				numLength++;
			//				sum /= 10;
			//			}
			//			char* sumTemp = (char*)malloc(sizeof(char)*numLength+1);
			//			sprintf(sumTemp,"%d",tempSum);
			//			push(ins,sumTemp);
			//			free(sumTemp);
			//			break;
			//		}
			//		case '-':
			//		{
			//			int sum = operand2 - operand1;
			//			int tempSum = sum;
			//			while(sum){
			//				numLength++;
			//				sum /= 10;
			//			}
			//			char* sumTemp = (char*)malloc(sizeof(char)*numLength+1);
			//			sprintf(sumTemp,"%d",tempSum);
			//			push(ins,sumTemp);
			//			free(sumTemp);
			//			break;
			//		}
			//		case '*':
			//		{
			//			int sum = operand2 * operand1;
			//			int tempSum = sum;
			//			while(sum){
			//				numLength++;
			//				sum /= 10;
			//			}
			//			char* sumTemp = (char*)malloc(sizeof(char)*numLength+1);
			//			sprintf(sumTemp,"%d",tempSum);
			//			push(ins,sumTemp);
			//			free(sumTemp);
			//			break;
			//		}
			//		case '/':
			//		{
			//			int sum = operand2 / operand1;
			//			int tempSum = sum;
			//			while(sum){
			//				numLength++;
			//				sum /= 10;
			//			}
			//			char* sumTemp = (char*)malloc(sizeof(char)*numLength+1);
			//			sprintf(sumTemp,"%d",tempSum);
			//			push(ins,sumTemp);
			//			free(sumTemp);
			//			break;
			//		}
			//}
*/
