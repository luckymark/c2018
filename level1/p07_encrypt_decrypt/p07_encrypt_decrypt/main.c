#include <stdio.h>
#include <string.h>
void Encrypt(char a[])
{
    int lenth = strlen(a) ;
    int m = lenth / 2 ;
    for(int i = 0 ; i <= m ; i++){
        a[i]-- ;
    }
    for(int i = m+1 ; i <lenth ; i++){
        a[i]++ ;
    }
}
void Decrypt(char a[])
{
    int lenth = strlen(a) ;
    int m = lenth /2 ;
    for(int i = 0 ; i <= m ; i++){
        a[i]++ ;
    }
    for(int i = m+1 ; i < lenth ; i++){
        a[i]-- ;
    }
}
#define MAX 1000
char strs[MAX] ;
int main()
{
    void (*fun[2]) (char *) = {Encrypt , Decrypt} ;
    printf("0 Encrypt , 1 Decrypt : ") ;
    int flag ;
    scanf("%d" ,&flag) ;
    if(!flag){
        printf("Encrypt: ") ;
    }
    else{
        printf("Decrypt: ") ;
    }
    getchar() ;
    char ch = getchar() ;
    int cnt = 0 ;
    while(ch != '\n'){
        strs[cnt++] = ch ;
        ch = getchar() ;
    }
    strs[cnt] = '\0' ;
    (*fun[flag])(strs) ;
    printf("%s" ,strs) ;
    return 0;
}
