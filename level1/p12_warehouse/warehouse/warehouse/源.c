#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#define MAX 40
void SetPos(int x, int y)
{
	COORD pos;
	HANDLE handle;
	pos.X = x;
	pos.Y = y;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}
struct goods
{
	char name[MAX];
	int amount;
};
int main(void)
{
	char ch;
	int n, i, j, sum = 0;
	struct goods NO[MAX];
	FILE *fp;
	fopen_s(&fp, "D:\\zyh-git\\warehouse.txt", "r+");
	if (fp == NULL) {

		printf("fail to open the file");
		system("pause");
		return -1;
	}
START:
	system("cls");
	SetPos(30, 8);
	printf("hello\n");
	SetPos(30, 9);
	puts("1.��ʾ����б�");
	SetPos(30, 10);
	puts("2.���");
	SetPos(30, 11);
	puts("3.����");
	SetPos(30, 12);
	puts("4.�˳�����");


	while (ch = _getch())
	{
		switch (ch)
		{
		case '1':  //��ʾ����б�
			for (i = 0; i < sum; i++)
			{
				int k = 0;
				fscanf_s(fp, "%s %d", NO[i].name, MAX, &NO[i].amount);
				printf("��%d�ֻ��� name=%s amount=%d\n", i + 1, NO[i].name, NO[i].amount);
			}
			fseek(fp, 0, SEEK_SET);
			puts("��ʾ���");
			system("pause");
			goto START;
			goto START;
			break;
		case '2':  //���
			printf("��Ҫ���Ļ�������:\n");
			scanf_s("%d", &n);
			sum = sum + n;
			for (i = sum - n; i < sum; i++)
			{
				printf("����������Ƽ�����\n");
				scanf_s("%s%d", NO[i].name, MAX, &NO[i].amount);
			}
			for (i = sum - n; i < sum; i++)
			{
				fprintf(fp, "%s %d", NO[i].name, NO[i].amount);
			}
			fseek(fp, 0, SEEK_SET);
			puts("������");
			system("pause");
			goto START;
			break;
		case '3':  //����
			printf("�����������Ļ�����\n");
			scanf_s("%d", &i);
			printf("��������������\n");
			scanf_s("%d", &j);
			NO[i - 1].amount = NO[i - 1].amount - j;
			for (i = 0; i < sum; i++)
			{
				fprintf(fp, "%s %d", NO[i].name, NO[i].amount);
			}
			fseek(fp, 0, SEEK_SET);
			goto START;
			break;
		case '4':  //�˳�����
			fclose(fp);
			return 0;
			break;
		default: break;
		}
	}

	system("pause");
	return 0;
}
