#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define N 100

void logo(void);
int stock_search(char name_input[]);
void stock_display(void);
void stock_in(void);
void stock_out(void);
void load(void);
void save(void);

struct stock
{
    int num,price;
    char name[30];
}
stocks[N];
int n=0,i;

void logo(void)
{
    printf("********************************\n");
    printf("*********Stocks manager*********\n");
    printf("********************************\n");
    printf("\n");
    printf("Press '2' to display inventory list\n");
    printf("Press '3' to put in storage\n");
    printf("Press '4' to put out of storage\n");
    printf("Press '5' to save and quit\n");
}

int stock_search(char name_input[])
{
    for(i=1;i<N;i++)
        if(strcmp(name_input,stocks[i].name)==0)
            return i;
    return 0;
}

void stock_display(void)
{
    if(n<=0)
    {
        printf("No cargo yet!\n");
        getchar();
        return;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            printf("\nname:%-8s",stocks[i].name);
            printf("price:%-5d",stocks[i].price);
            printf("num:%-5d\n",stocks[i].num);
        }
        getchar();
    }
}

void stock_in(void)
{
    char name_input[30];
    printf("Please input name\n");
    scanf("%s",name_input);
    if(stock_search(name_input))
    {
        strcpy(stocks[i].name,name_input);
        printf("Please input num\n");
        int num;
        scanf("%d",&num);
        if(num>0)
            stocks[i].num+=num;
        else
            printf("error!\n");
    }
    else
    {
        n++;
        strcpy(stocks[n].name,name_input);
        printf("Please input price\n");
        int price;
        scanf("%d",&price);
        if(price>=0)
            stocks[n].price=price;
        else
            printf("error!\n");
        printf("Please input num\n");
        int num;
        scanf("%d",&num);
        if(num>0)
            stocks[n].num=num;
        else
            printf("error!\n");
    }
    printf("\n");
}

void stock_out(void)
{
    printf("Please input name\n");
    char name_input[30];
    scanf("%s",name_input);
    if(stock_search(name_input))
    {
        printf("Please input num\n");
        int num;
        scanf("%d",&num);
        if(stocks[i].num>=num)
            stocks[i].num-=num;
        else
            printf("error!\n");
    }
    else
    {
        printf("Cargo not exist!\n");
    }
    getchar();
}

void load(void)
{
    FILE *fp=fopen("data.txt","r+");
    if(fp==NULL)
    {
        FILE *fp=fopen("data.txt","w+");
        if(fp==NULL)
        {
            printf("error!\n"); 
            getchar();
            exit(1); 
        }
        else
            fclose(fp);
    }
    else
    {
        fread(&n,sizeof(n),1,fp);
        fread((char*)stocks,sizeof(struct stock),N,fp);
        fclose(fp);
    }
}

void save(void)
{
    FILE *fp=fopen("data.txt","r+");
    if(fp==NULL)
    {
        printf("error!\n"); 
        getchar();
        exit(1); 
    }
    fwrite(&n,sizeof(n),1,fp);
    fwrite((char*)stocks,sizeof(struct stock),N,fp);
}

int main(void)
{
    #ifdef _WIN32
    system("color f9");
    #endif
    load();
    while(1)
    {
        logo();
        switch(getch())
        {
            case '2':
                stock_display();
                break;
            case '3':
                stock_in();
                break;
            case '4':
                stock_out();
                break;
            case '5':
                save();
                exit(0);
        }
    }
    getchar();
    return 0;
}
