#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

_Bool select_mode(void);
_Bool show_list(void);
_Bool storage(void);
_Bool outbound(void);

struct goods {
	int id;
	char name[30];
	int number;
}good;
_Bool error = 0;

int main()
{
	system("mode con cols=50 lines=20");
	select_mode();
}

_Bool select_mode(void)
{
	int mode;
re_input:
	system("cls");
	for (int i = 0; i < 50; i++)
	{
		printf("*");
	}
	for (int i = 0; i < 21; i++)
	{
		printf(" ");
	}
	printf("选择模式\n");

	for (int i = 0; i < 50; i++)
	{
		printf("*");
	}
	printf("\n1.显示存货列表.\n");
	printf("2.入库\n");
	printf("3.出库\n");
	printf("4.退出程序");
	scanf("%d",&mode);
	switch (mode)
	{
	case 1:
		show_list();
		system("pause");
		break;
	case 2:
		storage();
		break;
	case 3:
		outbound();
		break;
	case 4:
		return 1;
	default:
		printf("错误的输入\n请尝试正确的输入\n");
		system("pause");
	}
	goto re_input;
}

_Bool show_list(void)
{
	system("cls");
	FILE *list;
	list = fopen("goods_list.dat", "rb");
	if (list == NULL)
	{
		return 1;
	}
	printf("\tID");
	printf("\t名称");
	printf("\t数量\n");
	while (fread(&good, sizeof(struct goods), 1, list) != 0)
	{
		printf("\t%d", good.id);
		printf("\t%s", good.name);
		printf("\t%d\n", good.number);
	}
	fclose(list);
	return 0;
}

_Bool storage(void)
{
	int id;
	char mode;
	FILE *list;
input_more:
	system("cls");
	show_list();
	printf("1.向存货列表中添加新的货物。\n");
	printf("2.添加存货数量.\n");
	printf("按r返回上级菜单.\n");
	good.id = 0;
	scanf("%c",&mode);
	switch (mode)
	{
	case '1':
		printf("请输入货物id:\n");
		scanf("%d", &good.id);
		printf("请输入货物名称:\n");
		scanf("%s", &good.name);
		printf("请输入货物数量:\n");
		scanf("%d", &good.number);
		list = fopen("goods_list.dat", "rb+");
		if (list == NULL)
		{
			return 1;
		}
		fseek(list,0,2);
		fwrite(&good, sizeof(struct goods), 1, list);
		fclose(list);
		break;
	case '2':
		printf("请输入货物id以增加货物数量:\n");
		scanf("%d", &id);
		list = fopen("goods_list.dat", "rb+");
		while(fread(&good, sizeof(struct goods), 1, list) != 0)
		{
			if (good.id = id)
			{
				int add_num=0;
				printf("\t%d\t%s\t%d\n",good.id, good.name, good.number);
				printf("请输入增量:\n");
				scanf("%d", &add_num);
				good.number += add_num;
				fseek(list, -(int)sizeof(struct goods), 1);
				fwrite(&good, sizeof(struct goods), 1, list);
				fclose(list);
				break;
			}
		}
		break;
	case 'r':
		return 0;
	}
	goto input_more;
}
_Bool outbound(void)
{
	system("cls");
	int id;
	FILE *list;
input_more:
	good.id = 0;
	list = fopen("goods_list.dat", "rb+");
	if (list == NULL)
	{
		return 1;
	}
	show_list();
	printf("按r返回上级菜单.\n");
	printf("请输入存货id:\n");
	scanf("%d", &id);
	while(fread(&good, sizeof(struct goods), 1, list) != 0)
	{
		if (good.id == id)
		{
			int jian_num = 0;
			printf("\t%d\t%s\t%d\n", good.id, good.name, good.number);
			printf("请输入减少量:\n");
			scanf("%d", &jian_num);
			good.number -= jian_num;
			fseek(list, -(int)sizeof(struct goods), 1);
			fwrite(&good, sizeof(struct goods), 1, list);
			fclose(list);
			break;
		}
	}
	goto input_more;
}