#include<stdio.h> 
#include<conio.h>          //getch的原型 
#include<stdlib.h>
#include<windows.h>
#define WIDE 9
#define LEN  10
#define ENDJUDGE(c) MAP[end[c].x][end[c].y] != 'B'  //终点判断 

struct COD{                            //指明坐标的结构 
	int x;
	int y;
};
struct COD end[4];                   //终点数组记录每一关卡的终点 
int cnt=1;                           //用于异常检测 

char MAP[WIDE][LEN];
void Initmap(void);                 //将数组全部初始化为空格 
struct COD Initmap_1(void);
struct COD Initmap_2(void);
struct COD Initmap_3(void);
void BuildrBarrier(int st,int end,int row);
void BuildlBarrier(int st,int end,int line);//辅助造墙函数 
void PlayerMove(int twd,struct COD* now);
int GetPlayerCommand(void);                //读取用户命令 
void Judge(int twd,struct COD* now,struct COD* New);//判断人的移动 
void BJudge(struct COD* Bnow,struct COD* BNew);//判断箱子移动 
void BoxMove(int Btwd,struct COD* Bnow);
void Put(void);//输出二维数组的当前值 

int main(void){
	struct COD* now;                         
	struct COD loc=Initmap_1();
	now = &loc;
	
	while(ENDJUDGE(0) || ENDJUDGE(1) || ENDJUDGE(2) || ENDJUDGE(3) ){
		Put();
		PlayerMove(GetPlayerCommand(),now);
	}
	Put();
	printf("you win!,turn to level 2！\n"); 
	Sleep(1000);
	
	system("cls");
	loc = Initmap_2();
	now = &loc;
	while(ENDJUDGE(0) || ENDJUDGE(1) || ENDJUDGE(2) ){
		Put();
		PlayerMove(GetPlayerCommand(),now);
	}
	Put();
	printf("you win!,turn to level 3!\n");
	Sleep(1000);
	
	system("cls");
	loc = Initmap_3();
	now = &loc;
	while(ENDJUDGE(0) || ENDJUDGE(1) || ENDJUDGE(2) || ENDJUDGE(3) ){
		Put();
		PlayerMove(GetPlayerCommand(),now);
	}
	Put();
	printf("you win!,Here is your score list");
	
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

void Initmap(void){
	int i,j;	
	for(i=1;i<WIDE;i++){
		for(j=1;j<LEN;j++){
			MAP[i][j]=' ';
		}
	} 
}

struct COD Initmap_1(void){                       
	struct COD start;
	Initmap();
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
	start =(struct COD){4,4};
	return start;
}

struct COD Initmap_2(void){
	end[3]=(struct COD){0,0};          //此关只有三个箱子 
	struct COD start;              
	Initmap();
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
	start=(struct COD){1,1};
	return start;
} 

struct COD Initmap_3(void){
	struct COD start;
	Initmap();
	BuildrBarrier(1,7,0);
	BuildrBarrier(0,5,2);
	BuildlBarrier(3,5,0);
	BuildrBarrier(1,8,6);
	BuildlBarrier(4,5,4);
	BuildlBarrier(4,5,8);
	BuildlBarrier(1,4,9);
	BuildrBarrier(7,8,1);
	MAP[1][1]='#',MAP[5][1]='#';
	MAP[3][2]='o';
	MAP[2][2]='B',MAP[3][4]='B',MAP[3][7]='B',MAP[4][6]='B';
	MAP[4][2]='X',MAP[4][3]='X',MAP[5][2]='X',MAP[5][3]='X';
	end[0]=(struct COD){4,2};
	end[1]=(struct COD){4,3};
	end[2]=(struct COD){5,2};
	end[3]=(struct COD){5,3};
	start =(struct COD){3,2};
	return start;
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

void Judge(int twd,struct COD* now,struct COD* New){                    
	char temp;
	if(MAP[New->x][New->y] == ' ' || MAP[New->x][New->y] == 'X' ){
		MAP[New->x][New->y]='o';
		MAP[now->x][now->y]=' ';
		*now = *New;
	}
	if(cnt){
		if(MAP[New->x][New->y] == 'B'){
			struct COD *Bnow=New;
			BoxMove(twd,Bnow);
			PlayerMove(twd,now);
			cnt=1;
		}
	}
	for(int i=0;i<4;i++){                              //回复X的值 
		if(MAP[end[i].x][end[i].y] == ' '){
			MAP[end[i].x][end[i].y] = 'X';
		}
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

void BJudge(struct COD* Bnow,struct COD* BNew){
	char temp;
	if(MAP[BNew->x][BNew->y] == 'X' || MAP[BNew->x][BNew->y] == ' '){                              
		MAP[BNew->x][BNew->y] = 'B';
		MAP[Bnow->x][Bnow->y] = ' ';
		*Bnow = *BNew;
	}
	if(MAP[BNew->x][BNew->y] == '#' || MAP[BNew->x][BNew->y] == 'B'){
		cnt = 0;
	}
}

void BoxMove(int Btwd,struct COD* Bnow){                        
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

