#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

#define N 55

typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, l, r, sum, cnt, ans;
int A[N][N];
bool chk[N][N];
queue<P> q;

void f(int x, int y) {

	sum += A[x][y]; cnt++;
	chk[x][y] = true;
	q.push({ x, y });
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 1 || n < nx || ny < 1 || n < ny) continue;
		if (chk[nx][ny]) continue;

		int diff = abs(A[x][y] - A[nx][ny]);
		if (l <= diff && diff <= r) f(nx, ny);
	}
}

int main(void) {

	scanf("%d %d %d", &n, &l, &r);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	ans = 0;
	while (true) {
		bool isMoved = false;

		memset(chk, false, sizeof(chk));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (chk[i][j]) continue;

				sum = 0; cnt = 0;
				f(i, j);
				if (cnt > 1) isMoved = true;
				while (!q.empty()) {
					A[q.front().first][q.front().second] = sum / cnt;
					q.pop();
				}
			}
		}

		if (isMoved) ans++;
		else break;
	}

	printf("%d", ans);

	return 0;
}