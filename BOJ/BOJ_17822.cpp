#include <iostream>
#include <cstring>
using namespace std;

#define N 55

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, t, x, d, k, cnt, ans;
int board[N][N], stdd[N];
bool isVisit[N][N];

int f(int x, int y, int v, bool chk) {
	int ny = (stdd[x] + y) % m;

	if (board[x][ny] != v) return 0;

	if (isVisit[x][ny]) return 0;
	isVisit[x][ny] = true;
	
	int ret = 1;
	if (x < n - 1) ret += f(x + 1, y, v, true);
	if (x > 0) ret += f(x - 1, y, v, true);
	ret += f(x, (y + 1) % m, v, true);
	ret += f(x, (y + m - 1) % m, v, true);

	if (chk || ret > 1) board[x][ny] = -1;
	return ret;
}

int main(void) {

	scanf("%d %d %d", &n, &m, &t);
	for (int i = 0; i < n; i++) {
		stdd[i] = 0;
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	cnt = n * m;
	for (int h = 1; h <= t; h++) {
		scanf("%d %d %d", &x, &d, &k);

		for (int i = x - 1; i < n; i += x) {
			if (d) stdd[i] = (stdd[i] + k) % m;
			else stdd[i] = (stdd[i] + m - k) % m;
		}

		int sum = 0;
		bool chk = true;
		memset(isVisit, false, sizeof(isVisit));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int nj = (stdd[i] + j) % m;
				if (board[i][nj] < 0) continue;
				sum += board[i][nj];
				int ret = f(i, j, board[i][nj], false);
				if (ret > 1) {
					chk = false;
					cnt -= ret;
				}
			}
		}
		if (chk) {
			double avg = (double)sum / cnt;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (board[i][j] < 0) continue;
					if ((double)board[i][j] > avg) board[i][j]--;
					else if ((double)board[i][j] < avg) board[i][j]++;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] < 0) continue;
			ans += board[i][j];
		}
	}
	printf("%d", ans);

	return 0;
}