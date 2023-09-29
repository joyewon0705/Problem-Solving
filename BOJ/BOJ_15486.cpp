#include <iostream>
#include <vector>
using namespace std;

#define N 1505050
typedef pair<int, int> P;

int n, t, p;
int dp[N];
vector<P> v = { { 0, 0 } };

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &t, &p);
		v.push_back({ t, p });
	}

	for (int i = 1; i <= n; i++) {
		if (dp[i - 1] > dp[i]) dp[i] = dp[i - 1];
		int tmp = dp[i] + v[i].second;
		if (dp[i + v[i].first] < tmp)
			dp[i + v[i].first] = tmp;
	}

	if (dp[n] > dp[n + 1]) dp[n + 1] = dp[n];
	printf("%d", dp[n + 1]);

	return 0;
}