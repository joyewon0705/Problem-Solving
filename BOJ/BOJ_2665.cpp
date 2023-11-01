#include <iostream>
#include <queue>
using namespace std;

#define INF 1<<30
#define N 55
typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

char ch;
int n;
bool m[N][N];
int d[N][N];
queue<pair<int, P>> q;

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 1; j <= n; j++) {
			if (getchar() == '1') m[i][j] = true;
			d[i][j] = INF;
		}
	}

	q.push({ 0, { 1, 1 } });
	while (!q.empty()) {
		int chk = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		if (d[x][y] <= chk) continue;
		d[x][y] = chk;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 1 || n < nx || ny < 1 || n < ny) continue;
			if (m[nx][ny]) q.push({ chk, { nx, ny } });
			else q.push({ chk + 1, { nx, ny } });
		}
	}

	printf("%d", d[n][n]);

	return 0;
}