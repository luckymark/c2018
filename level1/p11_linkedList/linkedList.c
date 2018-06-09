#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <conio.h>
#include <Windows.h>
#else
#include <unistd.h>
#include <stdio_ext.h>
#include <pthread.h>
#endif
#define LEN sizeof(struct node)

void clrbuf(void);
void create(void);
void display(void);
void reverse(void);
int search(void);

struct node
{
    int data;
    struct node *next;
};
struct node *p, *pl, *head, *p2;
node *now, *next = NULL;
int a = 0, b = -1, n=0 , ch , i;
int numin[1000];

#ifdef _WIN32
DWORD WINAPI clrbuf(LPVOID lpParameter)
{
    while((ch=getchar())!=EOF&&ch!='\n');
    return 0;
}

DWORD WINAPI scanf(LPVOID lpParameter)
{
    #ifdef DEGBUG2
    scanf("%d", &b);
    return 0;
    #else
    for (i = 0;; i++)
        scanf("%d",&numin[i]);
    #endif
}

#else 
void *getnum(void *arg)
{
    pthread_testcancel();
    for (i = 0;; i++)
        scanf("%d",&numin[i]);
    pthread_testcancel();
}
#endif

void clrbuf(void)
{
    #ifdef DEGBUG2
    HANDLE Thread1 = CreateThread(NULL, 0, clrbuf, NULL, 0, NULL);
    Sleep(10);
    TerminateThread(Thread1, 0);
    CloseHandle(Thread1);
    #elif defined _WIN32
    rewind(stdin);
    #else
    __fpurge(stdin);
    #endif
}

void create(void)
{
    head = p = (struct node*)malloc(LEN);
    printf("Creating linked list...\n");
    printf("Please input data:\n");
    #ifdef DEGBUG1
    char str1[10], str2[10];
    scanf("%d", &p->data);
    getchar();
    while (1)
    {
        a = getchar();
        if (a != '\n')
        {
            b = -1;
            pl = p;
            p = (struct node*)malloc(LEN);
            HANDLE Thread2 = CreateThread(NULL, 0, scanf, NULL, 0, NULL);
            Sleep(10);
            if (b == -1)
            {
                TerminateThread(Thread2,0);
                CloseHandle(Thread2);
                p->data = a - 48;
                pl->next = p;
                clrbuf();
            }
            else
            {
                CloseHandle(Thread2);
                _itoa(a - 48, str1, 10);
                _itoa(b, str2, 10);
                strcat(str1, str2);
                p->data = atoi(str1);
                pl->next = p;
            }
            continue;
        }
        break;
    }
    #else
    clrbuf();
    a=getchar();
    ungetc(a,stdin);
    #ifdef _WIN32
    HANDLE Thread2 = CreateThread(NULL, 0, scanf, NULL, 0, NULL);
    Sleep(10);
    TerminateThread(Thread2, 0);
    CloseHandle(Thread2);
    #else
    pthread_t tid;
    int *temp=NULL;
    if(pthread_create(&tid,NULL,getnum,temp)!=0)
    {
        perror("Can't create thread!");
        getchar();
        exit(1);
    }
    sleep(0.1);
    if(pthread_cancel(tid)!=0)
    {
        perror("Can't kill thread!");
        getchar();
        exit(1);
    }
    #endif
    p->data = numin[0];
    for (int j = 1; j < i; j++)
    {
        pl = p;
        p = (struct node*)malloc(LEN);
        p->data = numin[j];
        pl->next = p;
    }
    #endif
    p->next = NULL;
    p = head;
}

void display(void)
{
    printf("Data:");
    while (p->next != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
}

void reverse(void)
{
    printf("Reversing...\n");
    node *pre;
    pre = head;
    now = head->next;
    while (now)
    {
        next = now->next;
        now->next = pre;
        pre = now;
        now = next;
    }
    head->next = NULL;
    head = pre;
}

int search(void)
{
    bool flag = 0;
    if (next == NULL)
    {
        next = head;
        now = NULL;
    }
    else
    {
        now = next;
        next = next->next;
    }
    while (next != NULL)
    {
        n++;
        if (next->data == 5)
        {
            flag = 1;
            return n;
            break;
        }
        now = next;
        next = next->next;
    }
    if (flag == 0)
        return -1;
    else
        return 0;
}

int main(void)
{
    #ifdef _WIN32
    system("color f9");
    #endif
    create();
    display();
    reverse();
    display();
    printf("Searching...\n");
    printf("%d\n", search());
    printf("%d\n", search());
    #ifdef _WIN32
    system("pause");
    #endif
    return 0;
}
