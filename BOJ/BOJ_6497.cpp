#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define M 202020
typedef pair<int, int> P;

int m, n, x, y, z, sum, ans;
bool chk[M];
vector<P> v[M];
priority_queue<P, vector<P>, greater<P>> pq;

int main(void) {

	while (true) {
		scanf("%d %d", &m, &n);
		
		if (m == 0 && n == 0) break;

		for (int i = 0; i < m; i++) {
			v[i] = vector<P>();
			chk[i] = false;
		}

		sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &x, &y, &z);
			v[x].push_back({ z, y });
			v[y].push_back({ z, x });
			sum += z;
		}

		ans = 0;
		pq.push({ 0, 0 });
		while (!pq.empty()) {
			int val = pq.top().first;
			int cur = pq.top().second;
			pq.pop();

			if (chk[cur]) continue;
			chk[cur] = true;
			ans += val;

			for (P next : v[cur]) {
				if (chk[next.second]) continue;
				pq.push(next);
			}
		}

		printf("%d\n", sum - ans);
	}

	return 0;
}