#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <conio.h>
#endif

void logo(void);
void read(int ch);
void map(void);
void game(void);
void write(int ch);

#ifndef _WIN32
int getch(void)
{
    char ch;
    ch=getchar();
    clrbuf(); 
    return ch;
} 
#endif

int x,y,box=0,box_done=0,score=500;
int a[50][50];
int m,n,highest_score[4];

void logo(void)
{
    printf("***************************\n");
    printf("*********Pushboxes*********\n");
    printf("***************************\n");
    printf("\n");
    printf("Press '1' to play leval 1\n");
    printf("Press '2' to play leval 2\n");
    printf("Press '3' to play leval 3\n");
    printf("Press 'q' to quit\n");
}

void read(int ch)
{
    FILE *fp = fopen("map.dat", "rb+");
    if (fp == NULL)  
    {
        printf("error!\n"); 
        getchar(); 
        exit(1);  
    }
    if(ch==1)
    {
        fseek(fp,0,SEEK_SET);
        fread(a, sizeof(a), 1, fp);
        fread(&m, sizeof(m), 1, fp);
        fread(&n, sizeof(n), 1, fp);
        fread(&highest_score[1], sizeof(highest_score[1]), 1, fp);
    }
    else if(ch==2)
    {
        fseek(fp,sizeof(a)+3*sizeof(m),SEEK_SET);
        fread(a, sizeof(a), 1, fp);
        fread(&m, sizeof(m), 1, fp);
        fread(&n, sizeof(n), 1, fp);
        fread(&highest_score[2], sizeof(highest_score[2]), 1, fp);
    }
    else if(ch==3)
    {
        fseek(fp,2*(sizeof(a)+3*sizeof(m)),SEEK_SET);
        fread(a, sizeof(a), 1, fp);
        fread(&m, sizeof(m), 1, fp);
        fread(&n, sizeof(n), 1, fp);
        fread(&highest_score[3], sizeof(highest_score[3]), 1, fp);
    }
    fclose(fp);
}

void map(void)
{
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

void game(int in)
{
    printf("Score:%d\n",score);
    printf("Highest score:%d\n",highest_score[in]);
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
    if(score>=highest_score[in])
    {
        highest_score[in]=score;
        write(in);
        printf("You break the record!!!\n");
        getchar();
        exit(0);
    }
    else
        printf("You win!!!\n");
        getchar();
        exit(0);
}

void write(int ch)
{
    FILE *fp = fopen("map.dat", "rb+");
    if (fp == NULL)  
    {
        printf("error!\n"); 
        getchar(); 
        exit(1);  
    }
    if(ch==1)
    {
        fseek(fp,sizeof(a)+2*sizeof(m),SEEK_SET);
        fwrite(&highest_score[1],sizeof(m),1,fp);
    }
    else if(ch==2)
    {
        fseek(fp,2*sizeof(a)+5*sizeof(m),SEEK_SET);
        fwrite(&highest_score[2],sizeof(m),1,fp);
    }
    else if(ch==3)
    {
        fseek(fp,3*sizeof(a)+8*sizeof(m),SEEK_SET);
        fwrite(&highest_score[3],sizeof(m),1,fp);
    }
    fclose(fp);
}

int main(void)
{
    #ifdef _WIN32
    system("color f9");
    #endif
    logo();
    char ch=getch();
    if(ch=='1')
    {
        read(1);
        while(1)
        {
            map();
            game(1);
        }
    }    
    else if(ch=='2')
    {
        read(2);
        while(1)
        {
            map();
            game(2);
        }
    }    
    else if(ch=='3')
    {
        read(3);
        while(1)
        {
            map();
            game(3);
        }
    }    
    else if(ch=='q')
        exit(0);
    else;
    getchar();
    return 0;
}
