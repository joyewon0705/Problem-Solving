#include <iostream>

#define N 1010101

int n, m, ans;
int idx2num[N], num2idx[N], dp[N];

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &idx2num[i]);
		num2idx[idx2num[i]] = i;
	}
	for (int i = n; i; i--) {
		dp[i] = 1 + dp[num2idx[idx2num[i] + 1]];
		if (ans < dp[i]) ans = dp[i];
	}

	printf("%d", n - ans);

	return 0;
}