#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
struct Location{
    int x ;
    int y ;
}plocat , clocat[10] , dest[10] ;
int casenum ;
char map[100][100] ;
int WIDTH , HIGH ;
int steps ;
int Draw(int pxwill , int pywill)
{
    if(map[pxwill][pywill] != '#'){
        int cxwill = -1 ;
        int cywill = -1 ;
        int i ;
        for( i = 0 ; i < casenum ; i++){
            if(pxwill == clocat[i].x && pywill == clocat[i].y){
                cxwill = clocat[i].x + (pxwill - plocat.x) ;
                cywill = clocat[i].y + (pywill - plocat.y) ;
                break ;
            }
        }
        int flag = 1 ;
        if(cxwill != -1){
            if(map[cxwill][cywill] == '#'){
                flag = 0 ;
            }
            for(int j = 0 ; j < casenum ; j++){
                if(cxwill == clocat[j].x && cywill == clocat[j].y){
                    flag = 0 ;
                    break ;
                }
            }
        }
        if(flag){
            plocat.x = pxwill ;
            plocat.y = pywill ;
            if(cxwill != -1){
                clocat[i].x = cxwill ;
                clocat[i].y = cywill ;
            }
            steps++ ;
        }
    }
    for(int i = 0 ; i < WIDTH ; i++){
        for(int j = 0 ; j < HIGH ; j++){
            if(i == plocat.x && j == plocat.y){
                putchar('P') ;
                continue ;
            }
            int flag = 1 ;
            for(int k = 0 ; k < casenum ; k++){
                if(i == clocat[k].x && j == clocat[k].y){
                    putchar('C') ;
                    flag = 0 ;
                    break ;
                }
                /*if(i == dest[k].x && j == dest[k].y){
                    putchar('O') ;
                    flag = 0 ;
                    break ;
                }*/
            }
            if(flag){
                printf("%c" ,map[i][j]) ;
            }
        }
        putchar('\n') ;
    }
    int ret = 0 ;
    for(int i = 0 ; i < casenum ;i++){
        int j ;
        for(j = 0 ; j < casenum ; j++){
            if(clocat[i].x == dest[j].x && clocat[i].y == dest[j].y)
                break ;
        }
        if(j == casenum){
            ret = 1 ;
            break ;
        }
    }
    return ret ;
}
int main(void)
{
    char *selectmap[2] = {"1.txt" , "2.txt"} ;
    char *grademap[2] = {"1_grade.txt" , "2_grade.txt"} ;
    int cnt = 0 ;
    while(cnt < 2){
        FILE *fp = fopen(selectmap[cnt],"r") ;
        if(fp == NULL){
            printf("Cannot open file\n") ;
            exit(0) ;
        }
        fscanf(fp , "%d %d" ,&WIDTH , &HIGH) ;
        fgetc(fp) ;
        for(int i = 0 ; i < HIGH ; i++){
            for(int j = 0 ; j < WIDTH ; j++){
                fscanf(fp,"%c", &map[i][j]) ;
            }
            fgetc(fp) ;
        }
        fclose(fp) ;
        int dcnt = 0 , ccnt = 0 ;
        for(int i = 0 ; i < HIGH ; i++){
            for(int j = 0 ; j < WIDTH ; j++){
                if(map[i][j] == 'P'){
                    plocat.x = i ;
                    plocat.y = j ;
                    map[i][j] = ' ' ;
                }
                if(map[i][j] == 'O'){
                    dest[dcnt].x = i ;
                    dest[dcnt++].y = j ;
                }
                if(map[i][j] == 'C'){
                    clocat[ccnt].x = i ;
                    clocat[ccnt++].y = j ;
                    map[i][j] = ' ' ;
                }
            }
        }
        casenum = dcnt ;
        int pxwill = plocat.x ;
        int pywill = plocat.y ;
        steps = 0 ;
        system("cls") ;
        printf("P is person , C is case , O is destination\n") ;
        while(Draw(pxwill , pywill)){
            printf("level %d next move(enter 'a' 'w' 's' 'd' for moving) : " , cnt) ;
            char move = getchar() ;
            fflush(stdin) ;
            pxwill = plocat.x ;
            pywill = plocat.y ;
            switch(move)
            {
            case 'a':
                pywill = plocat.y - 1;
                break ;
            case 'w' :
                pxwill = plocat.x -1 ;
                break ;
            case 'd' :
                pywill = plocat.y + 1;
                break ;
            case 's' :
                pxwill = plocat.x + 1 ;
                break ;
            }
            system("cls") ;
        }
        printf("steps : %d\n" , steps) ;
        printf("press enter to next level") ;
        getchar() ;
        FILE *fp2 = fopen(grademap[cnt] , "r") ;
        if(fp2 == NULL){
            fp2 = fopen(grademap[cnt] , "w") ;
            fprintf(fp2 ,"%d" , steps) ;
        }
        else{
            int minsteps ;
            fscanf(fp2 ,"%d" , &minsteps) ;
            if(steps < minsteps){
                fclose(fp2) ;
                fp2 = fopen(grademap[cnt] , "w") ;
                fprintf(fp2 , "%d" , steps) ;
            }
        }
        fclose(fp2) ;
        cnt++ ;
    }
    printf("YOU WIN ,game over") ;
    system("pause") ;
    return 0 ;
}
