#include <iostream>

#define N 33

int n;
long long dp[N][N];

long long f(int x, int y) {

	if (dp[x][y]) return dp[x][y];
	
	long long ret = 0;
	if (y) ret += f(x, y - 1);
	if (x) ret += f(x - 1, y + 1);
	return dp[x][y] = ret;
}

int main(void) {

	dp[1][0] = 1;
	dp[0][1] = 1;
	
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;
		printf("%lld\n", f(n, 0));
	}

	return 0;
}