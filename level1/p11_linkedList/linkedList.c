#include<stdio.h>
#define N 10000
struct node
{
	int v,next;
}d[N+1];
int head,i,flag=0,n;
void reverse(){
	int tmp=0,v=0;
	for(int i=head;i;i=d[i].next)
	{
		d[v].next = tmp;
		tmp = v;
		v = i;
	}
	d[v].next = tmp;
	head = v;
}
int main(){
	scanf("%d", &n);
	for(i=1;i<=n;i++)
		d[i].v = i;
	for(i=1;i<n;i++)
		d[i].next=i+1;
	head = 1;
	reverse();
	for (int i=head;i;i=d[i].next)
		if (d[i].v == 5)
		{
			flag = 1;
			printf("%d\n",i);
		}
	if(!flag) printf("-1\n");
	return 0;
}


