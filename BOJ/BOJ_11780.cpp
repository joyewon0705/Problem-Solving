#include <iostream>
#include <queue>
using namespace std;

#define INF 1<<30
#define N 101

int n, m, a, b, c;
int d[N][N], p[N][N];
queue<int> q;

void prt(int a, int b) {

	if (a == b) return;

	q.push(p[a][b]);
	prt(p[a][b], b);
}

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = INF;
		}
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (d[a][b] > c) {
			d[a][b] = c;
			p[a][b] = b;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (d[i][k] >= INF) continue;
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (d[k][j] >= INF) continue;
				if (i == 1 && j == 4)
					int tmp = 0;
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					p[i][j] = p[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] >= INF) printf("0 ");
			else printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] >= INF) printf("0\n");
			else {
				q.push(i);
				prt(i, j);

				printf("%d ", q.size());
				while (!q.empty()) {
					printf("%d ", q.front());
					q.pop();
				}
				printf("\n");
			}
		}
	}

	return 0;
}