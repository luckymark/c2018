#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100000
#define MAXN N*4
const int length2=30;
const long long MOD2=(1<<30);
const long long MOD10=1e8;
int tot,r,totans;
long long a[N/2];
long long ans[N/2],pi[N/2];
int pre(int x){
	x=MAXN-4-x;
	a[x/length2]=(1<<(x%length2));
	x/=length2;
	memset(a,0,sizeof(long long)*x);
	return x;
}
void divide(int x,int len){
	for (int i=len;i>=0;i--){
		if (i)a[i-1]+=a[i]%x*MOD2;
		a[i]/=x;
	}
	for (int i=0;i<=len;i++)
		a[i+1]+=a[i]/MOD2,a[i]%=MOD2;
	while (!a[len]&&len)len--;
}
void merge(int len,int sig){
	for (int i=0;i<=len;i++){
		ans[i]+=a[i]*sig;
		if (ans[i]<0)ans[i+1]--,ans[i]+=MOD2;
		ans[i+1]+=ans[i]/MOD2;
		ans[i]%=MOD2;
	}
	len++;
	while (ans[len]>1){
		ans[len+1]+=ans[len]/MOD2;
		ans[len]%=MOD2;
		len++;
	}
	while (ans[len]<0){
		ans[len]+=MOD2;
		ans[len+1]--;
		len++;
	}
	totans=(totans>len?totans:len);
}
void twice(){
	for (int i=0;i<=tot;i++)
		pi[i]*=MOD2;
	for (int i=0;i<=tot;i++)
		pi[i+1]+=pi[i]/MOD10,pi[i]%=MOD10;
	while (pi[tot+1]){
		++tot;
		pi[tot+1]+=pi[tot]/MOD10;
		pi[tot]%=MOD10;	
	}
}
void turn(){
	for (int i=totans;i>=0;i--){
		twice();
		if (!r&&ans[i]){
			r=i*length2;
			int x=ans[i];
			while (x)r++,x/=2;
		}
		pi[0]+=ans[i];
	}
	for (int i=0;i<=tot;i++)
		pi[i+1]+=pi[i]/MOD10,pi[i]%=MOD10;
	while (pi[tot+1]){
		++tot;
		pi[tot+1]+=pi[tot]/MOD10;
		pi[tot]%=MOD10;	
	}
	int x=tot;
	tot=N/2;
	for (int i=x;i>=0;i--)
		pi[--tot]=pi[i];
	for (int i=tot-1;i>=0;i--)pi[i]=0;
	tot=N/2;
}
void dividepi(int x){
	for (int i=tot;i>=0;i--){
		if (i)pi[i-1]+=pi[i]%x*MOD10;
		pi[i]/=x;
	}
	for (int i=0;i<=tot;i++)
		pi[i+1]+=pi[i]/MOD10,pi[i]%=MOD10;
	while (!pi[tot]&&tot)tot--;
}
int main(){
	freopen("pi.out","w",stdout);
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
	for (int i=0;i<=r-2;)
		if (i+length2<=r-2){
			dividepi(MOD2);
			i+=length2;
		}else
			dividepi(1<<(r-2-i)),i=r-2+1;
	int sum=0;
	long long x=1;
	while (x<pi[tot])x*=10;
	x/=100;
	printf("3.");
	while (x){
		printf("%d",pi[tot]/x%10);
		sum++;
		x/=10;
	};
	for (int i=tot-1;i>=0&&sum<N;i--){
		x=MOD10/10;
		while (x&&sum<N){
			printf("%d",pi[i]/x%10);
			sum++;
			x/=10;
		}
	}
	printf("\n");
	return 0;
}
