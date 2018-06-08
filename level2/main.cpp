#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#define len 15

int map[len][len];
int worb = 2;
int count = 0;
int m;

int nowx,nowy;
int ansx,ansy;
int posx,posy;

void start_game();
void move_cursor(char key);
void vs_ai();
void vs_player();
void initial();
void make_map();
int jugde_chess(int x,int y);
int judgewinner(int x,int y,int worb);
int ai_step();
int givescore(int x,int y,int worb);
int maxmin(int worb, int count, int alpha, int beta);

struct _cursor
{
	int x;
	int y;
}cursor={7,9};


void gotoxy(int x, int y) //建立坐标函数
{
COORD c;
c.X = x;
c.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void start_game()
{
printf("\n\n\n\n\n");
printf("             ********************* 【五子棋】 *******************\n\n\n");
printf("             *********************【游戏说明】 ******************\n");
printf("                                                               \n");
printf("                   【1】: 黑子由机器使用                       \n");
printf("                -------------------------------------------------\n");
printf("                   【2】: 白子由人使用                         \n");
printf("                                                               \n");
printf("             ****************************************************\n");
printf("\n\n      【人机博弈按：1】 【双人博弈按：2】 【退出按：Esc】");
}

void make_map()
{
	printf("\n\n");
	int i, j, k;
	for(j=0;j<len;j++)
	{
		for(i=0;i<len;i++)
		{
			if (map[j][i] == 1)
			printf("●   ");
			else if (map[j][i] == 2)
			printf("○   ");
			else if (j == 0 && i == 0)
			printf("┏   ");
			else if (j == 0 && i == len - 1)
			printf("┓   ");
			else if (j == len - 1 && i == 0)
			printf("┗   ");
			else if (j == len - 1 && i == len - 1)
			printf("┛   ");
			else if (j == 0 && i != 0 && i != len - 1)
			printf("┯   ");
			else if (j != 0 && j != len - 1 && i == 0)
			printf("┠   ");
			else if (j != 0 && j != len - 1 && i == len - 1)
			printf("┨   ");
			else if (j == len - 1 && i != 0 && i != len - 1)
			printf("┷   ");
			else if (j != 0 && j != len - 1 && i != 0 && i != len - 1)
			printf("┼   ");
		}
	printf("\n\n");
	}
	printf("\n");
	printf(" 【 重玩按：n 】 【返回按：Backspace】 【退出按：Esc】\n 【 空格下子  】 【上,下,左,右移动光标】");
}

void move_cursor(char key)
{
	switch (key)
	{


		case 0x48:
			if (cursor.y>=1)
			cursor.y--;
			if (cursor.y<1)
			cursor.y = len;
			break;
		/*光标向上移动*/


		case 0x50:
			if (cursor.y<=len )
			cursor.y++;
			if (cursor.y>len)
			cursor.y = 1;
			break;
		/*光标向下移动*/


		case 0x4B:
			if (cursor.x>-1)
			cursor.x--; 
			if (cursor.x<0)
			cursor.x = len - 1; 
			break;
		/*光标向左移动*/


		case 0x4D:
			if (cursor.x<len)
			cursor.x++; 
			if (cursor.x>len - 1)
			cursor.x = 0; 
			break;
		/*光标向右移动*/
	}
	gotoxy(4 *cursor.x, 2 * cursor.y);
}

void initial()
{
	int i, j;
	for (i = 0; i<len; i++)    //重置对局数据
	{
		for (j = 0; j<len; j++)
		{
			map[i][j] = 0;
		}
	}	
	worb = 2;	
	count = 0;
	system("cls");
	make_map();
	cursor.x = 0;
	cursor.y = 0;
	gotoxy(cursor.x, cursor.y);
}

int judge_chess(int x, int y)
{
	if (map[x][y] != 0)
	return 1;
	return 0;
}

int judgewinner(int x,int y,int worb)
{
	int row, col, count;
	row = x;
	col = y;
	count = 0;
	while (map[row][col] == worb && col < len)
	{
		count++;
		col++;
	}
	col = y - 1;
	while (map[row][col] == worb && col >= 0)
	{
		count++;
		col--;
	}
	if (count >= 5)
	return 1;


	row = x;
	col = y;
	count = 0;
	while (map[row][col] == worb && row < len)
	{
		count++;
		row++;
	}
	row = x - 1;
	while (map[row][col] == worb && row >= 0)
	{
		count++;
		row--;
	}
	if (count >= 5)
	return 1;


	row = x;
	col = y;
	count = 0;
	while (map[row][col] == worb && col < len && row < len)
	{
		count++;
		col++;
		row++;
	}
	col = y - 1, row = x - 1;
	while (map[row][col] == worb && col >= 0 && row >= 0)
	{
		count++;
		col--;
		row--;
	}
	if (count >= 5)
	return 1;


	row = x;
	col = y;
	count = 0;
	while (map[row][col] == worb && col < len && row >= 0)
	{
		count++;
		col++;
		row--;
	}
	col = y - 1, row = x + 1;
	while (map[row][col] == worb && col >= 0 && row < len)
	{
		count++;
		col--;
		row++;
	}
	if (count >= 5)
	return 1;

	return 0;
}






int ai_step()
{
	int i, j, cscore, cscorel, pscore, pscorel, row1, col1, row2, col2, x, y;
	cscore = pscore = 0; row1 = row2 = col1 = col2 = 0;
	if (count == 1)
	{
		srand((unsigned)time(NULL));
		row1 = rand() % 3+posx-1;
		col1 = rand() % 3+posy-1;
		count++;
		while (judge_chess(row1, col1)||row1<0||row1>=len||col1<0||col1>=len)
		{	
		row1 = rand() % 3+posx-1;
		col1 = rand() % 3+posy-1;
		}
		map[row1][col1] = 1;
		worb = 3 - worb;
		x = abs(cursor.x - col1);
		y = abs(cursor.y - 2 - row1);
		if (cursor.x - col1>0)
		{
			for (i = 0; i < x; i++)
			move_cursor(0x4B);
		}
		else 
		{
			for (i = 0; i < x; i++)
			move_cursor(0x4D);
		}

		if (cursor.y - 2 - row1>0)
		{
			for (i = 0; i < y; i++)
			move_cursor(0x48);
		}
		else 
		{
			for (i = 0; i < y; i++)
			move_cursor(0x50);
		}
		printf("●");
	}

	else
	{
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < len; j++)
			{
				if (!judge_chess(i, j))
				{
					cscorel = givescore(i, j, 1);
					if (cscorel > cscore)
					{
						cscore = cscorel;
						row1 = i;
						col1 = j;
					}
					pscorel = givescore(i, j, 2);
					if (pscorel > pscore)
					{
						pscore = pscorel;
						row2 = i;
						col2 = j;
					}
				}
			}
		}
		
	if(count == 3)
	{
		map[row1][col1] = 1;
		worb = 3 - worb;
		count++;
		x = abs(cursor.x - col1);
		y = abs(cursor.y - 2 - row1);
		if (cursor.x - col1>0)
		{	
			for (i = 0; i < x; i++)
			move_cursor(0x4B);
		}
		else 
		{
			for (i = 0; i < x; i++)
			move_cursor(0x4D);
		}
		if (cursor.y - 2 - row1>0)
		{
			for (i = 0; i < y; i++)
			move_cursor(0x48);
		}
		else 
		{
			for (i = 0; i < y; i++)
			move_cursor(0x50);
		}
		printf("●");
	}
	else
	{
	 if(cscore>=pscore)
	{
		if(cscore<790000)
		{
			maxmin(1,0,INT_MIN,INT_MAX);
			row1=ansx;
			col1=ansy;
		}
		else
		{	
			row1=row1;
			col1=col1;
		}
	}
	else
	{
		if(pscore>=790000)
		{
			row1=row2;
			col1=col2;
		}
		else
		{
			maxmin(1,0,INT_MIN,INT_MAX);
			row1=ansx;
			col1=ansy;
		}
	}
	map[row1][col1] = 1;
			worb = 3 - worb;
			count++;
			x = abs(cursor.x - col1);
			y = abs(cursor.y - 2 - row1);
			if (cursor.x - col1>0)
			for (i = 0; i < x; i++)
			move_cursor(0x4B);
			else for (i = 0; i < x; i++)
			move_cursor(0x4D);
			if (cursor.y - 2 - row1>0)
			for (i = 0; i < y; i++)
			move_cursor(0x48);
			else for (i = 0; i < y; i++)
			move_cursor(0x50);
			printf("●");
			if (judgewinner(row1, col1, 1))
			{
				gotoxy(22, 17);
				printf("【 黑子胜利 】");
				return 1;
			}
	}
	/*
	else
	{
		if (cscore >= pscore)
		{
			map[row1][col1] = 1;
			worb = 3 - worb;
			count++;
			x = abs(cursor.x - col1);
			y = abs(cursor.y - 2 - row1);
			if (cursor.x - col1>0)
			for (i = 0; i < x; i++)
			move_cursor(0x4B);
			else for (i = 0; i < x; i++)
			move_cursor(0x4D);
			if (cursor.y - 2 - row1>0)
			for (i = 0; i < y; i++)
			move_cursor(0x48);
			else for (i = 0; i < y; i++)
			move_cursor(0x50);
			printf("●");
			if (judgewinner(row1, col1, 1))
			{
				gotoxy(22, 17);
				printf("【 黑子胜利 】");
				return 1;
			}
		}	
		else
		{
			map[row2][col2] = 1;
			worb = 3 - worb;
			count++;
			x = abs(cursor.x - col2);
			y = abs(cursor.y - 2 - row2);
			if (cursor.x - col2>0)
			for (i = 0; i < x; i++)
			move_cursor(0x4B);
			else for (i = 0; i < x; i++)
			move_cursor(0x4D);
			if (cursor.y - 2 - row2>0)
			for (i = 0; i < y; i++)
			move_cursor(0x48);
			else for (i = 0; i < y; i++)
			move_cursor(0x50);
			printf("●");
			if (judgewinner(row2, col2, 1))
			{
				gotoxy(22, 17);
				printf("【 黑子胜利 】");
				return 1;
			}
		}
	}*/
	}
