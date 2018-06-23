#include<stdio.h>
#include<stdlib.h>
int main(){
	int the_age_of_diu=0;
	while (1){
		the_age_of_diu++;
		if (the_age_of_diu%6)continue;
		if (the_age_of_diu%12)continue;
		if (the_age_of_diu%7)continue;
		int childhood=the_age_of_diu/6;
		int youth=the_age_of_diu/12;
		int bachelor=the_age_of_diu/7;
		if (the_age_of_diu<childhood+youth+bachelor+5+4)continue;
		printf("When son was dead,Diu was %d years old.\n",the_age_of_diu-4);
		break;
	}
	return 0;
}
