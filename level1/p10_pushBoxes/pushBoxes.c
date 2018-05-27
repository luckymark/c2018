#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
	
int main(){
	void chooselevel(int *plevel);
	void showscore();
	void getrowcolaim(FILE *fin,int *prow,int *pcol,int *paim);
	void creatmap(FILE *fin,int *p,int row,int col);
	void output(int *p,int x,int y,int n,int COL);							//函数声明 
	int getmove(int *p,char ch,int *px,int *py,int ROW,int COL);
	void print(int *p,int ROW,int COL);
	void findplayer(int *p,int *px,int *py,int ROW,int COL);
	void goto_xy(int,int);
	int gameover(int *p,int ROW,int COL,int AIM);
	void savescores(FILE *fout,int steps);
	
	int x = 0,y = 0;														//定义变量 
	int *px = &x,*py = &y;
	
	char m;
	
	int row, col, aim;
	int *prow = &row, *pcol = &col, *paim = &aim;
	
	FILE *fin,*fout;
	
	int level;
	int *plevel = &level;
	
	chooselevel(plevel);													//调用选关函数 
	while (1){
		switch (level){
			case 0:{												//调用函数查看纪录
				showscore();
				system("pause");
				system("cls");
				chooselevel(plevel);
			}
			case 1:{														//打开对应关卡文件 
				if ((fin = fopen("map1.dat","r+")) == NULL) {
					printf("Can't open this map!\n");
					exit(0);
				}
				if ((fout = fopen("score1.dat","a+")) == NULL) {
					printf("Can't read the scores!\n");
					exit(0);
				}
				break;
			}
			case 2:{
				if ((fin = fopen("map2.dat","r+")) == NULL) {
					printf("Can't open this map!\n");
					exit(0);
				}
				if ((fout = fopen("score2.dat","a+")) == NULL) {
					printf("Can't read the scores!\n");
					exit(0);
				}
				break;
			}
			default:;
		}
		if (level != 0){
			break;
		}
	}
	
	
	getrowcolaim(fin,prow,pcol,paim);									//获取地图行数,列数和箱子数 
	
	const int ROW = row, COL = col, AIM = aim;							//创建对应的大小数组 并 读入地图数组 
	int map[ROW][COL];
	int *p = &map[0][0];
	creatmap(fin,&map[0][0],ROW,COL);
	
	
	print(&map[0][0],ROW,COL);      									//输出地图 
	findplayer(&map[0][0],px,py,ROW,COL);								//定位玩家初始坐标 
	goto_xy(0,ROW+9);
	
	int steps = 0;														//此变量记录玩家步数 
	
	m = getch();
	while (1){
		
		if (m == 'q') {													//输入 q 退出游戏 
			printf("Game Over!\n");
			system("pause");
			exit(0);
		}
		
		int temp = getmove(p,m,px,py,ROW,COL);							//玩家每推着箱子走一步，计数器+1
		if (temp == 1){
			steps++;
		}
		goto_xy(0,ROW+9);
		printf("已走步数:%d\n",steps);	
		
		if (gameover(&map[0][0],ROW,COL,AIM) == 0){						//箱子全部到达目的地,游戏结束 
			break;
		}
		
		m = getch();
	}
	printf("Congratulations!\n");										//收尾工作 
	savescores(fout,steps);												//保存成绩 
	fclose(fin);														//关闭文件 
	fclose(fout);
	system("pause");
	return 0;
}

void chooselevel(int *plevel) {											//选关函数 
	printf("推箱子小游戏\n");
	printf("输入 0 查看纪录  1,2... 选关\n");
	
	scanf("%d",plevel);
	system("cls");
	
}

void showscore(){														//从对应文件在读入纪录 
	printf("请输入你想查看纪录的关卡:\n");
	int n;
	scanf("%d",&n);
	FILE *fscore;
	switch(n){
		case 1:{
			if ((fscore = fopen("score1.dat","r")) == NULL) {
				printf("Can't read your score!\n");
				exit(0);
			}
			break;
		}
		case 2:{
			if ((fscore = fopen("score2.dat","r")) == NULL) {
				printf("Can't read your score!\n");
				exit(0);
			}
			break;
		}
		default:;
	}
	rewind(fscore);
	
	while(!feof(fscore)){
		putchar(getc(fscore));
	}
	putchar(10);		//输出一个空格 
}

void getrowcolaim(FILE *fin,int *prow,int *pcol,int *paim){				//从文件中读入地图行数,列数和箱子数 
	int row,col,aim;
	fscanf(fin,"%d,%d,%d,",&row,&col,&aim);
	*prow = row; *pcol = col; *paim = aim;
}

void creatmap(FILE *fin,int *p,int row,int col){						//从文件中读入地图数组 
	
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			fscanf(fin,"%d,",(p+(i*col)+j));
		}
	}
}

