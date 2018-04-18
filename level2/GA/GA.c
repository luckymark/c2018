#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#define HIGTH 17
#define WIDTH 27
#define RNUM 100
#define PNUM 100
#define TUBIANLV 0.01
#define JIAOHUANLV 0.7
#define SHIDAISHU 500 
#define REPEAT_PUNSIHMENT 0.55
#define EPOCHCISHU 100
typedef struct _quality{
	char road[RNUM];
	double score;
}indiv;
indiv popul[PNUM];
int map[HIGTH][WIDTH]={
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,
1,4,0,1,1,0,0,0,0,0,1,1,0,0,0,0,1,3,1,0,0,0,0,0,0,0,0,
1,0,0,0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,
1,0,0,0,1,0,0,1,1,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,
1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,
1,0,1,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,
1,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
1,0,0,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
1,0,0,1,1,0,0,0,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
1,0,0,0,1,1,0,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,
1,0,0,1,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,
1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,
};
int aiPos[2];
int end[2];
int best;
int sucdaishu[EPOCHCISHU];
int epochI;

void finstart(void);//find where qidian is
void initPop(void);//chu shi hua popul

void fzindiv(indiv zhi,indiv* beifu);

int epoch(int);
int roulette(double);		//轮盘赌 
void regene(indiv*,indiv*,double);	//杂交
void tubian(indiv*,double);	//突变 

void zhanshi(int);//test


void printone(int);
void printmap(void);
void printroad(char[]);
void printgene(int);
void Pos(int,int);

double markall(void);
double mark(char[]);

void tongji(void);

int main(void){
	int a;
	srand((unsigned)(time(NULL)));
	finstart();
	for(epochI=0;epochI<EPOCHCISHU;epochI++)
	{
	initPop();
	a=epoch(SHIDAISHU);
	if(a<0)
	{
		printone(best);
		printf("未产生到达者\n");
	}
	else
	{
	printone(a);
	printf("共繁衍%d代\n",sucdaishu[epochI]);
	}
	}
	tongji();
	return 0;
}
void finstart(void){
	int i,j;
	int qidian=0,zhongdian=0;
	for(i=0;i<HIGTH;i++)
	{
		for(j=0;j<WIDTH;j++)
		{
			if(map[i][j]==4)
			{
				aiPos[0]=i;
				aiPos[1]=j;
				qidian=1;
			}
			else if(map[i][j]==3)
			{
				end[0]=i;
				end[1]=j;
				zhongdian=1;
			}
		}
	}
	if(!qidian)
		printf("起点不存在！\n");
	else if(!zhongdian)
		printf("终点不存在！\n");
	else
		return;
	exit(EXIT_FAILURE);
}
void initPop(void){
	int i,j;
	for(i=0;i<PNUM;i++)
	{
		popul[i].score=0;
		for(j=0;j<RNUM;j++)
		{
			popul[i].road[j]=rand()%2+'0';
		}
	}
}

