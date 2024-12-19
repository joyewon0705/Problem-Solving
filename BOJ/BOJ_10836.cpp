#include <iostream>

#define M 707

int m, n, g0, g1, g2;
int larva[2 * M];

int main(void) {

	scanf("%d %d", &m, &n);
	for (int i = 1; i < 2 * m; i++) {
		larva[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &g0, &g1, &g2);

		for (int j = g0 + 1; j <= g0 + g1; j++) larva[j] += 1;
		for (int j = g0 + g1 + 1; j <= 2 * m; j++) larva[j] += 2;
	}

	for (int i = 1; i <= m; i++) {
		printf("%d ", larva[m + 1 - i]);
		for (int j = 2; j <= m; j++) {
			printf("%d ", larva[m - 1 + j]);
		}
		printf("\n");
	}

	return 0;
}