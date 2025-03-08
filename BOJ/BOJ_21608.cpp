#include <iostream>

#define N 22

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, o, ans;
int map[N][N];
bool s[N * N][N * N];

int main(void) {

	scanf("%d", &n);
	for (int t = 0; t < n * n; t++) {
		scanf("%d", &m);
		for (int i = 0; i < 4; i++) {
			scanf("%d", &o);
			s[m][o] = true;
		}

		int x = 0, y = 0, a = 0, b = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j]) continue;

				int na = 0, nb = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx < 1 || n < nx || ny < 1 || n < ny) continue;
					if (s[m][map[nx][ny]]) na++;
					else if (map[nx][ny] == 0) nb++;
				}

				if (a < na || (a == na && b < nb)) {
					x = i; y = j; 
					a = na; b = nb;
				}
				else if (x == 0) {
					x = i; y = j;
					a = na; b = nb;
				}
			}
		}
		map[x][y] = m;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			m = map[i][j];
			o = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 1 || n < nx || ny < 1 || n < ny) continue;
				if (s[m][map[nx][ny]]) o++;
			}
			ans += o == 1 ? 1 : o == 2 ? 10 : o == 3 ? 100 : o == 4 ? 1000 : 0;
		}
	}

	printf("%d", ans);

	return 0;
}