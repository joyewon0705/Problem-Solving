#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 1010
typedef pair<int, int> P;

int t, k, m, p, a, b;
vector<bool> isVisit;
vector<int> v[N], cnt;
vector<P> chk;
queue<int> q;

int main(void) {

	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d %d %d", &k, &m, &p);
		
		isVisit = vector<bool>(m + 1, false);
		for (int i = 1; i <= m; i++) v[i] = vector<int>();
		cnt = vector<int>(m + 1, 0);
		chk = vector<P>(m + 1, { 0, 0 });

		for (int i = 0; i < p; i++) {
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
			cnt[b]++;
		}

		for (int i = 1; i <= m; i++) {
			if (cnt[i]) continue;
			q.push(i);
			chk[i] = { 1, 0 };
		}

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			if (isVisit[cur]) continue;
			isVisit[cur] = true;

			if (chk[cur].second > 1)
				chk[cur] = { chk[cur].first + 1, 0 };

			for (int next : v[cur]) {
				if (chk[next].first < chk[cur].first)
					chk[next] = { chk[cur].first, 1 };
				else if (chk[next].first == chk[cur].first)
					chk[next].second++;
				cnt[next]--;
				if (cnt[next] == 0) q.push(next);
			}
		}

		printf("%d %d\n", tc, chk[m].first);
	}

	return 0;
}