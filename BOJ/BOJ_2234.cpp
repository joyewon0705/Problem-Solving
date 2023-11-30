#include <iostream>
#include <queue>
using namespace std;

#define N 55
typedef pair<int, int> P;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

int n, m, a, b, c;
int map[N][N], set[N][N], chk[N * N];
queue<P> q;
queue<int> t;

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (set[i][j]) continue;

			int size = 0;
			a++;
			q.push({ i, j });
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				if (set[x][y]) continue;
				set[x][y] = a;
				size++;

				int wall = map[x][y];
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (set[nx][ny] && set[nx][ny] < a) t.push(chk[set[nx][ny]]);
					if (wall & (1 << k)) continue;

					q.push({ nx, ny });
				}
			}

			chk[a] = size;
			if (b < size) b = size;

			while (!t.empty()) {
				int s = t.front();
				t.pop();

				if (c < size + s) c = size + s;
			}
		}
	}

	printf("%d\n%d\n%d", a, b, c);

	return 0;
}