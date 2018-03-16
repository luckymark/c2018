#include <stdio.h>
#include <stdlib.h>
#define DIGIT 3

int qpow(int a, int b){
	int base=a,r=1;
	while(b!=0){
		if(b&1!=0){
			r*=base;
			}
		base*=base;
		b>>=1;
	}
	return r;
}

int main(){
	int i,single,ten,hundred;
	for(i=qpow(10,DIGIT-1);i<qpow(10,DIGIT);i++){
		single=i%10;
		ten=(i/10)%10;
		hundred=i/100;
		if(i==qpow(single,DIGIT)+qpow(ten,DIGIT)+qpow(hundred,DIGIT)){
			printf("%d\n",i);
		}
	}
	return 0;
} 
