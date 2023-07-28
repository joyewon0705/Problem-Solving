#include <iostream>

#define N 404

int n, k, a, b, s;
int order[N][N];

int main(void) {

	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &a, &b);
		order[a][b] = -1;
		order[b][a] = 1;
	}

	for (int h = 1; h <= n; h++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (order[i][h] * order[h][j] == 1) order[i][j] = order[i][h];
			}
		}
	}

	scanf("%d", &s);
	for (int i = 0; i < s; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", order[a][b]);
	}

	return 0;
}