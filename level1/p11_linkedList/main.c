#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist
{
    int date;
    struct linkedlist *next;
}link;

link *creat_link(link *p,int N)
{
    if(0!=N) scanf("%d",&(*p).date);
    if(2==N)
    {
        (*p).next=NULL;
        return NULL;
    }
    link *pre=(link *)malloc(sizeof(link));
    (*p).next=pre;
    return pre;
}

link *length_link(int N)
{
    link *head=(link *)malloc(sizeof(link));
    link *a=(link *)malloc(sizeof(link));
    for(int i=0;i<=N;i++)
    {
        if(0==i) a=creat_link(head,0);
        else if(N==i) a=creat_link(a,2);
        else a=creat_link(a,1);
    }
    return head;
}

void print_link(link *p)
{
    system("cls");
    int count=0;
    while(NULL!=p)
    {
        if(0==count)
        {
            p=(*p).next;
            count++;
            continue;
        }
        printf("link%d:%5d\n",count++,(*p).date);
        p=(*p).next;
    }
    system("pause");
    return 0;
}

void find_value(link *p)
{
    system("cls");
    printf("Do you want to find some number of the linkedlist:\nY/y:YES  N/n:NO\n");
    char Find;
    scanf("%c",&Find);
    while('N'!=Find && 'n'!=Find && 'Y'!=Find && 'y'!=Find)
    {
        printf("pls input Y/y:YES  N/n:NO\n");
        scanf("%c",&Find);
    }
    if('Y'==Find || 'y'==Find)
    {
        int count=0;
        while(NULL!=p)
        {
            if(0==count)
            {
                p=(*p).next;
                count++;
                continue;
            }
            if(5==(*p).date)
            {
                printf("link%d:%p\n",count++,p);
                p=(*p).next;
            }
            else
            {
                count++;
                p=(*p).next;
            }
        }
        system("pause");
    }
    if('N'==Find || 'n'==Find) return 0;
}

void reverse_link(link *p)
{
    system("cls");
    printf("Do you want to reverse the linkedlist:\nY/y:YES  N/n:NO\n");
    char is_reverse;
    scanf("%c",&is_reverse);
    while('N'!=is_reverse && 'n'!=is_reverse && 'Y'!=is_reverse && 'y'!=is_reverse)
    {
        printf("pls input Y/y:YES  N/n:NO\n");
        scanf("%c",&is_reverse);
    }
    if('Y'==is_reverse || 'y'==is_reverse)
    {
        link *rev,*old;
        link *head=p;
        int count=0;
        while(NULL!=(*p).next)
        {
            if(0==count)
            {
                old=p;
                p=(*p).next;
                rev=(*p).next;
                (*p).next=NULL;
                old=p;
                p=rev;
                count++;
                continue;
            }
            rev=(*p).next;
            (*p).next=old;
            old=p;
            p=rev;
        }
        (*p).next=old;
        (*head).next=p;
        print_link(head);
    }
    if('N'==is_reverse || 'n'==is_reverse) return 0;
}

int main()
{
    int n;
    printf("pls input the length of the linkedlist:\n");
    scanf("%d",&n);
    link *head=length_link(n);
    print_link(head);
    reverse_link(head);
    find_value(head);
    return 0;
}
