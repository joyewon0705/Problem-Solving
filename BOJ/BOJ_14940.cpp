#include <iostream>
#include <queue>
using namespace std;

#define N 1010
typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, in;
P dst;
bool chk[N][N];
int val[N][N];
queue<pair<int, P>> q;

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &in);
			if (in == 0) continue;
			if (in == 2) dst = { i, j };
			chk[i][j] = true;
			val[i][j] = -1;
		}
	}

	q.push({ 0, dst });
	while (!q.empty()) {
		int cnt = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		if (!chk[x][y]) continue;
		if (val[x][y] > -1 && val[x][y] <= cnt) continue;
		val[x][y] = cnt;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 1 || n < nx || ny < 1 || m < ny) continue;
			q.push({ cnt + 1, { nx, ny } });
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", val[i][j]);
		}
		printf("\n");
	}

	return 0;
}