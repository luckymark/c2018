#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 100

int main(){
	int i,j,k,t=0,flag=1,n;
	n=MAXN;
	int num;
	num=ceil(n/(log((double)n)-1.08366));  //有不超过num个素数 
	int prime[num]={},book[n]={};		
	for(i=2;i<=n;i++){
		if(!book[i]){
			prime[t++]=i;
		} 
		for(j=0;j<t&&i*prime[j]<=n;j++){
			book[i*prime[j]]=1;		//质数的倍数刷掉  
		}
	}		//获得素数表 
	for(i=4;i<=100;i+=2){
		if(flag==0){
			printf("Wrong theorem!");
			return 0;
		} 
		flag=0;
		for(j=0;j<t;j++){
			for(k=0;k<t;k++){
				if(prime[j]+prime[k]==i){
					printf("%d + %d = %d\n",prime[j],prime[k],i);
					flag=1;
					break;
				}
			}
			if(flag)break;
		}
	}
	printf("Right theorem!");
	return 0;
} 
