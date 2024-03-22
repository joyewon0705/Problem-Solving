#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define N 10101

typedef pair<int, int> P;

int n, m, t, a, b, c, ans, cnt;
bool isVisit[N];
vector<P> v[N];
priority_queue<P, vector<P>, greater<P>> pq;

int main(void) {

	scanf("%d %d %d", &n, &m, &t);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ c, b });
		v[b].push_back({ c, a });
	}

	isVisit[1] = true;
	for (P next : v[1]) pq.push(next);
	while (!pq.empty()) {
		int val = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (isVisit[cur]) continue;
		isVisit[cur] = true;
		ans += val + t * cnt++;
		
		for (P next : v[cur]) pq.push(next);
	}

	printf("%d", ans);
		
	return 0;
}