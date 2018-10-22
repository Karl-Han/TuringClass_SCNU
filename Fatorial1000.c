#include <stdio.h>
#include <stdlib.h>
#include <string.h>

short digit[10000];
int length = 0;

void fatorial(int fac){
	memset(digit,0,sizeof(short)*10000);
	digit[0] = 1;
	int carry = 0;
	int sum = 0;
	for(int i = 2;i <= fac;i++){
		;
		for(int j = 0;j < 10000;j++){
			if(digit[j] == 0){
				digit[j] = carry;
				//carry = 0;
				//sum = 0;
				continue;
			}
			sum = i * digit[j] + carry;
			digit[j] = sum % 10;
			carry = (sum - digit[j]) / 10;
		}
	}
	length = 9999;
	while(digit[length--] == 0);
	printf("%d\n",length);
}

int main(){
	int fac = 0;
	scanf("%d",&fac);
	fatorial(fac);
	for(int i = length-1;i >= 0;i--){
		printf("%d",digit[i]);
	}
	return 0;
}
