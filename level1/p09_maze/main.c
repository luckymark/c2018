//基于Prism生成算法

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stdbool.h"
#include <memory.h>

#define EAST    0
#define SOUTH   1
#define WEST    2
#define NORTH   3

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int isWall;
} Room;


Point currentPoint;//当前位置
Point *stack;
int stackNum;
Room *room;
int WIDTH, HEIGHT;

char getch() {  //无回显getch
    char c;
    system("stty -echo");
    system("stty -icanon");
    c = getchar();
    system("stty icanon");
    system("stty echo");
    return c;
}

void push(int x, int y) {
    stack[stackNum].x = x;
    stack[stackNum].y = y;
    stackNum++;
}

void pop(int x, int y) {
    for (int i = 0; i < stackNum; i++) {
        if (stack[i].x == x && stack[i].y == y) {
            for (int j = i; j < stackNum - 1; j++) { //将该位弹出，后边的续上
                stack[j] = stack[j + 1];
            }
            stack[stackNum - 1].x = stack[stackNum - 1].y = 0;  //末尾清除
            stackNum--;
            return;
        }
    }
}

void printMaze() {
    system("clear");//clear scr
    //printf("\33[2J"); clear scr with bugs......
    for (int i = 1; i < HEIGHT + 1; i++) {
        for (int j = 1; j < WIDTH + 1; j++) {
            if (currentPoint.x == j && currentPoint.y == i) {
                printf("$");
                continue;
            }
            printf(room[getCood(j, i)].isWall == true ? "@" : " ");
        }
        printf("\n");
    }
}

int isOk(int x, int y) {  //是否被墙包围，即没有被访问过
    if (room[getCood(x - 1, y)].isWall == true &&
        room[getCood(x + 1, y)].isWall == true &&
        room[getCood(x, y + 1)].isWall == true &&
        room[getCood(x, y - 1)].isWall == true) {
        return true;
    }
    return false;
}

int randomChooseNB(int x, int y) {
    int result[5] = {0};

    if ((x - 2 >= 2) && (isOk(x - 2, y) == true)) {
        result[0]++;
        result[result[0]] = WEST;
    }
    if ((x + 2 <= WIDTH - 1) && (isOk(x + 2, y) == true)) {
        result[0]++;

        result[result[0]] = EAST;
    }
    if ((y - 2 >= 2) && (isOk(x, y - 2) == true)) {
        result[0]++;
        result[result[0]] = NORTH;
    }
    if ((y + 2 <= HEIGHT - 1) && (isOk(x, y + 2) == true)) {
        result[0]++;
        result[result[0]] = SOUTH;
    }
    if (result[0] == 0)
        return -1;
    return result[getRand(1, result[0])];
}


Point randomChooseFromStack() {
    return stack[getRand(0, stackNum - 1)];
}


int getRand(int a, int b) {   //返回从a到b区间内的一个随机数，包括a、b
    srand(time(NULL));
    return (rand() % (b - a + 1)) + a;
}

int getCood(int x, int y) {
    return (y - 1) * WIDTH + x - 1;
}

void generateMaze(int width, int height) {
    WIDTH = (2 * width + 1);
    HEIGHT = (2 * height + 1);

    stack = malloc(width * height * sizeof(Point));
    stackNum = 0;

    int size = WIDTH * HEIGHT;
    room = malloc(size * sizeof(Room));
    memset(room, 0, size * sizeof(Room));
    for (int i = 1; i < height + 1; i++) {
        for (int j = 1; j < WIDTH + 1; j++) {
            room[getCood(j, i * 2 - 1)].isWall = true;  //单数行全部设置成墙壁
            room[getCood(j, i * 2)].isWall = j % 2 == 1 ? true : false;    //偶数则间隔设置
        }
    }
    for (int j = 1; j < WIDTH + 1; j++)
        room[getCood(j, HEIGHT)].isWall = true;  //最后一行全为墙壁

    push(2, 2);//左上角第一个房间入栈
    while (stackNum) {
        Point pt = randomChooseFromStack();
        int direction = randomChooseNB(pt.x, pt.y);
        if (direction == -1) {
            pop(pt.x, pt.y);
        } else {
            switch (direction) {
                case WEST:
                    room[getCood(pt.x - 1, pt.y)].isWall = false;
                    push(pt.x - 2, pt.y);
                    break;
                case NORTH:
                    room[getCood(pt.x, pt.y - 1)].isWall = false;
                    push(pt.x, pt.y - 2);
                    break;
                case SOUTH:
                    room[getCood(pt.x, pt.y + 1)].isWall = false;
                    push(pt.x, pt.y + 2);
                    break;
                case EAST:
                    room[getCood(pt.x + 1, pt.y)].isWall = false;
                    push(pt.x + 2, pt.y);
                    break;
                default:
                    break;
            }
        }
    }
    room[getCood(WIDTH, HEIGHT - 1)].isWall = false;


}

int keyLoop() {
    bool dontPrint;
    while (1) {
        switch (getch()) {
            case 0x1b:
                switch (getch()) {
                    case 0x5b:
                        dontPrint = false;
                        switch (getch()) {
                            case 0x41://north
                                if (room[getCood(currentPoint.x, currentPoint.y - 1)].isWall == false) {
                                    currentPoint.y -= 1;
                                }
                                break;
                            case 0x42://south
                                if (room[getCood(currentPoint.x, currentPoint.y + 1)].isWall == false) {
                                    currentPoint.y += 1;
                                }
                                break;
                            case 0x43://east
                                if (room[getCood(currentPoint.x + 1, currentPoint.y)].isWall == false) {
                                    currentPoint.x += 1;
                                }
                                break;
                            case 0x44://west
                                if (room[getCood(currentPoint.x - 1, currentPoint.y)].isWall == false) {
                                    currentPoint.x -= 1;
                                }
                                break;
                            default:
                                dontPrint = true;
                        }
                        if (dontPrint == false) {
                            printMaze();
                            if (currentPoint.x == WIDTH && currentPoint.y == HEIGHT - 1) {
                                printf("\n\nCongratulations!~\n");
                                free(room);
                                free(stack);
                                return 0;
                            }
                        }
                        break;
                    case 0x1b:
                        free(room);
                        free(stack);
                        return 0;
                }
                break;
            default:
                break;
        }
    }
}

int main() {
    generateMaze(20, 10);
    currentPoint.x = currentPoint.y = 2;
    printMaze();
    keyLoop();
}
