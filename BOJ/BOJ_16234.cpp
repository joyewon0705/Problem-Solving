#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define N 55
typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool isLoop;
int n, l, r, cnt;
bool chk[N][N];
int A[N][N];
queue<P> q;

void move(int x, int y) {
	int a = 0, b = 0;
	vector<P> v;

	q.push({ x, y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (chk[x][y]) continue;
		chk[x][y] = true;
		v.push_back({ x, y });
		a += A[x][y];
		b += 1;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
			if (chk[nx][ny]) continue;

			int diff = abs(A[x][y] - A[nx][ny]);
			if (l <= diff && diff <= r) q.push({ nx, ny });
		}
	}

	int c = a / b;
	for (P cur : v) {
		A[cur.first][cur.second] = c;
	}

	if (v.size() > 1) isLoop = true;
}

int main(void) {

	scanf("%d %d %d", &n, &l, &r);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	isLoop = true;
	while (isLoop) {
		isLoop = false;
		memset(chk, false, sizeof(chk));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (chk[i][j]) continue;
				move(i, j);
			}
		}
		if (isLoop) cnt++;
	}

	printf("%d", cnt);

	return 0;
}