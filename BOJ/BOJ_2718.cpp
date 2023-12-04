#include <iostream>
#include <vector>
using namespace std;

int t, n;
vector<int> dp, sum;

int main(void) {

	dp = { 1, 1, 5, 11 };
	sum = { 1, 1, 6, 12 };

	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		scanf("%d", &n);
		for (int i = dp.size(); i <= n; i++) {
			dp.push_back(dp[i - 1] + dp[i - 2] * 4 + sum[i - 3] * 2 + sum[i - 4] * 3);
			sum.push_back(dp[i] + sum[i - 2]);
		}
		printf("%d\n", dp[n]);
	}

	return 0;
}