#include <iostream>
#include <algorithm>
using namespace std;

#define N 10101

int n, ans;
int a[N], dp[N][3];

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	dp[1][1] = a[1];
	for (int i = 2; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
		dp[i][1] = dp[i - 1][0] + a[i];
		dp[i][2] = dp[i - 1][1] + a[i];
	}

	ans = max(dp[n][0], max(dp[n][1], dp[n][2]));
	printf("%d", ans);

	return 0;
}