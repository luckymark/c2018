#include <stdio.h>

int IsPrime(int number) {
    for (int i = 2; i < number; i++) {
        if (number % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int number;
    scanf("%d", &number);
    if (IsPrime(number))
        printf("Prime.\n");
    else
        printf("Not prime.\n");
    return 0;
}