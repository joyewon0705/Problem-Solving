#include <iostream>
#include <cstring>
using namespace std;

#define N 55

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int r, c, t, p, ans;
int map[N][N], add[N][N];

void f(int x, int y, int d, int t) {

	while (true) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		switch (t) {
			case 0:
				if (nx < 1 || p - 1 < nx || ny < 1 || c < ny) {
					d = (d + 1) % 4;
					continue;
				}
				break;
			case 1:
				if (nx < p || r < nx || ny < 1 || c < ny) {
					d = (d + 3) % 4;
					continue;
				}
				break;
		}
		if (map[nx][ny] == -1) {
			map[x][y] = 0;
			break;
		}

		map[x][y] = map[nx][ny];
		x = nx; y = ny;
	}
}

int main(void) {

	scanf("%d %d %d", &r, &c, &t);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == -1) p = i;
		}
	}

	while (t--) {

		memset(add, 0, sizeof(add));
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx < 1 || r < nx || ny < 1 || c < ny) continue;
					if (map[nx][ny] < 0) continue;

					add[nx][ny] += map[i][j] / 5;
					cnt++;
				}
				map[i][j] -= (map[i][j] / 5) * cnt;
			}
		}
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				map[i][j] += add[i][j];
			}
		}

		f(p - 2, 1, 3, 0);
		f(p + 1, 1, 1, 1);
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			ans += map[i][j];
		}
	}
	printf("%d", ans + 2);

	return 0;
}