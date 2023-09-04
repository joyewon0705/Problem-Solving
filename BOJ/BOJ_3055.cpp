#include <iostream>
#include <queue>
using namespace std;

#define N 55
typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

char ch;
int r, c, s, cnt, ans;
bool isVisit[N][N];
int map[N][N];
P D, S;
queue<P> q, t;

int main(void) {

	scanf("%d %d", &r, &c);
	for (int i = 1; i <= r; i++) {
		getchar();
		for (int j = 1; j <= c; j++) {
			scanf("%c", &ch);
			
			if (ch == '*') map[i][j] = 1;
			else if (ch == 'X') map[i][j] = -1;
			else if (ch == 'S') S = { i, j };
			else if (ch == 'D') {
				D = { i, j }; map[i][j] = 2;
			}
		}
	}
	
	q.push(S);
	while (!ans && q.size()) {
		cnt++;

		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (map[i][j] == 1) {
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];

						if (nx < 1 || r < nx || ny < 1 || c < ny) continue;
						if (map[nx][ny] == 0) t.push({ nx, ny });
					}
				}
			}
		}
		while (!t.empty()) {
			int x = t.front().first;
			int y = t.front().second;
			t.pop();

			map[x][y] = 1;
		}

		s = q.size();
		while (s--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (isVisit[x][y]) continue;
			isVisit[x][y] = true;

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
 				int ny = y + dy[k];

				if (nx < 1 || r < nx || ny < 1 || c < ny) continue;
				if (nx == D.first && ny == D.second) {
					ans = cnt;
					break;
				}
				if (map[nx][ny] == 0) q.push({ nx, ny });
			}

			if (ans) break;
		}
	}

	if (ans) printf("%d", ans);
	else printf("KAKTUS");

	return 0;
}