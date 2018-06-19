#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h> 
#define WALL '0'
#define BLANK '1'
#define GOAL '2'
#define BOX '8'
#define PLAYER '5'
#define MAXN '3'
FILE* fp;
char maze[1000][1000],opt;
int tx,ty,len,hig,cnt,flag;
void init();
void play();
void displayf();
void selectf(char);
void disp(); 
void meun();

int main(){
while(1)
{
	flag=0;
	meun();
	scanf("%c",&opt);
	selectf(opt);
	fscanf(fp,"%d%d%d",&len,&hig,&cnt);
	char x;
	int i,j;
	init();
	for(i=0;i<len;i++){
		for(j=0;j<hig;j++){
			fscanf(fp,"%c",&x);
			if(x=='\n'){
				j--;
				continue;
			}
			if(x==PLAYER) ty=i,tx=j;
			maze[i][j]=x;
		}
	}
	displayf();
	play();
	fclose(fp);
}
} 

void init(){
	int i,j;
	for(i=0;i<1000;i++){
		for(j=0;j<1000;j++){
			maze[i][j]='0';
		}
	}
}

void displayf(){
	system("cls");
	int i,j;
	for(i=0;i<len;i++){
		for(j=0;j<hig;j++){
			if(maze[i][j]==WALL){
				printf("0");
			}
			if(maze[i][j]==BLANK){
				printf(" ");
			}
			if(maze[i][j]==GOAL){
				printf("#");
			}
			if(maze[i][j]==BOX){
				printf("*");
			}
			if(maze[i][j]==PLAYER){
				printf("@"); 
			}
		} 
		printf("\n");
	}
	printf("如果卡关请按两次 r ！！"); 
}

void meun(){
	system("cls");
	fflush(stdin);
	printf("请选择关卡:\n1.走廊\n2.跑道\n3.森林\n");
}

void selectf(char k){
	if(k>MAXN){
		printf("coming soon!\n");
		system("pause");
		meun();
		scanf("%c",&k);
		selectf(k);
		return ;
	}
	char A[10]="M0.txt";
	A[1]=k;
	fp = fopen(A,"r");
}

void disp(int opt,int x,int y){
	HANDLE hout;
	COORD coord;
	hout=GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X=y;
	coord.Y=x;
	SetConsoleCursorPosition(hout,coord);
	switch(opt){
		case PLAYER:	
			printf("@");
			break;
		case BOX:
			printf("*");
			break;
		case BLANK:
			printf(" ");
			break;
		case WALL:
			printf("0");
			break;
		case GOAL:
			printf("#");
			break;
	}
	SetConsoleCursorPosition(hout,coord);
}

void play(){
	HANDLE hout;
	COORD coord;
	hout=GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X=tx;
	coord.Y=ty;
	SetConsoleCursorPosition(hout,coord);
	while(1){
		char ch;
		ch=_getch();
		ch=_getch();
		if(ch=='r'||ch=='R') return ;
		if(ch==72){
			ty--;
			if(maze[ty][tx]==WALL){
				ty++;
				continue;
			}
			if(maze[ty][tx]==GOAL){
				maze[ty+1][tx]=BLANK;
				disp(BLANK,ty+1,tx); 
				disp(PLAYER,ty,tx);
				continue;
			}
			if(maze[ty][tx]==BOX){
				if(maze[ty-1][tx]==GOAL){
					maze[ty-1][tx]=WALL;
					disp(WALL,ty-1,tx);
					flag++;
					if(flag==cnt){
						system("cls");
						printf("you make it!");
						system("pause");
						return ;
					}
				}
				else if(maze[ty-1][tx]==WALL||maze[ty-1][tx]==BOX){
					ty++;
					continue;
				}
				else{
					maze[ty-1][tx]=BOX;
					disp(BOX,ty-1,tx);
				}
			}
			if(maze[ty+1][tx]==GOAL){
				disp(GOAL,ty+1,tx);
			} 
			else{
				disp(BLANK,ty+1,tx);
			}
			maze[ty][tx]=PLAYER;
			disp(PLAYER,ty,tx); 
			continue;
		}
		if(ch==80){
			ty++;
			if(maze[ty][tx]==WALL){
				ty--;
				continue;
			}
			if(maze[ty][tx]==GOAL){
				maze[ty-1][tx]=BLANK;
				disp(BLANK,ty-1,tx); 
				disp(PLAYER,ty,tx);
				continue;
			}
			if(maze[ty][tx]==BOX){
				if(maze[ty+1][tx]==GOAL){
					maze[ty+1][tx]=WALL;
					disp(WALL,ty+1,tx);
					flag++;
					if(flag==cnt){
						system("cls");
						printf("you make it!");
						system("pause");
						return ;
					}
				}
				else if(maze[ty+1][tx]==WALL||maze[ty+1][tx]==BOX){
					ty--;
					continue;
				}
				else{
					maze[ty+1][tx]=BOX;
					disp(BOX,ty+1,tx);
				}
			}
			if(maze[ty-1][tx]==GOAL){
				disp(GOAL,ty-1,tx);
			} 
			else{
				disp(BLANK,ty-1,tx);
			}
			maze[ty][tx]=PLAYER;
			disp(PLAYER,ty,tx); 
			continue;
		}
		
		if(ch==75){
			tx--;
			if(maze[ty][tx]==WALL){
				tx++;
				continue;
			}
			if(maze[ty][tx]==GOAL){
				maze[ty][tx+1]=BLANK;
				disp(BLANK,ty,tx+1); 
				disp(PLAYER,ty,tx);
				continue;
			}
			if(maze[ty][tx]==GOAL){
				disp(PLAYER,ty,tx);
				continue;
			}
			if(maze[ty][tx]==BOX){
				if(maze[ty][tx-1]==GOAL){
					maze[ty][tx-1]=WALL;
					disp(WALL,ty,tx-1);
					flag++;
					if(flag==cnt){
						system("cls");
						printf("you make it!");
						system("pause");
						return ;
					}
				}
				else if(maze[ty][tx-1]==WALL||maze[ty][tx-1]==BOX){
					tx++;
					continue;
				}
				else{
					maze[ty][tx-1]=BOX;
					disp(BOX,ty,tx-1);
				}
			}
			if(maze[ty][tx+1]==GOAL){
				disp(GOAL,ty,tx+1);
			} 
			else{
				disp(BLANK,ty,tx+1);
			}
			maze[ty][tx]=PLAYER;
			disp(PLAYER,ty,tx); 
			continue;
		}
		
		if(ch==77){
			tx++;
			if(maze[ty][tx]==WALL){
				tx--;
				continue;
			}
			if(maze[ty][tx]==GOAL){
				maze[ty][tx-1]=BLANK;
				disp(BLANK,ty,tx-1); 
				disp(PLAYER,ty,tx);
				continue;
			}
			if(maze[ty][tx]==BOX){
				if(maze[ty][tx+1]==GOAL){
					maze[ty][tx+1]=WALL;
					disp(WALL,ty,tx+1);
					flag++;
					if(flag==cnt){
						system("cls");
						printf("you make it!");
						system("pause");
						return ;
					}
				}
				else if(maze[ty][tx+1]==WALL||maze[ty][tx+1]==BOX){
					tx--;
					continue;
				}
				else{
					maze[ty][tx+1]=BOX;
					disp(BOX,ty,tx+1);
				}
			}
			maze[ty][tx]=PLAYER;
			disp(PLAYER,ty,tx);
			if(maze[ty][tx-1]==GOAL){
				disp(GOAL,ty,tx-1);
			} 
			else{
				disp(BLANK,ty,tx-1);
			}
			continue;
		}
	}
}
