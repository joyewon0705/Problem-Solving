#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define N 10101
typedef pair<int, int> P;

int n, m, k, ans;
int t[N], cnt[N];
vector<int> v[N];
priority_queue<P, vector<P>, greater<P>> pq;

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			scanf("%d", &k);
			v[k].push_back(i);
			cnt[i]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) pq.push({ t[i], i });
	}
	while (!pq.empty()) {
		int val = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		ans = val;

		for (int next : v[cur]) {
			cnt[next]--;
			if (cnt[next] == 0) pq.push({ val + t[next], next });
		}
	}

	printf("%d", ans);

	return 0;
}