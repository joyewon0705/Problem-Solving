#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> P;

int n, p, q, cnt;
vector<int> c;
vector<P> v;
priority_queue<P, vector<P>, greater<P>> pq, pq2;

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p, &q);
		v.push_back({ p, q });
	}

	sort(v.begin(), v.end());

	c.push_back(0);
	pq.push({ 0, 0 });
	for (P cur : v) {
		while (!pq.empty() && pq.top().first <= cur.first) {
			pq2.push({ pq.top().second, pq.top().first });
			pq.pop();
		}
		if (pq2.empty()) {
			pq.push({ cur.second, c.size()});
			c.push_back(1);
		}
		else {
			int t = pq2.top().first;
			pq2.pop();
			pq.push({ cur.second, t });
			c[t]++;
		}
	}

	printf("%d\n", c.size());
	for (int prt : c) printf("%d ", prt);

	return 0;
}