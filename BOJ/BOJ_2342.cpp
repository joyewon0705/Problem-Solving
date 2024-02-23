#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1<<30
#define N 101010

int n, ans;
int a[N], dp[N][5][5];

int move(int a, int b) {

	if (a == 0) return 2;
	if (a == b) return 1;
	if (abs(a - b) == 2) return 4;
	return 3;
}

int main(void) {

	for (int i = 1; ; i++) {
		scanf("%d", &a[i]);
		if (!a[i]) {
			n = i - 1;
			break;
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int l = 0; l < 5; l++) {
			for (int r = 0; r < 5; r++) {
				dp[i][l][r] = INF;
			}
		}
	}

	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i++) {
		int t = a[i];
		for (int l = 0; l < 5; l++) {
			for (int r = 0; r < 5; r++) {
				if (dp[i - 1][l][r] >= INF) continue;
				dp[i][t][r] = min(dp[i][t][r], dp[i - 1][l][r] + move(l, t));
				dp[i][l][t] = min(dp[i][l][t], dp[i - 1][l][r] + move(r, t));
			}
		}
	}

	ans = INF;
	for (int l = 0; l < 5; l++) {
		for (int r = 0; r < 5; r++) {
			if (ans > dp[n][l][r]) ans = dp[n][l][r];
		}
	}
	printf("%d", ans);

	return 0;
}