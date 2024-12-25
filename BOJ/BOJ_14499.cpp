#include <iostream>

#define N 22

int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };

int n, m, x, y, k, d;
int map[N][N], dice[7] = { 0 };

void moveDice() {
	int tmp = dice[1];

	switch (d) {
		case 1:
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = tmp;
			break;
		case 2:
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = tmp;
			break;
		case 3:
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = tmp;
			break;
		case 4:
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = tmp;
			break;
	}
}

int main(void) {

	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < k; i++) {
		scanf("%d", &d);

		x += dx[d];
		y += dy[d];

		if (x < 0 || n <= x || y < 0 || m <= y) {
			x -= dx[d];
			y -= dy[d];
			continue;
		}

		moveDice();

		if (map[x][y]) {
			dice[6] = map[x][y];
			map[x][y] = 0;
		}
		else {
			map[x][y] = dice[6];
		}

		printf("%d\n", dice[1]);
	}

	return 0;
}