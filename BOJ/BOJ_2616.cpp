#include <iostream>

#define N 50505

int n, m;
int a[N], b[N], dp[N][4];

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[i] = b[i - 1] + a[i];
	}
	scanf("%d", &m);

	for (int k = 1; k <= 3; k++) {
		dp[k * m][k] = dp[(k - 1) * m][k - 1] + b[k * m] - b[(k - 1) * m];
		for (int i = k * m + 1; i <= n; i++) {
			dp[i][k] = dp[i - m][k - 1] + b[i] - b[i - m];
			if (dp[i][k] < dp[i - 1][k]) dp[i][k] = dp[i - 1][k];
		}
	}

	printf("%d", dp[n][3]);

	return 0;
}