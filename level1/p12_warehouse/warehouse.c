#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct goods
{
	char name[20];
	int num;
}list[10010],t;
int tot,mark,n,i,j,cnt;
char cmd[10];

int cmp(char*s1, char*s2)
{
	if(strlen(s1)!=strlen(s2))
		return 0;
	for(int i=strlen(s1)-1;i>=0;i--)
		if(s1[i]!=s2[i])
			return 0;
	return 1;
}

void showGoodsList()
{
	system("clear");
	printf("Goods list:\n");
	printf("%10s", "GoodsName");
	printf("%10s", "GoodsNum");
	printf("\n");
	for(int i=1;i<=tot;i++)
	{
		printf("%10s", list[i].name);
		printf("%10d  ",list[i].num);
		printf("\n");
	}
	return;
}

int main()
{
	FILE *file = fopen("goodsList","r");
	while(!feof(file))
	{
		tot++;
		fscanf(file,"%s %d",list[tot].name,&list[tot].num);
	}
	while(tot && list[tot].num)
		tot--;
	tot--;
	fclose(file);

	for(;;)
	{
		printf("Please input your order:\n");
		printf("2:Show the current goods list, 3:Import goods, 4:Export goods, 5:Save the data and exit.\n");
		printf("You may enter the command like this: 2 / 3 goodsName goodsNum / 4 goodsName goodsNum / 5.\n");
		printf("Please input you command:\n");

		scanf("%s",cmd);
		if(cmd[0] == '2')
		{
			showGoodsList();
			continue;
		}
		else if(cmd[0] == '3')
		{
			scanf("%s %d", t.name, &t.num);
			mark = tot+1;
			for(i=1;i<=tot;i++)
				if(cmp(t.name,list[i].name))
				{
					mark = i;
					break;
				}
			t.num += list[mark].num;
			list[mark] = t;
			if(mark>tot) tot=mark;
		}
		else if(cmd[0] == '4')
		{
			scanf("%s %d", t.name, &t.num);
			mark=0;
			for(i=1;i<=tot;i++)
				if(cmp(t.name,list[i].name))
				{
					mark=i;
					break;
				}
			if(!mark || list[mark].num<t.num)
			{
				printf("Error!\n");
				continue;
			}
			else 
				list[mark].num-=t.num;
			if(!list[mark].num)
			{
				for(i=mark;i<tot;i++)
					list[i]=list[i+1];
				tot--;
			}
		}
		else if(cmd[0] == '5')
		{
			FILE *file=fopen("goodsList","w");
			for(i=1;i<=tot;i++)
				fprintf(file,"%s %d\n",list[i].name,list[i].num);
			fclose(file);
			printf("Data has been saved and the program will abort.\n");
			return 0;
		}
		else
			printf("Error!");
	}
	return 0;
}