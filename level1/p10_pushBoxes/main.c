//linux下编写，请将level1-4以及score.data文件拷贝至工作目录

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


#define PERSON  4
#define WALL    5
#define BOX     6
#define DEST    7
#define FREE    0

#define NORTH   7
#define SOUTH   8
#define WEST    9
#define EAST    10

typedef struct {
    int x;
    int y;
} Point;

Point cp;//当前位置
char *room;
Point *dest;//记录目标位置
int destIp = 0;
int steps = 0;//步数
int currentLevel;
int WIDTH, HEIGHT;
int Status = 0;   //0->not win    1->win

int getCoord(int x, int y) {
    return (y - 1) * WIDTH + x - 1;
}

char getch() {  //无回显getch
    char c;
    system("stty -echo");
    system("stty -icanon");
    c = getchar();
    system("stty icanon");
    system("stty echo");
    return c;
}

void Move(int Direction) {
    switch (Direction) {
        case NORTH:
            if (room[getCoord(cp.x, cp.y - 1)] == FREE) {
                //往上走，没有墙没有box
                room[getCoord(cp.x, cp.y - 1)] = PERSON;
                room[getCoord(cp.x, cp.y)] = FREE;
                cp.y--;
                steps++;
            } else if (room[getCoord(cp.x, cp.y - 1)] == BOX && room[getCoord(cp.x, cp.y - 2)] == FREE) {
                //上面有box且box上面没有墙

                room[getCoord(cp.x, cp.y - 2)] = BOX;
                room[getCoord(cp.x, cp.y - 1)] = PERSON;
                room[getCoord(cp.x, cp.y)] = FREE;
                cp.y--;
                steps++;
            }
            break;
        case SOUTH:
            if (room[getCoord(cp.x, cp.y + 1)] == FREE) {

                room[getCoord(cp.x, cp.y + 1)] = PERSON;
                room[getCoord(cp.x, cp.y)] = FREE;
                cp.y++;
                steps++;
            } else if (room[getCoord(cp.x, cp.y + 1)] == BOX && room[getCoord(cp.x, cp.y + 2)] == FREE) {

                room[getCoord(cp.x, cp.y + 2)] = BOX;
                room[getCoord(cp.x, cp.y + 1)] = PERSON;
                room[getCoord(cp.x, cp.y)] = FREE;
                cp.y++;
                steps++;
            }
            break;
        case WEST:
            if (room[getCoord(cp.x - 1, cp.y)] == FREE) {
                room[getCoord(cp.x - 1, cp.y)] = PERSON;
                room[getCoord(cp.x, cp.y)] = FREE;
                cp.x--;
                steps++;
            } else if (room[getCoord(cp.x - 1, cp.y)] == BOX && room[getCoord(cp.x - 2, cp.y)] == FREE) {

                room[getCoord(cp.x - 2, cp.y)] = BOX;
                room[getCoord(cp.x - 1, cp.y)] = PERSON;
                room[getCoord(cp.x, cp.y)] = FREE;
                cp.x--;
                steps++;
            }
            break;
        case EAST:
            if (room[getCoord(cp.x + 1, cp.y)] == FREE) {

                room[getCoord(cp.x + 1, cp.y)] = PERSON;
                room[getCoord(cp.x, cp.y)] = FREE;
                cp.x++;
                steps++;
            } else if (room[getCoord(cp.x + 1, cp.y)] == BOX && room[getCoord(cp.x + 2, cp.y)] == FREE) {
                room[getCoord(cp.x + 2, cp.y)] = BOX;
                room[getCoord(cp.x + 1, cp.y)] = PERSON;
                room[getCoord(cp.x, cp.y)] = FREE;
                cp.x++;
                steps++;
            }
            break;
    }

    display();
}

