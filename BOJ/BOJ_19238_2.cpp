#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define INF 1<<30
#define N 22

typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, o, x, y, r, c, cnt;
int map[N][N];
P dst[N * N];

int main(void) {

	scanf("%d %d %d", &n, &m, &o);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j]) map[i][j] = -1;
		}
	}
	scanf("%d %d", &x, &y);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d %d", &r, &c, &dst[i].first, &dst[i].second);
		map[r][c] = i;
	}

	cnt = m;
	while (cnt) {
		int nx, ny, next, dist = INF;
		bool isVisit[N][N] = { false };
		queue<pair<int, P>> q;

		q.push({ 0, { x, y } });
		while (!q.empty()) {
			int cnt = q.front().first;
			P cur = q.front().second;
			q.pop();

			if (o < cnt || dist < cnt) break;

			if (isVisit[cur.first][cur.second]) continue;
			isVisit[cur.first][cur.second] = true;

			if (map[cur.first][cur.second] > 0) {
				if (dist < INF && (nx < cur.first || (nx == cur.first && ny < cur.second))) 
					continue;

				nx = cur.first;
				ny = cur.second;
				next = map[nx][ny];
				dist = cnt;
				continue;
			}

			for (int k = 0; k < 4; k++) {
				int nx = cur.first + dx[k];
				int ny = cur.second + dy[k];

				if (nx < 1 || n < nx || ny < 1 || n < ny) continue;
				if (map[nx][ny] < 0) continue;

				q.push({ cnt + 1, { nx, ny } });
			}
		}

		if (o >= dist) o -= dist;
		else o = -1;

		dist = INF;
		memset(isVisit, false, sizeof(isVisit));
		q = queue<pair<int, P>>();
		q.push({ 0, { nx, ny } });
		while (!q.empty()) {
			int cnt = q.front().first;
			P cur = q.front().second;
			q.pop();

			if (o < cnt) break;

			if (cur == dst[next]) {
				dist = cnt;
				break;
			}

			if (isVisit[cur.first][cur.second]) continue;
			isVisit[cur.first][cur.second] = true;

			for (int k = 0; k < 4; k++) {
				int nx = cur.first + dx[k];
				int ny = cur.second + dy[k];

				if (nx < 1 || n < nx || ny < 1 || n < ny) continue;
				if (map[nx][ny] < 0) continue;

				q.push({ cnt + 1, { nx, ny } });
			}
		}

		if (o >= dist) o -= dist;
		else o = -1;
		
		if (o < 0) break;
		x = dst[next].first;
		y = dst[next].second;
		o += 2 * dist;
		map[nx][ny] = 0;
		cnt--;
	}

	if (cnt) o = -1;
	printf("%d", o);

	return 0;
}