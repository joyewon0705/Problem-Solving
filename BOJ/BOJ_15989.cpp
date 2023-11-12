#include <iostream>

#define N 10101

int t, n, m, cnt;
int dp[N][3];

int main(void) {

	dp[1][0] = 1;
	dp[2][0] = 1; dp[2][1] = 1;
	dp[3][0] = 1; dp[3][1] = 1; dp[3][2] = 1;
	m = 3;
	
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d", &n);

		for (int i = m + 1; i <= n; i++) {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
			dp[i][2] = dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2];
		}
		if (m < n) m = n;

		printf("%d\n", dp[n][0] + dp[n][1] + dp[n][2]);
	}

	return 0;
}