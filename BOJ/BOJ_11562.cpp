#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1<<30
#define N 252

int n, m, u, v, b, k, s, e;
int d[N][N];

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &b);
		d[u][v] = 0;
		if (b) d[v][u] = 0;
		else d[v][u] = 1;
	}
	scanf("%d", &k);

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][k] == INF || d[k][j] == INF) continue;
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	for (int i = 0; i < k; i++) {
		scanf("%d %d", &s, &e);
		printf("%d\n", d[s][e]);
	}

	return 0;
}