return 0;
}









int givescore(int x, int y, int worb)   //棋盘权值函数
{
int count3, count4, sumscore = 0;
char u, d, l, r, lu, ld, ru, rd;    //u上 d下 l左 r右 lu左斜上 ld左斜下 ru右斜上 rd右斜下
int row, col, count1, count2;   //1表示横向 2表示竖向 3表示斜上方向 4表示斜下方向


count1 = count2 = count3 = count4 = 1;
l = r = u = d = lu = ld = ru = rd = 0;


map[x][y] = worb;      //模拟下棋




/*---------------------------------------①判断横向棋子并记录空格子---------------------------*/
row = x, col = y + 1;
while (map[row][col] == worb && col < len)
{
count1++;
col++;
}
while (col < len && map[row][col] == 0)
{
r++;
col++;
}
row = x, col = y - 1;
while (map[row][col] == worb && col >= 0)
{
count1++;
col--;
}
while (col >= 0 && map[row][col] == 0)
{
l++;
col--;
}
/*------------------------------------------------------------------------------------------*/




/*-------------------------------------②判断竖向棋子并记录空格子---------------------------*/
row = x + 1, col = y;
while (map[row][col] == worb && row < len)
{
count2++;
row++;
}
while (row < len && map[row][col] == 0)
{
d++;
row++;
}
row = x - 1, col = y;
while (map[row][col] == worb && row >= 0)
{
count2++;
row--;
}
while (row >= 0 && map[row][col] == 0)
{
u++;
row--;
}
/*------------------------------------------------------------------------------------------*/


/*------------------------------------③判断斜上向棋子并记录空格子--------------------------*/
row = x - 1, col = y + 1;
while (map[row][col] == worb && col < len && row >= 0)
{
count3++;
col++;
row--;
}
while (col < len && row >= 0 && map[row][col] == 0)
{
ru++;
col++;
row--;
}
row = x + 1, col = y - 1;
while (map[row][col] == worb && col >= 0 && row < len)
{
count3++;
col--;
row++;
}
while (col >= 0 && row < len && map[row][col] == 0)
{
ld++;
col--;
row++;
}
/*------------------------------------------------------------------------------------------*/






/*-----------------------------------④判断斜下向棋子并记录空格子---------------------------*/
row = x + 1, col = y + 1;
while (map[row][col] == worb && col < len && row < len)
{
count4++;
col++;
row++;
}
while (col < len && row < len && map[row][col] == 0)
{
rd++;
col++;
row++;
}
row = x - 1, col = y - 1;
while (map[row][col] == worb && col >= 0 && row >= 0)
{
count4++;
col--;
row--;
}
while (col >= 0 && row >= 0 && map[row][col] == 0)
{
lu++;
col--;
row--;
}
/*------------------------------------------------------------------------------------------*/


map[x][y] = 0;




if (count1 >= 5 || count2 >= 5 || count3 >= 5 || count4 >= 5)    //判断五子
{
return sumscore = 5000000;
}




if ((count1 == 4 && count2 == 4 && l >= 1 && r >= 1 && u >= 1 && d >= 1) ||
(count1 == 4 && count3 == 4 && l >= 1 && r >= 1 && ru >= 1 && ld >= 1) ||
(count1 == 4 && count4 == 4 && l >= 1 && r >= 1 && rd >= 1 && lu >= 1) ||
(count2 == 4 && count3 == 4 && u >= 1 && d >= 1 && ru >= 1 && ld >= 1) ||
(count2 == 4 && count4 == 4 && u >= 1 && d >= 1 && lu >= 1 && rd >= 1) ||
(count3 == 4 && count4 == 4 && ru >= 1 && ld >= 1 && lu >= 1 && rd >= 1))   //判断双活四
{
return sumscore = 4000000;
}






if ((count1 == 4 && l >= 1 && r >= 1) || (count2 == 4 && u >= 1 && d >= 1) ||
(count3 == 4 && ru >= 1 && ld >= 1) || (count4 == 4 && lu >= 1 && rd >= 1))   //判断活四
{
return sumscore = 800000;
}




if ((count1 == 4 && ((l == 0 && r >= 1) || (l >= 1 && r == 0))) || (count2 == 4 && ((u == 0 && d >= 1) || (u >= 1 && d == 0))) ||
(count3 == 4 && ((ld == 0 && ru >= 1) || (ld >= 1 && ru == 0))) || (count4 == 4 && ((lu == 0 && rd >= 1) || (lu >= 1 && rd == 0))))
{
sumscore = sumscore + 35000;  //成四
}


if( ( count1 == 3 && count2 == 3 && l >=1 && r >=1 && u >=1 && d >=1) ||
( count1 == 3 && count3 == 3 && l >=1 && r >=1 && ru >=1 && ld >=1 ) ||
( count1 == 3 && count4 == 3 && l >=1 && r >=1 && rd >=1 && lu >=1 ) ||
( count2 == 3 && count3 == 3 && u >=1 && d >=1 && ru >=1 && ld >=1 ) ||
( count2 == 3 && count4 == 3 && u >=1 && d >=1 && lu >=1 && rd >=1 ) ||
( count3 == 3 && count4 == 3 && ru >=1 && ld >=1 && lu >=1 && rd >=1) )   //判断双活三
{
return sumscore + 400000;
}








if ((count1 == 3 && l >= 1 && r >= 1) || (count2 == 3 && u >= 1 && d >= 1) ||
(count3 == 3 && ru >= 1 && ld >= 1) || (count4 == 3 && lu >= 1 && rd >= 1))
{
sumscore = sumscore + 60000;
return sumscore;
}     //判断活三








if ((count1 == 2 && count2 == 2 && l >= 1 && r >= 1 && u >= 1 && d >= 1) ||
(count1 == 2 && count3 == 2 && l >= 1 && r >= 1 && ru >= 1 && ld >= 1) ||
(count1 == 2 && count4 == 2 && l >= 1 && r >= 1 && rd >= 1 && lu >= 1) ||
(count2 == 2 && count3 == 2 && u >= 1 && d >= 1 && ru >= 1 && ld >= 1) ||
(count2 == 2 && count4 == 2 && u >= 1 && d >= 1 && lu >= 1 && rd >= 1) ||
(count3 == 2 && count4 == 2 && ru >= 1 && ld >= 1 && lu >= 1 && rd >= 1))
{
sumscore = sumscore + 20000;   //判断双活二
}




if ((count1 == 2 && l >= 1 && r >= 1) || (count2 == 2 && u >= 1 && d >= 1) ||
(count3 == 2 && ru >= 1 && ld >= 1) || (count4 == 2 && lu >= 1 && rd >= 1))
{
sumscore = sumscore + 10000;     //单活二
}


return sumscore;


}

