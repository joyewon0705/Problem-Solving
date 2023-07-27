#include <iostream>
#include <algorithm>
using namespace std;

#define N 1010

int n, m;
int val[N][N], L[N], R[N];

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &val[i][j]);
		}
	}

	for (int j = 2; j <= m; j++) val[1][j] = val[1][j - 1] + val[1][j];
	for (int i = 2; i <= n; i++) {
		L[1] = val[i - 1][1] + val[i][1];
		R[m] = val[i - 1][m] + val[i][m];
		for (int j = 2; j <= m; j++) L[j] = max(val[i - 1][j], L[j - 1]) + val[i][j];
		for (int j = m - 1; j > 0; j--) R[j] = max(val[i - 1][j], R[j + 1]) + val[i][j];
		for (int j = 1; j <= m; j++) val[i][j] = max(L[j], R[j]);
	}

	printf("%d", val[n][m]);

	return 0;
}