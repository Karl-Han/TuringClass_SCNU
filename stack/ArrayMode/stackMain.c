#include "stack.h"

int main(){
	Stack_p ins = initialStack(10);
	if(ins == NULL){
		printf("Malloc memory failed");
		return 1;
	}
	push(ins,10);
	push(ins,30);
	push(ins,20);
	push(ins,50);
	//50
	printf("%d ",top(ins));
	//50-20-30-10
	popAll(ins);
	pop(ins);
	push(ins,5);
	//5
	printf("%d ",pop(ins));
	popAll(ins);
	return 0;
}

