#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#include "cls.h"

typedef struct
{
    int x,y
}point;

int size,map[40][160]={0};
char replay='Y';

int clears()
{
    int ch;
    while ((ch=getchar())!=EOF && ch!='\n');
    return 0;
}

void color(short x) //自定义函根据参数改变颜色
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);    //只有一个参数，改变字体颜色
}

int modes()
{
    int mode;
    printf("Select mode:\nvery easy --- 1\neasy -------- 2\nnormal ------ 3\nhard -------- 4\nvery hard --- 5\n");
    while(1)
    {
        scanf("%d",&mode);
        if(mode>=1 && mode<=5) break;
        else printf("Please select the mode you want to play\n");
        clears();
    }
    return mode*8;
}

point is_direction(int x)
{
    point temp;
    if (4==x)
    {
        temp.x=-1;temp.y=0;
    }
    else if (2==x)
    {
        temp.x=0;temp.y=1;
    }
    else if (1==x)
    {
        temp.x=1;temp.y=0;
    }
    else if (3==x)
    {
        temp.x=0;temp.y=-1;
    }
    return temp;
}

int is_dig(int x,int y,int dx,int dy)
{
    if (x>0 && x<size-1 && y>0 && y<4*size-1 && x+dx>=0 && x+dx<=size-1 && y+dy>=0 && y+dy<=4*size-1)
    {
        if (0==dx && 0==map[x][y])
        {
            for (int i=-1;i<=1;i++) if (1==map[x+i][y+dy]) return 0;
            return 1;
        }
        if (0==dy && 0==map[x][y])
        {
            for (int i=-1;i<=1;i++) if (1==map[x+dx][y+i]) return 0;
            return 1;
        }
    }
    return 0;
}

int is_did(int* p,int n)
{
    for (int i=0;i<4;i++) if (n==*(p+i)) return 1;
    return 0;
}

int dfs(int x,int y)
{
    map[x][y]=1;
    //print_map();
    int did[4]={0},temp,count=0;
    while (4!=count)
    {
        temp=rand()%4+1;
        if (is_did(did,temp)) continue;
        point direction=is_direction(temp);
        if (is_dig(x+direction.x,y+direction.y,direction.x,direction.y)) dfs(x+direction.x,y+direction.y);
        did[count]=temp;
        count++;
    }
    return 0;
}

int map_end()
{
    int x=size;
    int y=4*size-2;
    while(0==map[x-1][y])
    {
        map[x-1][y]=1;
        x=x-1;
    }
    map[size-1][4*size-2]=2;
    return 0;
}

int print_map()
{
    cls();
    //system("cls");
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<4*size;j++)
        {
            if (0==map[i][j]) printf("#");
            else if (1==map[i][j]) printf(" ");
            else if (2==map[i][j])
            {
                color(12);
                printf("A");
                color(7);
            }
        }
        printf("\n");
    }
    return 0;
}

int playermove()
{
    int x=size-1;
    int y=4*size-2;
    int ch;
    while((1!=x || 0!=y) && (ch=getch())!=0x1B)
    {
        switch(ch)
        {
            case 0xE0:
            switch(ch=getch())
            {
                case 72:  {if (1==map[x-1][y] && x-1>=0 && x-1<size) {map[x][y]=1;x--;} break;}
                case 80:  {if (1==map[x+1][y] && x+1>=0 && x+1<size) {map[x][y]=1;x++;} break;}
                case 75:  {if (1==map[x][y-1] && y-1>=0 && y-1<4*size) {map[x][y]=1;y--;} break;}
                case 77:  {if (1==map[x][y+1] && y+1>=0 && y+1<4*size) {map[x][y]=1;y++;} break;}
                default:break;
            }
            break;
            default:break;
        }
        map[x][y]=2;
        print_map();
    }
    if (0x1B==ch)
    {
        cls();
        printf("Thanks for your play\n");
        system("pause");
    }
    else
    {
        printf("You are win!!!\nThanks for your play\n");
        system("pause");
    }
    return 0;
}

char is_replay()
{
    cls();
    printf("Do you want to play again?\n\nY/y:YES\tN/n:NO\n");
    while(0==scanf("%['Y','y','N','n']",&replay))
    {
        printf("Please select the mode you want to do\n");
        clears();
    }
    if ('Y'==replay || 'y'==replay)
    {
        memset(map,0,sizeof(map));
    }
    else
    {
        system("cls");
        printf("Thanks for your play\n");
        system("pause");
    }
    return replay;
}

int main()
{
    srand((unsigned)time(0));
    system("mode con cols=160 lines=41");
    while('Y'==replay || 'y'==replay)
    {
        cls();
        replay='m';
        //system("color f0");
        size=modes();
        dfs(1,0);
        map_end();
        print_map();
        playermove();
        is_replay();
    }
    return 0;
}
