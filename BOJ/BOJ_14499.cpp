#include <iostream>

#define N 22
int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };

int n, m, x, y, k, d, cur;
int map[N][N], dice[4][3];

int main(void) {

	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < k; i++) {
		scanf("%d", &d);

		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 0 || n <= nx || ny < 0 || m <= ny) continue;

		int tmp;
		switch (d) {
			case 1:
				tmp = dice[1][0];
				dice[1][0] = dice[3][1];
				dice[3][1] = dice[1][2];
				dice[1][2] = dice[1][1];
				dice[1][1] = tmp;
				break;
			case 2:
				tmp = dice[1][2];
				dice[1][2] = dice[3][1];
				dice[3][1] = dice[1][0];
				dice[1][0] = dice[1][1];
				dice[1][1] = tmp;
				break;
			case 3:
				tmp = dice[2][1];
				dice[2][1] = dice[3][1];
				dice[3][1] = dice[0][1];
				dice[0][1] = dice[1][1];
				dice[1][1] = tmp;
				break;
			case 4:
				tmp = dice[0][1];
				dice[0][1] = dice[3][1];
				dice[3][1] = dice[2][1];
				dice[2][1] = dice[1][1];
				dice[1][1] = tmp;
				break;
		}

		if (map[nx][ny]) {
			dice[3][1] = map[nx][ny];
			map[nx][ny] = 0;
		}
		else {
			map[nx][ny] = dice[3][1];
		}

		x = nx; 
		y = ny;

		printf("%d\n", dice[1][1]);
	}

	return 0;
}