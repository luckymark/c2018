#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#define MAXN 200
#define LENGTH_OF_CONSOLE 102  //console 宽度
#define WIDE_OF_CONSOLE 31  //console 高度
#define UP 72 //上
#define DOWN 80  //下
#define LEFT 75  //左
#define RIGHT 77  //右
#define RESET 13  //重置


int maze[MAXN][MAXN]={0};
int nowx,nowy,temp,end=0;
int dealx[]={0,0,1,-1},dealy[]={1,-1,0,0};  //人物移动的操作数组
void hide();
void init();
int check(int x,int y);
void make_a_maze(int x,int y);
void redraw_the_map();
void settle();

int main()
{
    hide();  //隐藏光标
    init();  //初始化 随机生成地图
    char c;
    int s;
    while (c=getch())
    {
        s=4;
        switch (c)
        {
            case RESET:  //重置
                {
                    system("cls");
                    init();
                    continue;
                }
            case UP:s=3;break;  //上
            case DOWN:s=2;break;  //下
            case LEFT:s=1;break;  //左
            case RIGHT:s=0;break;  //右
            default:continue; //遇到其他字符 重新读取
        }
        if (s<4)
        {
            int tempx=nowx+dealx[s],tempy=nowy+dealy[s];
            if (check(tempx,tempy) && maze[tempx][tempy]!=1)
            {
                if (maze[tempx][tempy]==2)
                {
                    settle();  //结算
                    continue;
                }
                maze[tempx][tempy]=3;
                maze[tempx-dealx[s]][tempy-dealy[s]]=0;
                nowx=tempx;
                nowy=tempy;
                system("cls");
                redraw_the_map();  //移动人物
            }
        }
        continue;
    }
    return 0;
}


void hide()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = 0;
    SetConsoleCursorInfo(handle, &CursorInfo);
}

void init()
{
    system("mode con cols=102 lines=31");  //设置console窗口大小
    end=0;  //是否胜利的标记
    memset(maze,0,sizeof(maze));
    nowx=WIDE_OF_CONSOLE,nowy=LENGTH_OF_CONSOLE/2;
    int i,j;
    for (i=1;i<=WIDE_OF_CONSOLE;i++)
        for (j=1;j<=LENGTH_OF_CONSOLE/2;j++)
        {
            if (maze[i][j] == 0)
            {
                if (i%2==1 && j%2==1) maze[i][j]=0;else maze[i][j]=1;
            }
        }
    make_a_maze(1,1);  //dfs随机生成地图
    maze[1][1]=2;  //设置出口
    maze[WIDE_OF_CONSOLE][LENGTH_OF_CONSOLE/2]=3;  //设置入口
    redraw_the_map();  //打印地图


}

void make_a_maze(int x,int y)
{
    int order[4]={4,4,4,4},num=0,flag=0;
    int i;
    while (num<4)
    {
        int temp=rand()%4; //随机方向
        flag=0;
        for (i=0;i<=num;i++)
            if (order[i]==temp)
            {
                flag=1;
            }
        if (flag) continue;
        order[num]=temp;
        num++;
    }  
    for (i=0;i<4;i++)
    {
        int s=order[i];
        int tempx=x+dealx[s]*2,tempy=y+dealy[s]*2;
        if (check(tempx,tempy) && (maze[tempx][tempy]==0 || maze[tempx][tempy]==2))
        {
            maze[tempx-dealx[s]][tempy-dealy[s]]=maze[tempx][tempy]=10;  //联通
            make_a_maze(tempx,tempy); //dfs下一步
        }
    }
}

void redraw_the_map()
{
    int i,j;
    for (i=1;i<=WIDE_OF_CONSOLE;i++)
        for (j=1;j<=LENGTH_OF_CONSOLE/2;j++)
        {
            switch (maze[i][j]%10)
            {
                case 0:printf("  ");break;
                case 1:printf("¨~");break;
                case 2:printf("¡î");break;
                case 3:printf("¡ï");break;
                default:continue;
            }
            if (j==LENGTH_OF_CONSOLE/2 && i<WIDE_OF_CONSOLE) printf("\n");
        }


}

int check(int x,int y) //判断位置是否合法
{
    if (x>0 && y>0 && y<=LENGTH_OF_CONSOLE/2 && x<=WIDE_OF_CONSOLE) return 1;  
    return 0;
}

void settle()
{
    end=1;  //标记胜利
    system("cls");
    char win[]="You Win !";
    char restart[]="If you want to start a new game, please press 'Enter' ";
    char quit[]="If you want to quit the game, please press any one of 'F1'~'F9' or click '¡Á'";
    int i;
    printf("\n\n\n\n\n\n\n");
    for (i=1;i<(LENGTH_OF_CONSOLE-strlen(win))/2;i++) printf(" ");
    printf("%s\n\n\n\n\n",win);
    for (i=1;i<(LENGTH_OF_CONSOLE-strlen(restart))/2;i++) printf(" ");
    printf("%s\n\n\n\n\n",restart);
    for (i=1;i<(LENGTH_OF_CONSOLE-strlen(quit))/2;i++) printf(" ");
    printf("%s",quit);
}