//00 w ; 01 a ; 10 d ;11 s
double mark(char* road){
	int i,a,b,repunish=0;
	char fuzhe[HIGTH][WIDTH];
	int mpos[2];
	mpos[0]=aiPos[0];
	mpos[1]=aiPos[1];
	memset(fuzhe,0,(sizeof(char))*HIGTH*WIDTH);
	for(i=0;i<RNUM;i+=2)
	{
		if(road[i]=='0'&&road[i+1]=='0')
		{
			if(mpos[0]==0||map[mpos[0]-1][mpos[1]]==1)
				continue;
			mpos[0]--;
		}
		else if(road[i]=='0'&&road[i+1]=='1')
		{
			if(mpos[1]==0||map[mpos[0]][mpos[1]-1]==1)
				continue;
			mpos[1]--;
		}
		else if(road[i]=='1'&&road[i+1]=='0')
		{
			if(mpos[1]==WIDTH-1||map[mpos[0]][mpos[1]+1]==1)
				continue;
			mpos[1]++;
		}
		else if(road[i]=='1'&&road[i+1]=='1')
		{
			if(mpos[0]==HIGTH-1||map[mpos[0]+1][mpos[1]]==1)
				continue;
			mpos[0]++;
		}
		if(mpos[0]==end[0]&&mpos[1]==end[1])
			break;
		if(fuzhe[mpos[0]][mpos[1]]=='1')
		{
			repunish++;
		}
		fuzhe[mpos[0]][mpos[1]]='1';
	}
	a=mpos[0]-end[0];
	b=mpos[1]-end[1];
	a=(a>0?a:-a);
	b=(b>0?b:-b);
	return 1/(double)(sqrt(a*a+b*b)+1+repunish*REPEAT_PUNSIHMENT);
}
double markall(void){
	int i;
	double sumMark=0.0;
	best=0;//test
	for(i=0;i<PNUM;i++)
	{
		if((popul[i].score=mark(popul[i].road))==1.0)
		{
			best=i;
			return i+100;
		}
		
		if(popul[i].score>popul[best].score)//test
			best=i;//test
			
		sumMark+=popul[i].score;
	}
	return sumMark;
}
void printroad(char* road){
	int i;
	int mpos[2];
	mpos[0]=aiPos[0];
	mpos[1]=aiPos[1];
	for(i=0;i<RNUM;i+=2)
	{
		if(road[i]=='0'&&road[i+1]=='0')
		{
			if(mpos[0]==0||map[mpos[0]-1][mpos[1]]==1)
				continue;
			mpos[0]--;
		}
		else if(road[i]=='0'&&road[i+1]=='1')
		{
			if(mpos[1]==0||map[mpos[0]][mpos[1]-1]==1)
				continue;
			mpos[1]--;
		}
		else if(road[i]=='1'&&road[i+1]=='0')
		{
			if(mpos[1]==WIDTH-1||map[mpos[0]][mpos[1]+1]==1)
				continue;
			mpos[1]++;
		}
		else if(road[i]=='1'&&road[i+1]=='1')
		{
			if(mpos[0]==HIGTH-1||map[mpos[0]+1][mpos[1]]==1)
				continue;
			mpos[0]++;
		}
		Pos(mpos[0],mpos[1]);
		printf("●");
		if(mpos[0]==end[0]&&mpos[1]==end[1])
			break;
	}
	Pos(mpos[0],mpos[1]);
	printf("★");
}
void Pos(int row,int rank){
	COORD position;
	HANDLE hOutPut;
	position.X=2*rank;
	position.Y=row;
	hOutPut=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutPut,position);
}
void printmap(void){
	int i,j;
	Pos(0,0);
	for(i=0;i<HIGTH;i++)
	{
		for(j=0;j<WIDTH;j++)
		{
			switch(map[i][j]){
				case 1:
					printf("■");
					break;
				case 0:
				case 4:
					printf("  ");
					break;
				case 3:
					printf("×");
					break;
			}	
		}
		printf("\n");
	}
}
void printone(int winner){
	printmap();
	printroad(popul[winner].road);
	Pos(20,0);
	printf("最优第%d号\n",winner);
	printgene(winner);
}
int epoch(int daishu){
	int i,j;
	int father,mother;
	double sumMark;
	indiv sonPopul[100];
	for(i=0;i<daishu;i++)
	{
		memset(sonPopul,0,100*(sizeof(indiv)));
		if((sumMark=markall())>=100)
		{
			sucdaishu[epochI]=i;//
			return (int)(sumMark-100);
		}
		//zhanshi(i);//test
		
		
		for(j=0;j<PNUM;j+=2)
		{
			father=roulette(sumMark);
			fzindiv(popul[father],sonPopul+j);
			mother=roulette(sumMark);
			fzindiv(popul[mother],sonPopul+j+1);
			regene(sonPopul+j,sonPopul+j+1,JIAOHUANLV);
			tubian(sonPopul+j,TUBIANLV);
			tubian(sonPopul+j+1,TUBIANLV);
		}
		for(j=0;j<PNUM;j++)
		{
			fzindiv(sonPopul[j],&popul[j]);
		}

	}
	sucdaishu[epochI]=-1;
	return -1;
}
void fzindiv(indiv zhi,indiv* beifu){
	int i;
	for(i=0;i<RNUM;i++)
	{
		beifu->road[i]=zhi.road[i];
	}
	beifu->score=0;
}
void regene(indiv* father,indiv* mother,double jilv){
	double a;
	int changeWei,i;
	char b;
	a=rand()/(double)(RAND_MAX);
	if(a<=jilv)
	{
		changeWei=rand()%RNUM;
		for(i=changeWei;i<RNUM;i++)
		{
			b=father->road[i];
			father->road[i]=mother->road[i];
			mother->road[i]=b;
		}
	}
}
int roulette(double zhuanpan){
	int ri;
	double zhuanzhen=0.0,zhongdian;
	zhongdian=zhuanpan*(rand()/(double)(RAND_MAX));
	for(ri=0;ri<PNUM;ri++)
	{
		zhuanzhen+=popul[ri].score;
		if(zhuanzhen>=zhongdian)
			return ri;
	}
	return -1;
}
void tubian(indiv* geti,double jilv){
	int i;
	for(i=0;i<RNUM;i++)
	{
		if((rand()/(double)(RAND_MAX))<jilv)
		{
			geti->road[i]=(geti->road[i]=='0'?'1':'0');
		}
	}
}
void zhanshi(int daishu){
	Sleep(10);
	printone(best);
	Pos(19,0);
	printf("第%3d代",daishu);

}
void printgene(int geti){
	int i;
	printf("基因为: ");
	for(i=0;i<RNUM;i++)
	{
		printf("%c",popul[best].road[i]);
	}
	printf("\n");
}
void tongji(void){
	int i;
	int sum=0;
	int lose=0;
	for(i=0;i<EPOCHCISHU;i++)
	{
		if(sucdaishu[i]==-1)
		{
			lose++;
		}
		else
		{
			sum+=sucdaishu[i];
		}
	}
	printf("在%d次%d代繁衍后，失败%d次，成功%d次，平均成功代数为%f代\n",EPOCHCISHU,SHIDAISHU,lose,EPOCHCISHU-lose,sum/(double)(EPOCHCISHU-lose));
}
