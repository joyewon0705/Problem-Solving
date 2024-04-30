#include <iostream>

#define N 303
#define M 22

int n, m, a;
int p[N][M], d[N][M], c[N][M];

void f(int cur, int val) {

	if (cur > 1) f(cur - 1, val - c[val][cur]);
	printf("%d ", c[val][cur]);
}

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		for (int j = 1; j <= m; j++) {
			scanf("%d", &p[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k <= i; k++) {
				if (d[i][j] < d[i - k][j - 1] + p[k][j]) {
					d[i][j] = d[i - k][j - 1] + p[k][j];
					c[i][j] = k;
				}
			}
		}
	}

	printf("%d\n", d[n][m]);
	f(m, n);

	return 0;
}