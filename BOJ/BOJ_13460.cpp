#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

#define N 11

typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

char ch;
int n, m, ans;
P o, r, b;
bool board[N][N], chk[N][N][N][N];
queue<tuple<int, P, P>> q;

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 1; j <= m; j++) {
			scanf("%c", &ch);
			if (ch == '#') board[i][j] = true;
			else if (ch == 'O') o = { i, j };
			else if (ch == 'R') r = { i, j };
			else if (ch == 'B') b = { i, j };
		}
	}

	ans = -1;
	q.push({ 0, r, b });
	while (!q.empty()) {
		int cnt = get<0>(q.front());
		P r = get<1>(q.front());
		P b = get<2>(q.front());
		q.pop();

		if (cnt >= 10) continue;
		if (chk[r.first][r.second][b.first][b.second]) continue;
		chk[r.first][r.second][b.first][b.second] = true;

		for (int k = 0; k < 4; k++) {
			bool cr = true, cb = true;
			int nx, ny;
			P nr = r, nb = b;

			while (cr || cb) {
				if (cr) {
					nx = nr.first + dx[k];
					ny = nr.second + dy[k];

					if (board[nx][ny]) cr = false;
					else nr = { nx, ny };
					if (nr == o) cr = false;
				}
				if (cb) {
					nx = nb.first + dx[k];
					ny = nb.second + dy[k];

					if (board[nx][ny]) cb = false;
					else nb = { nx, ny };
					if (nb == o) cb = false;
				}
				if (nr == nb) {
					if (cr) {
						nr = { nr.first - dx[k], nr.second - dy[k] };
						cr = false;
					}
					if (cb) {
						nb = { nb.first - dx[k], nb.second - dy[k] };
						cb = false;
					}
				}
			}


			if (nb == o) continue;
			if (nr == o) {
				ans = cnt + 1;
				q = queue<tuple<int, P, P>>();
				break;
			}
			else q.push({ cnt + 1, nr, nb });
		}
	}

	printf("%d", ans);

	return 0;
}