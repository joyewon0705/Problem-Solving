#include <iostream>
#include <cmath>
using namespace std;

#define N 16

int n, t, p;
int dp[N];

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &t, &p);
		dp[i] = max(dp[i - 1], dp[i]);
		if (i + t - 1 <= n) {
			dp[i + t - 1] = max(dp[i + t - 1], dp[i - 1] + p);
		}
	}
	printf("%d", dp[n]);

	return 0;
}