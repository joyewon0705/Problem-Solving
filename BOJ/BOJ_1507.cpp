#include <iostream>
#include <queue>
using namespace std;

#define N 22
typedef pair<int, int> P;

int n, ans;
int m[N][N], t[N][N];

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &m[i][j]);
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (i == k || m[i][k] == 0) continue;
			for (int j = 1; j <= n; j++) {
				if (j == k || m[k][j] == 0) continue;
				if (m[i][j] == m[i][k] + m[k][j]) m[i][j] = 0;
				else if (m[i][j] > m[i][k] + m[k][j]) {
					ans = -1;
					break;
				}
			}
			if (ans < 0) break;
		}
		if (ans < 0) break;
	}

	if (ans == 0) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ans += m[i][j];
			}
		}
	}

	printf("%d", ans);

	return 0;
}