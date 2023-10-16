#include <iostream>
#include <queue>
using namespace std;

#define INF 1<<30
#define N 127
typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int t, n;
int map[N][N], m[N][N];
queue<pair<int, P>> q;

int main(void) {

	while (true) {
		scanf("%d", &n);
		if (n == 0) break;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &map[i][j]);
				m[i][j] = INF;
			}
		}

		q.push({ map[1][1], { 1, 1 } });
		while (!q.empty()) {
			int val = q.front().first;
			int x = q.front().second.first;
			int y = q.front().second.second;
			q.pop();

			if (m[x][y] <= val) continue;
			m[x][y] = val;

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < 1 || n < nx || ny < 1 || n < ny) continue;
				q.push({ val + map[nx][ny], { nx, ny } });
			}
		}

		t++;
		printf("Problem %d: %d\n", t, m[n][n]);
	}

	return 0;
}