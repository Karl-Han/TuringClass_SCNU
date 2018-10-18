#include <stdlib.h>
#include "Queue_Linklist.h"

int main(){
	Queue_p ins = initialQueue();
	for(int i = 0;i < 10; i++){
		enqueue(ins,i*10+1);
	}
	enqueue(ins,101);
	enqueue(ins,201);
	enqueue(ins,301);
	printf("ins->front = %d",front(ins));
	printf("ins->back= %d",back(ins));
	Queue_p ins2 = initialQueue();
	printf("\n%p",&ins2);
	//copy(ins, ins2);
	printf("\n");
	printf("\n");
	//copy(ins,ins);
	printf("\n");
	for(int i = 0;i < 11;i++){
		printf("%d th is: %d\n",i+1,dequeue(ins));
	}
	dequeueAll(ins2);
	destoryQueue(ins);
	destoryQueue(ins2);
	return 0;
}
