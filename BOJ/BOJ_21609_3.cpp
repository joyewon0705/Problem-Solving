#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define N 22

typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, ans;
int map[N][N];
queue<P> q;

void gravity() {

	for (int i = n - 1; i; i--) {
		for (int j = n; j; j--) {
			if (map[i][j] < 0) continue;

			for (int k = i + 1; k <= n; k++) {
				if (map[k][j] < -1) {
					map[k][j] = map[k - 1][j];
					map[k - 1][j] = -2;
				}
				else break;
			}
		}
	}
}

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	while (true) {
		int mx, my, mc = 0, mr = 0;
		bool chk[N][N] = { false };

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] < 1 || chk[i][j]) continue;

				int sr = 0, sc = 0;
				bool isVisit[N][N] = { false };

				q.push({ i, j });
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					if (isVisit[x][y]) continue;
					isVisit[x][y] = true;
					sc++;

					if (map[x][y]) chk[x][y] = true;
					else sr++;

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (nx < 1 || n < nx || ny < 1 || n < ny) continue;
						if (map[nx][ny] && (map[nx][ny] != map[i][j])) continue;

						q.push({ nx, ny });
					}
				}

				if (mc < sc || (mc == sc && mr <= sr)) {
					mx = i; my = j; mr = sr; mc = sc;
				}
			}
		}
		if (mc < 2) break;

		ans += mc * mc;
		mc = map[mx][my];
        map[mx][my] = -2;
		q.push({ mx, my });
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < 1 || n < nx || ny < 1 || n < ny) continue;
				if (map[nx][ny] && (map[nx][ny] != mc)) continue;

				q.push({ nx, ny });
			    map[nx][ny] = -2;
			}
		}

		gravity();

		int tmap[N][N];
		memcpy(tmap, map, sizeof(map));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				map[n - j + 1][i] = tmap[i][j];
			}
		}

		gravity();
	}

	printf("%d", ans);

	return 0;
}