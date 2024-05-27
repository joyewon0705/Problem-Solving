#include <iostream>
#include <algorithm>
using namespace std;

#define N 22
#define C 1010

int c, n, ans;
int cost[N], client[N];
int dp[C * 100];

int main(void) {

	scanf("%d %d", &c, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &cost[i], &client[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= C * 100; j++) {
			if (j - cost[i] >= 0) {
				dp[j] = max(dp[j], dp[j - cost[i]] + client[i]);
			}
		}
	}

	for (int i = 1; i <= C * 100; i++) {
		if (dp[i] >= c) {
			printf("%d", i);
			break;
		}
	}

	return 0;
}