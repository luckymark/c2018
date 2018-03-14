#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100000
#define omp_threads 8
#define MAXN N*4
#define max(x,y) (x<y?y:x)
#define MOD2 1073741824
#define length2 30
#define MOD2_1 1073741823
#define MOD10 100000000
#include<omp.h>
#include<mpi.h>
int tot,r,totans,lena,len,lenb,lend,lenc;
long long a[N/3+1],b[N/3+1],c[N/3+1],d[N/3+1];
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
void merge1(long long*a,long long*ans,int len, int* len1){
	for (int i=0;i<=len;i++){
		ans[i]+=a[i],a[i]=0;
		ans[i+1]+=(ans[i]>>length2);
		ans[i]&=(MOD2_1);
	}
	len++;
	while (ans[len]>MOD2_1){
		ans[len+1]+=(ans[len]>>length2);
		ans[len]&=(MOD2_1);
		len++;
	}
	*len1=(*len1>len?*len1:len);
}
void merge(){
	for (int i=0;i<=len;i++){
		ans[i]+=a[i]-b[i]-c[i]-d[i];
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
int main(int argc,char*argv[]){
	int my_rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	if (my_rank==0)
	{
#pragma omp parallel for num_threads(omp_threads) 
		for (int i=0;i<N;i++){
			long long a1[N/3+1];
			int lena1;
			pre(a1,i*4-2,&lena1);
			divide(a1,i*8+1,&lena1);
#pragma omp critical
			merge1(a1,a,lena1,&lena);
		}
	}else
	if (my_rank==1){
#pragma omp parallel for num_threads(omp_threads)
		for (int i=0;i<N;i++){
			long long a1[N/3+1];
			int lena1;
			pre(a1,i*4-1,&lena1);
			divide(a1,i*8+4,&lena1);
#pragma omp critical
			merge1(a1,a,lena1,&lena);
		}
	}else
	if (my_rank==2){
#pragma omp parallel for num_threads(omp_threads)
		for (int i=0;i<N;i++){
			long long a1[N/3+1];
			int lena1;
			pre(a1,i*4,&lena1);
			divide(a1,i*8+5,&lena1);
#pragma omp critical
			merge1(a1,a,lena1,&lena);
		}
	}else{
#pragma omp parallel for num_threads(omp_threads)
		for (int i=0;i<N;i++){
			long long a1[N/3+1];
			int lena1;
			pre(a1,i*4,&lena1);
			divide(a1,i*8+6,&lena1);
#pragma omp critical
			merge1(a1,a,lena1,&lena);
		}
	}
	if (my_rank == 0){
		MPI_Status status;
		MPI_Recv(b,N/3+1,MPI_LONG_LONG,MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
		MPI_Recv(c,N/3+1,MPI_LONG_LONG,MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
		MPI_Recv(d,N/3+1,MPI_LONG_LONG,MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
		len=lena;
		merge();
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
		freopen("pi.out","w",stdout);
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
	}else{
		MPI_Send(a, N/3+1, MPI_LONG_LONG, 0, 0, MPI_COMM_WORLD);
	}
	MPI_Finalize();
	return 0;
}
