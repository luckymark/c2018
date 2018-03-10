#include<stdio.h>
#include<stdlib.h>
#define N 10000000
int a[N+1],d[N+1];
int main(){
	freopen("a.out","w",stdout);
	for (int i=2;i<=N;i++){
		if (!a[i])d[a[i]=++d[0]]=i;
		for (int j=1;j<=a[i];j++)
			if ((long long)d[j]*i>N)break;
			else
				a[d[j]*i]=j;
	}
	for (int i=1;i<=d[0];i++)printf("%d ",d[i]);
	return 0;
}
