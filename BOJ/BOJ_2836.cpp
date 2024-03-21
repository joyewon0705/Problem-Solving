#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> P;

int n, m, a, b;
long long ans;
priority_queue<P> pq;

int main(void) {
	
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		if (a > b) pq.push({ a, b });
	}

	ans = m;
	a = pq.top().first;
	b = pq.top().second;
	while (!pq.empty()) {
		int x = pq.top().first;
		int y = pq.top().second;
		pq.pop();

		if (b > x) {
			ans += 2 * (a - b);
			a = x;
			b = y;
		}
		else b = min(b, y);
	}
	ans += 2 * (a - b);

	printf("%lld", ans);
		
	return 0;
}