void vs_ai()
{
int c = 0,w = 0;
char key;


m = 1;



while (1)
{


initial();
w = 0;






while (1)
{


key = _getch();

if(w == 0)
{
cursor.x = 7;
cursor.y = 9;
gotoxy(cursor.x, cursor.y);
w++;
}


if (key == 27)   //退出游戏
{
exit(0);
}
else if (key == 8)   //返回主界面
{
break;
}
else if (key == 110)  //重新玩
{
break;
}
else if (key == 32)//落子 
{
if (count == len * len)
{
gotoxy(22, 13);
printf("【 平局 】");
count = 0;
break;
}
else if (worb == 2)
{


if (judge_chess(cursor.y - 2, cursor.x) == 0)
{
printf("○");


map[cursor.y - 2][cursor.x] = worb;

posx=cursor.y - 2;
posy=cursor.x;


count++;




if (judgewinner(cursor.y - 2, cursor.x, worb))
{
gotoxy(22, 15);
printf("【 白子胜利 】");

key = _getch();

while(key != 27 && key != 110 && key != 8)
key = _getch();


if(key == 8 || key == 110)
break;
else exit(0);
}


else 
{
worb = 3 - worb;

c = ai_step();


if(c)
{
key = _getch();

while(key != 27 && key != 110 && key != 8)
{
key = _getch();
}


if(key == 8 || key == 110)
break;
else exit(0);
}
}





}


}


}
else  //光标移动
{
key = _getch();
move_cursor(key);
}


}




if (key == 8)
break;


}
}




