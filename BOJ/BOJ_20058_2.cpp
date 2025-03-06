#include <iostream>
#include <cmath>
using namespace std;

#define N 66

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, q, l, sum, cnt;
int a[N][N], b[N][N];

int f(int x, int y) {
	int ret = 0;

	if (a[x][y] == 0) return 0;
	sum += a[x][y];
	a[x][y] = 0;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 1 || m < nx || ny < 1 || m < ny) continue;
		ret += f(nx, ny);
	}
	return ret + 1;
}

int main(void) {

	scanf("%d %d", &n, &q);
	m = pow(2, n);
	for (int i = 1; i <= m; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int t = 1; t <= q; t++) {
		scanf("%d", &l);

		l = pow(2, l);
		for (int i = 1; i <= m; i += l) {
			for (int j = 1; j <= m; j += l) {
				for (int r = 0; r < l; r++) {
					for (int c = 0; c < l; c++) {
						b[i + c][j + l - 1 - r] = a[i + r][j + c];
					}
				}
			}
		}

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				if (b[i][j] == 0) {
					a[i][j] = 0;
					continue;
				}
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (b[nx][ny]) cnt++;
				}
				if (cnt < 3) a[i][j] = b[i][j] - 1;
				else a[i][j] = b[i][j];
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			cnt = max(cnt, f(i, j));
		}
	}
	if (cnt == 1) cnt = 0;
	printf("%d\n%d", sum, cnt);

	return 0;
}