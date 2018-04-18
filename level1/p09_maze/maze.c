#include<stdio.h>
#include<conio.h>  //kbhit的原型 
#include<stdlib.h>
#define WIDE 15
#define LEN  17

struct COD{
	int x;
	int y;
};

char maze[WIDE][LEN]; 
void Initmap(void);
void BuildrBarrier(int st,int end,int row);
void BuildlBarrier(int st,int end,int line);//辅助造墙函数 
void PlayerMove(int twd,struct COD* now);
int GetPlayerCommand(void);
void Judge(struct COD* now,struct COD* New);

int main(void){
	struct COD* now;
	struct COD loc={1,1,}; 
	now = &loc;
	
	Initmap();
	while(now->y < 16){
		system("cls");
		int i,j;
		for(i=0;i<WIDE;i++){
			for(j=0;j<LEN;j++){
				printf("%c",maze[i][j]);
			}
			printf("\n");
		}
		PlayerMove(GetPlayerCommand(),now);
	}
	printf("you win!\n");
		
	return 0;
} 

void BuildlBarrier(int st,int end,int line){
	int i;
	for(i=st;i<=end;i++){
		maze[i][line]='#';
	}
}

void BuildrBarrier(int st,int end,int row){
	int i;
	for(i=st;i<=end;i++){
		maze[row][i]='#';
	}
}

void Initmap(void){
	int i,j;
	for(i=0;i<WIDE;i++){
		maze[i][0] = '#';
		maze[0][i] = '#';
	}
	for(j=0;j<LEN;j++){
		maze[j][LEN-1]  = '#';
		maze[WIDE-1][j] = '#';
	}                                 //生成边界墙 
	for(i=1;i<WIDE-1;i++){
		for(j=1;j<LEN-1;j++){
			maze[i][j]=' ';
		}
	}
	BuildlBarrier(1,4,3);
	BuildrBarrier(7,13,3);
	BuildrBarrier(12,15,5);                           
	BuildrBarrier(1,6,7);
	BuildlBarrier(4,8,7);
	BuildrBarrier(10,15,7);
	BuildrBarrier(3,10,10);
	BuildlBarrier(10,13,12);
	BuildlBarrier(8,10,10);
	BuildrBarrier(14,15,12);
	maze[6][12]='#',maze[9][3]='#',maze[10][13]='#';//初始化迷宫地图 
	maze[1][1]='o';
	maze[13][16]=' ';
}

int GetPlayerCommand(void){
	int c= -1;
	char ch;
	if(ch=getch()){
		switch(ch){
			case'd':case'D':c=0;break;
			case's':case'S':c=1;break;
			case'a':case'A':c=2;break;
			case'w':case'W':c=3;break;
			case 27:exit(0);
		}
	}
	return c;
}

void Judge(struct COD* now,struct COD* New){
	char temp;
	if(maze[New->x][New->y] != '#'){
		temp=maze[now->x][now->y];
		maze[now->x][now->y]=maze[New->x][New->y];
		maze[New->x][New->y]=temp;
		*now= *New;
	}
}

void PlayerMove(int twd,struct COD* now){
	struct COD n =*now;
	struct COD *New=&n;
	switch(twd){
		case -1: break; 
		case  0: n.y++;Judge(now,New);break;
		case  1: n.x++;Judge(now,New);break;
		case  2: n.y--;Judge(now,New);break;
		case  3: n.x--;Judge(now,New);break;
	}
}
