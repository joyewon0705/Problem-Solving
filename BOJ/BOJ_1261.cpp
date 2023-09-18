#include <iostream>
#include <queue>
using namespace std;

#define INF 1<<30
#define N 101
typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m;
bool map[N][N];
int ans[N][N];
queue<pair<int, P>> q;

int main(void) {

	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 1; j <= m; j++) {
			if (getchar() == '0') map[i][j] = true;
			ans[i][j] = INF;
		}
	}

	q.push({ 0, { 1, 1 } });
	while (!q.empty()) {
		int cnt = q.front().first;
		P cur = q.front().second;
		q.pop();

		if (cnt >= ans[cur.first][cur.second]) continue;
		ans[cur.first][cur.second] = cnt;

		for (int k = 0; k < 4; k++) {
			int nx = cur.first + dx[k];
			int ny = cur.second + dy[k];

			if (nx < 1 || n < nx || ny < 1 || m < ny) continue;
			if (map[nx][ny]) q.push({ cnt, { nx, ny } });
			else q.push({ cnt + 1, { nx, ny } });
		}
	}

	printf("%d", ans[n][m]);

	return 0;
}