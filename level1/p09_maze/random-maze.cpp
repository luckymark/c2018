#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h> 
#define ROW 39														//迷宫行数 
#define COL 39														//迷宫列数 
#define DOWN 46														//玩家输入移动指令时光标的位置 

typedef struct _SITE {												//自定义坐标类型SITE 

INT X;

INT Y;

} SITE;

int main(){
	void output(int (*p)[COL],int x,int y,char ch);					//函数声明 
	void originalmaze(int (*p)[COL]);
	void makemaze(int (*p)[COL], int *px, int *py);
	void replace(int (*p)[COL]);
	int destination(int (*p)[COL]);
	void move(int (*p)[COL],char ch,int *px,int *py);
	void print(int *p);
	void goto_xy(int,int);
	
	int x = 0, y = 0, desti;												//定义变量 
	int *px = &x, *py = &y;
	int maze[ROW][COL];
	int (*p)[COL] = maze;
	char m;
	
	originalmaze(p);
	makemaze(p,px,py);
	replace(p);
	desti = destination(p);
	
	output(p,x,y,'w');												//迷宫实现 

	m = getch();
	while (1){
		move(p,m,px,py);
		if (maze[0][desti] == 64){
			break;
		}
		m = getch();
	}
	printf("Congratulations!\n");
	system("pause");
	return 0;
}

void print(int *p){													//输出迷宫数组 
	printf("\n");
	for (int i = 0; i<ROW; i++){
		for (int j = 0; j<COL; j++,p++){
			printf(" ");
			printf("%c",*p);
		}
		printf("\n");
	}
		
	printf("迷宫小游戏\n");
	printf("图例：\n");
	printf("%c --墙壁, %c --人物\n",35,64);
	printf("输入w, a, s, d移动人物\n");
	printf("w -- 向上, a -- 向左, s -- 向下, d -- 向右\n");
	
}

void goto_xy(int x,int y){										//定位光标位置到指定坐标
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={x,y};
	SetConsoleCursorPosition(hOut,pos);
}

void originalmaze(int (*p)[COL]){									//初始化迷宫数组 
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			if ((i%2) == 0){
				*(*(p+i)+j) = 0;
			}
			else{
				if (j != 0 && j != (COL-1)){
					if (*(*(p+i)+(j-1)) == 0){
						*(*(p+i)+j) = 1;
					}
					else {
						*(*(p+i)+j) = 0;
					}
				}
				else{
					*(*(p+i)+j) = 0;
				}
			}
		}
	}
}


//此随机迷宫生成思路详见同名附件文档 --方案二 

//此函数生成随机迷宫 
void makemaze(int (*p)[COL], int *px, int *py){						//2x --红色x , 3x -- 蓝色x
	int x = ROW-2, y = *py, x0, y0, r1, r2;
	SITE randblue = {0,0};
	
	void mark(int (*p)[COL],int x,int y);							//函数声明 
	SITE randchoose(int (*p)[COL],int *px,int *py);
	int judire(int (*p)[COL],int *px,int *py);
	
    srand((unsigned int)time(NULL));
    r1 = (rand()%((COL-1)/2) +1)*2 -1;								//生成2-COL 之间的随机偶数 
    *(*(p+x)+r1) = 21;												//随机取一个地图边缘的1，把它标记为红色1
    y = r1;
    x0 = x; y0 = y;													//记录迷宫起点坐标 
    
    mark(p,x,y);													//把红色1旁边的0标记成蓝色0，表示"待定"
    randblue = randchoose(p,px,py);									//随机选一个蓝色0
    while (1){
    	if (randblue.X != 0 && randblue.Y != 0){
	    	*px = randblue.X; *py = randblue.Y;
	    	x = *px; y = *py;
	    	
			int direction = judire(p,px,py);						//调用函数判断蓝色0的哪个方向有1, 返回值:1-左, 2-右, 3-上, 4-下 
			switch (direction){
				case 1:{
					*(*(p+x)+(y-1)) = 21;
					*(*(p+x)+y) = 20;
					y--; *py = y;
					break;
				}
				case 2:{
					*(*(p+x)+(y+1)) = 21;
					*(*(p+x)+y) = 20;
					y++; *py = y;
					break;
				}
				case 3:{
					*(*(p+(x-1))+y) = 21;
					*(*(p+x)+y) = 20;
					x--; *px = x;
					break;
				}
				case 4:{
					*(*(p+(x+1))+y) = 21;
					*(*(p+x)+y) = 20;
					x++; *px = x;
					break;
				}
				default:;
			}
			mark(p,x,y);
			randblue = randchoose(p,px,py);
    	}
    	else {
    		*(*(p+x0)+y0) = 41;
    		*px = x0+1; *py = y0;								//将坐标重新定位至迷宫起点 
    		break;
    	}
    }
    
}

