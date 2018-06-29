#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h> 
void setColor (unsigned short ForeColor,unsigned short BackGroundColor)
{
	
HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(handle,ForeColor+BackGroundColor*0x10);
}


void setPos(int x,int y)
{
    COORD pos;
HANDLE handle;
    pos.X=x;
    pos.Y=y;
    handle=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle,pos);
}
int level=0,maxlevel=10;
int steps=0;
static int X1=52,Y1=13;
static int X2=50,Y2=11;
static int X3=52,Y3=13;
static int X4=50,Y4=12;
static int X5=52,Y5=12;
static int X6=66,Y6=18;
static int X7=60,Y7=11;
static int X8=60,Y8=13;
static int X9=60,Y9=17;
static int X10=50,Y10=17;
struct point {
	int x;
	int y;
};
	struct point Wall1[100]={{50,10},{52,10},{54,10}, {50,11},{54,11},{50,12},{46,12},{48,12},{54,12},{58,12},
						{56,12},{50,16},{52,16},{54,16},{50,15},{54,15},{46,13},{46,14},{48,14},
						{50,14},{54,14},{56,14},{58,14},{58,13}}; 
	struct point Box1[20]={{50,13},{52,12},{54,13},{52,14}};
	struct point Despoint1[20]={{52,11},{48,13},{56,13},{52,15}};
	struct point Wall2[100]={{50,10},{48,10},{52,10},{54,10},{56,10},{48,11},{56,11},{48,12},{56,12},{48,13},
							{56,13},{48,14},{50,14},{52,14},{56,14},{58,14},{50,15},{52,15},{50,16},{58,16},{50,17},
							{58,17},{50,18},{52,18},{54,18},{56,18},{58,18},{60,12},{62,12},{64,12},{60,13},{64,13},
							{60,14},{64,14},{64,15},{64,16},{60,17},{62,17},{64,17}};
	struct point Box2[20]={{52,12},{54,12},{52,13}};
	struct point Despoint2[20]={{62,13},{62,14},{62,15}};
	struct point Wall3[100]={{50,10},{52,10},{54,10},{56,10},{58,10},{60,10},{62,10},{50,11},{62,11},{64,11},{66,11},
						{48,12},{50,12},{54,12},{56,12},{58,12},{66,12},{48,13},{66,13},{48,14},{56,14},{64,14},
						{64,14},{66,14},{48,15},{50,15},{56,15},{64,15},{50,16},{52,16},{54,16},{56,16},{58,16},
						{60,16},{62,16},{64,16}};	
	struct point Box3[20]={{52,12},{56,13},{62,13},{60,14}};
	struct point Despoint3[20]={{52,14},{54,14},{52,15},{54,15}};
	struct point Wall4[100]={{50,10},{52,10},{54,10},{56,10},{48,11},{50,11},{56,11},{48,12},{56,12},{48,13},{50,13},
						{56,13},{58,13},{48,14},{50,14},{58,14},{48,15},{58,15},{48,16},{58,16},{48,17},{50,17},{52,17},
						{54,17},{56,17},{58,17}};
	struct point Box4[20]={{52,12},{52,13},{52,15},{54,14},{54,16}};
	struct point Despoint4[20]={{50,15},{50,16},{52,16},{54,16},{56,16}};	
	struct point Wall5[100]={{50,10},{52,10},{54,10},{56,10},{58,10},{50,11},{56,11},{58,11},{60,11},{50,12},{60,12},
						{48,13},{50,13},{52,13},{56,13},{60,13},{62,13},{48,14},{52,14},{56,14},{62,14},{48,15},{58,15},
						{62,15},{48,16},{62,16},{48,17},{50,17},{52,17},{54,17},{56,17},{58,17},{60,17},{62,17}};
	struct point Box5[20]={{54,12},{52,15},{58,16}};
	struct point Despoint5[20]={{50,14},{50,15},{50,16}};
	struct point Wall6[100]={{50,10},{52,10},{54,10},{56,10},{58,10},{60,10},{62,10},{44,11},{46,11},{48,11},{50,11},{62,11},
							{44,12},{54,12},{56,12},{58,12},{62,12},{44,13},{48,13},{52,13},{62,13},{64,13},{44,14},{48,14},
							{58,14},{64,14},{44,15},{48,15},{60,15},{64,15},{44,16},{50,16},{60,16},{64,16},{44,17},{46,17},
							{56,17},{60,17},{64,17},{66,17},{68,17},{46,18},{50,18},{52,18},{54,18},{68,18},{46,19},{58,19},
							{60,19},{68,19},{46,20},{48,20},{50,20},{52,20},{54,20},{56,20},{58,20},{60,20},{62,20},{64,20},
							{66,20},{68,20}};	
	struct point Box6[20]={{52,14},{52,16},{56,14},{56,16},{54,15}};
	struct point Despoint6[20]={{52,12},{56,18},{48,16},{60,14},{54,15}};
	struct point Wall7[100]={{50,10},{52,10},{54,10},{56,10},{58,10},{60,10},{62,10},{48,11},{50,11},{56,11},{62,11},{48,12},
							{56,12},{62,12},{48,13},{62,13},{48,14},{54,14},{56,14},{62,14},{44,15},{46,15},{48,15},{56,15},
							{60,15},{62,15},{44,16},{60,16},{44,17},{46,17},{48,17},{50,17},{52,17},{54,17},{56,17},{58,17},{60,17} };	
	struct point Box7[20]={{50,13},{54,13},{58,13},{52,14},{52,15}};
	struct point Despoint7[20]={{46,16},{48,16},{50,16},{52,16},{54,16}};	
	struct point Wall8[100]={{50,10},{52,10},{54,10},{56,10},{58,10},{60,10},{46,11},{48,11},{50,11},{60,11},{44,12},{46,12},{54,12},
							{56,12},{60,12},{62,12},{44,13},{62,13},{44,14},{60,14},{62,14},{44,15},{46,15},{48,15},{50,15},{52,15},
							{54,15},{60,15},{54,16},{56,16},{58,16},{60,16}	};
	struct point Box8[20]={{52,12},{50,13},{54,13},{52,14},{56,14}};
	struct point Despoint8[20]={{48,12},{46,13},{48,13},{46,14},{48,14}};
	struct point Wall9[100]={{46,10},{48,10},{50,10},{52,10},{54,10},{56,10},{58,10},{60,10},{62,10},{46,11},{52,11},{54,11},{62,11},
							{46,12},{62,12},{46,13},{52,13},{54,13},{56,13},{62,13},{46,14},{50,14},{58,14},{62,14},{44,15},{46,15},
							{50,15},{58,15},{62,15},{64,15},{44,16},{64,16},{44,17},{56,17},{64,17},{44,18},{46,18},{48,18},{50,18},
							{52,18},{54,18},{56,18},{58,18},{60,18},{62,18},{64,18}};
	struct point Box9[20]={{54,12},{48,13},{60,13},{48,16},{54,16},{60,16}};
	struct point Despoint9[20]={{52,14},{54,14},{56,14},{52,15},{54,15},{56,15}};	
	struct point Wall10[100]={{50,10},{52,10},{54,10},{58,10},{56,10},{48,11},{50,11},{58,11},{60,11},{48,12},{60,12},
						{62,12},{46,13},{48,13},{54,13},{62,13},{46,14},{54,14},{62,14},{46,15},{52,15},{54,15},
						{56,15},{62,15},{46,16},{60,16},{62,16},{46,17},{48,17},{60,17},{48,18},{50,18},{52,18},
						{54,18},{56,18},{58,18},{60,18}};
	struct point Box10[20]={{54,12},{50,13},{58,13},{50,15},{58,15},{52,16},{56,16}};
	struct point Despoint10[20]={{56,12},{58,12},{56,13},{60,13},{56,14},{58,14},{60,14}};
