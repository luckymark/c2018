#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20+1
struct Node{
    int data ;
    int next ;
};
void Reverse(struct Node a[] , int head)
{
    int pre = head ;
    int now = a[head].next ;
    int last = now ;
    while(now != -1){
        int temp = a[now].next ;
        a[now].next = pre ;
        pre = now ;
        now = temp ;
    }
    a[last].next = -1 ;
    a[head].next = pre ;
}
int Search(struct Node a[] , int v , int head)
{
    for(int p = a[head].next ; p != -1 ; p = a[p].next){
        if(a[p].data == v){
            return p ;
        }
    }
    return -1 ;
}
int main()
{
    struct Node linklist[MAX] ;
    srand(time(NULL)) ;
    for(int i = 0 ; i < MAX ; i++){
        linklist[i].data= rand() % 10 ;
        linklist[i].next = i + 1 ;
    }
    linklist[MAX-1].next= -1 ;
    int head = 0 ;
    for(int p = linklist[head].next ; p != -1 ; p = linklist[p].next){
        printf("%d " , linklist[p].data) ;
    }
    Reverse(linklist , 0) ;
    putchar('\n') ;
    for(int p = linklist[head].next ; p != -1 ; p = linklist[p].next){
        printf("%d " , linklist[p].data) ;
    }
    int locat = Search(linklist , 5 , head) ;
    if(locat != -1){
        printf("\nthe 1th %d is in array %d \n" , linklist[locat].data ,locat) ;
    }
    else{
        printf("\nnot found\n") ;
    }
    int cnt = 2 ;
    locat = Search(linklist , 5 , locat) ;
    while(locat != -1){
        printf("the %dth %d is in array %d \n", cnt++ , linklist[locat].data , locat) ;
        locat = Search(linklist , 5 , locat) ;
    }
    return 0;
}
