#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

#define N 66
typedef pair<int, int> P;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, q, l, sum, maxs, cnt;
int A[N][N], NA[N][N];
queue<P> qu;

void rotate(int x, int y, int s) {

	if (s == l) {
		for (int i = 0; i < s; i++) {
			for (int j = 0; j < s; j++) {
				NA[x + j][y + s - 1 - i] = A[x + i][y + j];
			}
		}
		return;
	}

	int ns = s / 2;
	rotate(x, y, ns);
	rotate(x, y + ns, ns);
	rotate(x + ns, y, ns);
	rotate(x + ns, y + ns, ns);
}

void melt() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!A[i][j]) continue;
			cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (NA[nx][ny]) cnt++;
			}
			if (cnt < 3) A[i][j]--;
		}
	}
}

int main(void) {

	scanf("%d %d", &n, &q);
	n = pow(2, n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	for (int i = 1; i <= q; i++) {
		scanf("%d", &l);
		l = pow(2, l);
		rotate(1, 1, n);
		memcpy(A, NA, sizeof(A));
		melt();
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!A[i][j]) continue;

			cnt = 0;
			qu.push({ i, j });
			while (!qu.empty()) {
				int x = qu.front().first;
				int y = qu.front().second;
				qu.pop();

				if (!A[x][y]) continue;
				sum += A[x][y];
				A[x][y] = 0;
				cnt++;

				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					qu.push({ nx, ny });
				}
			}
			if (maxs < cnt) maxs = cnt;
		}
	}

	printf("%d\n%d", sum, maxs);

	return 0;
}