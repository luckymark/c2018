#include<stdio.h>
#include<stdlib.h>
#define N 100
int a[N+1],d[N+1],isprime[N+1],b[N][2];
int main(){
	for (int i=2;i<=N;i++){
		if (!a[i])isprime[d[a[i]=++d[0]]=i]=1;
		for (int j=1;j<=a[i];j++)
			if ((long long)d[j]*i>N)break;
			else
				a[d[j]*i]=j;
	}
	freopen("log","w",stdout);
	for (int i=4;i<=N;i+=2){
		for (int j=1;j<=d[0];j++)
			if (d[j]<=i&&isprime[i-d[j]]){
				b[i][0]=d[j],b[i][1]=i-d[j];
			}
		if (b[i][0]==0){
			printf("Not right!!%d is special!!",i);
			return 0;
		}
	}
	printf("Goldbach is right between 1 and 100!Here are the ways.\n");
	for (int i=4;i<=N;i+=2)
		printf("%d=%d+%d\n",i,b[i][0],b[i][1]);
	return 0;
}
