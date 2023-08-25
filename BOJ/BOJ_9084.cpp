#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int t, n, m, in, ans;
int dp[21][10001];
vector<int> v;

int search(int idx, int rm) {

	if (dp[idx][rm] >= 0) return dp[idx][rm];
	dp[idx][rm] = 0;

	if (rm == 0) return dp[idx][rm] = 1;
	if (idx == 0) return 0;

	int val = v[idx];
	int tmp = rm / val;
	for (int i = tmp; i >= 0; i--) {
		int next = rm - (val * i);
		
		dp[idx][rm] += search(idx - 1, next);
	}
	return dp[idx][rm];
}

int main(void) {

	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		memset(dp, -1, sizeof(dp));
		v = { 0 };
		ans = 0;

		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &in);
			v.push_back(in);
		}
		scanf("%d", &m);

		ans = search(n, m);

		printf("%d\n", ans);
	}

	return 0;
}