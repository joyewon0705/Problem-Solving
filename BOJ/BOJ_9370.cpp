#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1<<29
#define N 2020
typedef pair<int, int> P;

int tc, n, m, t, s, f, g, h, a, b, d, x;
vector<int> v, ds, dg, dh;
vector<P> p[N];

vector<int> dijkstra(int s) {
	int cur, next;
	vector<bool> chk = vector<bool>(n + 1, false);
	vector<int> d = vector<int>(n + 1, INF);

	d[s] = 0;
	next = s;
	for (int i = 1; next; i++) {
		cur = next;
		chk[cur] = true;

		for (P path : p[cur]) {
			if (chk[path.second]) continue;
			d[path.second] = min(d[path.second], d[cur] + path.first);
			if (!next || d[next] > d[path.second]) next = path.second;
		}
		
		next = 0;
		for (int j = 1; j <= n; j++) {
			if (chk[j] || d[j] >= INF) continue;
			if (!next || d[next] > d[j]) next = j;
		}

		cur = next;
		chk[cur] = true;
	}
	return d;
}

int main(void) {

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d %d", &n, &m, &t);
		scanf("%d %d %d", &s, &g, &h);
		
		v = vector<int>();
		for (int i = 1; i <= n; i++) p[i] = vector<P>();
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &d);
			p[a].push_back({ d, b });
			p[b].push_back({ d, a });
			if ((a == g && b == h) || (a == h && b == g)) f = d;
		}
		for (int i = 0; i < t; i++) {
			scanf("%d", &x);
			v.push_back(x);
		}

		ds = dijkstra(s);
		dg = dijkstra(g);
		dh = dijkstra(h);

		sort(v.begin(), v.end());
		for (int e : v) {
			if (ds[e] < ds[g] + f + dh[e] && ds[e] < ds[h] + f + dg[e]) continue;
			printf("%d ", e);
		}
		printf("\n");

	}

	return 0;
}