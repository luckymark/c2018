#include <iostream>
using namespace std;
char na[10],nb[10];
double m1,m2,p1,p2,c1,c2;
int main()
{
	scanf("%s",na);
 	scanf("%s",nb);
	cin>>m1>>m2>>p1>>p2>>c1>>c2;
	printf("%10s","NAME");
	printf("%10s","MATH");
	printf("%10s","PHYSICS");
	printf("%10s","CHEMISTRY");
	printf("%10s","SUM");
	printf("%10s","AVERAGE");
	printf("\n");

	printf("%10s",na);
	printf("%10.1f",m1);
	printf("%10.1f",p1);
	printf("%10.1f",c1);
	printf("%10.1f",m1+p1+c1);
	printf("%10.1f",(m1+p1+c1)/3);
	printf("\n");

	printf("%10s",nb);
	printf("%10.1f",m2);
	printf("%10.1f",p2);
	printf("%10.1f",c2);
	printf("%10.1f",m2+p2+c2);
	printf("%10.1f",(m2+p2+c2)/3);
	printf("\n");
} 
