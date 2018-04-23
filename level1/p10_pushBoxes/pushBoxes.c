#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#define MAXN 100
#define N 10000
#define LENGTH_OF_CONSOLE 100
#define WIDE_OF_CONSOLE 30
#define UP 72 //上
#define DOWN 80  //下
#define LEFT 75  //左
#define RIGHT 77  //右
#define RESET 13 //重置

void hide();
void login();
void read_the_map(int level);
void redraw_the_map();
void init();
void settle();

int size[]={8,9,10,8,10,8};
int reminder[]={1,1,1,1,1,1,1};
int intial_map[MAXN][MAXN],now_map[MAXN][MAXN];
int dealx[]={0,1,-1,0},dealy[]={1,0,0,-1}; //存放操作动作的数组
int end=0,now_step=0,tot_step=0,nowx,nowy,left_box,tot_box,victory;
int level=1;


int main()
{
    login();
    hide();
    init(); //初始化
    char c;
    int push;
    while (c=getch())
    {
        int s=4;
        switch (c)
        {
            case RESET:
            {
                tot_step=tot_step-now_step;
                init();
                break;
            }
            case UP:s=2;break;
            case DOWN:s=1;break;
            case LEFT:s=3;break;
            case RIGHT:s=0;break;
            default:continue;
        }
        if (s<4)
        {
            int tempx=nowx+dealx[s],tempy=nowy+dealy[s];
            if (now_map[tempx][tempy]!='1' && !end)
            {
                if (now_map[tempx][tempy]=='4')
                {
                    if (intial_map[tempx+dealx[s]][tempy+dealy[s]]=='1' || now_map[tempx+dealx[s]][tempy+dealy[s]]=='4')
                    {
                        continue;
                    }
                    if (now_map[tempx+dealx[s]][tempy+dealy[s]]=='2' && intial_map[tempx][tempy]!='2')
                    {
                        left_box--;
                    }
                    now_map[tempx+dealx[s]][tempy+dealy[s]]='4';
                }
                now_map[nowx][nowy]=intial_map[nowx][nowy]=='2'?'2':'0';
                now_map[tempx][tempy]='3';
                nowx=tempx;
                nowy=tempy;
                tot_step++;  //记录总步数
                now_step++;  //记录当前关卡步数
                redraw_the_map();
                if (! left_box )
                {
                    level++;
                    victory=1;
                    init();
                    continue;
                }
            }
        }
    }
    return 0;
}

void login()
{
    system("mode con cols=102 lines=31");

    char welcome[]="Welcome to the game! please login your name:";
    char name[MAXN];
    int i;
    for (i=0;i<=(WIDE_OF_CONSOLE-size[level-1])/2;i++) printf("\n");
    for (i=1;i<=(LENGTH_OF_CONSOLE-strlen(welcome))/2-7;i++) printf(" ");
    printf("%s",welcome);
    gets(name);

    time_t now;
    struct tm *tm_now;
    time(&now);
    tm_now=localtime(&now);

    FILE *fp1;
    fp1=fopen("userlog.txt","a");
    fprintf(fp1,"\n\n%d-%d-%d %d:%d:%d\n",tm_now->tm_year+1900, tm_now->tm_mon+1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec) ;
    fprintf(fp1,"Player:%s\n",name);
    fclose(fp1);  //将玩家每次的游戏记录储存在文本"userlog.txt"中 包括游戏的时间 玩家用户名以及每关分数
}

void init()
{
    FILE *fp1;
    fp1=fopen("userlog.txt","a");
    if (!reminder[level-1] && victory)
    {
        fprintf(fp1,"%d\n",now_step);
    }
    if (reminder[level])
    {
        fprintf(fp1,"level %d:",level);
        reminder[level]=0;
    }
    fclose(fp1);  //数据存入文件

    victory=0;
    now_step=0;
    read_the_map(level);
    if (! end) redraw_the_map();
}

void hide()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = 0;
    SetConsoleCursorInfo(handle, &CursorInfo);
}

void read_the_map(int level)  //读入地图
{
    int i,j;
    FILE *fp1,*fp2;
    switch (level)
    {
        case 1:fp1 = fopen("map1.txt","r");break;
        case 2:fp1 = fopen("map2.txt","r");break;
        case 3:fp1 = fopen("map3.txt","r");break;
        case 4:fp1 = fopen("map4.txt","r");break;
        case 5:fp1 = fopen("map5.txt","r");break;
        case 6:fp1 = fopen("map6.txt","r");break; 
        default:
            {
                end=1;
                settle(); //通关
                return;
            }
    }
    char temp;
    left_box=0;
    for (i=1;i<=size[level-1];i++)
    {
        for (j=1;j<=size[level-1]+1;j++)
        {
            fscanf(fp1,"%c",&temp);
            if (temp>='0' && temp<='4')
            {
                if (temp=='3')
                {
                    nowx=i;
                    nowy=j;
                }
                if (temp>='4') left_box++;
                intial_map[i][j]=now_map[i][j]=temp;
            }
        }
    }
    tot_box=left_box;
    fclose(fp1);
}

void redraw_the_map()  //绘制地图 包括当前关卡和步数
{
    system("cls");
    char nowlevel[]="Level:";
    char yourstep_now[]="The steps you cost in this level:";
    char yourstep_tot[]="The steps you cost in total:";

    int i,j;
    char temp;
    printf("%s %d\n",nowlevel,level);
    printf("%s %d\n",yourstep_now,now_step);
    printf("%s %d\n",yourstep_tot,tot_step);

    for (i=1;i<=(WIDE_OF_CONSOLE-size[level-1])/2-3;i++) printf("\n");
    for (i=1;i<=size[level-1];i++)
    {
        for (j=1;j<(LENGTH_OF_CONSOLE-size[level-1])/2-1;j++) printf(" ");
        for (j=1;j<=size[level-1]+1;j++)
        {
            switch (now_map[i][j])
            {
                case '\n':continue;
                case '0':printf("  ");break; //空地
                case '1':printf("##");break; //墙
                case '2':printf("@@");break; //地点
                case '3':printf("!!");break; //人物
                case '4':printf("$$");break; //箱子
                default:continue;
            }
        }
        printf("\n");
    }
}

void settle()  //通关后显示赢得游戏胜利
{
    system("cls");
    char quit[]="If you want to quit the game, please press any one of 'F1'~'F9' or click 'X'";
    char win[]="Congratulations! You just won all the games !";

    int i;
    for (i=0;i<=(WIDE_OF_CONSOLE-size[level-1])/2;i++)
        printf("\n");
    for (i=1;i<=(LENGTH_OF_CONSOLE-strlen(win))/2-1;i++)
        printf(" ");
    printf("%s\n\n\n\n",win);
    for (i=1;i<=(LENGTH_OF_CONSOLE-strlen(quit))/2-1;i++)
        printf(" ");
    printf("%s",quit);
    for (i=1;i<=(WIDE_OF_CONSOLE-size[level-1])/2-3;i++)
        printf("\n");
}


