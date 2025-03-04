#include <iostream>

#define N 505

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int n, x, y, d, cnt, ans;
int a[N][N];

void scatter(int x, int y, int v) {

	if (x < 1 || n < x || y < 1 || n < y) ans += v;
	else if (a[x][y] > -1) a[x][y] += v;
	cnt += v;
}

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	d = 3;
	x = y = n / 2 + 1;
	a[x][y] = -1;
	while (x != 1 || y != 1) {
		int nx, ny, amt;
		
		nx = x + dx[(d + 1) % 4];
		ny = y + dy[(d + 1) % 4];
		if (a[nx][ny] < 0) {
			nx = x + dx[d];
			ny = y + dy[d];
		}
		else d = (d + 1) % 4;

		cnt = 0;
		amt = a[nx][ny];
		a[nx][ny] = 0;
		if (d % 2) {
			scatter(x, y - 1, amt * 0.01); scatter(x, y + 1, amt * 0.01);
			scatter(nx, ny - 1, amt * 0.07); scatter(nx, ny + 1, amt * 0.07);
			scatter(nx, ny - 2, amt * 0.02); scatter(nx, ny + 2, amt * 0.02);
			scatter(nx + dx[d], ny - 1, amt * 0.1); scatter(nx + dx[d], ny + 1, amt * 0.1);
			scatter(nx + 2 * dx[d], ny, amt * 0.05);
			amt -= cnt;
			scatter(nx + dx[d], ny, amt);
		}
		else {
			scatter(x - 1, y, amt * 0.01); scatter(x + 1, y, amt * 0.01);
			scatter(nx - 1, ny, amt * 0.07); scatter(nx + 1, ny, amt * 0.07);
			scatter(nx - 2, ny, amt * 0.02); scatter(nx + 2, ny, amt * 0.02);
			scatter(nx - 1, ny + dy[d], amt * 0.1); scatter(nx + 1, ny + dy[d], amt * 0.1);
			scatter(nx, ny + 2 * dy[d], amt * 0.05);
			amt -= cnt;
			scatter(nx, ny + dy[d], amt);
		}

		x = nx;
		y = ny;
		a[x][y] = -1;
	}

	printf("%d", ans);

	return 0;
}