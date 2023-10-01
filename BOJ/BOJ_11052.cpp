#include <iostream>
#include <cmath>
using namespace std;

#define N 1010

int n;
int dp[N];

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &dp[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i / 2; j++) {
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}

	printf("%d", dp[n]);

	return 0;
}