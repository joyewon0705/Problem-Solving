#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 1<<30
#define N 1010
typedef pair<int, int> P;

int n, m, a, b, c, wst, bst;
bool isVisit[N][2];
vector<P> v[N];
priority_queue<P> max_q;
priority_queue<P, vector<P>, greater<P>> min_q;

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 0; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ !c, b });
		v[b].push_back({ !c, a });
	}

	max_q.push({ 0, 0 });
	while (!max_q.empty()) {
		int val = max_q.top().first;
		int cur = max_q.top().second;
		max_q.pop();

		if (isVisit[cur][0]) continue;
		isVisit[cur][0] = true;
		if (val) wst++;

		for (P next : v[cur]) {
			if (isVisit[next.second][0]) continue;
			max_q.push(next);
		}
	}

	min_q.push({ 0, 0 });
	while (!min_q.empty()) {
		int val = min_q.top().first;
		int cur = min_q.top().second;
		min_q.pop();

		if (isVisit[cur][1]) continue;
		isVisit[cur][1] = true;
		if (val) bst++;

		for (P next : v[cur]) {
			if (isVisit[next.second][1]) continue;
			min_q.push(next);
		}
	}

	printf("%d", wst * wst - bst * bst);

	return 0;
}