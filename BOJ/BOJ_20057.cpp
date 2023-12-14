#include <iostream>
#include <queue>
using namespace std;

#define N 505
typedef pair<int, int> P;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int n, x, y, d, a, b, cnt, ans;
bool isVisit[N][N];
int A[N][N];

void flutter(int nx, int ny, int r) {
	int val = A[a][b] * (0.01 * r);

	if (nx < 1 || n < nx || ny < 1 || n < ny) ans += val;
	else A[nx][ny] += val;
	cnt += val;
}

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	x = y = (n / 2) + 1;
	while (true) {

		if (x == 1 && y == 1) break;

		isVisit[x][y] = true;
		cnt = 0;

		a = x + dx[d];
		b = y + dy[d];

		switch (d) {
		case 0:
			flutter(x - 1, y, 1); flutter(x + 1, y, 1);
			flutter(x - 1, y - 1, 7); flutter(x + 1, y - 1, 7);
			flutter(x - 2, y - 1, 2); flutter(x + 2, y - 1, 2);
			flutter(x - 1, y - 2, 10); flutter(x + 1, y - 2, 10);
			flutter(x, y - 3, 5); break;
		case 1:
			flutter(x, y - 1, 1); flutter(x, y + 1, 1);
			flutter(x + 1, y - 1, 7); flutter(x + 1, y + 1, 7);
			flutter(x + 1, y - 2, 2); flutter(x + 1, y + 2, 2);
			flutter(x + 2, y - 1, 10); flutter(x + 2, y + 1, 10);
			flutter(x + 3, y, 5); break;
		case 2:
			flutter(x - 1, y, 1); flutter(x + 1, y, 1);
			flutter(x - 1, y + 1, 7); flutter(x + 1, y + 1, 7);
			flutter(x - 2, y + 1, 2); flutter(x + 2, y + 1, 2);
			flutter(x - 1, y + 2, 10); flutter(x + 1, y + 2, 10);
			flutter(x, y + 3, 5); break;
		case 3:
			flutter(x, y - 1, 1); flutter(x, y + 1, 1);
			flutter(x - 1, y - 1, 7); flutter(x - 1, y + 1, 7);
			flutter(x - 1, y - 2, 2); flutter(x - 1, y + 2, 2);
			flutter(x - 2, y - 1, 10); flutter(x - 2, y + 1, 10);
			flutter(x - 3, y, 5); break;
		}

		A[a][b] -= cnt;
		flutter(a + dx[d], b + dy[d], 100);
		A[a][b] = 0;

		x = a;
		y = b;
		a = x + dx[(d + 1) % 4];
		b = y + dy[(d + 1) % 4];
		if (!isVisit[a][b]) d = (d + 1) % 4;
	}

	printf("%d", ans);

	return 0;
}