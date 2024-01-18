#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define N 1010
typedef pair<int, int> P;

int n, m, u, v, d, ans;
bool s[N], chk[N];
vector<P> r[N];
priority_queue<P, vector<P>, greater<P>> pq;

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		getchar();
		if (getchar() == 'M') s[i] = true;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &d);
		r[u].push_back({ d, v });
		r[v].push_back({ d, u });
	}

	pq.push({ 0, 1 });
	while (!pq.empty()) {
		int dst = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (chk[cur]) continue;
		chk[cur] = true;
		ans += dst;
		n--;

		bool sx = s[cur];
		for (P next : r[cur]) {
			if (sx == s[next.second]) continue;
			pq.push(next);
		}
	}
	
	if (n) ans = -1;
	printf("%d", ans);

	return 0;
}