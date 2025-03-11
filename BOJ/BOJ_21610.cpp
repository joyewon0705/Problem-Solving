#include <iostream>
#include <queue>
using namespace std;

#define N 55

typedef pair<int, int> P;
int dx[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

int n, m, d, s, ans;
int a[N][N];
queue<P> q;

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	q.push({ n, 1 });
	q.push({ n, 2 });
	q.push({ n - 1, 1 });
	q.push({ n - 1, 2 });
	while (m--) {
		scanf("%d %d", &d, &s);

		int mx = dx[d] * s;
		int my = dy[d] * s;
		bool chk[N][N] = { false };
		queue<P> tq;
		for (int i = q.size(); i; i--) {
			int x = ((q.front().first + mx - 1) % n + n) % n + 1;
			int y = ((q.front().second + my - 1) % n + n) % n + 1;
			q.pop();

			if (x < 1 || n < x || y < 1 || n < y) continue;

			a[x][y]++;
			chk[x][y] = true;
			tq.push({ x, y });
		}

		while (!tq.empty()) {
			int x = tq.front().first;
			int y = tq.front().second;
			tq.pop();

			for (int k = 2; k <= 8; k += 2) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (a[nx][ny]) a[x][y]++;
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][j] < 2 || chk[i][j]) continue;

				a[i][j] -= 2;
				q.push({ i, j });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += a[i][j];
		}
	}
	printf("%d", ans);

	return 0;
}