#include <iostream>

#define INF 1<<30
#define N 11

int n, k, ans = INF;
bool isVisit[N];
int T[N][N];

void f(int cur, int cnt, int val) {

	if (ans < val) return;
	if (cnt == n - 1) {
		if (ans > val) ans = val;
		return;
	}

	for (int next = 0; next < n; next++) {
		if (isVisit[next]) continue;
		isVisit[next] = true;
		f(next, cnt + 1, val + T[cur][next]);
		isVisit[next] = false;
	}
}

int main(void) {

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &T[i][j]);
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (T[i][j] > T[i][k] + T[k][j])
					T[i][j] = T[i][k] + T[k][j];
			}
		}
	}

	isVisit[k] = true;
	f(k, 0, 0);

	printf("%d", ans);

	return 0;
}