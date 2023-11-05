#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 1010

int t, n;
int a[N], dp[N][N];

int f(int i, int j) {

	if (i > j) return 0;
	if (dp[i][j]) return dp[i][j];

	if ((n + i - j) % 2)
		return dp[i][j] = max(a[i] + f(i + 1, j), f(i, j - 1) + a[j]);
	else
		return dp[i][j] = min(f(i + 1, j), f(i, j - 1));
}

int main(void) {

	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		memset(dp, 0, sizeof(dp));

		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}

		printf("%d\n", f(1, n));
	}

	return 0;
}