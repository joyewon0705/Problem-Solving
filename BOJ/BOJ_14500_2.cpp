#include <iostream>
#include <cmath>
using namespace std;

#define N 505

int n, m, ans = 0;
int p[N][N];

int getMax(int x, int y) {
	int ret = 0;

	// 2x2
	if (x < n && y < m) {
		ret = p[x][y] + p[x][y + 1] + p[x + 1][y] + p[x + 1][y + 1];
	}

	// 1x4
	if (y + 2 < m) {
		ret = max(ret, p[x][y] + p[x][y + 1] + p[x][y + 2] + p[x][y + 3]);
	}
	// 4x1
	if (x + 2 < n) {
		ret = max(ret, p[x][y] + p[x + 1][y] + p[x + 2][y] + p[x + 3][y]);
	}

	// 2x3
	if (x < n && y + 1 < m) {
		ret = max(ret, p[x][y] + p[x][y + 1] + p[x][y + 2] + p[x + 1][y]);
		ret = max(ret, p[x][y] + p[x][y + 1] + p[x][y + 2] + p[x + 1][y + 2]);
		ret = max(ret, p[x][y] + p[x + 1][y] + p[x + 1][y + 1] + p[x + 1][y + 2]);
		ret = max(ret, p[x][y + 2] + p[x + 1][y] + p[x + 1][y + 1]+ p[x + 1][y + 2]);
	
		ret = max(ret, p[x][y] + p[x][y + 1] + p[x + 1][y + 1] + p[x + 1][y + 2]);
		ret = max(ret, p[x][y + 1] + p[x][y + 2] + p[x + 1][y] + p[x + 1][y + 1]);
	
		ret = max(ret, p[x][y] + p[x][y + 1] + p[x][y + 2] + p[x + 1][y + 1]);
		ret = max(ret, p[x][y + 1] + p[x + 1][y] + p[x + 1][y + 1] + p[x + 1][y + 2]);
	}
	// 3x2
	if (x + 1 < n && y < m) {
		ret = max(ret, p[x][y] + p[x][y + 1] + p[x + 1][y] + p[x + 2][y]);
		ret = max(ret, p[x][y] + p[x + 1][y] + p[x + 2][y] + p[x + 2][y + 1]);
		ret = max(ret, p[x][y] + p[x][y + 1] + p[x + 1][y + 1] + p[x + 2][y + 1]);
		ret = max(ret, p[x][y + 1] + p[x + 1][y + 1] + p[x + 2][y] + p[x + 2][y + 1]);
	
		ret = max(ret, p[x][y] + p[x + 1][y] + p[x + 1][y + 1] + p[x + 2][y + 1]);
		ret = max(ret, p[x][y + 1] + p[x + 1][y] + p[x + 1][y + 1] + p[x + 2][y]);
	
		ret = max(ret, p[x][y] + p[x + 1][y] + p[x + 1][y + 1] + p[x + 2][y]);
		ret = max(ret, p[x][y + 1] + p[x + 1][y] + p[x + 1][y + 1] + p[x + 2][y + 1]);
	}

	return ret;
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
			ans = max(ans, getMax(i, j));
		}
	}

	printf("%d", ans);

	return 0;
}