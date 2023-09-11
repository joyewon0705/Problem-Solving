#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 101
typedef pair<int, int> P;

int n, a, b, cnt;
int dp[N];
vector<int> m = { 0 };
vector<P> v;

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end());
	m.push_back(v[0].second);
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m.size(); j++) {
			if (v[i].second < m[j]) {
				m[j] = v[i].second;
				dp[i] = j;
				break;
			}
		}
		if (dp[i] == 0) {
			m.push_back(v[i].second);
			dp[i] = m.size() - 1;
		}
		if (cnt < dp[i]) cnt = dp[i];
	}

	printf("%d", n - cnt);

	return 0;
}