void keyLoop() {
    while (1) {
        switch (getch()) {
            case 0x1b:
                switch (getch()) {
                    case 0x5b:
                        switch (getch()) {//响应方向键需要检测三次输入
                            case 0x41://north
                                Move(NORTH);
                                break;
                            case 0x42://south
                                Move(SOUTH);
                                break;
                            case 0x43://east
                                Move(EAST);
                                break;
                            case 0x44://west
                                Move(WEST);
                                break;
                            default:
                                break;
                        }
                        if (isWin() == 1) {
                            printf("\n\nYou win, Congratulations~\n");
                            saveScoreboard();
                            return;
                        }
                        break;
                    case 0x1b:
                        return;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
}

int isDest(int x, int y) {
    int i = 0;
    do {
        if (dest[i].x == x && dest[i].y == y) {
            return 1;
        }
        i++;
    } while (dest[i].x != 0 && dest[i].y != 0);
    return 0;
}

void display() {
    system("clear");
    printf("Level%d, Current step(s): %d\n\n", currentLevel + 1, steps);
    for (int y = 1; y < HEIGHT + 1; y++) {
        for (int x = 1; x < WIDTH + 1; x++) {
            if (isDest(x, y) == 1 && room[getCoord(x, y)] == FREE) {
                printf(".");
            } else {
                switch (room[getCoord(x, y)]) {
                    case BOX:
                        printf("B");
                        break;
                    case FREE:
                        printf(" ");
                        break;
                    case PERSON:
                        cp.x = x;
                        cp.y = y;
                        printf("O");
                        break;
                    case WALL:
                        printf("@");
                        break;
                    default:
                        break;
                }
            }
        }
        printf("\n");
    }
}

int isWin() {
    int i = 0;
    do {
        if (room[getCoord(dest[i].x, dest[i].y)] != BOX) {
            //目标位置有没有放置好的
            return 0;
        }
        i++;
    } while (dest[i].x != 0 && dest[i].y != 0);
    return 1;
}

//mapdata:
//width height room1 room2 room3 room4 room5 room6 ......
void loadMaps() {
    char map_path[4][20] = {"./level1.map", "./level2.map", "./level3.map", "./level4.map"};

    FILE *file = fopen(map_path[currentLevel], "rb+");
    if (file == NULL) {
        printf("I'm sorry, but where is my mapdata \"%s\" ?\r\n", map_path[currentLevel]);
        return;
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (size <= 2) {
        printf("Invalid mapdata. Size: %d\r\n", size);
        return;
    }

    char *mapdata = malloc(size);
    memset(mapdata, 0, size);
    fread(mapdata, size, 1, file);
    fclose(file);

    memcpy(&WIDTH, mapdata, 4);
    memcpy(&HEIGHT, mapdata + 4, 4);

    if (WIDTH * HEIGHT != (size - 2 * 4)) {
        printf("Invalid mapdata.\r\n");
        return;
    }

    room = malloc(WIDTH * HEIGHT);
    dest = malloc(WIDTH * HEIGHT * sizeof(Point));
    destIp = 0;
    memset(room, 0, WIDTH * HEIGHT);
    memset(dest, 0, WIDTH * HEIGHT * sizeof(Point));

    memcpy(room, mapdata + 8, WIDTH * HEIGHT);

    for (int y = 1; y < HEIGHT + 1; y++) {
        for (int x = 1; x < WIDTH + 1; x++) {
            if (room[getCoord(x, y)] == DEST) {
                room[getCoord(x, y)] = FREE;
                dest[destIp].x = x;
                dest[destIp].y = y;
                destIp++;
            }

        }
    }
    dest[destIp].x = dest[destIp].y = 0;

    display();
}

void saveScoreboard() {
    FILE *fd;
    fd = fopen("./score.data", "rb+");
    if (fd == NULL) {
        printf("I'm sorry, but where is the scoreBoard data file (score.data) ?\n");
        return;
    }

    char score[16] = {0};
    fread(score, 16, 1, fd);
    fclose(fd);

    fd = fopen("./score.data", "wb+");
    if (((int *) score)[currentLevel] > steps ||
        !((int *) score)[currentLevel]) {
        ((int *) score)[currentLevel] = steps;
        printf("New record for level%d: %d steps.\n\n", currentLevel + 1, steps);
    }

    fwrite(&score, 16, 1, fd);
    fclose(fd);
}

void printScoreboard() {
    FILE *fd;
    fd = fopen("./score.data", "rb+");
    if (fd == NULL) {
        printf("I'm sorry, but where is the scoreBoard data file (score.data) ?\n\n");
        return;
    }
    char score[16] = {0};
    fread(score, 16, 1, fd);
    fclose(fd);
    printf("-----Score Board-----\n");
    for (int i = 0; i < 4; i++) {
        printf("level%d: %d steps\n", i + 1, ((int *) score)[i]);
    }

    printf("\nPress 'c' to clean score board or other keys to continue.\n");
    getch();
    if (getch() == 'c') {
        char score[16] = {0};
        fd = fopen("./score.data", "wb+");
        fwrite(&score, 16, 1, fd);
        fclose(fd);
        printf("Cleared.\n");
    }
}

//下面的东西是方便把画的迷宫转化成转化文件
void printData(char *string) {
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        switch (string[i]) {
            case '#':
                printf("5,");
                break;
            case 'B':
                printf("6,");
                break;
            case 'O':
                printf("4,");
                break;
            case '.':
                printf("7,");
                break;
            case ' ':
                printf("0,");
                break;
        }
    }
}

int main() {
    int key;
    system("clear");
    printf("Welcome to pushBox game ~\n");

    while (1) {
        printf("\n游戏中按esc两次返回主菜单\nPlease choose a mode:\n0.Score board.\n1.level1.\n2.level2\n3.level3.\n4.level4.\n\n");
        if (scanf("%d", &key) != 0) {
            if (key == 0) {
                system("clear");
                printScoreboard();
            } else if (key > 0 && key < 5) {
                steps = 0;
                currentLevel = key - 1;
                loadMaps();
                keyLoop();
            } else {
                printf("Hello my friend? What did you say?\n\n");
            }
        } else {
            printf("Hello my friend? What did you say?\n\n");
            char clearStdin[100];
            scanf("%s", clearStdin);
        }

    }
    //下面的东西是方便把画的迷宫转化成转化文件，和游戏无关
    /*char ff[]={12,0,0,0,12,0,0,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,7,7,7,7,5,5,5,5,4,5,5,7,7,7,7,7,5,5,0,0,0,0,5,7,0,0,0,7,5,5,0,6,6,0,5,0,0,0,0,0,5,5,0,0,6,6,5,5,5,0,5,5,5,5,0,0,6,0,0,6,0,0,0,0,5,5,0,0,0,6,0,0,6,0,5,0,5,5,0,0,0,6,6,6,5,5,5,0,5,5,0,0,5,0,6,0,5,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,5,5};
    FILE *fd;
    fd=fopen("./level4.map","wb+");
    fwrite(ff,sizeof(ff),1,fd);
    fclose(fd);*/

    /*char tmp[1000]={0};
    do{
    fread(tmp,145,1,stdin);
    printData(tmp);}while(1);*/
    return 0;
}