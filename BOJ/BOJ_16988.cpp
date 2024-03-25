#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define N 22
typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, s, ans;
bool isVisit[N][N];
int board[N][N];
vector<P> v;
queue<P> q;

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 0) v.push_back({ i, j });
		}
	}

	s = v.size();
	for (int i = 0; i < s; i++) {
		board[v[i].first][v[i].second] = 1;
		for (int j = i + 1; j < s; j++) {
			board[v[j].first][v[j].second] = 1;

			int sum = 0;
			memset(isVisit, false, sizeof(isVisit));
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (isVisit[i][j]) continue;
					if (board[i][j] == 2) {
						bool chk = true;
						int cnt = 0;
						q = queue<P>();

						q.push({ i, j });
						while (!q.empty()) {
							int x = q.front().first;
							int y = q.front().second;
							q.pop();

							if (board[x][y] == 0) { chk = false; continue; }
							if (board[x][y] == 1) continue;
							if (isVisit[x][y]) continue;
							isVisit[x][y] = true;
							cnt++;

							for (int k = 0; k < 4; k++) {
								int nx = x + dx[k];
								int ny = y + dy[k];

								if (nx < 1 || n < nx || ny < 1 || m < ny) continue;
								q.push({ nx, ny });
							}
						}

						if (chk) sum += cnt;
					}
				}
			}
			if (ans < sum) 
				ans = sum;

			board[v[j].first][v[j].second] = 0;
		}
		board[v[i].first][v[i].second] = 0;
	}

	printf("%d", ans);

	return 0;
}