void print(int *p,int ROW,int COL){												//输出地图数组 
	for (int i = 0; i<ROW; i++){
		for (int j = 0; j<COL; j++,p++){
			printf(" ");
			printf("%c",*p);
		}
		printf("\n");
	}
		
	printf("\n推箱子小游戏\n图例:\n");
	printf("%c --空地, %c --墙壁, %c --未到目的地箱子, %c --目的地, %c --玩家, %c --已到目的地箱子\n",32,35,88,79,64,85);
	printf("输入w, a, s, d移动人物\n");
	printf("w -- 向上, a -- 向左, s -- 向下, d -- 向右\n");
	printf("输入 q 退出游戏\n");
}

void goto_xy(int x,int y){									//定位光标位置到指定坐标
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={x,y};
	SetConsoleCursorPosition(hOut,pos);
}

void findplayer(int *p,int *px,int *py,int ROW,int COL){					//定位玩家初始坐标 
	for (int i = 0; i<ROW; i++){
		for (int j = 0; j<COL; j++,p++){
			if (*p == 64){
				*px = i; 
				*py = j;
				return;
			}
		}
	}
}


int isBox(int *p,int x,int y,int COL){						//判断位置(x,y)是否为箱子 
	if (*(p+(x*COL)+y) == 88){
		return 10;
	}
	else if (*(p+(x*COL)+y) == 85){
		return 11;
	}
	else return 0;
}

int isStop(int *p,int x,int y,int COL){						//判断下一步是否可移动到位置(x,y)
	if (*(p+(x*COL)+y) == 32 || *(p+(x*COL)+y) == 79){
		return 0;
	}
	else return 1;
}

int isDesti(int *p,int x,int y,int COL){						//判断位置(x,y)是否为目的地 
	if (*(p+(x*COL)+y) == 79){
		return 1;
	}
	else return 0;
}

void judge(int *p,int *pr,char ch,int x,int y,int COL){		//判断函数，判断玩家即将移动的方向 的情况， 
	int x0 = x, y0 = y;										//并将判断结果返回到move函数的result数组中 
	switch(ch){
		case 'w':{
			x-=1;
			*pr = isBox(p,x,y,COL);				//判断玩家前方是否为箱子 
			if(*pr == 10){					//进一步判断，该箱子是什么箱子 
				x-=1;						//如果是未到目的地的箱子，x-1，供下面的函数进一步判断 
			}
			else if(*pr == 11){
				x-=1;
				*(pr+4) = 1;				//如果是已到目的地的箱子，返回结果到result数组，记录该箱子状态为 已到目的地 
			}
			pr++;
			*pr = isStop(p,x,y,COL); pr++;		//判断即将移动的位置是否可移动 
			*pr = isDesti(p,x,y,COL);pr++;		//判断即将移动的位置是否为目的地 
			
			if (*(p+(x0*COL)+y0) == 641){	//判断玩家当前是否站在目的地上 
				*pr = 1;
			}
			break;
		}
		case 'a':{
			y-=1;
			*pr = isBox(p,x,y,COL);
			if(*pr == 10){
				y-=1;
			}
			else if(*pr == 11){
				y-=1;
				*(pr+4) = 1;
			}
			pr++;
			*pr = isStop(p,x,y,COL); pr++;
			*pr = isDesti(p,x,y,COL);pr++;
			
			if (*(p+(x0*COL)+y0) == 641){
				*pr = 1;
			}
			break;
		}
		case 's':{
			x+=1;
			*pr = isBox(p,x,y,COL);
			if(*pr == 10){
				x+=1;
			}
			else if(*pr == 11){
				x+=1;
				*(pr+4) = 1;
			}
			pr++;
			*pr = isStop(p,x,y,COL); pr++;
			*pr = isDesti(p,x,y,COL);pr++;
			
			if (*(p+(x0*COL)+y0) == 641){
				*pr = 1;
			}
			break;
		}
		case 'd':{
			y+=1;
			*pr = isBox(p,x,y,COL);
			if(*pr == 10){
				y+=1;
			}
			else if(*pr == 11){
				y+=1;
				*(pr+4) = 1;
			}
			pr++;
			*pr = isStop(p,x,y,COL); pr++;
			*pr = isDesti(p,x,y,COL);pr++;
			
			if (*(p+(x0*COL)+y0) == 641){
				*pr = 1;
			}
			break;
		}
		default:;
	}
}

void output(int *p,int x,int y,int n,int COL){			//输出函数，根据传入参数进行不同的输出 
	switch(n){
		case 1:{							//在位置(x,y)输出 空地 
			*(p+(x*COL)+y) = 32;
			goto_xy(2*y+1,x);
			printf("%c",*(p+(x*COL)+y));
			break;
		}
		case 2:{							//在位置(x,y)输出 玩家 
			*(p+(x*COL)+y) = 64;
			goto_xy(2*y+1,x);
			printf("%c",*(p+(x*COL)+y));
			break;
		}
		case 3:{							//在位置(x,y)输出 站在目的地上的玩家 
			*(p+(x*COL)+y) = 641;
			goto_xy(2*y+1,x);
			printf("%c",64);
			break;
		}
		case 4:{							//在位置(x,y)输出 未到目的地的箱子 
			*(p+(x*COL)+y) = 88;
			goto_xy(2*y+1,x);
			printf("%c",*(p+(x*COL)+y));
			break;
		}
		case 5:{							//在位置(x,y)输出 已到目的地的箱子 
			*(p+(x*COL)+y) = 85;
			goto_xy(2*y+1,x);
			printf("%c",*(p+(x*COL)+y));
			break;
		}
		case 6:{							//在位置(x,y)输出 目的地 
			*(p+(x*COL)+y) = 79;
			goto_xy(2*y+1,x);
			printf("%c",*(p+(x*COL)+y));
			break;
		}
	}
}

