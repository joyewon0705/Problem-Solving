#include <iostream>
#include <queue>
#include <map>
using namespace std;

#define N 1010
typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, cnt, ans;
bool e[N][N];
int chk[N][N], set[N * N / 2];
queue<P> q;

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &e[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (e[i][j] && !chk[i][j]) {
				cnt++;
				q.push({ i, j });
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					if (!e[x][y] || chk[x][y]) continue;
					chk[x][y] = cnt;
					set[cnt]++;

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (nx < 1 || n < nx || ny < 1 || m < ny) continue;
						q.push({ nx, ny });
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (e[i][j]) continue;
			map<int, bool> mm;

			int tmp = 1;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 1 || n < nx || ny < 1 || m < ny) continue;
				if (mm.find(chk[nx][ny]) != mm.end()) continue;
				mm.insert({ chk[nx][ny], true });

				tmp += set[chk[nx][ny]];
			}

			if (ans < tmp) ans = tmp;
		}
	}

	printf("%d", ans);

	return 0;
}