void replace(int (*p)[COL]){									//对生成的迷宫数组字符进行替换，便于输出 
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			if (*(*(p+i)+j) == 0){
				*(*(p+i)+j) = 35;
			}
			if (*(*(p+i)+j) == 41){
				*(*(p+(i+1))+j) = 64;
				*(*(p+i)+j) = 32;
			}
			if (*(*(p+i)+j) == 21 || *(*(p+i)+j) == 20){
				*(*(p+i)+j) = 32;
			}
		}
	}
}

int destination(int (*p)[COL]){							//生成迷宫出口 
	int r;
	srand((unsigned int)time(NULL));
	r = rand()%(COL-3) +1;
	while (*(*(p+1)+r) != 32){
		r = rand()%(COL-3) +1;
	}
	*(*(p)+r) = 32;
	return r;
}

void mark(int (*p)[COL],int x,int y){						//把红色1旁边的0标记成蓝色0，表示"待定"
	if (*(*(p+x)+y) == 21){
		if ((y-1) != 0 && *(*(p+x)+(y-1)) == 0){
			*(*(p+x)+(y-1)) = 30;
		}
		if ((y+1) != (COL-1) && *(*(p+x)+(y+1)) == 0){
			*(*(p+x)+(y+1)) = 30;
		}
		if ((x-1) != 0 && *(*(p+(x-1))+y) == 0){
			*(*(p+(x-1))+y) = 30;
		}
		if ((x+1) != (ROW-1) && *(*(p+(x+1))+y) == 0){
			*(*(p+(x+1))+y) = 30;
		}
	}
}

SITE randchoose(int (*p)[COL],int *px,int *py){				//随机选一个蓝色0
	SITE blue[ROW*COL];
	int k = 0, r;
	for (int i = 1; i < (ROW-1); i++){
		for (int j = 1; j < (COL-1); j++){
			if (*(*(p+i)+j) == 30){
				blue[k] = {i,j};
				k++;
			}
		}
	}
	if (k != 0){
		srand((unsigned int)time(NULL));
		r = rand()%k;
		*px = blue[r].X;
		*py = blue[r].Y;
		return blue[r];
	}
	else {
		 SITE over = {0,0};
		 return over;
	}
}

int judire(int (*p)[COL],int *px,int *py){					//判断哪个方向有1; 返回值:1-左, 2-右, 3-上, 4-下 
	int x = *px; int y = *py;
	if (*(*(p+x)+(y+1)) == 21 && *(*(p+x)+(y-1)) == 1){
		return 1;
	}
	else if (*(*(p+x)+(y-1)) == 21 && *(*(p+x)+(y+1)) == 1){
		return 2;
	}
	else if (*(*(p+(x+1))+y) == 21 && *(*(p+(x-1))+y) == 1){
		return 3;
	}
	else if (*(*(p+(x-1))+y) == 21 && *(*(p+(x+1))+y) == 1){
		return 4;
	}
	else {
		*(*(p+x)+y) = 0;
		return 0;
	}
}


void output(int (*p)[COL],int x,int y,char ch){				//实现玩家移动 
	
	if (ch == 'w'){
		*(*(p+x)+y) = 64;
		system("cls");
		print((int *) p);
		goto_xy(0,DOWN);
	}
	else {
		*(*(p+x)+y) = 32;
		system("cls");
		print((int *) p);
		goto_xy(0,DOWN);
	}
}

int isWall(int (*p)[COL],int x,int y){						//判断玩家移动位置是否为墙壁 
	if (*(*(p+x)+y) == 32){
		return 0;
	}
	else return 1;
}

void move(int (*p)[COL],char ch,int *px,int *py){			//实现玩家移动 
	int x = *px, y = *py;
	switch (ch){
		case 'w':
			if (isWall(p,x-1,y) == 0){
				output(p,x,y,'b');
				output(p,x-1,y,'w');
				*px = x-1;
			}
			break;
		case 'a':
			if (isWall(p,x,y-1) == 0){
				output(p,x,y,'b');
				output(p,x,y-1,'w');
				*py = y-1;
			}
			break;
		case 's':
			if (isWall(p,x+1,y) == 0){
				output(p,x,y,'b');
				output(p,x+1,y,'w');
				*px = x+1;
			}
			break;
		case 'd':
			if (isWall(p,x,y+1) == 0){
				output(p,x,y,'b');
				output(p,x,y+1,'w');
				*py = y+1;
			}
			break;
		default:;
	}
}



