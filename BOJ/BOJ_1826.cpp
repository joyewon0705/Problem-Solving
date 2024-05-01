#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> P;

int n, a, b, l, p, ans;
vector<P> v;
priority_queue<int> pq;

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		v.push_back({ a, b });
	}
	scanf("%d %d", &l, &p);

	sort(v.begin(), v.end());

	a = 0;
	while (p < l) {
		while (a < n && p >= v[a].first) {
			pq.push({ v[a].second });
			a++;
		}

		if (pq.empty()) {
			ans = -1;
			break;
		}

		p += pq.top();
		pq.pop();
		ans++;
	}

	printf("%d", ans);

	return 0;
}