#include <iostream>

#define MOD 10007

int n, ans;
int dp[1010][10];

int main(void) {

	scanf("%d", &n);

	for (int i = 0; i < 10; i++) dp[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
			}
		}
	}

	for (int i = 0; i < 10; i++) ans = (ans + dp[n][i]) % MOD;

	printf("%d", ans);

	return 0;
}