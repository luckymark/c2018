#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
#define LENTH 20
int main()
{
    FILE *fp = fopen("data.txt","r") ;
    int flag = 1 ;
    if(fp == NULL){
        fp = fopen("data.txt" , "w+") ;
        flag = 0 ;
    }
    struct Node{
        char model[LENTH] ;
        int num ;
        int tag ;
    }product[MAX] ;
    int pronum ;
    fscanf(fp ,"%d" ,&pronum) ;
    fgetc(fp) ;
    if(flag == 0){
        pronum = 0 ;
    }
    for(int i = 0 ; i < pronum ; i++){
        int cnt = 0 ;
        char ch ;
        while((ch = fgetc(fp)) != ' ' && cnt < LENTH -1){
            product[i].model[cnt++] = ch ;
        }
        product[i].model[cnt] = '\0' ;
        fscanf(fp ,"%d" , &product[i].num) ;
        product[i].tag = 1 ;
        fgetc(fp) ;
    }
    fclose(fp) ;
    printf("1) print list \n2) put in storage \n3) put out storage \n0) exit\n:");
    int op ;
    scanf("%d" ,&op) ;
    getchar() ;
    int removenum = 0 ;
    while(op){
        if(op == 1){
            for(int i = 0 ; i < pronum ; i++){
                if(product[i].tag){
                    printf("model: %s , amount: %d\n" , product[i].model ,product[i].num) ;
                }
            }
        }
        else if(op == 2){
            printf("input model and amount :") ;
            char inmodel[LENTH] ;
            char ch ;
            int cnt = 0 ;
            while((ch = getchar()) != ' ' && cnt < LENTH - 1){
                inmodel[cnt++] = ch ;
            }
            inmodel[cnt] = '\0' ;
            int i ;
            for( i = 0 ; i < pronum ; i++){
                if( strcmp(inmodel , product[i].model) == 0){
                    break ;
                }
            }
            int tnum ;
            scanf("%d" ,&tnum) ;
            if(i < pronum){
                product[i].num += tnum ;
            }
            else{
                product[pronum].num = tnum ;
                product[pronum].tag = 1 ;
                strcpy(product[pronum++].model , inmodel) ;
            }

        }
        else if(op == 3){
            printf("input model and mount for out storage :") ;
            char outmodel[LENTH] ;
            char ch ;
            int cnt = 0 ;
            while((ch = getchar()) != ' ' && cnt < LENTH - 1){
                outmodel[cnt++] = ch ;
            }
            outmodel[cnt] = '\0' ;
            int tnum ;
            scanf("%d" , &tnum) ;
            int i ;
            for( i = 0 ; i < pronum ; i++){
                if( strcmp(outmodel , product[i].model) == 0){
                    break ;
                }
            }
            if( i < pronum){
                if( tnum > product[i].num){
                    printf(" no enough product for out\n") ;
                }
                else if(tnum == product[i].num){
                    product[i].num -= tnum ;
                    product[i].tag = 0 ;
                    removenum++ ;
                }
                else{
                    product[i].num -= tnum ;
                }
            }
        }
        printf("1) print list \n2) put in storage \n3) put out storage \n0) exit\n:");
        scanf("%d" , &op) ;
        getchar() ;
    }
    fp = fopen("data.txt" ,"w") ;
    fprintf(fp , "%d\n" , pronum - removenum) ;
    for(int i = 0 ; i < pronum ; i++){
        if(product[i].tag){
            fprintf(fp ,"%s %d\n" , product[i].model , product[i].num) ;
        }
    }
    fclose(fp) ;
    return 0;
}
