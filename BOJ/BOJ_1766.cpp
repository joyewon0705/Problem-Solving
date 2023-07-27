#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 32032

int n, m, a, b;
int cnt[N], isVisit[N];
vector<int> v[N], ans;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		cnt[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) pq.push(i);
	}

	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();

		if (isVisit[cur]) continue;
		isVisit[cur] = 1;
		ans.push_back(cur);

		for (int next : v[cur]) {
			cnt[next]--;
			if (cnt[next] == 0) pq.push(next);
		}
	}

	for (int prt : ans) printf("%d ", prt);

	return 0;
}