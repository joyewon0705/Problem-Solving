#include <iostream>
#include <cstring>
using namespace std;

#define INF 1<<30
#define N 101

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int n, m, k, minn, maxx, a, b, e, t, ans;
int p[N], np[N], p1[11][11], p2[5][26];

void getP1() {
	int x, y, d;

	a = b = 2;
	while (n > a * b) {
		if (a == b) a++;
		else b++;
	}

	e = n + 1;
	if (n < a * b) {
		if (a == b) e = a * (b - 1) + 1;
		else e = (a - 1) * b + 1;
	}

	d = 3;
	x = (a + 1) / 2;
	y = (b + 1) / 2;
	for (int i = 1; i < e; i++) {
		p1[x][y] = i;

		int nd = (d + 1) % 4;
		int nx = x + dx[nd];
		int ny = y + dy[nd];
		if (!p1[nx][ny]) {
			d = nd;
			x = nx;
			y = ny;
		}
		else {
			x += dx[d];
			y += dy[d];
		}
	}
	if (e > n) {
		x -= dx[d];
		y -= dy[d];
	}

	if (x == 1 && y == 1) t = 1;
	else if (x == a && y == b) t = 2;
	else if (x == 1 && y == b) t = 3;
	else t = 4;
}

void getP2() {

	int cur = 1;
	for (int j = m; j; j--) p2[3][j] = cur++;
	for (int j = 1; j <= m; j++) p2[2][j] = cur++;
	for (int j = m; j; j--) p2[1][j] = cur++;
	for (int j = 1; j <= m; j++) p2[4][j] = cur++;
}

void setP1() {

	memset(np, 0, sizeof(np));
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			int cur = p1[i][j];
			if (cur == 0) continue;

			np[cur] += p[cur];
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 1 || a < nx || ny < 1 || b < ny) continue;

				int next = p1[nx][ny];
				if (next == 0) continue;

				int d = (p[cur] - p[next]) / 5;
				if (d > 0) {
					np[cur] -= d;
					np[next] += d;
				}
			}
		}
	}
	for (int cur = e; cur <= n; cur++) {
		np[cur] = p[cur];
		int d = (p[cur] - p[cur - 1]) / 5;
		np[cur] -= d;
		np[cur - 1] += d;
	}

	int cur = 1;
	if (t == 1) {
		for (int j = b; j; j--) {
			for (int i = 1; i <= a; i++) {
				if (p1[i][j]) p[cur++] = np[p1[i][j]];
			}
		}
	}
	else if (t == 2) {
		for (int j = 1; j <= b; j++) {
			for (int i = a; i; i--) {
				if (p1[i][j]) p[cur++] = np[p1[i][j]];
			}
		}
	}
	else if (t == 3) {
		for (int i = a; i; i--) {
			for (int j = b; j; j--) {
				if (p1[i][j]) p[cur++] = np[p1[i][j]];
			}
		}
	}
	else {
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= b; j++) {
				if (p1[i][j]) p[cur++] = np[p1[i][j]];
			}
		}
	}
	for (int cur = e; cur <= n; cur++) p[cur] = np[cur];
}

void setP2() {

	memset(np, 0, sizeof(np));
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= m; j++) {
			int cur = p2[i][j];
			np[cur] += p[cur];
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 1 || 4 < nx || ny < 1 || m < ny) continue;

				int next = p2[nx][ny];
				int d = (p[cur] - p[next]) / 5;
				if (d > 0) {
					np[cur] -= d;
					np[next] += d;
				}
			}
		}
	}

	int cur = 1;
	for (int j = 1; j <= m; j++) {
		for (int i = 4; i; i--) {
			p[cur++] = np[p2[i][j]];
		}
	}
}

int main(void) {

	minn = INF; maxx = -INF;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		if (p[i] < minn) minn = p[i];
		if (maxx < p[i]) maxx = p[i];
	}
	m = n / 4;
	
	getP1();
	getP2();

	while (maxx - minn > k) {
		ans++;

		for (int i = 1; i <= n; i++) {
			if (p[i] == minn) p[i]++;
		}

		setP1();
		setP2();

		minn = INF; maxx = -INF;
		for (int i = 1; i <= n; i++) {
			if (p[i] < minn) minn = p[i];
			if (maxx < p[i]) maxx = p[i];
		}
	}

	printf("%d", ans);

	return 0;
}