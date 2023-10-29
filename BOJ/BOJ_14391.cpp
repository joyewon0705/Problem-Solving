#include <iostream>

#define N 5

int n, m, ans;
bool isVisit[N][N];
int map[N][N];

void f(int x, int y, int sum) {

	if (x == n && y > m) {
		if (ans < sum) ans = sum;
		return;
	}

	if (y > m) { x += 1; y = 1; }
	if (isVisit[x][y]) f(x, y + 1, sum);
	else {
		int val = 0;
		for (int i = x; i <= n; i++) {
			val = val * 10 + map[i][y];
			isVisit[i][y] = true;
			f(x, y + 1, sum + val);
		}
		for (int i = n; i >= x; i--) {
			isVisit[i][y] = false;
		}
		val = 0;
		for (int j = y; ; j++) {
			if (isVisit[x][j] || j > m) {
				for (j -= 1; j >= y; j--) {
					isVisit[x][j] = false;
				}
				break;
			}
			val = val * 10 + map[x][j];
			isVisit[x][j] = true;
			f(x, j + 1, sum + val);
		}
	}
}

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 1; j <= m; j++) {
			map[i][j] = getchar() - '0';
		}
	}

	f(1, 1, 0);

	printf("%d", ans);

	return 0;
}