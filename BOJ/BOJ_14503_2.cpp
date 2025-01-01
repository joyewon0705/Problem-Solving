#include <iostream>

#define N 55

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int n, m, r, c, d, ans;
int room[N][N];

int main(void) {

	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &d);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &room[i][j]);
		}
	}

	while (true) {
		
		if (!room[r][c]) {
			room[r][c] = 2;
			ans++;
		}

		bool chk = false;
		for (int k = 3; k >= 0; k--) {
			int nd = (d + k) % 4;
			int nx = r + dx[nd];
			int ny = c + dy[nd];

			if (room[nx][ny]) continue;

			d = nd;
			r = nx; 
			c = ny;
			chk = true;
			break;
		}
		if (chk) continue;

		r -= dx[d];
		c -= dy[d];
		if (room[r][c] == 1) break;
	}

	printf("%d", ans);

	return 0;
}