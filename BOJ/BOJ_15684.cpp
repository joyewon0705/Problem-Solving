#include <iostream>

#define INF 1<<30
#define N 11
#define M 33

int n, m, h, a, b, ans = INF;
bool chk[N][M];

bool promising() {

	for (int i = 1; i <= n; i++) {
		int t = i;
		for (int j = 1; j <= h; j++) {
			if (chk[t][j]) t++;
			else if (chk[t - 1][j]) t--;
		}
		if (t != i) return false;
	}
	return true;
}

void search(int max, int cur, int cnt) {
	
	if (cnt > max) return;
	if (promising()) {
		if (ans > cnt) ans = cnt;
		return;
	}
	if (ans == max) return;

	for (int i = 1; i < n; i++) {
		for (int j = cur; j <= h; j++) {
			if (chk[i][j]) continue;
			if (chk[i - 1][j]) continue;
			if (chk[i + 1][j]) continue;

			chk[i][j] = true;
			search(max, j, cnt + 1);
			chk[i][j] = false;
		}
	}
}

int main(void) {

	scanf("%d %d %d", &n, &m, &h);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		chk[b][a] = true;
	}

	for (int i = 0; i < 4; i++) {
		search(i, 1, 0);
		if (ans == i) break;
	}

	if (ans >= INF) ans = -1;
	printf("%d", ans);

	return 0;
}