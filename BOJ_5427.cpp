#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define W 1010

typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

char ch;
int t, w, h, ans;
int map[W][W];

int main(void) {

	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		memset(map, 0, sizeof(map));
		queue<P> q, tq;

		scanf("%d %d", &w, &h);
		for (int i = 1; i <= h; i++) {
			getchar();
			for (int j = 1; j <= w; j++) {
				scanf("%c", &ch);
				if (ch == '#') map[i][j] = -1;
				else if (ch == '@') tq.push({ i, j });
				else if (ch == '*') q.push({ i, j });
			}
		}

		ans = 0;
		for (int cnt = 0; !tq.empty(); cnt++) {
			int it = q.size();
			while (it--) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				if (x < 1 || h < x || y < 1 || w < y) continue;
				if (map[x][y] < 0) continue;
				map[x][y] = -1;

				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					q.push({ nx, ny });
				}
			}

			it = tq.size();
			while (it--) {
				int x = tq.front().first;
				int y = tq.front().second;
				tq.pop();

				if (map[x][y]) continue;
				map[x][y] = cnt;
				if (x < 1 || h < x || y < 1 || w < y) {
					ans = cnt;
					break;
				}

				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					tq.push({ nx, ny });
				}
			}
			
			if (ans) break;
		}

		if (ans) printf("%d\n", ans);
		else printf("IMPOSSIBLE\n");
	}

	return 0;
}