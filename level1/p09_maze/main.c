#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> 
#include <conio.h>
#define N 31
#define WALL 0
#define ROAD 1
#define END 2 
int maze[N][N];  //一开始全是墙 
int move[4][2]={1,0,-1,0,0,1,0,-1}; //移动的方式 
int tx,ty;  //实时坐标 
void play();
void setstart();
int check();
void path();
int main(){
	srand((unsigned)time(0)); 
	int i,j;
	path(N-2,N-2); //从终点前开始递归 
	maze[N-2][N-1]=END; //定义终点
	setstart();
	for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(maze[i][j]==ROAD){
					printf(" ");
				}
				if(maze[i][j]==WALL){
					printf("0");	//可以改为printf("%c",219); 
				}
				if(maze[i][j]==END){
					printf("*");
				}
				if(j==N-1){
					printf("\n");
				}
			}
	}
	printf("光标是您，请到达星星位置\n");
	play();
	return 0; 
}

void play(){
	HANDLE hout;
	COORD coord;
	hout=GetStdHandle(STD_OUTPUT_HANDLE);
	while(1){
		if(ty==N-2&&tx==N-1){
			system("cls");
			printf("you make it!");
			return ;
		}

		coord.X=tx;
		coord.Y=ty;
		SetConsoleCursorPosition(hout,coord);
		char ch;
		ch=_getch();
		ch=_getch();
		if(ch==72){
			ty--;
			if(maze[ty][tx]==WALL){
				ty++;
			}
			continue;
		}
		if(ch==80){
			ty++;
			if(maze[ty][tx]==WALL){
				ty--;
				
			}
			continue;
		}
		if(ch==75){
			tx--;
			if(maze[ty][tx]==WALL){
				tx++;
			
			}
			continue;
		}
		if(ch==77){
			tx++;
			if(maze[ty][tx]==WALL){
				tx--;
			
			}
			continue;
		}
	}
}

void setstart(){
	int i;
	for(i=1;i<N-1;i++){
		if(maze[1][i]==ROAD) {
			ty=1;
			tx=i; 
			return ;
		} 
	}
}

int check(int a,int b,int k){
	int i,tot=0;
	for(i=0;i<4;i++){
		if(maze[a+move[i][0]][b+move[i][1]]==WALL){
			tot++;
		}
	} 
	if(tot==3) return 1;
	else return 0;
}

void path(int a,int b){
	maze[a][b]=ROAD;
	int i,k,t;
	t = rand()%2 ? 1 : 3; //使方向的变更更有随机性 
	k = rand()%4;
	for(i=0;i<4;i++,k=(k+t)%4){ 
		if(a+2*move[k][0]>N-1||a+2*move[k][0]<0||b+2*move[k][1]>N-1||b+2*move[k][1]<0){
			continue;
		}
		if(check(a+move[k][0],b+move[k][1],k)&&maze[a+move[k][0]][b+move[k][1]]!=ROAD){
			maze[a+move[k][0]][b+move[k][1]]=ROAD;
			path(a+move[k][0],b+move[k][1]);
		}
	}
	return ;
} 
