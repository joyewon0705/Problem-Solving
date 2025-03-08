#include <iostream>
#include <cstring>
using namespace std;

#define N 22

typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, mx, my, mc, mr, ans;
int map[N][N], tmap[N][N];
bool chk[N][N], isVisit[N][N];

void dfse(int x, int y, int c) {

    map[x][y] = -2;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 1 || n < nx || ny < 1 || n < ny) continue;
        if (map[nx][ny] && (map[nx][ny] != c)) continue;

        dfse(nx, ny, c);
    }
}

P dfs(int x, int y, int c) {
	P ret = { 0, 0 };

	if (isVisit[x][y]) return ret;
	isVisit[x][y] = true;
	ret.first++;

	if (map[x][y]) chk[x][y] = true;
	else ret.second++;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 1 || n < nx || ny < 1 || n < ny) continue;
		if (map[nx][ny] && (map[nx][ny] != c)) continue;

		P tmp = dfs(nx, ny, c);
		ret.first += tmp.first;
		ret.second += tmp.second;
	}
	return ret;
}

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
		mc = mr = 0;
		memset(chk, false, sizeof(chk));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] < 1 || chk[i][j]) continue;

				memset(isVisit, false, sizeof(isVisit));
				P ret = dfs(i, j, map[i][j]);

				if (mc < ret.first || (mc == ret.first && mr <= ret.second)) {
					mx = i; my = j; mc = ret.first; mr = ret.second;
				}
			}
		}
		if (mc < 2) break;

		ans += mc * mc;
		dfse(mx, my, map[mx][my]);

		gravity();

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