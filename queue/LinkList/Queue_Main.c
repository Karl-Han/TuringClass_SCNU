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
	printf("ins->front = %d\n",front(ins));
	printf("ins->back= %d\n",back(ins));
	Queue_p ins2 = initialQueue();
	ins2 = copy(ins);
	for(int i = 0;i < 11;i++){
		printf("%d th is: %d\n",i+1,dequeue(ins));
	}
	destoryQueue(ins);
	dequeueAll(ins2);
	destoryQueue(ins2);
	return 0;
}
