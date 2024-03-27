#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 30303
#define K 3030
typedef pair<int, int> P;

int n, m, k, a, b, ans;
bool isVisit[N];
int dp[K];
vector<int> c, v[N];
vector<P> pv;
queue<int> q;

int main(void) {

	scanf("%d %d %d", &n, &m, &k);
	c.push_back(0);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		c.push_back(a);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (isVisit[i]) continue;

		int sum = 0;
		int cnt = 0;
		q.push(i);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			if (isVisit[cur]) continue;
			isVisit[cur] = true;
			sum += c[cur];
			cnt++;

			for (int next : v[cur]) q.push(next);
		}

		pv.push_back({ cnt , sum });
	}

	a = pv.size();
	b = 0;
	for (int i = 0; i < a; i++) {
		b += pv[i].first;
		for (int j = min(b, k - 1); j >= pv[i].first; j--) {
			dp[j] = max(dp[j], dp[j - pv[i].first] + pv[i].second);
			if (ans < dp[j]) ans = dp[j];
		}
	}

	printf("%d", ans);

	return 0;
}