void move(int *p,int *pr,int x,int y,int x1,int y1,int x2,int y2,int COL){
	//移动函数,根据result数组的内容，调用output函数输出从而实现玩家移动和推箱子 
		if (*pr == 0){								// 
			if(*(pr+2) == 0){						//result数组内容代表的含义:玩家即将移动的位置 的情况 
				if (*(pr+3) == 0){					//result[0]: 是否为箱子，0 --不是，1 --是 
					output(p,x,y,1,COL);			//result[1]: 是否为障碍物，0 --不是，1 --是 
					output(p,x1,y1,2,COL);			//result[2]: 是否为目的地，0 --不是，1 -- 是 
				}									//result[3]: 玩家当前位置是否为目的地， 0 --不是，1 --是 
				else {								//result[4]: 箱子当前位置是否为目的地， 0 --不是，1 --是 
					output(p,x,y,6,COL);
					output(p,x1,y1,2,COL);
				}
			}
			else {
				if (*(pr+3) == 0){
					output(p,x,y,1,COL);
					output(p,x1,y1,3,COL);
				}
				else {
					output(p,x,y,6,COL);
					output(p,x1,y1,3,COL);
				}
			}
		}
		else {
			if(*(pr+2) == 0){
				if (*(pr+3) == 0){
					if (*(pr+4) == 0){
						output(p,x,y,1,COL);
						output(p,x1,y1,2,COL);
						output(p,x2,y2,4,COL);
					}
					else {
						output(p,x,y,1,COL);
						output(p,x1,y1,3,COL);
						output(p,x2,y2,4,COL);
					}
				}
				else {
					if (*(pr+4) == 0){
						output(p,x,y,6,COL);
						output(p,x1,y1,2,COL);
						output(p,x2,y2,4,COL);
					}
					else {
						output(p,x,y,6,COL);
						output(p,x1,y1,3,COL);
						output(p,x2,y2,4,COL);
					}
				}
			}
			else {
				if (*(pr+3) == 0){
					if (*(pr+4) == 0){
						output(p,x,y,1,COL);
						output(p,x1,y1,2,COL);
						output(p,x2,y2,5,COL);
					}
					else {
						output(p,x,y,1,COL);
						output(p,x1,y1,3,COL);
						output(p,x2,y2,5,COL);
					}
				}
				else {
					if (*(pr+4) == 0){
						output(p,x,y,6,COL);
						output(p,x1,y1,2,COL);
						output(p,x2,y2,5,COL);
					}
					else {
						output(p,x,y,6,COL);
						output(p,x1,y1,3,COL);
						output(p,x2,y2,5,COL);
					}
				}
			}
		}
}

int getmove(int *p,char ch,int *px,int *py,int ROW,int COL){		//读入玩家移动方向，并调用move函数进行移动 
	int x = *px, y = *py;
	int result[5] = {0,0,0,0,0};
	int *pr = &result[0];
	
	judge(p,pr,ch,x,y,COL);
	
	switch(ch){
		case 'w':{
			if ((x-1) != 0 && result[1] == 0){
				move(p,pr,x,y,x-1,y,x-2,y,COL);
				*px = x-1;
			}
			break;
		}
		case 'a':{
			if ((y-1) != 0 && result[1] == 0){
				move(p,pr,x,y,x,y-1,x,y-2,COL);
				*py = y-1;
			}
			break;
		}
		case 's':{
			if ((x+1) != (ROW-1) && result[1] == 0){
				move(p,pr,x,y,x+1,y,x+2,y,COL);
				*px = x+1;
			}
			break;
		}
		case 'd':{
			if ((y+1) != (COL-1) && result[1] == 0){
				move(p,pr,x,y,x,y+1,x,y+2,COL);
				*py = y+1;
			}
			break;
		}
		default :{
			return 0;
		}
	}
	if (((result[0]/10) == 1) && (result[1] == 0)) {
		return 1;
	}
	return 0;
} 


int gameover(int *p,int ROW,int COL,int AIM){									//判断箱子是否全部到达目的地 
	int count=0;
	for (int i = 0; i<ROW; i++){
		for (int j = 0; j<COL; j++,p++){
			if (*p == 85){
				count++;
			}
		}
	}
	if (count == AIM){
		return 0;
	}
	else {
		return 1;
	}
}

void savescores(FILE *fout,int steps){											//保存玩家成绩 
	char name[20];
	int i = 0;
	printf("\n请留下尊姓大名(以 # 结束):");
	name[0] = getchar();
	
	while (name[i] != '#'){
		fprintf(fout,"%c",name[i]);
		i++;
		name[i] = getchar();
		
	}
	fprintf(fout," : ");
	fprintf(fout,"%d ,\n",steps);
	printf("你的成绩已保存!\n");
}

