#include<stdio.h>
#define N 100
#define M 10
struct node
{
	int v,next;
};
node a[N+1];
int head;
void rotate(){
	int x=0,y=0;
	for (int i=head;i;i=a[i].next)	
		a[y].next=x,x=y,y=i;
	a[y].next=x;
	head=y;
}
int main(){
	srand((int)time(0));
	for (int i=1;i<=N;i++)a[i].v=rand()%M;
	for (int i=1;i<N;i++)a[i].next=i+1;
	head=1;
	rotate();
	for (int i=head;i;i=a[i].next)
		if (a[i].v==5)printf("%d\n",i);
	printf("-1");
	return 0;
}

