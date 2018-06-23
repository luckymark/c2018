#include<stdio.h>
#include<stdlib.h>
int power(int x,int y){
	int s=1;
	while (y--)s*=x;
	return s;
}
int check(int x,int n){
	int y=0,z=x;
	while (z)y+=power(z%10,n),z/=10;;
	return y==x;
}
int main(){
	int n;
	printf("Input n:");
	scanf("%d",&n);
	printf("水仙花数有：\n");
	int l=power(10,n-1),r=l*10;
	for (int i=l;i<r;i++)
		if (check(i,n))printf("%d\n",i);
	return 0;
}
