#include <stdio.h>
#include <MacTypes.h>
#include <stdlib.h>
#define inchMax 10

int personX=2;
int personY=2;

int people[inchMax+2][inchMax+2];
int maze[inchMax+2][inchMax+2];
int nextDerection[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

void swap(int* a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

void randomDerection()
{
    
    for(int i=0;i<4;i++)
    {
        int t=rand()%4;
        swap(&nextDerection[i][0],&nextDerection[t][0]);
        swap(&nextDerection[i][1],&nextDerection[t][1]);
    }
}


void dfs(int x,int y)
{
    maze[x][y]=1;
    randomDerection();
    for(int i=0;i<4;i++)
    {
        if(maze[x+2*nextDerection[i][0]][y+2*nextDerection[i][1]]==0){
            maze[x+nextDerection[i][0]][y+nextDerection[i][1]]=1;
            dfs(x+2*nextDerection[i][0],y+2*nextDerection[i][1]);
            
        }
    }
}

void initMaze()
{
    for (int i = 0; i <inchMax+2; ++i) {
        for (int j = 0; j <inchMax+2 ; ++j) {
            if(i==inchMax+1||j==inchMax+1||!i||!j)
                maze[i][j]=1;
            else
                maze[i][j]=0;
        }
        
    }
    dfs(2,2);
    maze[2][2]=2;
    maze[inchMax][inchMax+1]=3;
}

void printMaze() {
    system("clear");
    for (int i = 1; i < inchMax+2; i++) {
        for (int j = 1; j <inchMax+2 ; j++) {
            if (maze[i][j]==3)
                printf("@");
            else if (!maze[i][j]||!j||i==inchMax+1||j==inchMax+1)
                printf("#");
            else if(maze[i][j]==1)
                printf(" ");
            else
                printf("*");
            
        }
        printf("\n");
    }
}


void gameStart()
{
    while(1) {
        char person;
        if (person = getchar()) {
            switch (person) {
                case 'w' :
                    if (maze[personX - 1][personY]) {
                        maze[personX][personY] = 1;
                        personX--;
                        maze[personX][personY] = 2;
                    }
                case 'a':
                    if (maze[personX][personY - 1]) {
                        maze[personX][personY] = 1;
                        personY--;
                        maze[personX][personY] = 2;
                    }
                case 's':
                    if (maze[personX + 1][personY]) {
                        maze[personX][personY] = 1;
                        personX++;
                        maze[personX][personY] = 2;
                    }
                case 'd':
                    if (maze[personX][personY + 1]) {
                        maze[personX][personY] = 1;
                        personY++;
                        maze[personX][personY] = 2;
                    }
            }
            printMaze();
            if(personX==inchMax&&personY==inchMax+1) {
                printf("Perfect!you win!");
                break;
            }
        }
    }
}

int main()
{
    srand(0);
    initMaze();
    printMaze();
    gameStart();
    return 0;
}

