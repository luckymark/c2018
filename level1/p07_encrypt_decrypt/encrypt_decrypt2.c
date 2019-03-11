#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <conio.h>
#else
#include <stdio_ext.h>
#endif
#define N 1000

void clrbuf(void);
void logo(void);
void get(char ch);
void encrypt(void);
void decrypt(void);

#ifndef _WIN32
int getch(void)
{
    char ch;
    ch=getchar();//先用getchar占个坑，以后用fork写个无阻塞的。。 
    clrbuf(); 
    return ch;
} 
#endif

void clrbuf(void)
{
    #ifdef _WIN32
    rewind(stdin);
    #else
    __fpurge(stdin);
    #endif
}
//用库函数的话只能这样 

void logo(void)
{
    printf("************************************************\n");
    printf("*********String Encrypter and Decrypter*********\n");
    printf("************************************************\n");
    printf("\n");
    printf("Press 'e' to encrypt a string\n");
    printf("Press 'd' to decrypt a string\n");
    printf("Press 'q' to quit\n");
}

int i,num;
char s[N];
char s1[N];
int s2[N]={0};

void get(char ch)
{
    if(ch=='e')
    {
        loop:while(1)
        {
            printf("Please input your string.\n");
            clrbuf();
            fgets(s,N,stdin);
            num=0;
            if(s[0]=='\n')
            continue;
            while(s[++num]!='\n');
            for(i=0;i<num;i++)
            {
                if(s[i]<0)
                {
                    printf("不支持中文~~~\n");
                    goto loop; 
                }
                else;
            }
            break;
        }
    }
    else if(ch=='d')
    {
        while(1)
        {
            printf("Please input your string.\n");
            clrbuf();
            fgets(s1,N,stdin);
            if(s1[0]!='*')
            {
                printf("Invalid string!!!\n");
                continue;
            }
            else
            {
                int i=1;
                num=0;
                int max=strlen(s1);
                while(i<max)
                {
                    sscanf(&s1[i],"%d*",&s2[num]);
                    if(s2[num]>=0&&s2[num]<10)
                    i=i+2,num++; 
                    else if((s2[num]>=10&&s2[num]<100)||(s2[num]<0&&s2[num]>-10))
                    i=i+3,num++;
                    else if((s2[num]>=100&&s2[num]<1000)||(s2[num]<=-10&&s2[num]>-100))
                    i=i+4,num++;
                    else if(s2[num]<=-100&&s2[num]>-1000)
                    i=i+5,num++;
                    else
                    {i++; continue;}
                } 
            }
            break;
        }
    }
    else;
}

void encrypt(void)
{
    get('e');
    printf("Encrypted string is\n*");
    for(i=0;i<num;i++)
    {
        char ch;
        char highfour,lowfour;
        ch=s[i];
        lowfour=ch&0xf;
        ch>>=4;
        highfour=ch&0xf;
        ch=lowfour;
        ch<<=4;
        ch=ch|highfour;
        printf("%d*",ch);
    }
    printf("\n");
    printf("Press any key to continue.\n");
    while (!getch());
    logo();
}

void decrypt(void)
{
    get('d');
    printf("Decrypted string is\n");
    for(i=0;i<num;i++)
    {
        short num;
        char highfour,lowfour;
        num=s2[i];
        lowfour=num&0xf;
        num>>=4;
        highfour=num&0xf;
        num=lowfour;
        num<<=4;
        num=num|highfour;
        printf("%c",num);
    }
    printf("\n");
    printf("Press any key to continue.\n");
    while (!getch());
    logo();
}

int main(void)
{
    #ifdef _WIN32
    system("color f9");
    #endif
    logo();
    while(1)
    {
        char ch;
        ch=getch();
        if(ch=='e')
        {
            encrypt();
            continue;
        }
        else if(ch=='d')
        {
            decrypt();
            continue;
        }
        else if(ch=='q')
        {
            exit(0);
        }
        else;
    }
    getchar();
    return 0;
}
