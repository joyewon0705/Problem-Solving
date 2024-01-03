#include <iostream>

#define INF 1<<30
#define N 22

int n, cnt, total, sum, mmax, mmin, ans = INF;
int A[N][N];

int f(int x, int y, int d1, int d2) {
	sum = 0; mmax = 0; mmin = INF;

	cnt = 0;
	for (int i = 1, l = y; i < x + d1; i++) {
		if (i >= x) l--;
		for (int j = 1; j <= l; j++) {
			cnt += A[i][j];
		}
	}
	if (mmax < cnt) mmax = cnt;
	if (mmin > cnt) mmin = cnt;
	sum += cnt;

	cnt = 0;
	for (int i = 1, l = y + 1; i <= x + d2; i++) {
		if (i > x) l++;
		for (int j = l; j <= n; j++) {
			cnt += A[i][j];
		}
	}
	if (mmax < cnt) mmax = cnt;
	if (mmin > cnt) mmin = cnt;
	sum += cnt;

	cnt = 0;
	for (int i = x + d1, l = y - d1 - 1; i <= n; i++) {
		if (i <= x + d1 + d2) l++;
		for (int j = 1; j < l; j++) {
			cnt += A[i][j];
		}
	}
	if (mmax < cnt) mmax = cnt;
	if (mmin > cnt) mmin = cnt;
	sum += cnt;

	cnt = 0;
	for (int i = x + d2 + 1, l = y + d2 + 1; i <= n; i++) {
		if (i <= x + d1 + d2 + 1) l--;
		for (int j = l; j <= n; j++) {
			cnt += A[i][j];
		}
	}
	if (mmax < cnt) mmax = cnt;
	if (mmin > cnt) mmin = cnt;
	sum += cnt;

	cnt = total - sum;
	if (mmax < cnt) mmax = cnt;
	if (mmin > cnt) mmin = cnt;

	return mmax - mmin;
}

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &A[i][j]);
			total += A[i][j];
		}
	}

	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			for (int d1 = 1; x + d1 <= n; d1++) {
				for (int d2 = 1; x + d2 <= n; d2++) {
					if (x + d1 + d2 > n || y - d1 < 1 || y + d2 > n) continue;
					
					int ret = f(x, y, d1, d2);
					if (ans > ret) ans = ret;
				}
			}
		}
	}

	printf("%d", ans);

	return 0;
}