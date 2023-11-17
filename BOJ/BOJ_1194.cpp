#include <iostream>
#include <queue>
using namespace std;

#define INF 1<<30
#define N 55
typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, ans;
P st;
char map[N][N];
int chk[N][N][1 << 7];
queue<pair<P, P>> q;

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 1; j <= m; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == '0') st = { i, j };
		}
	}

	ans = INF;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 0; k <= 1 << 7; k++)
				chk[i][j][k] = INF;

	q.push({ st, { 0, 0 } });
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second.first;
		int key = q.front().second.second;
		q.pop();

		if (map[x][y] == '1') {
			if (ans > cnt) ans = cnt;
			continue;
		}
		if (map[x][y] == '#') continue;
		if (map[x][y] >= 'A' && map[x][y] <= 'F') {
			int mask = 1 << (map[x][y] - 'A' + 1);
			if (!(key & mask)) continue;
		}
		if (map[x][y] >= 'a' && map[x][y] <= 'f') 
			key |= 1 << (map[x][y] - 'a' + 1);

		if (chk[x][y][key] <= cnt) continue;
		chk[x][y][key] = cnt;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 1 || n < nx || ny < 1 || m < ny) continue;
			q.push({ { nx, ny }, { cnt + 1, key } });
		}
	}

	if (ans >= INF) ans = -1;
	printf("%d", ans);

	return 0;
}