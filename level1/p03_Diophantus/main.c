#include <stdio.h>

int main() {
    for(float FatherAge=1;FatherAge<200;FatherAge++){
        if(FatherAge/6+FatherAge/12+FatherAge/7+5+FatherAge/2+4==FatherAge){
            printf("%f\n",FatherAge-4);
        }
    }
    return 0;
}