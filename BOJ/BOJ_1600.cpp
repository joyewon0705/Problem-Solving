#include <iostream>
#include <queue>
using namespace std;

#define N 202
#define K 33
int dx[] = { -1, 1, 0, 0, -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[] = { 0, 0, -1, 1, -1, 1, -2, 2, -2, 2, -1, 1 };
typedef pair<int, int> P;

int k, w, h, ans = -1;
bool map[N][N];
int cnt[N][N][K];
queue<pair<P, P>> q;

int main(void) {

	scanf("%d", &k);
	scanf("%d %d", &w, &h);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	q.push({ { 0, 0 }, { 1, 1 } });
	while (!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		if (cnt[x][y][b] && cnt[x][y][b] <= a) continue;
		cnt[x][y][b] = a;

		for (int c = 0; c < 12; c++) {
			int nx = x + dx[c];
			int ny = y + dy[c];

			if (nx < 1 || h < nx || ny < 1 || w < ny) continue;
			if (map[nx][ny]) continue;
			if (c > 3 && b >= k) break;
			if (c > 3) q.push({ { a + 1, b + 1 }, { nx, ny } });
			else q.push({ { a + 1, b }, { nx, ny } });
		}
	}

	for (int i = 0; i <= k; i++) {
		if (cnt[h][w][i]) {
			if (ans < 0 || ans > cnt[h][w][i])
				ans = cnt[h][w][i];
		}
	}
	if (w == 1 && h == 1) ans = 0;
	printf("%d", ans);

	return 0;
}