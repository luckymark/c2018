#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
#define MAXN N*4
int tot;
int a[MAXN];
int ans[MAXN],pi[MAXN];
int pre(int x){
	x=MAXN-3-x;
	memset(a,0,sizeof(a));
	a[x]=1;
	return x;
}
void divide(int x,int len){
	for (int i=len;i>=0;i--){
		if (i)a[i-1]+=a[i]%x*2;
		a[i]/=x;
	}
	for (int i=0;i<=len;i++)
		a[i+1]+=a[i]/2,a[i]%=2;
}
void merge(int len,int sig){
	for (int i=0;i<=len;i++){
		ans[i]+=a[i]*sig;
		if (ans[i]<0)ans[i+1]--,ans[i]+=2;
		ans[i+1]+=ans[i]/2;
		ans[i]%=2;
	}
	len++;
	while (ans[len]>1){
		ans[len+1]+=ans[len]/2;
		ans[len]%=2;
		len++;
	}
	while (ans[len]<0){
		ans[len]+=2;
		ans[len+1]--;
		len++;
	}
}
void twice(){
	for (int i=0;i<=tot;i++)
		pi[i]*=2;
	for (int i=0;i<=tot;i++)
		pi[i+1]+=pi[i]/10,pi[i]%=10;
	while (pi[tot+1]){
		++tot;
		pi[tot+1]+=pi[tot]/10;
		pi[tot]%=10;	
	}
}
void divide2(){
	for (int i=tot;i>=0;i--){
		if (i)pi[i-1]+=pi[i]%2*10;
		pi[i]/=2;
	}
	for (int i=0;i<=tot;i++)
		pi[i+1]+=pi[i]/10,pi[i]%=10;
	while (!pi[tot])tot--;
}
void turn(){
	for (int i=MAXN-4;i>=0;i--){
		twice();
		pi[0]+=ans[i];
	}
	divide2();
	for (int i=0;i<=tot;i++)
		pi[i+1]+=pi[i]/10,pi[i]%=10;
	while (pi[tot+1]){
		++tot;
		pi[tot+1]+=pi[tot]/10;
		pi[tot]%=10;	
	}
}
int main(){
	for (int i=0;i<N;i++){
		int len=pre(i*4-2);
		divide(i*8+1,len);
		merge(len,1);	
		len=pre(i*4-1);
		divide(i*8+4,len);
		merge(len,-1);
		len=pre(i*4);
		divide(i*8+5,len);
		merge(len,-1);
		len=pre(i*4);
		divide(i*8+6,len);
		merge(len,-1);
	}
	turn();
	return 0;
}
