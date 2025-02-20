#include <iostream>
using namespace std;

#define N 22

typedef pair<int, int> P;
int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, -1, 1 };

int n, m, k, cnt, sec;
int map[N][N], dir[N * N], pri[N * N][5][5];
P smap[N][N], p[N * N];

int main(void) {

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j]) p[map[i][j]] = { i, j };
		}
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &dir[i]);
	}
	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				scanf("%d", &pri[k][i][j]);
			}
		}
	}

	cnt = m;
	while (cnt > 1 && sec <= 1000) {
		for (int i = 1; i <= m; i++) {
			bool isMove = false;
			int x = p[i].first;
			int y = p[i].second;
			int d = dir[i];

			if (map[x][y] != i) continue;

			smap[x][y] = { i, sec };
			for (int j = 1; j <= 4; j++) {
				int nd = pri[i][d][j];
				int nx = x + dx[nd];
				int ny = y + dy[nd];

				if (nx < 1 || n < nx || ny < 1 || n < ny) continue;
				if (smap[nx][ny].first && smap[nx][ny].first != i && sec - smap[nx][ny].second < k) continue;

				if (isMove && smap[nx][ny].first == i && sec - smap[nx][ny].second < k) continue;

				isMove = true;
				if (map[nx][ny] && map[nx][ny] < i) {
					p[i] = { 0, 0 };
					cnt--;
				}
				else {
					dir[i] = nd;
					p[i] = { nx, ny };
				}
				if (smap[nx][ny].first != i || sec - smap[nx][ny].second >= k) break;
			}
			if (map[x][y] == i) map[x][y] = 0;
			map[p[i].first][p[i].second] = i;
		}
		sec++;
	}

	if (sec > 1000) sec = -1;
	printf("%d", sec);

	return 0;
}