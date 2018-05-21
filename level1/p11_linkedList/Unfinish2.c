#include<stdio.h>
#include<malloc.h>
int* ptr = NULL;
static int count = 0;
void insert(data){
	if (ptr == NULL) {
		ptr = (int*)malloc(sizeof(int));
		ptr[0] = data;
	}
	else {
		ptr = (int*)realloc(ptr, sizeof(int)*(count + 1));
		ptr[count] = data;
	}
	count++;
}
void show() {
	int i = 0;
	for (i = 0; i < count; i++) {
		printf("%d\n", ptr[i]);
	}
}
int main(int argc, char*argv[]) {
	int c = 0;
	int data;
	while (1)
	{
		printf("choice");
		printf("1 is to insert data\n");
		printf("2 is to show data.\n");
		printf("3 is to quit\n ");
		scanf("%d\n", &c);
		switch (c) {
		case 1:
			printf("date=");
			scanf("%d\n", &data);
			insert(data);
			break;
		case 2:
			show();
			break;
		case 3:
			exit(0);
		}
	}
	return 0;
	getchar();
}
  //Á´±í2£¿emmm´ý¶¨