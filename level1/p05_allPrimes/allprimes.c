#include<stdio.h>
#include<time.h>
#define MAX 1000

int isprime(int a);

int main(void){
	clock_t t1,t2;
	t1= clock();
	int i;
	for(i=2;i<MAX;i++){
		if(isprime(i) )
			printf("%d ",i);
	}
	printf("\n");
	t2=clock();
	printf("0.0%ds\n",t2-t1);
	return 0;
} 

int isprime(int a){
	int i;
	int cnt=0;
	
	for(i=2;i<a;i++){
		if(a%i == 0){
			cnt=0;
			break;
		}
		else
			cnt =1;
	}
	if(a == 1)
		cnt=0; 
	if(a == 2)
		cnt =1;
	return cnt;
}
