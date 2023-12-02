#include <iostream>

#define MOD 1000000007
#define N 1010101

int n;
int sum[N];
long long dp[N];

int main(void) {

	scanf("%d", &n);

	dp[0] = 0;
	dp[1] = 2;
	dp[2] = 7; sum[2] = 1;
	for (int i = 3; i <= n; i++) {
		sum[i] = (dp[i - 3] + sum[i - 1]) % MOD;
		dp[i] = (2 * dp[i - 1] + 3 * dp[i - 2] + 2 * sum[i]) % MOD;
	}

	printf("%d", dp[n]);

	return 0;
}