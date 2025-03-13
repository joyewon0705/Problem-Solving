#include <iostream>

#define N 22

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int dice[] = { 2, 1, 5, 6, 4, 3 };

int n, m, k, x, y, d, ans;
int map[N][N], set[N][N], cnt[N * N];

int f(int x, int y) {
	int ret = 0;

	if (set[x][y]) return ret;
	set[x][y] = d;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 1 || n < nx || ny < 1 || m < ny) continue;
		if (map[x][y] != map[nx][ny]) continue;

		ret += f(nx, ny);
	}
	return ret + 1;
}

int main(void) {

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (set[i][j]) continue;
			x = i;
			y = j;
			d++;
			cnt[d] = f(x, y);
		}
	}
	
	x = y = d = 1;
	while (k--) {
		x += dx[d];
		y += dy[d];

		if (x < 1 || n < x || y < 1 || m < y) {
			d = (d + 2) % 4;
			x += 2 * dx[d];
			y += 2 * dy[d];
		}

		int t = dice[1];
		if (d == 0) {
			dice[1] = dice[2]; dice[2] = dice[3];
			dice[3] = dice[0]; dice[0] = t;
		}
		else if (d == 1) {
			dice[1] = dice[4]; dice[4] = dice[3];
			dice[3] = dice[5]; dice[5] = t;
		}
		else if (d == 2) {
			dice[1] = dice[0]; dice[0] = dice[3];
			dice[3] = dice[2]; dice[2] = t;
		}
		else {
			dice[1] = dice[5]; dice[5] = dice[3];
			dice[3] = dice[4]; dice[4] = t;
		}

		ans += map[x][y] * cnt[set[x][y]];

		if (dice[3] > map[x][y]) d = (d + 1) % 4;
		else if (dice[3] < map[x][y]) d = (d + 3) % 4;
	}

	printf("%d", ans);

	return 0;
}