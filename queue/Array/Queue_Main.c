#include "Queue_Array.h"
#include <stdlib.h>

int main(){
	Queue_p ins = initialQueue(10);
	for(int i = 0;i < 10; i++){
		enqueue(ins,i*10+1);
	}
	enqueue(ins,101);
	front(ins);
	back(ins);
	Queue_p ins2 = NULL;
	copy(ins, ins2);
	copy(ins,ins);
	printf("\n");
	for(int i = 0;i < 11;i++){
		printf("%d th is: %d\n",i+1,dequeue(ins));
	}
	return 0;
}
