#include <iostream>
#include <queue>
using namespace std;

#define N 10101

int n, m, p, d, ans;
priority_queue<int> pq[N];

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p, &d);
		pq[d].push(p);
		if (m < d) m = d;
	}

	for (int i = m; i; i--) {
		int chk = 0, val = 0;
		for (int j = i; j <= m; j++) {
			if (pq[j].empty()) continue;
			if (pq[j].top() > val) {
				chk = j;
				val = pq[j].top();
			}
		}
		ans += val;
		if (chk) pq[chk].pop();
	}

	printf("%d", ans);

	return 0;
}