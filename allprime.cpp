#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> 
#define MAXN 1000

int main(){
	clock_t t1,t2;
	t1 = clock();
	double time;
	int i,n,j,t=0;
	n=MAXN;
	int num;
	num=ceil(n/(log((double)n)-1.08366));  //有不超过num个素数 
	int prime[num]={},flag[n]={};		
	for(i=2;i<=n;i++){
		if(!flag[i]){
			prime[t++]=i;
		} 
		for(j=0;j<t&&i*prime[j]<=n;j++){
			flag[i*prime[j]]=1;		//质数的倍数刷掉  
		}
	}
	for(i=0;i<num;i++){
		if(prime[i]==0)break;
		printf("%d\n",prime[i]);
	}
	t2=clock();
	time=(double)(t2-t1);
	printf("It takes about %lfms\n",time);
	return 0;
} 
