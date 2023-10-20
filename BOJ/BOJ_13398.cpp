#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1<<30
#define N 101010

int n, ans = -INF;
int a[N], dp[N][2];

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	dp[0][0] = -INF;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = max(a[i], dp[i - 1][0] + a[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + a[i]);
		ans = max(ans, max(dp[i][0], dp[i][1]));
	}

	printf("%d", ans);

	return 0;
}