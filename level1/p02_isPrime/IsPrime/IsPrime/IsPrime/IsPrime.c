#include<stdio.h>
#include<stdlib.h>
int main(void) {
	unsigned long long TextNumber;
	printf("�������������һ�����ֽ����������(��������Ӧ��ΪС��ULLONG_MAX��������)\n");
	while (scanf_s("%llu", &TextNumber)) {
		unsigned long long flag = 0;
		if (TextNumber <2) 
		{
			printf("%llu �Ȳ�������Ҳ���Ǻ���\n", TextNumber);
			continue;
		}
		for (int i = 2; i*i <= TextNumber; i++)
			if (TextNumber%i == 0)
			{
				flag++;
				break;
			}
		printf("%llu��%s\n", TextNumber, flag ? "����" : "����");
	}
	printf("end!\n");
	system("pause");
	return 0;

}
