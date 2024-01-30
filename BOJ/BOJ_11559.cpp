#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define N 12
#define M 6

typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool chk;
int ans;
bool isVisit[N][M];
char map[N][M];

int main(void) {

	for (int i = 0; i < N; i++) {
		scanf("%s", map[i]);
	}

	chk = true;
	while (chk) {
		chk = false;
		memset(isVisit, false, sizeof(isVisit));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (isVisit[i][j] || map[i][j] == '.') continue;

				queue<P> q, cq;

				q.push({ i, j });
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					if (isVisit[x][y]) continue;
					isVisit[x][y] = true;
					cq.push({ x, y });

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (nx < 0 || N <= nx || ny < 0 || M <= ny) continue;
						if (map[i][j] != map[nx][ny]) continue;

						q.push({ nx, ny });
					}
				}

				if (cq.size() < 4) continue;
				chk = true;

				while (!cq.empty()) {
					int x = cq.front().first;
					int y = cq.front().second;
					cq.pop();

					map[x][y] = '.';
				}
			}
		}

		if (chk) {
			ans++;

			for (int i = N - 2; i >= 0; i--) {
				for (int j = M - 1; j >= 0; j--) {
					if (map[i][j] == '.') continue;
					
					int t = i + 1;
					while (t < N && map[t][j] == '.') t++;
					if (t - 1 > i) {
						map[t - 1][j] = map[i][j];
						map[i][j] = '.';
					}
				}
			}
		}
	}

	printf("%d", ans);

	return 0;
}