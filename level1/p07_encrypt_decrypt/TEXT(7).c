#include<stdio.h>
#include<string.h>
#include<string.h>
int main() {

	int i, j, k, num, num1;
	char a1[30], a2[30];
	printf("��ѡ������:\n1.����\t 2.����\n");
	scanf("%d", &num);
	    if (num = 1) {
	
			printf("����������ı�:");
			int num1 = 0;
			int len;
			scanf("%d",&a1);
			len = strlen(a1);
			printf("�����ƶ�λ��:");
			scanf("%d", num1);
		for (i = 0; i < len; i++) {
				if (a1[i] >= 'A'&&a1[i] <= 'Z')
				{
					a1[i] = (a1[i] - 'A' + num1) % 26 + 'A';
				}
				else if (a1[i] >= 'a'&&a1[i] <= 'z')
				{
					a1[i] = (a1[i] - 'a' + num1) % 26 + 'a';
				}
				
			}
			printf("������ܽ��:%c", a1);
			printf("\n");
		}
	if (num = 2) {
		printf("����������ı�:");
		int len,num1;
		scanf("%d", &a1);
		len = strlen(a1);
		for (num1 = 0; num1 < 26;num1++) {
			for (i = 0; i < len; i++) {
				if (a1[i] >= 'A'&&a1[i] <= 'Z')
				{
					a1[i] = (a1[i] - 'A' + num1) % 26 + 'A';
				}
				else if (a1[i] >= 'a'&&a1[i] <= 'z')
				{
					a1[i] = (a1[i] - 'a' + num1) % 26 + 'a';
				}

			}
			printf("������ܽ��:%c",a1);
			system("pause");
			printf("\n");

		}
		}
	getchar();
	return 0;
	}

#define MAX 30
/*int main() {
char P[MAX] = { 0 };
printf("������������ı�:");
scanf("%d", &P);
int len, i, j, k, temp,num = 0;
len = strlen(P);
int A1[1][MAX] = { 0 }, A2[1][MAX] = { 0 };
int t1[MAX] = { 0 }, t2[MAX] = { 0 };
printf("�������ܳ�:\n");
for (i = 0; i < len; i++) {
for (j = 0; j < len; j++) {
scanf("%d", &A1[i][j]);
printf("�ܳ�Ϊ:%s", A1);
}
}

printf("��ѡ������:\n1.����\t 2.����\n");
scanf("%d", &num);
if (num = 1) {
for (i = 0; i < len; i++) {
if (P[i] >= 'A'&&P[i] <= 'Z') {
P[i] = P[i] +32;
t1[i] = P[i] - 'a';
}
}
for (i = 0; i < len; i++) {
for (j = 0; j < len; j++) {
temp = 0;
for (k = 0; k < len; k++) {
temp+= t1[k] * A1[k][j];
}
A2[i][j] = temp;
printf("%d\t", A2[i][j]);
}
printf("%d\n");
}
printf("%d", A2);
for (i = 0; i < len; i++) {
t2[i] = A2[i] + 'a';
}
printf("���ܽ��Ϊ:%d", t2[i]);
system("pause");
}
return 0;
}*/   //emmmmm��debug