#include <iostream>
#include <queue>
using namespace std;

#define N 55
typedef pair<int, int> P;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int n, m, r, c, d, ans;
int map[N][N];
queue<pair<P, int>> q;

int main(void) {

	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &d);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	q.push({ { r, c },  d });
	while (!q.empty()) {
		P cur = q.front().first;
		int d = q.front().second;
		q.pop();

		if (map[cur.first][cur.second] == 0) {
			map[cur.first][cur.second] = -1;
			ans++;
		}

		for (int i = 1; i <= 4; i++) {
			int new_d = (d + 4 - i) % 4;
			int new_x = cur.first + dx[new_d];
			int new_y = cur.second + dy[new_d];

			if (map[new_x][new_y] == 0) {
				q.push({ { new_x, new_y }, new_d });
				break;
			}
		}
		if (q.empty()) {
			int new_x = cur.first - dx[d];
			int new_y = cur.second - dy[d];

			if (map[new_x][new_y] > 0) break;
			else q.push({ { new_x, new_y }, d });
		}
	}

	printf("%d", ans);

	return 0;
}