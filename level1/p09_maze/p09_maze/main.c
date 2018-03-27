#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int nowlocation[2] = { 1 , 1} ;
#define ROW 10
#define COLUMN 10
int Draw(int prow , int pcolumn , char maze[100][100])
{
    int ret = 1 ;
    if(maze[prow][pcolumn] == '#') ;
    else if(prow == 0 || prow == ROW - 1 || pcolumn == 0 || pcolumn == COLUMN - 1){
        nowlocation[0] = prow ;
        nowlocation[1] = pcolumn ;
        ret = 0 ;
    }
    else{
        nowlocation[0] = prow ;
        nowlocation[1] = pcolumn ;
    }
    for(int i = 0 ; i < ROW ; i++){
        for(int j = 0 ; j < COLUMN ; j++){
            if(i == nowlocation[0] && j == nowlocation[1] ){
                putchar('P') ;
                continue ;
            }
            printf("%c" ,maze[i][j]) ;
        }
        putchar('\n') ;
    }
    return ret ;
}
int main()
{
    char maze[100][100] = {
    "##########" ,
    "#    #   #",
    "#### # # #",
    "#  # # # #",
    "# #  # # #",
    "# # ## # #",
    "#      # #",
    "######## #",
    "#        #",
    "# ########"} ;
    int prow = nowlocation[0] ;
    int pcolumn = nowlocation[1] ;
    while(Draw(prow , pcolumn , maze)){
        printf("enter 'a' or 'w' or 's' or 'd' to move : ") ;
        char ch = getchar() ;
        fflush(stdin) ;
        prow = nowlocation[0] ;
        pcolumn = nowlocation[1] ;
        switch(ch)
        {
        case 'a':
            pcolumn = nowlocation[1] - 1;
            break ;
        case 'w' :
            prow = nowlocation[0] -1 ;
            break ;
        case 'd' :
            pcolumn = nowlocation[1] + 1;
            break ;
        case 's' :
            prow = nowlocation[0] + 1 ;
            break ;
        default :
            prow = nowlocation[0] ;
            pcolumn = nowlocation[1] ;
        }
        system("cls") ;
    }
    printf("wow! you find the exit\n") ;
    system("pause") ;
    return 0;
}
