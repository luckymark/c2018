#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SHOW 1
#define PUTIN 2
#define PUTOUT 3
#define QUIT 4

char names[1000][20];
int ids[1000],amounts[1000],n=0;


void init();
void show_the_menu();
void show_the_inventory();
void modify(int op);


int main()
{
    int option;
    while (1)
    {
        init();
        show_the_menu();
        scanf("%d",&option);
        switch(option)
        {
            case SHOW:
                {
                    show_the_inventory();
                    break;
                }
            case PUTIN:
                {
                    printf("in:");
                    int add=1;
                    modify(add);
                    break;
                }
            case PUTOUT:
                {
                    printf("out:");
                    int del=-1;
                    modify(del);
                    break;
                }
            case QUIT:
                {
                    return 0;
                }
        }
    }
    return 0;
}



void show_the_menu()
{
    printf("-------------------------------------------------\n");
    printf("|            Welcome to the system !            |\n");
    printf("|         ****************************          |\n");
    printf("|         *           Menu           *          |\n");
    printf("|         *                          *          |\n");
    printf("|         *  1-show the inventory    *          |\n");
    printf("|         *  2-be put in storage     *          |\n");
    printf("|         *  3-be put out of storage *          |\n");
    printf("|         *  4-quit the system       *          |\n");
    printf("|         *                          *          |\n");
    printf("|         ****************************          |\n");
    printf("|      Please enter a number to continue..      |\n");
    printf("-------------------------------------------------\n");
    printf("\nThe option you want to choose is :");
}

void init()
{
    FILE *fp;
    fp=fopen("Data.txt","r");
    int tot,id,amount;
    n=0;
    char name[100];
    fscanf(fp,"%d",&tot);
    while (tot--)
    {
        fscanf(fp,"%d%s%d",&id,name,&amount);
        int i;
        for (i=0;i<strlen(name);i++) names[n][i]=name[i];
        ids[n]=id;
        amounts[n]=amount;
        n++;
    }
    fclose(fp);
}

void show_the_inventory()
{
    printf("\nLoading...\n\n");
    printf("The list is :\n");
    printf("--------------------------------\n");
    printf("|id        name      amount    |\n");
    int i;
    for (i=0;i<n;i++)
    {
        if (amounts[i]>0)
        {
            printf("|%3d%12s%9d      |\n",ids[i],names[i],amounts[i]);
        }
    }
    printf("--------------------------------\n\n\n\n");

}

void modify(int op)
{
    int id,amount;
    char name[100];
    scanf("%d %s %d",&id,name,&amount);
    int i,flag=1;
    for (i=0;i<n;i++)
        if (ids[i]==id)
        {
            int temp=amounts[i]+op*amount;
            if (temp<0)
            {
                printf("Error!\n");
                return;
            }
            else amounts[i]=temp;
            flag=0;
        }
    if (flag)
    {
        int i;
        for (i=0;i<strlen(name);i++) names[n][i]=name[i];
        ids[n]=id;
        amounts[n]=amount;
        n++;
    }
    printf("\nLoading...\n");
    FILE *fp,*fpp;
    fp=fopen("Data.txt","w+");
    fprintf(fp,"%d\n",n);
    for (i=0;i<n;i++)
    {
        if (amounts[i]>0)
            {
                fprintf(fp,"%d %s %d\n",ids[i],names[i],amounts[i]);
            }
    }
    fclose(fp);

    fpp=fopen("Log.txt","a");
    if (op)
    {
        fprintf(fpp,"in:");
    }
    else
    {
        fprintf(fpp,"out:");
    }
    fprintf(fpp,"%d %s %d\n",id,name,amount);
    fclose(fpp);

    printf("Completed!\n");
}










