#include <iostream>

#define N 505

bool chk;
int n, m, a, b, ans;
int d[N][N];

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		d[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (d[i][k] == 0) continue;
			for (int j = 1; j <= n; j++) {
				if (d[k][j] == 0) continue;
				if (i == j) continue;
				if (d[i][j] == 0 || d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		chk = true;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (d[i][j] == 0 && d[j][i] == 0) {
				chk = false;
				break;
			}
		}
		if (chk) ans++;
	}

	printf("%d", ans);

	return 0;
}