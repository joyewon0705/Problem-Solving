#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 1010
typedef pair<int, int> P;

int n, m, k, u, v, w, ans;
bool isVisit[N];
vector<P> cable[N];
priority_queue<P, vector<P>, greater<P>> pq;

int main(void) {
	
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &u);
		pq.push({ 0, u });
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		cable[u].push_back({ w, v });
		cable[v].push_back({ w, u });
	}

	while (!pq.empty()) {
		int val = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (isVisit[cur]) continue;
		isVisit[cur] = true;
		ans += val;

		for (P next : cable[cur]) pq.push(next);
	}

	printf("%d", ans);

	return 0;
}