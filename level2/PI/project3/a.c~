#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100000
#define MAXN N*4
#define max(x,y) (x<y?y:x)
#define MOD2 1073741824
#define length2 30
#define MOD2_1 1073741823
#define MOD10 100000000
#include<omp.h>
int tot,r,totans,lena,lenb,lenc,lend,len;
long long a[N/3+1],b[N/3+1],d[N/3+1],c[N/3+1];
long long ans[N/3+1],pi[N/3+1];
void pre(long long*a,int x,int*len){
	x=MAXN-4-x;
	a[*len=x/length2]=(1<<(x%length2));
	x/=length2;
}
void divide(long long*a,int x,int*len){
	for (int i=*len;i>=1;i--){
		a[i-1]+=((a[i]%x)<<length2);
		a[i]/=x;
	}
	a[0]/=x;
	while (!a[*len]&&*len)*len--;
}
void merge(){
	for (int i=0;i<=len;i++){
		ans[i]+=a[i]-b[i]-c[i]-d[i],a[i]=b[i]=c[i]=d[i]=0;
		while (ans[i]<0)ans[i+1]--,ans[i]+=MOD2;
		ans[i+1]+=(ans[i]>>length2);
		ans[i]&=(MOD2_1);
	}
	len++;
	while (ans[len]>MOD2_1){
		ans[len+1]+=(ans[len]>>length2);
		ans[len]&=(MOD2_1);
		len++;
	}
	totans=(totans>len?totans:len);
}
void twice(){
	for (int i=0;i<=tot;i++)
		pi[i]<<=length2;
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
	tot=N/3+1;
	for (int i=x;i>=0;i--)
		pi[--tot]=pi[i];
	for (int i=tot-1;i>=0;i--)pi[i]=0;
	tot=N/3;
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
	#pragma omp parallel sections num_threads(4)
	{
	#pragma omp section
		{
			pre(a,i*4-2,&lena);
			divide(a,i*8+1,&lena);
		}
	#pragma omp section
		{
			pre(b,i*4-1,&lenb);
			divide(b,i*8+4,&lenb);
		}
	#pragma omp section
		{
			pre(c,i*4,&lenc);
			divide(c,i*8+5,&lenc);
		}
	#pragma omp section
		{
			pre(d,i*4,&lend);
			divide(d,i*8+6,&lend);
		}
	}
		len=lena;
		merge();
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
