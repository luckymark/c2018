#include<stdio.h>
#include<stdlib.h>
long long x;
long long quick(long long x,long long y,long long p){
	x%=p,y%=p;
	return (x*y-(long long)((long double)x/p*y)*p+p)%p;
}
long long calc(long long x,long long y,long long p){
	static long long s;
	s=1;
	while (y){
		if (y&1)s=quick(s,x,p);
		x=quick(x,x,p),y>>=1;
	}
	return s;
}
long long Abs(long long x){
	return x<0?-x:x;
}
int Miller_Rabin(long long n,long long x){
	static long long s,next,r;
	s=n-1;
	r=0;
	while (!(s&1))++r,s>>=1;
	x=calc(x,s,n);
	if (x==1)return 1;
	for (;r--;x=quick(x,x,n))if (x==n-1)return 1;
	return 0;
}
int isprime(long long x){
	for (int i=2;i<=1000&&i<x;i++)
		if (!(x%i))return 0;
	if (x<=1000000)return 1;
	if (!Miller_Rabin(x,2))return 0;
	if (!Miller_Rabin(x,3))return 0;
	if (!Miller_Rabin(x,5))return 0;
	if (!Miller_Rabin(x,7))return 0;
	if (!Miller_Rabin(x,11))return 0;
	if (!Miller_Rabin(x,13))return 0;
	return 1;
}
int main(){
	printf("Input a number between 2 and 9223372036854775807:");
	scanf("%lld",&x);
	printf("\n");
	isprime(x)?printf("%lld is a prime number.",x):printf("%lld is not a prime number",x);
	return 0;
}
