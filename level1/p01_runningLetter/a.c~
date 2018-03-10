#include<stdio.h>
#include<stdlib.h>
#include<sys/ioctl.h>
#include<unistd.h> 
#include<string.h>
char s[100];
int n; 
void Sleep(int x){
	while (x--)
		for (int i=0;i<100000000;i++);
}
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	struct winsize size;
	printf("Input a word:\n");
	scanf(" %s",s);
	n=strlen(s);
	int sig=1;
	int space_length=0;
	while (1){
		printf("\033c");//or system("clear")(flip a page);
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);//size.ws_row,size.ws_col
		space_length=min(space_length,size.ws_col-n);
		for (int i=0;i<space_length;i++)printf(" ");
		printf("%s\n",s);
		if (sig+space_length<0||sig+space_length+n>size.ws_col)sig*=-1;
		space_length+=sig;
		Sleep(1);
	}
	return 0;
}
