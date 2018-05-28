#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <conio.h>
#endif

void logo(void);
void map(void);
void game(void);

#ifndef _WIN32
int getch(void)
{
    char ch;
    ch=getchar();
    clrbuf(); 
    return ch;
} 
#endif

int a[50][50]={{0,0,1,1,1,1,1,1,0,0}, 
               {0,0,1,0,0,0,0,1,1,1},
               {0,0,1,0,4,0,0,0,0,1},
               {1,1,1,0,4,0,1,1,0,1},
               {1,5,5,5,0,4,0,0,0,1},
               {1,5,5,5,4,1,4,0,0,1},
               {1,1,1,1,0,1,0,4,0,1},
               {0,0,0,1,0,0,3,0,0,1},
               {0,0,0,1,1,1,1,1,1,1}};
int i,m=9,n=10;
int x,y,box=0,box_done=0,score=500;

void logo(void)
{
    printf("***************************\n");
    printf("*********Pushboxes*********\n");
    printf("***************************\n");
    printf("\n");
    printf("Press 's' to start\n");
    printf("Press 'q' to quit\n");
}

void map(void)
{
    /*{"　　＃＃＃＃＃＃　　",
       "　　＃　　　　＃＃＃",
       "　　＃　█　　　　＃",
       "＃＃＃　█　＃＃　＃",
       "＃ＯＯＯ　█　　　＃",
       "＃ＯＯＯ█＃█　　＃",
       "＃＃＃＃　＃　█　＃",
       "　　　＃　　♀　　＃",
       "　　　＃＃＃＃＃＃＃"}; */ 
    system("cls");
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            switch (a[i][j])
            {
                case 0:
                    printf("  ");//空地
                    break;
                case 1:
                    printf("＃");//墙
                    break;
                case 3:
                    printf("♀");//人
                    break;
                case 4:
                    printf("█");//箱子
                    break;
                case 5:
                    printf("Ｏ");//目的地
                    break;
                case 8:
                    printf("♀");//人和目的地
                    break;
                case 9:
                    printf("▓");//箱子和目的地
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

void game(void)
{
    printf("score:%d",score);
    score--;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==3||a[i][j]==8)
            {
                x=i;
                y=j;
            }
        }
    }
    while(box==0)
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(a[i][j]==4||a[i][j]==9)
                    box++;
    char ch;
    while(box_done!=box)
    {
        ch=getch();
        if(ch=='w')
        {
            if(a[x-1][y]==0||a[x-1][y]==5)
            {
                a[x][y]-=3;
                a[x-1][y]+=3;
            }
            else if(a[x-1][y]==4||a[x-1][y]==9)
            {
                if(a[x-2][y]==0||a[x-2][y]==5)
                {
                    if(a[x-2][y]==0&&a[x-1][y]==9)
                    {
                        box_done--;
                    }
                    else if(a[x-2][y]==5&&a[x-1][y]==4)
                    {
                        box_done++;
                    }
                    else;
                    a[x-2][y]+=4;
                    a[x-1][y]-=1;
                    a[x][y]-=3;
                }
            }
            else;
            return;
        }
        if(ch=='s')
        {
            if(a[x+1][y]==0||a[x+1][y]==5)
            {
                a[x][y]-=3;
                a[x+1][y]+=3;
            }
            else if(a[x+1][y]==4||a[x+1][y]==9)
            {
                if(a[x+2][y]==0||a[x+2][y]==5)
                {
                    if(a[x+2][y]==0&&a[x+1][y]==9)
                    {
                        box_done--;
                    }
                    else if(a[x+2][y]==5&&a[x+1][y]==4)
                    {
                        box_done++;
                    }
                    else;
                    a[x+2][y]+=4;
                    a[x+1][y]-=1;
                    a[x][y]-=3;
                }
               }
            else;
            return;
        }
        if(ch=='a')
        {
            if(a[x][y-1]==0||a[x][y-1]==5)
            {
                a[x][y]-=3;
                a[x][y-1]+=3;
            }
            else if(a[x][y-1]==4||a[x][y-1]==9)
            {
                if(a[x][y-2]==0||a[x][y-2]==5)
                {
                    if(a[x][y-2]==0&&a[x][y-1]==9)
                    {
                        box_done--;
                    }
                    else if(a[x][y-2]==5&&a[x][y-1]==4)
                    {
                        box_done++;
                    }
                    else;
                    a[x][y-2]+=4;
                    a[x][y-1]-=1;
                    a[x][y]-=3;
                }
            }
            else;
            return;
        }
        if(ch=='d')
        {
            if(a[x][y+1]==0||a[x][y+1]==5)
            {
                a[x][y]-=3;
                a[x][y+1]+=3;
            }
            else if(a[x][y+1]==4||a[x][y+1]==9)
            {
                if(a[x][y+2]==0||a[x][y+2]==5)
                {
                    if(a[x][y+2]==0&&a[x][y+1]==9)
                    {
                        box_done--;
                    }
                    else if(a[x][y+2]==5&&a[x][y+1]==4)
                    {
                        box_done++;
                    }
                    else;
                    a[x][y+2]+=4;
                    a[x][y+1]-=1;
                    a[x][y]-=3;
                }
            }
            else;
            return;
        }
    }
    system("cls");
    printf("You win!!!\n");
    getchar();
    exit(0);
}

int main(void)
{
    #ifdef _WIN32
    system("color f9");
    #endif
    logo();
    char ch=getch();
    if(ch=='s')
        while(1)
        {
            map();
            game();
        } 
    else if(ch=='q')
        exit(0);
    else;
    getchar();
    return 0;
}
