#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void wall();
int path(int x, int y);

#define MaxLength 50
#define xLength 11
#define yLength 11
char coordinate[MaxLength + 2][MaxLength + 2] = { 0 };
int c1, c2;

int main() {

	wall();

	for (int i = 0; i <= xLength * 2 + 2; ++i) {
		printf("\n");
		for (int j = 0; j <= yLength * 2 + 2; ++j) {
			if (coordinate[i][j] == 1) {
				printf("  ");
			}
			else {
				printf("* ");
			}
		}
	}

	system("pause");

}

void wall() {

	for (c1 = 0, c2 = yLength * 2 + 2; c1 <= xLength * 2 + 2; ++c1) {
		coordinate[c1][0] = 1;
		coordinate[c1][c2] = 1;
	}
	for (c1 = xLength * 2 + 2, c2 = 0; c2 <= yLength * 2 + 2; ++c2) {
		coordinate[0][c2] = 1;
		coordinate[c1][c2] = 1;
	}

	coordinate[2][1] = 1;
	coordinate[xLength * 2][yLength * 2 + 1] = 1;

	srand((unsigned)time(NULL));
	path(rand() % xLength + 1, rand() % yLength + 1);
}

int path(int x, int y) {
	static int direction[4][2] = { 0,1,1,0,0,-1,-1,0 };
	int cx = x * 2;
	int cy = y * 2;
	coordinate[cx][cy] = 1;
	int turn = rand() % 2 ? 1 : 3;
	int next, i;
	for (i = 0, next = rand() % 4; i < 4; ++i, next = (next + turn) % 4) {
		int x1 = cx + direction[next][0] * 2;
		int y1 = cy + direction[next][1] * 2;
		int x2 = cx + direction[next][0];
		int y2 = cy + direction[next][1];
		int x3 = x + direction[next][0];
		int y3 = y + direction[next][1];
		if (coordinate[x1][y1] == 0) {
			coordinate[x2][y2] = 1;
			path(x3, y3);
		}
	}
	return 0;
}