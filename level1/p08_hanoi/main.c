#include <stdio.h>

//id从小到大代表从上到下
void Do(int id, int from, int buffer, int dst) {
    if (id == 1) {
        printf("%d号 柱%d->柱%d\n", id, from, dst);
    } else {
        Do(id - 1, from, dst, buffer);
        printf("%d号 柱%d->柱%d\n", id, from, dst);
        Do(id - 1, buffer, from, dst);
    }
}

int main() {
    int number = 10;//盘子的数量
    Do(number, 1, 2, 3);
    return 0;
}