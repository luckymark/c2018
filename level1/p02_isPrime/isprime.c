#include<stdio.h>
int main(void){
	int x;
	int i;
	int cnt=0;
	scanf("%d",&x);
	if( x == 2){
		cnt =1;
	}
	if(x == 1){
		cnt =0;
}
	for(i=2;i<x;i++){
		if(x%i == 0){
			cnt=0;
			break;
		}else
			cnt=1;
	}
	
	if(cnt==1)
		printf("yes\n");
	else
		printf("no\n");
	return 0;
} 
