#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1<<30
#define N 10101
typedef pair<int, int> P;

int t, n, d, c, a, b, s, ans1, ans2;
int chk[N];
vector<P> v[N];	
queue<P> q;

int main(void) {

	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		
		scanf("%d %d %d", &n, &d, &c);
		for (int i = 1; i <= n; i++) {
			chk[i] = INF;
			v[i] = vector<P>();
		}
		for (int i = 0; i < d; i++) {
			scanf("%d %d %d", &a, &b, &s);
			v[b].push_back({ a, s });
		}

		ans1 = 0;
		q.push({ c, 0 });
		while (!q.empty()) {
			int cur = q.front().first;
			int cnt = q.front().second;
			q.pop();

			if (chk[cur] <= cnt) continue;
			if (chk[cur] >= INF) ans1++;
			chk[cur] = cnt;

			for (P next : v[cur]) {
				q.push({ next.first, cnt + next.second });
			}
		}

		ans2 = 0;
		for (int i = 1; i <= n; i++) {
			if (chk[i] < INF && chk[i] > ans2) {
				ans2 = chk[i];
			}
		}

		printf("%d %d\n", ans1, ans2);
	}

	return 0;
}