#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define N 101
short dx[] = { -1, 1, 0, 0 };
short dy[] = { 0, 0, -1, 1 };

int n, ans = 1 << 30;
bool isVisit[N][N];
short map[N][N];

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 1) {
				queue<pair<short, pair<short, short>>> q;
				queue<pair<short, short>> tq;
				memset(isVisit, false, sizeof(isVisit));
	
				tq.push({ i, j });
				while (!tq.empty()) {
					short x = tq.front().first;
					short y = tq.front().second;
					tq.pop();
	
					if (map[x][y] != 1) continue;
					map[x][y] = -1;
					q.push({ 0, { x, y } });
	
					for (int k = 0; k < 4; k++) {
						short nx = x + dx[k];
						short ny = y + dy[k];
	
						if (map[nx][ny] != 1) continue;
						tq.push({ nx, ny });
					}
				}

				while (!q.empty()) {
					short cnt = q.front().first;
					short x = q.front().second.first;
					short y = q.front().second.second;
					q.pop();

					if (isVisit[x][y]) continue;
					isVisit[x][y] = true;

					if (map[x][y] == 0) cnt++;
					else if (map[x][y] > 0 && ans > cnt) { ans = cnt; break; }

					for (int k = 0; k < 4; k++) {
						short nx = x + dx[k];
						short ny = y + dy[k];

						if (nx < 1 || n < nx || ny < 1 || n < ny) continue;
						if (isVisit[nx][ny]) continue;
						if (map[nx][ny] < 0) continue;

						q.push({ cnt, { nx, ny } });
					}
				}
			}
		}
	}

	printf("%d", ans);

	return 0;
}