#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> P;

int n, m, a, b, ans;
priority_queue<int> pq;
priority_queue<P> list;

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		list.push({ a, b });
		if (m < a) m = a;
	}

	for (int i = m; i; i--) {
		while (!list.empty() && list.top().first >= i) {
			P cur = list.top();
			list.pop();
			pq.push(cur.second);
		}

		if (pq.empty()) continue;
		ans += pq.top();
		pq.pop();
	}

	printf("%d", ans);

	return 0;
}