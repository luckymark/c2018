#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#define MAXN 200
#define LENGTH_OF_CONSOLE 102
#define WIDE_OF_CONSOLE 31
#define UP '8'
#define DOWN '5'
#define LEFT '4'
#define RIGHT '6'
#define RESET 13


int maze[MAXN][MAXN]={0};
int nowx,nowy,temp,end=0;
int dealx[]={0,0,1,-1},dealy[]={1,-1,0,0};
void hide();
void init();
int check(int x,int y);
void make_a_maze(int x,int y);
void redraw_the_map();
void settle();

int main()
{
    hide();
    init();
    char c;
    int s;
    while (c=getch())
    {
        s=4;
        switch (c)
        {
            case RESET:
                {
                    system("cls");
                    init();
                    continue;
                }
            case UP:s=3;break;
            case DOWN:s=2;break;
            case LEFT:s=1;break;
            case RIGHT:s=0;break;
        }
        if (s<4)
        {
            int tempx=nowx+dealx[s],tempy=nowy+dealy[s];
            if (check(tempx,tempy) && maze[tempx][tempy]!=1)
            {
                if (maze[tempx][tempy]==2)
                {
                    settle();
                    continue;
                }
                maze[tempx][tempy]=3;
                maze[tempx-dealx[s]][tempy-dealy[s]]=0;
                nowx=tempx;
                nowy=tempy;
                system("cls");
                redraw_the_map();
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
    system("mode con cols=102 lines=31");
    end=0;
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
    make_a_maze(nowx,nowy);
    maze[1][1]=2;
    maze[WIDE_OF_CONSOLE][LENGTH_OF_CONSOLE/2]=3;
    redraw_the_map();


}

void make_a_maze(int x,int y)
{
    int order[4]={4,4,4,4},num=0,flag=0;
    int i;
    while (num<4)
    {
        int temp=rand()%4;
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
            maze[tempx-dealx[s]][tempy-dealy[s]]=maze[tempx][tempy]=10;
            make_a_maze(tempx,tempy);
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
            }
            if (j==LENGTH_OF_CONSOLE/2 && i<WIDE_OF_CONSOLE) printf("\n");
        }


}

int check(int x,int y)
{
    if (x>0 && y>0 && y<=LENGTH_OF_CONSOLE/2 && x<=WIDE_OF_CONSOLE) return 1;
    return 0;
}

void settle()
{
    end=1;
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


