#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#define H 27
#define W 29
#define N 9
void pos(int,int);
void creatMap(void);
void move(char);
void moveJudge(int,int);
void start(void);
int judge(void);
int coor[2]={4,9};
int boxNum=0;
int step=0;
int stage=2;
char map[H][W];
int main(void){
	int a;
	start();
	while(1)
	{
		move(getch());	
		if(judge()||stage==0)
			start();
	}
	return 0;
}
void pos(int row,int rank){
	COORD position;
	HANDLE hOutput;
	position.X=rank;
	position.Y=row;
	hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput,position);
}
void creatMap(void)
{
    int i,j,jinghao=0;
    char a;
	FILE * fp;
	boxNum=0;
	step=0;
	system("cls");
	if((fp=fopen("allMap","r"))==NULL)
	{
		printf("文件打开失败！请检查allMap是否存在");
		exit(EXIT_FAILURE);
	}
	while(1)
	{
		if((a=getc(fp))=='#')
		{
			jinghao++;
			if(jinghao==stage)
			{
				break;
			}
		}
		else if(a==EOF)
		{
			printf("地图读取失败！请检查allMap有无#作为隔断");
			exit(EXIT_FAILURE);	
		}
	}
    system("cls");
    for(j=0;j<H;j++)
	{
		for(i=0;i<W;i++)
    	{	a=getc(fp);
    		pos(j,2*i);
    		switch(map[j][i]=a)
			{
			case '#':
				pos(coor[0],2*coor[1]);
				printf("♀");
    			return;
    		case '1':
        		printf("■");
        		break;
        	case ' ':
        		printf("  ");
        		break;
        	case '2':
        		printf("□");
        		boxNum++;
        		break;
			case '3':
        		printf("×");
        		break;
        	case '4':
				printf("♀");
				map[j][i]=' ';
				coor[0]=j;
				coor[1]=i;
				break;
			case '5':
				printf("▓");
				boxNum++;
				break; 
        	case '-':
        		i=-1;
        		j++;
        		break;
        	default:
        		break;
        	}
    	}
	}
	pos(coor[0],2*coor[1]);
	printf("♀");
}
void move(char order){
	pos(coor[0],2*coor[1]);
	printf("  ");
	
	switch(order){
		case 'w':
			moveJudge(-1,0);
			break;
		case 's':
			moveJudge(1,0);
			break;
		case 'a':
			moveJudge(0,-1);
			break;
		case 'd':
			moveJudge(0,1);
			break;
		case 'r':
			creatMap();
			break;	
		case 'q':
			stage=0;
			break;		
	}
	pos(coor[0],2*coor[1]);
	printf("♀");
}
int judge(){
	int a; 
	if(boxNum==0){
		pos(10,20);
		printf("☆☆☆☆☆☆☆☆☆☆☆");
		pos(11,20);
		printf("☆ 恭喜你，完成了！ ☆");
		pos(12,20);
		printf("☆  共计移动%4d步  ☆",step);
		pos(13,20);
		printf("☆☆☆☆☆☆☆☆☆☆☆");
		step=0;
		pos(14,20);
		if(stage<N){
			printf("按r重玩本关，按d玩下一关，其余任意键重新选关");
			switch(getch()){
				case 'r':
					creatMap();
					return 0;
					break;
				case 'd':
					stage++;
					creatMap();
					return 0;
			}
			return 1;
		}
		else{
			printf("您已通关！！按r重玩本关，按d回到第一关，其余任意键重新选关");
			switch(getch()){
				case 'r':
					creatMap();
					return 0;
					break;
				case 'd':
					stage=1;
					creatMap();
					return 0;
			}
			return 1;
			 
		}
	}
	return 0;
}
void moveJudge(int h,int w){
	if(map[coor[0]+h][coor[1]+w]!='1'&&coor[0]+h>-1&&coor[0]+h<H+1&&coor[1]+w>-1&&coor[1]+w<W)//不是墙 ,没越界 
	{
		if(map[coor[0]+h][coor[1]+w]=='2')//是正常的箱子 
		{
			if(map[coor[0]+2*h][coor[1]+2*w]!='1'&&map[coor[0]+2*h][coor[1]+2*w]!='2'&&map[coor[0]+2*h][coor[1]+2*w]!='5')//为空或为X 
			{ 
				map[coor[0]+h][coor[1]+w]=' ';
				pos(coor[0]+2*h,2*coor[1]+4*w);
				
				if(map[coor[0]+2*h][coor[1]+2*w]=='3')
				{
					boxNum--;
					map[coor[0]+2*h][coor[1]+2*w]='5';
					printf("▓");
				}
				else
				{
					map[coor[0]+2*h][coor[1]+2*w]='2';
					printf("□");
				}
			}
			else{
				return;
			}
		}
		else if(map[coor[0]+h][coor[1]+w]=='5')//是下面有X的箱子 
		{
			if(map[coor[0]+2*h][coor[1]+2*w]!='1'&&map[coor[0]+2*h][coor[1]+2*w]!='2'&&map[coor[0]+2*h][coor[1]+2*w]!='5')
			{
				map[coor[0]+h][coor[1]+w]='3';
				pos(coor[0]+2*h,2*coor[1]+4*w);
				
				boxNum++;
				if(map[coor[0]+2*h][coor[1]+2*w]=='3')
				{
					map[coor[0]+2*h][coor[1]+2*w]='5';
					boxNum--;
					printf("▓");
				}
				else
				{
					map[coor[0]+2*h][coor[1]+2*w]='2';
					printf("□");
				}
			}
			else{
				return;
			}
		}
		pos(coor[0],2*coor[1]);
		if(map[coor[0]][coor[1]]==' ')
		{
			printf("  ");
		}
		else if(map[coor[0]][coor[1]]=='3')
		{
			printf("×");
		}
		coor[0]+=h;
		coor[1]+=w;
		step++;	
	}
}
void start(void){
	int a;
	system("cls");
	pos(2,8);
	printf("■■■■■■■■■■■");
	pos(3,8);
	printf("■      推箱子      ■");
	pos(4,8);
	printf("■     操作规则:    ■");
	pos(5,8);
	printf("■        w         ■");
	pos(6,8);
	printf("■      a s d       ■");
	pos(7,8);
	printf("■     控制移动     ■");
	pos(8,8);
	printf("■    r 重玩本关    ■");
	pos(9,8);
	printf("■    q 重新选关    ■");
	pos(10,8);
	printf("■      ■是墙      ■");
	pos(11,8);
	printf("■     □是箱子     ■");
	pos(12,8);
	printf("■ ▓是遮住×的箱子 ■");
	pos(13,8);
	printf("■ 一次只能推一个□ ■");
	pos(14,8);
	printf("■ □遮住所有×获胜 ■");
	pos(15,8);
	printf("■   输入1~9选关    ■");
	pos(16,8);
	printf("■■■■■■■■■■■");
	scanf("%d",&a);
	while(a<=0||a>9)
	{
		pos(16,8);
		printf("请输入1~9之间的数！");
		scanf("%d",&a); 
	}
	stage=a; 
	creatMap();
}