struct maps{
	struct point Wall[100];
	struct point Box[20];
	struct point Despoint[20];
	int X;
	int Y;
}Map[15];

int main()
{
	printf("是否选择关卡开始：\n");
	printf("按下相应键选择：y是/n否\n");
	char choice=getchar();
	if(choice=='y' || choice=='Y')
	{
		printf("最大关数为10\n"); 
		printf("请输入选择的关数：\n");
		int lev=11;
		while(lev>10)
		{
			scanf("%d",&lev);
			if (lev>10)
			printf("没有此关! 请重新输入：\n");
		}
		level=lev-1;	
	} 
	else if(choice=='n' || choice=='N')
	{
		level=0;
	}
	system("cls");
	void Level(int);
	void map(void);
	void move (void);
	Level(level);
	map();
	move();
	setColor(7,0);
	setPos(0,25);
	system("pause");
	return 0;
}
void map (void)
{
	void setPos(int x,int y);
	void menu(void);
	void wall(void);
	void box(void);
	void despoint(void);
	void player(void);
	menu();
	player();
	wall();
	box();
	despoint(); 
	setPos(0,0);
}
void wall(void)
{
	void setPos(int x,int y);
	int i;
	setColor(10,0);
	for(i=0;Map[level].Wall[i].x!=0;i++)
	{
		setPos(Map[level].Wall[i].x,Map[level].Wall[i].y);
		printf("█");
	}
}
void box(void)
{
	void setPos(int x,int y);
	int getpoint1(int);
	int i,j;
	for(i=0;Map[level].Box[i].x!=0;i++)
	{			
		if (getpoint1(i))
		{
			setColor(12,0);
			setPos(Map[level].Box[i].x,Map[level].Box[i].y);
			printf("█");
		}
		else
		{
			setColor(11,0);
			setPos(Map[level].Box[i].x,Map[level].Box[i].y);
			printf("█");
		}
	}
}
void despoint(void)
{
	void setPos(int x,int y);
	int getpoint2(int);
	int i,j;
	for(i=0;Map[level].Despoint[i].x!=0;i++)
	{
		if (getpoint2(i));
		else if(Map[level].Despoint[i].x==Map[level].X && Map[level].Despoint[i].y==Map[level].Y);
		else
		{
			setColor(12,0);
			setPos(Map[level].Despoint[i].x,Map[level].Despoint[i].y);
			printf("●");
		}
	}
}
void player(void)
{
	int i;
	for (i=0;Map[level].Despoint[i].x!=0;i++)
	{
		if (Map[level].Despoint[i].x==Map[level].X && Map[level].Despoint[i].y==Map[level].Y)
		{
			setColor(15,0);
			setPos(Map[level].X,Map[level].Y);
			printf("●");
			break;
		}
	}
	if (Map[level].Despoint[i].x==Map[level].X && Map[level].Despoint[i].y==Map[level].Y);
	else
	{
	setPos(Map[level].X,Map[level].Y); 
	setColor(15,0);
	printf("●");
	}
}
void move(void)
{
	void setPos(int x,int y);
	int win(void);
	void moveup(void);
	void movedown(void);
	void moveleft(void);
	void moveright(void);
	void map(void);
	void box(void);
	void Level(int);
	char ch;
	steps=0;
	setPos(46,23);
	setColor(10,0);
	printf("关卡：");
	setColor(15,0);
	printf("%d",level+1);
	setPos(54,23);
	setColor(10,0);
	printf("步数 ：");
	setColor(15,0);
	printf("%d",steps);
	setPos(0,0); 
	while ((ch=getch())!=0x1B) /*PRESS ESC TO QUIT*/
	{
		system("cls");
			switch(ch)
		{
			case 72:moveup();break;
			case 75:moveleft();break;
			case 80:movedown();break;
			case 77:moveright();break;
			dafault : break;
	    }
	    setPos(46,23);
	    setColor(10,0);
	    printf("关卡：");
	    setColor(15,0);
	    printf("%d",level+1);
	    setPos(54,23);
	    setColor(10,0);
	    printf("步数 ：");
	    setColor(15,0);
		printf("%d",steps);
	    map();
	    if (win()) 
	    {
	    	steps=0;
	    	setPos(42,5);
	    	setColor(15,0); 
	    	level++;
	    	if(level<maxlevel)
	    	{
	    		setPos(42,5);
	    		setColor(15,0);
	    		printf("恭喜过关！！！按任意键开始下一关");
	    		getch();
	    		Level(level);
			}
			else 
			{
				setPos(50,5);
	    		setColor(15,0);
				printf("恭喜通关！！！");
				break;
			} 
		}
	}
}
int obstacle(int x1,int y1)
{
	int i,p=0;
	for (i=0;Map[level].Wall[i].x!=0;i++)
	{
		if(x1==Map[level].Wall[i].x && y1==Map[level].Wall[i].y)
		p=1;
	}
	return p;
}
int push(int x2,int y2)
{
	int i,q=0;
	for(i=0;Map[level].Box[i].x!=0;i++)
	{
		if(x2==Map[level].Box[i].x && y2==Map[level].Box[i].y){
		q=i+1;
		}
	}
	return q;
}
void moveup(void)
{
	void box(void);
	int push(int,int);
	int obstacle(int x1,int y1);
	Map[level].Y--;
	if (obstacle(Map[level].X,Map[level].Y)){
		Map[level].Y++;
	}
	else if (push(Map[level].X,Map[level].Y))
	{
		int i=push(Map[level].X,Map[level].Y)-1;
		int a,b;
		a=Map[level].Box[i].x;
		b=Map[level].Box[i].y-1;
		if (obstacle (a,b) || push(a,b))
		{
			Map[level].Y++;
		}
		else 
		{
			Map[level].Box[i].y=(Map[level].Box[i].y)-1;
			steps++;
		}
	}
	else 
	{
		steps++;
	}	
}
void movedown(void)
{
	void box(void);
	int push(int,int);
	int obstacle(int x1,int y1);
	Map[level].Y++;
	if (obstacle(Map[level].X,Map[level].Y)){
		Map[level].Y--;
	}
	else if (push(Map[level].X,Map[level].Y))
	{
		int i;
		i=push(Map[level].X,Map[level].Y)-1;
		int a,b;
		a=Map[level].Box[i].x;
		b=Map[level].Box[i].y+1;
		if (obstacle (a,b) || push(a,b))
		{
			Map[level].Y--;
		}
		else 
		{
			Map[level].Box[i].y=(Map[level].Box[i].y)+1;
			steps++;
		}
	}
	else 
	{
		steps++;
	}	
}
void moveleft(void)
{
	void box(void);
	int push(int,int);
	int obstacle(int x1,int y1);
	Map[level].X=Map[level].X-2;
	if (obstacle(Map[level].X,Map[level].Y)){
		Map[level].X=Map[level].X+2;
	}
	else if (push(Map[level].X,Map[level].Y))
	{
		int i;
		i=push(Map[level].X,Map[level].Y)-1;
		int a,b;
		a=Map[level].Box[i].x-2;
		b=Map[level].Box[i].y;
		if (obstacle (a,b) || push(a,b))
		{
			Map[level].X=Map[level].X+2;
		}
		else
		{
			Map[level].Box[i].x=(Map[level].Box[i].x)-2;
			steps++;
		}
	}
	else 
	{
		steps++;
	}	
}
void moveright(void)
{
	void box(void);
	int push(int,int);
	int obstacle(int x1,int y1);
	Map[level].X=Map[level].X+2;
	if (obstacle(Map[level].X,Map[level].Y)){
		Map[level].X=Map[level].X-2;
	}
	else if (push(Map[level].X,Map[level].Y))
	{
		int i;
		i=push(Map[level].X,Map[level].Y)-1;
		int a,b;
		a=Map[level].Box[i].x+2;
		b=Map[level].Box[i].y;
		if (obstacle (a,b) || push(a,b))
		{
			Map[level].X=Map[level].X-2;
		}
		else
		{
				Map[level].Box[i].x=(Map[level].Box[i].x)+2;
				steps++;
		}
	}
	else 
	{
		steps++;
	}	
}
int getpoint1(int a)
{
	int b,p=0;
	for(b=0;Map[level].Despoint[b].x!=0;b++)
	{
		if (Map[level].Despoint[b].x==Map[level].Box[a].x && Map[level].Despoint[b].y==Map[level].Box[a].y)
		p=1;
	}
	return p; 
}
int getpoint2(int c)
{
	int d,q=0;
	for(d=0;Map[level].Box[d].x!=0;d++)
	{
		if (Map[level].Despoint[c].x==Map[level].Box[d].x && Map[level].Despoint[c].y==Map[level].Box[d].y)
		q=1;
	}
	return q;
}
void menu (void)
{
	void setPos(int x,int y);
	setColor(13,0);
	setPos(10,10);
	printf("欢迎来到推箱子游戏！！！");
	setPos(10,11);
	printf("按ESC退出游戏。");
	setPos(10,12);
	printf("按←↑→↓键控制小球移动方向") ;
	setPos(10,13);
	setColor(13,0);
	printf("墙壁：");
	setColor(10,0);
	printf("█");	
	setPos(20,13);
	setColor(13,0);
	printf("目的地点：");
	setColor(12,0);
	printf("●");
	setPos(10,14);
	setColor(13,0);
	printf("箱子：");
	setColor(11,0);
	printf("█");
	setPos(20,14);
	setColor(13,0);
	printf("玩家：");
	setColor(15,0);
	printf("●");
}
int win(void)
{
	int i,j,count=0,t=0;
	for(i=0;Map[level].Box[i].x!=0;i++)
	{
		for (j=0;Map[level].Despoint[j].x!=0;j++)
		{
			if(Map[level].Box[i].x==Map[level].Despoint[j].x && Map[level].Box[i].y==Map[level].Despoint[j].y)
			count++;
		}
	}
	if (count==j) t=1;
	return t;
}
void Level(int l)
{
	void level1(void);
	void level2(void);
	void level3(void);
	void level4(void);
	void level5(void);
	void level6(void);
	void level7(void);
	void level8(void);
	void level9(void);
	void level10(void);
	switch(l)
	{
		case 0:level1();break;
		case 1:level2();break;
		case 2:level3();break;
		case 3:level4();break;
		case 4:level5();break;
		case 5:level6();break;
		case 6:level7();break;
		case 7:level8();break;
		case 8:level9();break;
		case 9:level10();break;
		default :break;
	}
	
}
void level1(void)
{
	int k;
	for(k=0;Box1[k].x!=0;k++)
	{
		Map[level].Box[k]=Box1[k];
	}
	for(k=0;Despoint1[k].x!=0;k++)
	{
		Map[level].Despoint[k]=Despoint1[k];
	}
	for(k=0;Wall1[k].x!=0;k++)
	{
		Map[level].Wall[k]=Wall1[k];
	}
    Map[level].X=X1;
    Map[level].Y=Y1;
}
void level2(void)
{
	int k;
	for(k=0;Box2[k].x!=0;k++)
	{
		Map[level].Box[k]=Box2[k];
	}
	for(k=0;Despoint2[k].x!=0;k++)
	{
		Map[level].Despoint[k]=Despoint2[k];
	}
	for(k=0;Wall2[k].x!=0;k++)
	{
		Map[level].Wall[k]=Wall2[k];
	}
    Map[level].X=X2;
    Map[level].Y=Y2;
}
void level3(void)
{
	int k;
	for(k=0;Box3[k].x!=0;k++)
	{
		Map[level].Box[k]=Box3[k];
	}
	for(k=0;Despoint3[k].x!=0;k++)
	{
		Map[level].Despoint[k]=Despoint3[k];
	}
	for(k=0;Wall3[k].x!=0;k++)
	{
		Map[level].Wall[k]=Wall3[k];
	}
    Map[level].X=X3;
    Map[level].Y=Y3;
}
void level4(void)
{
	int k;
	for(k=0;Box4[k].x!=0;k++)
	{
		Map[level].Box[k]=Box4[k];
	}
	for(k=0;Despoint4[k].x!=0;k++)
	{
		Map[level].Despoint[k]=Despoint4[k];
	}
	for(k=0;Wall4[k].x!=0;k++)
	{
		Map[level].Wall[k]=Wall4[k];
	}
    Map[level].X=X4;
    Map[level].Y=Y4;
}
void level5(void)
{
	int k;
	for(k=0;Box5[k].x!=0;k++)
	{
		Map[level].Box[k]=Box5[k];
	}
	for(k=0;Despoint5[k].x!=0;k++)
	{
		Map[level].Despoint[k]=Despoint5[k];
	}
	for(k=0;Wall5[k].x!=0;k++)
	{
		Map[level].Wall[k]=Wall5[k];
	}
    Map[level].X=X5;
    Map[level].Y=Y5;
}
void level6(void)
{
	int k;
	for(k=0;Box6[k].x!=0;k++)
	{
		Map[level].Box[k]=Box6[k];
	}
	for(k=0;Despoint6[k].x!=0;k++)
	{
		Map[level].Despoint[k]=Despoint6[k];
	}
	for(k=0;Wall6[k].x!=0;k++)
	{
		Map[level].Wall[k]=Wall6[k];
	}
    Map[level].X=X6;
    Map[level].Y=Y6;
}
void level7(void)
{
	int k;
	for(k=0;Box7[k].x!=0;k++)
	{
		Map[level].Box[k]=Box7[k];
	}
	for(k=0;Despoint7[k].x!=0;k++)
	{
		Map[level].Despoint[k]=Despoint7[k];
	}
	for(k=0;Wall7[k].x!=0;k++)
	{
		Map[level].Wall[k]=Wall7[k];
	}
    Map[level].X=X7;
    Map[level].Y=Y7;
}
void level8(void)
{
	int k;
	for(k=0;Box8[k].x!=0;k++)
	{
		Map[level].Box[k]=Box8[k];
	}
	for(k=0;Despoint8[k].x!=0;k++)
	{
		Map[level].Despoint[k]=Despoint8[k];
	}
	for(k=0;Wall8[k].x!=0;k++)
	{
		Map[level].Wall[k]=Wall8[k];
	}
    Map[level].X=X8;
    Map[level].Y=Y8;
}
void level9(void)
{
	int k;
	for(k=0;Box9[k].x!=0;k++)
	{
		Map[level].Box[k]=Box9[k];
	}
	for(k=0;Despoint9[k].x!=0;k++)
	{
		Map[level].Despoint[k]=Despoint9[k];
	}
	for(k=0;Wall9[k].x!=0;k++)
	{
		Map[level].Wall[k]=Wall9[k];
	}
    Map[level].X=X9;
    Map[level].Y=Y9;
}
void level10(void)
{
	int k;
	for(k=0;Box10[k].x!=0;k++)
	{
		Map[level].Box[k]=Box10[k];
	}
	for(k=0;Despoint10[k].x!=0;k++)
	{
		Map[level].Despoint[k]=Despoint10[k];
	}
	for(k=0;Wall10[k].x!=0;k++)
	{
		Map[level].Wall[k]=Wall10[k];
	}
    Map[level].X=X10;
    Map[level].Y=Y10;
}
