#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//#include<conio.h>
#define N 3000
int n,m,i,j,r,cur,curX,curY,tot,curXX,curYY,dir,tot;
char map[N*2][N*2],map2[N*4][N*4],mov;
int path[N*2][2],vis[N][N],tmp,rx,ry,cnt;
int dx[8]={-1,0,1,0,-1,1,1,-1},dy[8]={0,1,0,-1,1,1,-1,-1};
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
void print2()
{
    for(int i=0;i<=2*n+1;i++)
    {
        for(int j=0;j<=2*m;j++)
            printf("%c",map2[i][j]);
        printf("%c\n",map2[i][2*m+1]);
    }
} 
int count(int x, int y)
{
    int sum = 0;
    for(i=0;i<=7;i++)
    {
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(map2[xx][yy]=='#' || map2[xx][yy]=='*') sum++;
    }
    return sum;
}
int main(){
    srand((int)time(0));
    printf("Input n and m (the size of maze, which is an odd number)):\n");
    scanf("%d %d",&n,&m);
    getchar();
    //n=55;
    //m=135;
	for(i=0;i<=n+1;i++)
 		for(j=0;j<=m+1;j++)
            map[i][j] = '#';
    for(i=0;i<=2*(n+1);i++)
 		for(j=0;j<=2*(m+1);j++)
			map2[i][j] = '#';
	for(i=1;i<=n;i+=2)
 		for(j=1;j<=m;j+=2)
            map[i][j] = ' ';
    tot = ((n+1)/2)*((m+1)/2);
    cur = 1;
    curX = (int)(n);
    curY = (int)(m/2);
    if (curY%2==0) curY++;

    map[0][m] = ' ';
    map[n+1][1] = '.';
    path[cur][0] = curX;
    path[cur][1] = curY;

    while(cur<=tot)
    {
        if(isBlank(curX, curY))
        {
            ok = 0;
            while(!ok)
            {
                r = (int)(4.0*rand()/(RAND_MAX));
                if(test(curX, curY, r))
                {
                    ok = 1;
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
        }
    }

    printf("Start the game!\n");
    printf("Please input W/A/S/D to move:\n");

    map[0][m] = ' ';
    map[n+1][1] = '.';
    print();

    printf("\n");
    for(i=1;i<=n+1;i++)
        for(j=1;j<=m+1;j++)
        {
            tmp = map[i][j];
            map2[2*i][2*j] = tmp;
            map2[2*i-1][2*j] = tmp;
            map2[2*i][2*j-1] = tmp;
            map2[2*i-1][2*j-1] = tmp;
        }

    curX = 2*n+1;
    curY = 1;
    map2[curX][curY] = '.';
    map2[curX][curY+1] = '#';
    map2[0][2*m] = ' ';
    cnt = 0;
    while(cnt<=2)
    {
        rx = (int)((double)(2*n)*rand()/(RAND_MAX))+1;
        ry = (int)((double)(2*m)*rand()/(RAND_MAX))+1;
        if(map2[rx][ry] == ' ' && count(rx,ry)<=2)
        {
            cnt++;
            map2[rx][ry] = '*';
        }
    }
    cnt = 0;
    tot = 0;
    print2();
    while(cnt<=2)
    {
        for(;;)
        {   
            scanf("%c",&mov);
	    getchar();
            if(mov=='w') dir=0;
            if(mov=='d') dir=1;
            if(mov=='s') dir=2;
            if(mov=='a') dir=3;
	    tot++;
            curX += dx[dir];
            curY += dy[dir];
            if(map2[curX][curY]=='#')
            {
                printf("Error!Please choose another direction:\n"); 
                curX -= dx[dir];
                curY -= dy[dir];
                continue;
            }
            else if(map2[curX][curY]==' ')
            {
                map2[curX][curY] = '.';
                map2[curX-dx[dir]][curY-dy[dir]] = ' ';
            }
            else if(map2[curX][curY]=='*')
            {
		if(map2[curX+dx[dir]][curY+dy[dir]] == '#' || map2[curX+dx[dir]][curY+dy[dir]] == '*')
		{
	             printf("Error!Please choose another direction:\n"); 
                     curX -= dx[dir];
                     curY -= dy[dir];
                    continue;
       		}
                map2[curX+dx[dir]][curY+dy[dir]] = '*';
                map2[curX][curY] = '.';
                map2[curX-dx[dir]][curY-dy[dir]] = ' ';
            }
            if(map2[0][2*m] == '*')
            {
                cnt++;
		map2[0][2*m] = ' ';
		printf("You've completed %d box\n",cnt);
		break;
            }
            print2();
	    printf("Step:%d\n",tot);
        }
    }
    printf("You win!\n");
    printf("Your sum of steps is %d\n",tot);
    return 0;
}
