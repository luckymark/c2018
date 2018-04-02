#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//#include<conio.h>
#define N 1000
int n,m,i,j,r,cur,curX,curY,tot,curYY,dir;
char map[N*2][N*2],mov;
int path[N*2][2],vis[N][N];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int ok=0;
int isBlank(int x, int y) //if there is a land near a land
{
    for(int i=0;i<=3;i++)
    {
        int xx = x+dx[i]*2;
        int yy = y+dy[i]*2;
        if(xx<=n && yy<=m && xx>=1 && yy>=1 && map[xx][yy]==' ' && vis[xx][yy]==0)
            return 1;
    }
    return 0;
}
int test(int x, int y, int r) // if a tile near a land is a wall
{
    int xx = x+dx[r]*2;
    int yy = y+dy[r]*2;
    if(xx<=n && yy<=m && xx>=1 && yy>=1 && map[xx][yy]==' ' && vis[xx][yy]==0)
        return 1;
    else
        return 0;
}
void print()
{
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=m;j++)
            printf("%c",map[i][j]);
        printf("%c\n",map[i][m+1]);
    }
}    
int main(){
    srand((int)time(0));
    //srand((unsigned) time(NULL));
	printf("Input n and m (the size of maze, which is an odd number)):");
    scanf("%d %d",&n,&m);
    //n=25;
    //m=25;
	for(i=0;i<=n+1;i++)
 		for(j=0;j<=m+1;j++)
			map[i][j] = '#';
	for(i=1;i<=n;i+=2)
 		for(j=1;j<=m;j+=2)
            map[i][j] = ' ';
    //print();
    tot = ((n+1)/2)*((m+1)/2);
    cur = 1;
    curX = (int)(n);
    curY = (int)(m/2);
    //curY = 3;
    if (curY%2==0) curY++;

    map[0][curY] = ' ';
    map[curX+1][curY] = ' ';
    path[cur][0] = curX;
    path[cur][1] = curY;

    //while(cur<=(int)(tot*1.5))
    while(cur<=tot)
    {
        //printf("\n");
        //printf("%d\n", cur);
        //print();
        if(isBlank(curX, curY))
        {
            ok = 0;
            while(!ok)
            {
                r = (int)(4.0*rand()/(RAND_MAX));
                if(test(curX, curY, r))
                {
                    ok = 1;
                    //printf("%d   dafsdf\n", r);
                }
            }
            //printf("%d\n", r);  
            cur++;
            curX += dx[r];
            curY += dy[r];
            map[curX][curY] = ' ';
            vis[curX][curY] = 1;
            curX += dx[r];
            curY += dy[r];
            vis[curX][curY] = 1;
            path[cur][0] = curX;
            path[cur][1] = curY;      
            //printf("%d1\n", cur);  
        }
        else
        {
            for(i=cur;i>=1;i--)
                if(isBlank(path[i][0],path[i][1]))
                    break;
            curX = path[i][0];
            curY = path[i][1];
            ok = 0;
            while(!ok)
            {
                r = (int)(4.0*rand()/(RAND_MAX));
                if(test(curX, curY, r))
                {
                    ok = 1;
                    //printf("case2 %d\n",r);
                }
                    
            }
            cur++;
            curX += dx[r];
            curY += dy[r];
            map[curX][curY] = ' ';
            vis[curX][curY] = 1;
            curX += dx[r];
            curY += dy[r];
            vis[curX][curY] = 1;
            path[cur][0] = curX;
            path[cur][1] = curY;    
            //printf("%d2\n", cur);    
        }
    }
    //printf("\n");
    //print();

    printf("Start the game!\n");
    printf("Please input W/A/S/D to move:\n");

    curX = (int)(n);
    curY = (int)(m/2);
    if(curY%2==0) curY++;
    curYY = curY;
    map[curX+1][curY] = '.';
    curX++;
    //printf("\n");
    //print();

    while(!(curX == 0 && curY==curYY))
    {
        scanf("%c",&mov);
        //mov = getch();
        if(mov=='w') dir=0;
        if(mov=='d') dir=1;
        if(mov=='s') dir=2;
        if(mov=='a') dir=3;
        curX += dx[dir];
        curY += dy[dir];
        if(map[curX][curY]=='#')
        {
            printf("Error!Please choose another direction:\n"); 
            curX -= dx[dir];
            curY -= dy[dir];
            continue;
        }
        else
        {
            map[curX][curY] = '.';
            map[curX-dx[dir]][curY-dy[dir]] = ' ';
        }
        if(curX==0 && curY==curYY)
        {
            printf("You win!\n");
        }
        print();
    }

	return 0;
}