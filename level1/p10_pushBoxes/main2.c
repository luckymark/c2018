#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#define H 27
#define W 29
void pos(int,int);
void creatMap(int,char[][W]);
void move(char,char[][W]);
void moveJudge(char[][W],int,int);
int judge(void);
int coor[2]={4,9};
int boxNum=0;
int main(void){
	int stage=2;
	char map[H][W];
	creatMap(stage,map);
	while(1)
	{
		move(getch(),map);	
		if(judge())
			break;
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
void creatMap(int stage,char (*map)[W])
{
    int i,j,jinghao=0;
    char a;
	FILE * fp;
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
void loadMap(){
	
	
}
void move(char order,char (*map)[W]){
	pos(coor[0],2*coor[1]);
	printf("  ");
	
	switch(order){
		case 'w':
			moveJudge(map,-1,0);
			break;
		case 's':
			moveJudge(map,1,0);
			break;
		case 'a':
			moveJudge(map,0,-1);
			break;
		case 'd':
			moveJudge(map,0,1);
			break;			
	}
	pos(coor[0],2*coor[1]);
	printf("♀");
}
int judge(){
	if(coor[0]==21&&coor[1]==23){
		pos(20,40);
		printf("you win!!!!!!!!!you win!!!!!!!you win!!!!!!");
		return 1;
	}
	return 0;
}
void moveJudge(char (*map)[W],int h,int w){
	if(map[coor[0]+h][coor[1]+w]!='1'&&coor[0]+h>-1&&coor[0]+h<H+1&&coor[1]+w>-1&&coor[1]+w<W)
	{
		if(map[coor[0]+2*h][coor[1]]+2*w!='1')
		{
			if(map[coor[0]+h][coor[1]+w]=='2')
			{
				pos(coor[0]+h,2*coor[1]+2*w);
				printf("  ");
				map[coor[0]+h][coor[1]+w]=' ';
				pos(coor[0]+2*h,2*coor[1]+4*w);
				printf("□");
				if(map[coor[0]+2*h][coor[1]+4*w]=='3')
				{
					boxNum--;
					map[coor[0]+2*h][coor[1]+4*w]='5';
				}
				else
					map[coor[0]+2*h][coor[1]+4*w]='2';
			}
			else if(map[coor[0]+h][coor[1]+w]=='5')
			{
				pos(coor[0]+h,2*coor[1]+2*w);
				printf("×");
				map[coor[0]+h][coor[1]+w]='3';
				pos(coor[0]+2*h,2*coor[1]+4*w);
				printf("□");
				boxNum++;
				if(map[coor[0]+2*h][coor[1]+2*w]=='3')
				{
					map[coor[0]+2*h][coor[1]+2*w]='5';
				}
				else
					map[coor[0]+2*h][coor[1]+2*w]='2';
			}
				
		}
		coor[0]+=h;
		coor[1]+=w;
		
	}
}

