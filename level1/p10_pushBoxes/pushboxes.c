#include<stdio.h>
#include<conio.h>  
#include<stdlib.h>
#include<windows.h>
#define WIDE 9
#define LEN  10
#define Boxpush MAP
#define ENDJUDGE(c) MAP[end[c].x][end[c].y] != 'B'  //终点判断 

struct COD{
	int x;
	int y;
};
struct COD end[4];                   //终点数组 

char MAP[WIDE][LEN]; 
struct COD Initmap_1(void);
struct COD Initmap_2(void);
void BuildrBarrier(int st,int end,int row);
void BuildlBarrier(int st,int end,int line);//辅助造墙函数 
void PlayerMove(int twd,struct COD* now);
int GetPlayerCommand(void);
void Judge(int twd,struct COD* now,struct COD* New);
void BJudge(struct COD* now,struct COD* New);
void BoxMove(int Btwd,struct COD* Bnow);
void Put(void);

int main(void){
	struct COD* now;
	struct COD loc=Initmap_1();
	now = &loc;
	
	while(ENDJUDGE(0) || ENDJUDGE(1) || ENDJUDGE(2) || ENDJUDGE(3) ){
		Put();
		PlayerMove(GetPlayerCommand(),now);
	}
	Put();
	printf("you win!,turn to level 2\n");
	Sleep(1000);
	
	system("cls");
	loc=Initmap_2();
	now = &loc;
	Put(); 
	
	while(ENDJUDGE(0) || ENDJUDGE(1) || ENDJUDGE(2) ){
		Put();
		PlayerMove(GetPlayerCommand(),now);
	}
	Put();
	printf("you win!,turn to level 3\n");
	Sleep(1000);
	
		
	return 0;
} 

void Put(void){
	system("cls");
	int i,j;
		for(i=0;i<WIDE;i++){
			for(j=0;j<LEN;j++){
				printf("%c",MAP[i][j]);
			}
			printf("\n");
		}
}

void BuildlBarrier(int st,int end,int line){
	int i;
	for(i=st;i<=end;i++){
		MAP[i][line]='#';
	}
}

void BuildrBarrier(int st,int end,int row){
	int i;
	for(i=st;i<=end;i++){
		MAP[row][i]='#';
	}
}

struct COD Initmap_1(void){                       //初始化第一关地图 
	int i,j;
	struct COD start1;
	for(i=1;i<WIDE;i++){
		for(j=1;j<LEN;j++){
			MAP[i][j]=' ';
		}
	} 
	BuildrBarrier(2,4,0);
	BuildlBarrier(1,3,2);
	BuildrBarrier(0,1,3);
	BuildrBarrier(0,3,5);
	BuildrBarrier(3,5,7);
	BuildrBarrier(4,7,2);
	BuildrBarrier(5,7,4);
	BuildlBarrier(5,6,5);
	MAP[4][4]='o';
	MAP[4][0]='#',MAP[6][3]='#',MAP[1][4]='#',MAP[3][7]='#';
	MAP[4][3]='B',MAP[3][3]='B',MAP[3][5]='B',MAP[5][4]='B';
	MAP[1][3]='X',MAP[4][1]='X',MAP[3][6]='X',MAP[6][4]='X';
	end[0]=(struct COD){1,3};
	end[1]=(struct COD){4,1};
	end[2]=(struct COD){3,6};
	end[3]=(struct COD){6,4}; 
	start1 =(struct COD){4,4};
	
	return start1;
}

struct COD Initmap_2(void){
	int i,j;
	struct COD start2;
	for(i=1;i<WIDE;i++){
		for(j=1;j<LEN;j++){
			MAP[i][j]=' ';
		}
	} 
	BuildrBarrier(0,4,0);
	BuildlBarrier(1,4,0);
	BuildlBarrier(4,8,1);
	BuildlBarrier(4,5,2);
	BuildrBarrier(2,5,8);
	BuildrBarrier(5,8,7);
	BuildlBarrier(2,6,8);
	BuildlBarrier(1,4,4);
	BuildlBarrier(2,4,6);
	MAP[6][5]='#',MAP[4][5]='#',MAP[2][7]='#';
	MAP[1][1]='o';
	MAP[2][2]='B',MAP[2][3]='B',MAP[3][2]='B';
	MAP[3][7]='X',MAP[4][7]='X',MAP[5][7]='X';
	end[0]=(struct COD){3,7};
	end[1]=(struct COD){4,7};
	end[2]=(struct COD){5,7};
	start2=(struct COD){1,1};
	
	return start2;
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

void Judge(int twd,struct COD* now,struct COD* New){                      //判断人的移动 
	char temp;
	if(MAP[New->x][New->y] == ' ' || MAP[New->x][New->y] == 'X' ){
		temp=MAP[now->x][now->y];
		MAP[now->x][now->y]=MAP[New->x][New->y];
		MAP[New->x][New->y]=temp;
		*now = *New;
	}
	if(MAP[New->x][New->y] == 'B'){
		struct COD *Bnow=New;
		BoxMove(twd,Bnow);
		PlayerMove(twd,now);
	}
}

void PlayerMove(int twd,struct COD* now){
	struct COD n =*now;
	struct COD *New=&n;
	switch(twd){
		case -1: break; 
		case  0: n.y++;Judge(twd,now,New);break;
		case  1: n.x++;Judge(twd,now,New);break;
		case  2: n.y--;Judge(twd,now,New);break;
		case  3: n.x--;Judge(twd,now,New);break;
	}
}

void BJudge(struct COD* now,struct COD* New){
	char temp;
	if(MAP[New->x][New->y] == ' '){
		temp=MAP[now->x][now->y];
		MAP[now->x][now->y]=MAP[New->x][New->y];
		MAP[New->x][New->y]=temp;
		*now = *New;
	}
	if(MAP[New->x][New->y] == 'X'){                              
		MAP[New->x][New->y] = 'B';
		MAP[now->x][now->y] = ' ';
		*now = *New;
	}
}

void BoxMove(int Btwd,struct COD* Bnow){                        //箱子移动 
	struct COD m =*Bnow;
	struct COD *BNew=&m;
	switch(Btwd){
		case -1: break; 
		case  0: m.y++;BJudge(Bnow,BNew);break;
		case  1: m.x++;BJudge(Bnow,BNew);break;
		case  2: m.y--;BJudge(Bnow,BNew);break;
		case  3: m.x--;BJudge(Bnow,BNew);break;
	}
}

