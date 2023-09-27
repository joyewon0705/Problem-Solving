#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define N 101
typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, cnt, ans1, ans2;
bool map[N][N], isVisit[N][N];
queue<P> q;

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j]) cnt++;
		}
	}

	while (cnt) {
		ans1++;
		ans2 = cnt;
		
		q.push({ 1, 1 });
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (isVisit[x][y]) continue;
			isVisit[x][y] = true;

			if (map[x][y]) {
				map[x][y] = false;
				cnt--;
				continue;
			}

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < 1 || n < nx || ny < 1 || m < ny) continue;
				q.push({ nx, ny });
			}
		}

		memset(isVisit, false, sizeof(isVisit));
	}

	printf("%d\n%d", ans1, ans2);

	return 0;
}