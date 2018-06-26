#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct film
{
	char  title[45];
	int rating;
}  ITEM;
typedef struct node
{
	ITEM film;
	int xuhao;
	struct node*next;
} NODE;
char * s_gets(char*st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
int main(void)
{
	int i = 1;
	char input[45];
	NODE * head = NULL;
	NODE * prev, *current, *m;

	puts("enter movie's name");

	while (s_gets(input, 45) != NULL && input[0] != '\0')
	{
		current = (struct node*) malloc(sizeof(struct node));
		if (head == NULL)
			head = current;
		else
			prev->next = current;
		current->next = NULL;
		strcpy_s(current->film.title, strlen(input) + 1, input);
		current->xuhao = i++;
		puts("enter your rating");
		scanf_s("%d", &current->film.rating);
		while (getchar() != '\n')
			continue;
		puts("enter next movie's name(empty to stop)");
		prev = current;

	}


	/*打印电影名单*/
	puts("here is the movies:");
	current = head;
	while (current != NULL)
	{

		printf("第%d部movis:  %s rating:  %d\n", current->xuhao, current->film.title, current->film.rating);
		current = current->next;
	}

	printf("\n\n\n");
	/*将链表反序*/

	prev = head;
	current = prev->next;
	m = current->next;
	prev->next = NULL;
	current->next = prev;
	while (m != NULL)
	{
		prev = current;
		current = m;
		m = current->next;
		current->next = prev;
	}
	head = current;


	/*打印电影名单*/
	puts("here is the movies2:");
	current = head;
	while (current != NULL)
	{

		printf("第%d部movis:  %s rating:  %d\n", current->xuhao, current->film.title, current->film.rating);
		current = current->next;
	}

	/*查找值为五的节点*/
	current = head;
	while (current != NULL)
	{
		if (current->film.rating == 5)
			printf("%d\n", current->xuhao);
		else
			printf("%d\n", -1);
		current = current->next;
	}


	current = head;
	while (head != NULL)
	{
		current = head;
		head = current->next;
		free(current);
	}
	system("pause");
	return 0;
}