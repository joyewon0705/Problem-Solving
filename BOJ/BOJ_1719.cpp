#include <iostream>

#define INF 1<<29
#define N 202

int n, m, a, b, c;
int p[N][N][2];

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		p[a][b][0] = c; p[a][b][1] = b;
		p[b][a][0] = c; p[b][a][1] = a;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (p[i][j][0] == 0) p[i][j][0] = INF;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (p[i][j][0] > p[i][k][0] + p[k][j][0]) {
					p[i][j][0] = p[i][k][0] + p[k][j][0];
					p[i][j][1] = p[i][k][1];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (p[i][j][1] == 0) printf("- ");
			else printf("%d ", p[i][j][1]);
		}
		printf("\n");
	}

	return 0;
}