void vs_player()
{
int w = 0;
char key;
m = 2;


while(1)
{
initial();
w = 0;


while(1)
{
key = _getch();

if(w == 0)
{
cursor.x = 7;
cursor.y = 9;
gotoxy(cursor.x, cursor.y);
w++;
}



if (key == 27)   //退出游戏
{
exit(0);
}
else if (key == 8)   //返回主界面
{
break;
}
else if (key == 110)  //重新玩
{
break;
}
else if(key == 32)//落子 
{
if(worb == 2)
{


if(judge_chess(cursor.y-2,cursor.x) == 0)
{
map[cursor.y-2][cursor.x] = 2;
printf("○");
count++;
if(judgewinner(cursor.y-2,cursor.x,worb))
{
gotoxy(22, 15);
printf("【 白子胜利 】");

key = _getch();

while(key != 27 && key != 110 && key != 8)
key = _getch();


if(key == 8 || key == 110)
break;
else exit(0);




}


worb = 3 - worb;
}


}


else
{
if(judge_chess(cursor.y-2,cursor.x) == 0)
{
map[cursor.y-2][cursor.x] = 1;
printf("●");
count++;
if(judgewinner(cursor.y-2,cursor.x,worb))
{
gotoxy(22, 15);
printf("【 黑子胜利 】");


key = _getch();

while(key != 27 && key != 110 && key != 8)
key = _getch();


if(key == 8 || key == 110)
break;
else exit(0);
}


worb = 3 - worb;
}
}

}
else
{
key = _getch();

move_cursor(key);
}


}


if (key == 8)
break;
}


}


