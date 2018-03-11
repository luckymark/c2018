#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#define N 1000
char map[N][N];
int n,m,step,x,y;
int b[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
void getmap(){
	freopen("map","r",stdin);
	while (scanf("%s",map[n])!=EOF)n++;
	m=strlen(map[n-1]);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (map[i][j]=='P')x=i,y=j;
	fclose(stdin);
}
void swap(char*x,char*y){
	int z=*y;
	*y=*x,*x=z;
}
void draw(){
	printf("\033c");
	printf("Instruction:\n");
	printf("#:Wall\n");
	printf("P:people\n");
	printf("E:export\n");
	printf(".:space\n");
	printf("Your steps:%d\n",step);
	for (int i=0;i<n;i++)printf("%s\n",map[i]);
}
int main()
{
	getmap();
    char ch;
    int tty = open("/dev/tty", O_RDONLY);
    struct termios newt, oldt;
    tcgetattr(tty, &oldt);
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr(tty, TCSANOW, &newt);
    draw();
   	printf("Please input your move(q for quit):\n");
    while (1) {
        read(tty, &ch, 1);
        if (ch == 'q') {
            tcsetattr(tty, TCSANOW, &oldt);
            fprintf(stderr, "Quit\n", ch);
            break;
        } else {
        	int sig=-1;
        	if (ch==65)sig=0;
        	else
        	if (ch==66)sig=1;
        	else
        	if (ch==68)sig=2;
        	else
        	if (ch==67)sig=3;
        	if (sig!=-1){
        		int xx=x+b[sig][0],yy=y+b[sig][1];
        		if (xx<0||yy<0||xx==n||yy==m)continue;
        		if (map[xx][yy]=='#')continue;
        		if (map[xx][yy]=='.'){
        			swap(&map[xx][yy],&map[x][y]);
        			x=xx,y=yy;
        			step++;
    				draw();
   					printf("Please input your move(q for quit):\n");
        			continue;
        		}
        		if (map[xx][yy]=='E'){
        			map[x][y]='.';
        			map[xx][yy]='P';
        			draw();
        			printf("You win!And you cost %d steps\n",step);
        			return 0;
        		}
        	}
        }
    }
    return 0;
}
