#include <iostream>

#define INF 1<<30
#define N 55

int n, ans;
int h[N];

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &h[i]);
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		double g = -INF;
		for (int j = i - 1; j; j--) {
			double t = (double)((double)h[j] - h[i]) / (i - j);
			if (g < t) {
				cnt++;
				g = t;
			}
		}
		g = -INF;
		for (int j = i + 1; j <= n; j++) {
			double t = (double)((double)h[j] - h[i]) / (j - i);
			if (g < t) {
				cnt++;
				g = t;
			}
		}
		if (ans < cnt) ans = cnt;
	}

	printf("%d", ans);

	return 0;
}