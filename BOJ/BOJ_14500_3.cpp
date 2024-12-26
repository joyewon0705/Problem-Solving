#include <iostream>

#define N 505

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, ans = 0;
int p[N][N];
bool isVisit[N][N];

void dfs(int x, int y, int cnt, int cur) {

	if (cnt >= 4) {
		if (ans < cur) ans = cur;
		return;
	}

	isVisit[x][y] = true;
	int a[] = { -1, -1, -1, -1 };
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 1 || n < nx || ny < 1 || m < ny) continue;
		if (isVisit[nx][ny]) continue;
		a[k] = p[nx][ny];
		
		dfs(nx, ny, cnt + 1, cur + p[nx][ny]);
	}
	if (cnt == 2) {
		for (int i = 0; i < 4; i++) {
			if (a[i] < 0) continue;
			for (int j = i + 1; j < 4; j++) {
				if (a[j] < 0) continue;
				dfs(0, 0, 4, cur + a[i] + a[j]);
			}
		}
	}
	isVisit[x][y] = false;
}

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &p[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dfs(i, j, 1, p[i][j]);
		}
	}

	printf("%d", ans);

	return 0;
}