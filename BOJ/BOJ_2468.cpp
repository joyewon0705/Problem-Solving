#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define N 101
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, ans = 1;
int map[N][N];
bool chk[N][N];

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] > m) m = map[i][j];
		}
	}

	for (int a = 1; a <= m; a++) {
		int cnt = 0;
		memset(chk, false, sizeof(chk));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] > a && !chk[i][j]) {
					queue<pair<int, int>> q;

					q.push({ i, j });
					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();

						if (chk[x][y]) continue;
						chk[x][y] = true;

						for (int k = 0; k < 4; k++) {
							int nx = x + dx[k];
							int ny = y + dy[k];

							if (nx < 1 || n < nx || ny < 1 || n < ny) continue;
							if (map[nx][ny] > a) q.push({ nx, ny });
						}
					}
					cnt++;
				}
			}
		}
		if (ans < cnt) ans = cnt;
	}

	printf("%d", ans);

	return 0;
}