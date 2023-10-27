#include <iostream>

#define N 1010
#define MOD 1000000003

int n, k;
int dp[N][N];

int main(void) {

	scanf("%d", &n);
	scanf("%d", &k);

	for (int i = 1; i <= n; i++) dp[i][1] = i;
	for (int j = 2; j <= k; j++) {
		for (int i = 2 * j - 1; i < n; i++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MOD;
		}
		dp[n][j] = (dp[n - 1][j] + dp[n - 3][j - 1]) % MOD;
	}

	printf("%d", dp[n][k]);

	return 0;
}