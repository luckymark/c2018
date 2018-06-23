#include<stdio.h>
#include<stdlib.h>
#define M 20
#include<string.h>
struct node{
	char name[20];
	int num;
}list[1000],u,e;
int tot;
char s[3][20]={"name","sum","empty!"};
void print(char*s){
	int len=strlen(s);
	for (int i=1;i<=M-len;i++)printf(" ");
	printf("%s",s);
}
void printnum(int x){
	int d[100];
	d[0]=0;
	while (x)d[++d[0]]=x%10,x/=10;
	for (int i=1;i<=M-d[0];i++)printf(" ");
	for (int i=d[0];i;i--)printf("%d",d[i]);
}
void draw(){
	printf("\033c");
	printf("Here are the information about the gist:\n");
	if (!tot){
		print(s[0]);
		print(s[1]);
		printf("\n");
		print(s[2]),print(s[2]);
		printf("\n");
	}else{
		print(s[0]);
		print(s[1]);
		printf("\n");
		for (int i=1;i<=tot;i++){
			print(list[i].name);
			printnum(list[i].num);
			printf("\n");
		}
	}
	printf("quit for quit,add for add,dec for decline\n");
	printf("For example:add 3 cola\n");
	printf("Please input you change:");
}
int thesame(char*s,char*s1){
	if (strlen(s)!=strlen(s1))return 0;
	for (int i=strlen(s)-1;i>=0;i--)
		if (s[i]!=s1[i])return 0;
	return 1;
}
void sleep(int x){
	while (x--)
		for (int i=1;i<=1e8;i++);
}
int main(){
	FILE *file=fopen("list","r");
	while(!feof(file)){
		++tot;
		fscanf(file,"%s %d",list[tot].name,&list[tot].num);
	}
	while (tot&&!list[tot].num)tot--;
	fclose(file);
	int bz=0;
	while (1){
		char sig[10];
		if (bz){
			switch(bz){
				case 1:
				printf("Please input a right operation!!\n");
				break;
				case 2:
				printf("%s is less than %d\n",u.name,u.num);
				break;
				case 3:
				printf("%s haven't appeared yet!\n",u.name);
				break;
			}
			printf("quit for quit,add for add,dec for decline\n");
			printf("For example:add 3 cola\n");
			printf("Please input you change:");
		}else
			draw();
		scanf("%s",sig);
		if (sig[0]=='q'&&sig[1]=='u'&&sig[2]=='i'&&sig[3]=='t'&&strlen(sig)==4){
			FILE *file=fopen("list","w");
			for (int i=1;i<=tot;i++)
				fprintf(file,"%s %d\n",list[i].name,list[i].num);
			fclose(file);
			printf("Information has been updated!\n");
			return 0;
		}else
		if (sig[0]=='a'&&sig[1]=='d'&&sig[2]=='d'&&strlen(sig)==3){
			u=e;
			scanf("%d %s",&u.num,u.name);
			int x=tot+1;
			for (int i=1;i<=tot;i++)
				if (thesame(u.name,list[i].name)){
					x=i;
					break;
				}
			u.num+=list[x].num;
			list[x]=u;
			if (x>tot)tot=x;
			printf("Ok!");
			sleep(1);
		}else
		if (sig[0]=='d'&&sig[1]=='e'&&sig[2]=='c'&&strlen(sig)==3){
			u=e;
			scanf("%d %s",&u.num,u.name);
			int x=0;
			for (int i=1;i<=tot;i++)
				if (thesame(u.name,list[i].name)){
					x=i;
					break;
				}
			if (!x){
				bz=3;
				continue;
			}
			if (list[x].num<u.num){
				bz=2;
				continue;
			}
			list[x].num-=u.num;
			if (!list[x].num){
				for (int i=x;i<tot;i++)
				list[i]=list[i+1];
				list[tot]=e;
				tot--;
			}
			printf("Ok!");
			sleep(1);
		}else
			bz=1;
	}
	return 0;
}
