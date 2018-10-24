#include <stdio.h>
#include <stdlib.h>
#include <string.h>

short digit[10000];
int length = 0;

/*
 * TO DO
 * 1. Improve the efficiency by decreasing the postion to multiply.
 *
 */

void fatorial(int fac){
	memset(digit,0,sizeof(short)*10000);
	digit[0] = 1;
	int carry = 0;
	int sum = 0;
	//int pos = 1;
	for(int i = 2;i <= fac;i++){
		;
		//int newpos = 0;
		for(int j = 0;j < 10000;j++){
			sum = i * digit[j] + carry;
			digit[j] = sum % 10;
			carry = (sum - digit[j]) / 10;
		}
	}
	length = 9999;
	while(digit[length] == 0){
		length--;
	}
}

int main(){
	int fac = 0;
	scanf("%d",&fac);
	fatorial(fac);
	for(int i = length;i >= 0;i--){
		printf("%d",digit[i]);
	}
	return 0;
}
