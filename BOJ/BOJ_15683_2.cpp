#include <iostream>
#include <vector>
using namespace std;

#define N 9

typedef struct _cctv { int x, y, t; }_cctv;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int n, m, c, ans = 1<<30;
int map[N][N];
vector<_cctv> cctv;

void setMap(int x, int y, int k, int val) {

	while (true) {
		x += dx[k];
		y += dy[k];

		if (x < 1 || n < x || y < 1 || m < y) break;
		if (map[x][y] < 0) break;

		map[x][y] += val;
	}
}

void f(int cur) {
	
	if (cur >= c) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == 0) cnt++;
			}
		}
		if (ans > cnt) ans = cnt;
		return;
	}

	int x = cctv[cur].x;
	int y = cctv[cur].y;
	int t = cctv[cur].t;
	if (t == 1) {
		for (int k = 0; k < 4; k++) {
			setMap(x, y, k, 1);
			f(cur + 1);
			setMap(x, y, k, -1);
		}
	}
	else if (t == 2) {
		for (int k = 0; k < 2; k++) {
			setMap(x, y, k, 1);
			setMap(x, y, k + 2, 1);
			f(cur + 1);
			setMap(x, y, k, -1);
			setMap(x, y, k + 2, -1);
		}
	}
	else if (t == 3) {
		for (int k = 0; k < 4; k++) {
			setMap(x, y, k, 1);
			setMap(x, y, (k + 1) % 4, 1);
			f(cur + 1);
			setMap(x, y, k, -1);
			setMap(x, y, (k + 1) % 4, -1);
		}
	}
	else if (t == 4) {
		for (int k = 0; k < 4; k++) {
			for (int l = 0; l < 3; l++) setMap(x, y, (k + l) % 4, 1);
			f(cur + 1);
			for (int l = 0; l < 3; l++) setMap(x, y, (k + l) % 4, -1);
		}
	}
	else {
		for (int k = 0; k < 4; k++) setMap(x, y, k, 1);
		f(cur + 1);
		for (int k = 0; k < 4; k++) setMap(x, y, k, -1);
	}
}

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &c);
			if (c == 6) map[i][j] = -1;
			else if (c) {
				map[i][j] = 1;
				cctv.push_back({ i, j, c });
			}
		}
	}

	c = cctv.size();
	f(0);

	printf("%d", ans);

	return 0;
}