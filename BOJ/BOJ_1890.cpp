#include <iostream>

#define N 101

int n, ans;
int map[N][N];
long long dp[N][N];

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	dp[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!dp[i][j]) continue;
			if (i == n && j == n) break;
			int x = i + map[i][j];
			int y = j + map[i][j];
			if (x <= n) dp[x][j] += dp[i][j];
			if (y <= n) dp[i][y] += dp[i][j];
		}
	}

	printf("%lld", dp[n][n]);

	return 0;
}