#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

    int a;

    scanf ("%d",&a);

    if (a>0) printf ("yes"); else printf ("no");//�ж��Ƿ�Ϊ����

    if (a%2==0) printf ("yes");else printf ("no");//�ж��Ƿ�Ϊż��

    if (a>=13 && a%13==0) printf("yes");else printf ("no");//�ж��Ƿ�Ϊ13����

    if (a%4==0 && a%100!=0 || a%400==0) printf("yes");else printf ("no");//�ж��Ƿ�Ϊ����
    
    int b[20],n,i,p;

    for(i=0;i<n;i++) scanf ("%d",&b[i]);

    for(i=1;i<n;i++){

       if (b[0]<b[i]) b[0]=b[i];}

       printf("%d",b[0]);//�ҳ�n�����е������  

	return 0;
}
