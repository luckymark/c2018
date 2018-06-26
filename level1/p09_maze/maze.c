//µ›πÈ√‘π¨

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define N 21

int n[N][N];
int x=1,y=1;

void filling();
void dig(int,int);
void output();
int digjudge(int,int);
int movejudge(char);
void move(int);
int winjudge();
void winput();

int main() {
    srand((unsigned)time(NULL)*rand()%11);
    filling();
    dig(x,y);
    n[x][y]=2;
    while(!winjudge()) {
    	output();
    	move(movejudge(getch()));
    	if(winjudge()) {
    		winput();
		}
		system("CLS");
	}
    getchar();
}
void filling() {
    for (int j=0; j<N; j++) {
        for (int i=0; i<N; i++) {
            if (i%2==1&&j%2==1) {
                n[i][j]=1;
            } else {
                n[i][j]=0;
            }
        }
    }
    return;
}
void dig(int i,int j) {
    n[i][j]=-1;
    while (digjudge(i,j)&&(j<N-2&&n[i][j+2]==1||i<N-2&&n[i+2][j]==1||j>1&&n[i][j-2]==1||i>1&&n[i-2][j]==1)) {
        int dric=rand()%4;
        if (dric==0&&n[i][j+1]!=1&&j<N-2&&n[i][j+2]==1) {
            n[i][j+1]=-1;
            dig(i,j+2);
            continue;
        }
        if (dric==1&&n[i+1][j]!=1&&i<N-2&&n[i+2][j]==1) {
            n[i+1][j]=-1;
            dig(i+2,j);
            continue;
        }
        if (dric==2&&n[i][j-1]!=1&&j>1&&n[i][j-2]==1) {
            n[i][j-1]=-1;
            dig(i,j-2);
            continue;
        }
        if (dric==3&&n[i-1][j]!=1&&i>1&&n[i-2][j]==1) {
            n[i-1][j]=-1;
            dig(i-2,j);
            continue;
        }
    }
    return;
}
void output() {
    for (int j=0; j<N; j++) {
        for (int i=0; i<N; i++) {
            if (i==1&&j==0||i==N-2&&j==N-1) {
                printf(" ");
            } else if (n[i][j]==0) {
                printf("#");
            } else if (n[i][j]==-1) {
                printf(" ");
            } else if (n[i][j]==1) {
                printf(" ");
            } else if (n[i][j]==2) {
            	printf("*");
			}
        }
        printf("\n");
    }
    return;
}
int digjudge(int i,int j) {
    if (i-1!=0) {
        if (n[i-1][j]==0) {
            return 1;
        }
    }
    if (i+1!=N-1) {
        if (n[i+1][j]==0) {
            return 1;
        }
    }
    if (j-1!=0) {
        if (n[i][j-1]==0) {
            return 1;
        }
    }
    if (j+1!=N-1) {
        if (n[i][j+1]==0) {
            return 1;
        }
    } else {
        return 0;
    }
}
int movejudge(char dir) {
	switch (dir) {
		case 's': {
			if(n[x][y+1]!=0) {
				n[x][y]=-1;
				y++;
			}
			return 0;
		}
		case 'd': {
			if(n[x+1][y]!=0) {
				n[x][y]=-1;
				x++;
			}
			return 1;
		}
		case 'w': {
			if(n[x][y-1]!=0) {
				n[x][y]=-1;
				y--;
			}
			return 2;
		}
		case 'a': {
			if(n[x-1][y]!=0) {
				n[x][y]=-1;
				x--;
			}
			return 3;
		} default :{
			return -1;
		}
	}
}
void move(int mj) {
	switch (mj) {
		case '-1': {
			break;
		}
		default: {
			n[x][y]=2;
			break;
		}
	}
	
}
int winjudge() {
	if(x==N-2&&y==N-2) {
		return 1;
	} else {
		return 0;
	}
}
void winput() {
	printf("you win!");
	getchar();
}
