#include<stdio.h>
#define MAX 100

int isprime(int a);
int main(void){
	int i;
	int x=0;
	int a[25]={0,};

	for(i=1;i<MAX;i++){
		if(isprime(i)){
			a[x]=i;
			x++;
		}
	} 
	
	int j=2;
	int m,n;
	
	for(j=2;j<=MAX;j+=2){
		int cnt=0;
		for(m=0;m<25;m++){
			for(n=0;n<25;n++){
				if(j == a[m]+a[n]){
					cnt=1;
					break;
				}
			}
			if(cnt==1)
				break;
		}
		if(cnt==0){
			printf("false\n");
			return 0;
		}
	}
	printf("ture\n");
	return 0;
}

int isprime(int a){
	int i;
	int cnt=0;
	
	for(i=2;i<a;i++){
		if(a%i == 0){
			cnt =0;
			break;
		}
			
		else
			cnt =1;
	}
	if(a == 1 ||a == 2)
		cnt =1;
	return cnt;
}
