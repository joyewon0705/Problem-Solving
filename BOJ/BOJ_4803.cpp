#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 505
typedef pair<int, int> P;

int n, m, a, b, ans;
bool isVisit[N];
vector<int> v[N];
queue<P> q;

int main(void) {

	for (int tc = 1; ; tc++) {
		scanf("%d %d", &n, &m);
		if (!n && !m) break;

		q = queue<P>();
		for (int i = 1; i <= n; i++) {
			v[i] = vector<int>();
			isVisit[i] = false;
		}

		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		
		ans = 0;
		for (int i = 1; i <= n; i++) {
			if (isVisit[i]) continue;

			bool isTree = true;
			q.push({ i, 0 });
			while (!q.empty()) {
				int cur = q.front().first;
				int before = q.front().second;
				q.pop();

				if (isVisit[cur]) {
					isTree = false;
					continue;
				}
				isVisit[cur] = true;

				for (int next : v[cur]) {
					if (next == before) continue;
					q.push({ next, cur });
				}
			}

			if (isTree) ans++;
		}

		printf("Case %d: ", tc);
		if (ans == 0) printf("No trees.\n");
		else if (ans == 1) printf("There is one tree.\n");
		else printf("A forest of %d trees.\n", ans);
	}

	return 0;
}