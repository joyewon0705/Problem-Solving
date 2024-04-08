#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, h, o, d, cnt, ans;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &h, &o);
		if (h > o) v.push_back({ h, o });
		else v.push_back({ o, h });
	}
	scanf("%d", &d);

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		int t = v[i].first - d;
		if (v[i].second >= t) pq.push(v[i].second);
		while (!pq.empty() && pq.top() < t) pq.pop();
		ans = max(ans, (int)pq.size());
	}

	printf("%d", ans);

	return 0;
}