#include <iostream>
#include <algorithm>
using namespace std;

#define INF (long long)1<<60
#define N 101

int t, n;
int num[] = {0, 0, 1, 7, 4, 2, 0, 8};
long long dp[N] = { 0, 9, 1, 7, 4, 2, 6, 8 };

int main(void) {

	for (int i = 8; i < N; i++) {
		dp[i] = INF;
		for (int j = 2; j <= 7; j++) {
			dp[i] = min(dp[i], dp[i - j] * 10 + num[j]);
		}
	}

	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		scanf("%d", &n);

		printf("%lld ", dp[n]);
		if (n % 2) printf("%d", 7);
		else printf("%d", 1);
		for (int i = n / 2 - 1; i; i--) printf("%d", 1);
		printf("\n");
	}

	return 0;
}