#include <stdio.h>
#include <windows.h>
#include <conio.h>
int main(void){
	HANDLE handle_out;
	CONSOLE_SCREEN_BUFFER_INFO screen_info;         //���崰�ڻ�������Ϣ�ṹ��     
    int i;
    int length=0;		//���ʵĳ��� 
    bool shuttle=true; 		//������ʾ������ȥ���ǻ� 
    int distance=1;		//��ʾ�ƶ��ĵ��ʵ�λ�� 
    char entity[30];	//��¼�ƶ��ĵ��� 
    scanf("%s",entity);	//��õ���
	length=strlen(entity);	//��õ��ʳ��� 
    while(1){
    	system("cls");
    	for(i=0;i<distance;i++){      //����distance�ĵ���/�ݼ���ÿ�ε��ʳ��ֵ�λ�ø�����/����Ӫ��һ�����ƶ��ļ��� 
    		printf(" ");
		}
		puts(entity);
		Sleep(50);
		if(shuttle)		//�������ȥ��distance���ӣ���֮���� 
			distance++;
		else
		    distance--;
		handle_out = GetStdHandle(STD_OUTPUT_HANDLE);   //��ñ�׼����豸���  
    	GetConsoleScreenBufferInfo(handle_out, &screen_info);   //��ȡ������Ϣ
		if(distance==screen_info.dwSize.X-length)	//������Ļ�ı�Եʱ�ı�״̬ 
			shuttle=false;
		if(distance==0)
			shuttle=true;    
	}
	return 0;
}
