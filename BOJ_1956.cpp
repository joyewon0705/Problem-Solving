#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1<<30
#define V 404
typedef pair<int, int> P;

int v, e, a, b, c, ans;
int dist[V][V];
vector<P> edges[V];

int main(void) {

	scanf("%d %d", &v, &e);
	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			dist[i][j] = INF;
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edges[a].push_back({ c, b });
		dist[a][b] = c;
	}

	for (int j = 1; j <= v; j++) {
		for (int i = 1; i <= v; i++) {
			if (dist[i][j] >= INF) continue;
			for (P edge : edges[j]) {
				dist[i][edge.second] = min(dist[i][edge.second], dist[i][j] + edge.first);
			}
		}
	}

	ans = INF;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (dist[i][j] >= INF || dist[j][i] >= INF) continue;
			ans = min(ans, dist[i][j] + dist[j][i]);
		}
	}

	if (ans >= INF) printf("-1");
	else printf("%d", ans);

	return 0;
}