#include <iostream>
#include <algorithm>
using namespace std;

#define N 1010

int n, m, ans;
bool map[N][N];
int dp[N][N][3];

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 1; j <= m; j++) {
			if (getchar() == '1') map[i][j] = true;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j]) {
				dp[i][j][0] = dp[i - 1][j][0] + 1;
				dp[i][j][1] = dp[i][j - 1][1] + 1;
				dp[i][j][2] = min(dp[i - 1][j - 1][2] + 1, min(dp[i][j][0], dp[i][j][1]));
				if (dp[i][j][2] < 1) dp[i][j][2] = 1;
				if (ans < dp[i][j][2]) ans = dp[i][j][2];
			}
		}
	}

	printf("%d", ans * ans);

	return 0;
}