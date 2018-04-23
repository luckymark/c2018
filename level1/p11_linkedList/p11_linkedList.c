#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUMBER 5

struct node
{
    int data;
    int num;
    struct node *next;
};

struct node *head;
int L;

void make_a_list();
void show_the_list();
void reserve_the_list();
void find_the_data();
int random_number();

int main()
{
    printf("Please enter the length of the list:");
    scanf("%d",&L);
    make_a_list();

    printf("The list:\n");
    show_the_list();

    reserve_the_list();
    printf("\nAfter reserving:\n");
    show_the_list();

    printf("\nThe positions of NUMBER 5 is:\n");
    find_the_data();
    return 0;
}

void make_a_list()
{
    struct node *p,*temp;
    int count=0;
    head=p=(struct node *)malloc(sizeof(struct node));

    srand((unsigned)time(NULL));
    head->data=random_number();
    while (1)
    {
        p->num=++count;
        if (count==L) break;
        temp=p;
        p=(struct node *)malloc(sizeof(struct node));
        p->data=random_number();
        temp->next=p;
    }
    p->next=NULL;
}


int random_number()
{
    return (rand()%10);
}


void show_the_list()
{
    struct node *temp;
    temp=head;
    while (1)
    {
        printf("Number:%d  Data:%d\n",temp->num,temp->data);
        if (temp->next==NULL) break;
        else
        {
            temp=temp->next;
        }
    }
}


void reserve_the_list()
{
    if (L==1) return;
    if (L==2)
    {
        struct node *p,*temp;
        p=head->next;
        temp=head;
        head=p;
        p=temp;
    }
    if (L > 2)
    {
        struct node *p_left,*p_middle,*p_right;
        p_left=head;
        p_middle=p_left->next;
        p_right=p_middle->next;
        while (1)
        {
            p_middle->next=p_left;
            p_left->num=L+1-p_left->num;
            if (p_right->next==NULL) break;
            p_left=p_middle;
            p_middle=p_right;
            p_right=p_right->next;
        }
        p_right->num=L+1-p_right->num;
        p_middle->num=L+1-p_middle->num;
        p_right->next=p_middle;
        head->next=NULL;
        head=p_right;
    }
}

void find_the_data()
{
    struct node *temp;
    temp=head;
    while (1)
    {
        if (temp->data==NUMBER)
        {
            printf("%d ",temp->num);
        }
        if (temp->next==NULL) break;
        else
        {
            temp=temp->next;
        }
    }
    if (temp->data!=NUMBER) printf("-1");
}
