int maxmin(int worb, int count, int alpha, int beta)
{
	int i,j,k,h;
	int f;
	int flag;
	if(count>4)
	return f=givescore(nowx,nowy,1)-givescore(nowx,nowy,2);
	flag=judgewinner(nowx,nowy,worb);
	if(1==flag)
	return f=givescore(nowx,nowy,1)-givescore(nowx,nowy,2);
	posx=nowx;
	posy=nowy;
	if(worb==1)
	{
		for(i=0;i<len;i++)
		{
			for(j=0;j<len;j++)
			{
				int mark=0;
				for(k=-3;k<4;k++)
				{
					for(h=-3;h<4;h++)
					{
						if(i+k>=0&&i+k<len&&j+h>=0&&j+h<len)
						{
							if(map[i+k][j+h]!=0)
							mark++;
						}
						
					}
				}
				if(mark)
				{
				if(map[i][j]==0)
				{
					nowx=i;
					nowy=j;
					int val;
					map[i][j]=worb;
					val=maxmin(3-worb,count+1,alpha,beta);
					map[i][j]=0;
					if(val>alpha)
					{
						alpha=val;
						ansx=i;
						ansy=j;
					}
					if(alpha>=beta)
					return alpha;
				}
				}
			}
		}
		
		return alpha;
	}
	
	else 
	{
		for(i=0;i<len;i++)
		{
			for(j=0;j<len;j++)
			{
				int mark=0;
				for(k=-3;k<4;k++)
				{
					for(h=-3;h<4;h++)
					{
						if(i+k>=0&&i+k<len&&j+h>=0&&j+h<len)
						{
							if(map[i+k][j+h]!=0)
							mark++;
						}
						
					}
				}
				if(mark)
				{
				if(map[i][j]==0)
				{
					nowx=i;
					nowy=j;
					int val;
					map[i][j]=worb;
					val=maxmin(3-worb,count+1,alpha,beta);
					map[i][j]=0;
					if(val<beta)
					{
						beta=val;
					}
					if(alpha>=beta)
					return beta;
				}
				}
			}
		}
		
		return beta;
	}	
}






int main()
{
int choice = 0;


system("title  【五子棋】");
//system("color f2");
//system("mode con cols=83 lines=35");


while (1)
{
start_game();


printf("\n\n\n             【请输入你的选择】:");


while (1)
{
choice = _getch();


if (choice == 27)
{
exit(0);
}


else if (choice == 49)  //人机博弈
{
vs_ai();
break;
}
else if (choice == 50)  //双人博弈
{
vs_player();
break;
}


}


system("cls");


}


return 0;
}
