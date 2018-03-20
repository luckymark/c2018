#include<bits/stdc++.h>
using namespace std;
const int N=101,T=100,Allsum=20,MAXN=1000;
const double rate=0.01;
const int b[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
const char c[4]={'u','d','l','r'};
char Map[N][N];
int n,m,sum,t;
struct point{
	int x,y;
	point(int X=0,int Y=0){x=X,y=Y;}
	bool operator==(point s){
		return s.x==x&&s.y==y;
	}
	int dis(point s){
		return abs(s.x-x)+abs(s.y-y);
	}
	void walk(int sig){
		x+=b[sig][0],y+=b[sig][1];
	}
	bool legal(){
		return x&&x<=n&&y&&y<=m&&Map[x][y]!='#';
	}
}start,end;
struct V{
	int Mandis,steps;
	V(int Mandis1=0,int steps1=0){
		Mandis=Mandis1,steps=steps1;
	}
	bool operator<(const V s){
		return Mandis<s.Mandis||(Mandis==s.Mandis&&steps<s.steps);
	}
};
struct gene{
	int step[N*N/10+1];
	V v;
	bool operator<(const gene&a){
		return v<a.v;
	}
	void init(){
		for (int i=0;i<sum;i++)
			step[i*2/20]+=(1<<(i*2%20))*(rand()&1),step[(i*2+1)/20]+=(1<<((i*2+1)%20))*(rand()&1);
	}
	int getsig(int i){
		return step[i*2/20]/(1<<(i*2%20))%4;
	}
	void check(){
		for (int i=1;i<sum;i++)
			while ((getsig(i)^getsig(i-1))==1){
				step[i*2/20]-=getsig(i)*(1<<(i*2%20));
				step[i*2/20]+=rand()%4*(1<<(i*2%20));
			}
	}
	void calc(){
		point s=start;
		int i=0,steps=0;
		v.Mandis=v.steps=1e9;
		while (i<sum){
			int sig=getsig(i);
			point next=s;
			next.walk(sig);
			while  (!next.legal()){
				next=s;
				sig=rand()%4;
				step[i*2/20]-=getsig(i)*(1<<(i*2%20));
				step[i*2/20]+=sig*(1<<(i*2%20));
				next.walk(sig);
			}
			s=next;
			steps++;
			if (v.Mandis>end.dis(s)){
				v.Mandis=end.dis(s);
				v.steps=steps;
				if (!v.Mandis)break;
			}	
			i++;
		}
	}
	void clear(){
		for (int i=0;i<sum*2/20;i++)
			step[i]=0;
	}
	double getrate(){
		double v=rand()%MAXN;
		return v/MAXN;	
	}
	void mutation(){
		for (int i=0;i<sum;i++)
			if (getrate()<=rate){
				step[i*2/20]-=(step[i*2/20]&((1<<(i*2%20))+(1<<((i*2+1)%20))));
				step[i*2/20]+=(1<<(i*2%20))*(rand()&1)+(1<<((i*2+1)%20))*(rand()&1);
			}
	}
	void output(){
		point s=start;
		int i=0,steps=0;
		while (i<sum){
			int sig=step[i*2/20]/(1<<(i*2%20))%4;
			point next=s;
			next.walk(sig);
			if (next.legal()){
				s=next,printf("%c",c[sig]),steps++;
				if (steps==v.steps)break;
			}
			++i;
		}
		printf("\n");
		printf("%d",steps);
	}
}group[(Allsum+3)*(Allsum+3)],ans,help[Allsum+10];
void init(){
	freopen("map.in","r",stdin);
	srand((unsigned)time(NULL));
	n=0,m=0;
	ans.v.steps=ans.v.Mandis=1e9;
	while (scanf("%s",Map[++n]+1)!=EOF);
	while (Map[n][1]!='.'&&Map[n][1]!='#'&&Map[n][1]!='E'&&Map[n][1]!='P')n--;
	m=strlen(Map[n]+1);
	sum=n*m;	
	for (int i=1;i<=Allsum*Allsum;i++)
		group[i].init();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (Map[i][j]=='E')end=point(i,j);
			else
				if (Map[i][j]=='P')start=point(i,j);
	t=0;
}
int f(int x){
	return Allsum-x+1;
}
void calc(){
	for (int i=1;i<=Allsum*Allsum;i++){
		group[i].check();
		group[i].calc();
	}
	sort(group+1,group+1+Allsum*Allsum);
	if (group[1].v<ans.v)
		ans=group[1];
	for (int i=1;i<=Allsum;i++){
		int x=rand()%((1+Allsum)*Allsum/2)+1;
		for (int j=1;j<=Allsum;j++)
			if ((x-=f(j))<=0){
				help[i]=group[j];
				break;	
			}
	}
	for (int i=1;i<=Allsum;i++)
		group[i]=help[i];
}
void jiao(gene &a,gene &b,gene &c){
	c.clear();
	int l=0;
	if (rand()&1){
		l=a.v.steps;
		for (int i=0;i<l;i++)
			c.step[i*2/20]+=a.step[i*2/20]/(1<<(i*2%20))%4*(1<<(i*2%20));
	}else{
		l=b.v.steps;
		for (int i=0;i<l;i++)
			c.step[i*2/20]+=b.step[i*2/20]/(1<<(i*2%20))%4*(1<<(i*2%20));
	}
	for (int i=l;i<sum;i++)
		if (rand()&1)
			c.step[i*2/20]+=a.step[i*2/20]/(1<<(i*2%20))%4*(1<<(i*2%20));
		else
			c.step[i*2/20]+=b.step[i*2/20]/(1<<(i*2%20))%4*(1<<(i*2%20));
}
void reproduct(){
	int tot=Allsum;
	for (int i=1;i<=Allsum;i++)
		for (int j=1;j<=Allsum;j++)
			if (i!=j)
				jiao(group[i],group[j],group[++tot]);
}
void mutation(){
	for (int i=1;i<=Allsum*Allsum;i++)
		group[i].mutation();
}
int main(){
	init();
	while (++t<=T){
		calc();
		reproduct();	
		mutation();
	}
	ans.output();
	return 0;
}
