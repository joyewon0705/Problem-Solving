#include <iostream>
#include <queue>
using namespace std;

#define N 505
typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, ans1, ans2;
bool p[N][N], s[N][N];
queue<P> q;

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &p[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (p[i][j] && !s[i][j]) {
				int tmp = 0;
				ans1++;
				q.push({ i, j });
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					if (s[x][y]) continue;
					s[x][y] = true;
					tmp++;

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (nx < 1 || n < nx || ny < 1 || m < ny) continue;
						if (p[nx][ny]) q.push({ nx, ny });
					}
				}
				if (ans2 < tmp) ans2 = tmp;
			}
		}
	}

	printf("%d\n%d", ans1, ans2);

	return 0;
}