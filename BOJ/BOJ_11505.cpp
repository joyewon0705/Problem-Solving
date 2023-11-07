#include <iostream>

#define N 1010101
#define MOD 1000000007

int n, m, k, a, b, c;
int num[N], d[4 * N];

long long f1(int cur, int low, int high) {

	if (low == high) return d[cur] = num[low];

	int mid = (low + high) / 2;
	long long val = f1(2 * cur, low, mid) * f1(2 * cur + 1, mid + 1, high);
	return d[cur] = val % MOD;
}

long long f2(int cur, int low, int high, int x, int y) {

	if (high < x || y < low) return 1;
	if (x <= low && high <= y) return d[cur];

	int mid = (low + high) / 2;
	long long val = f2(2 * cur, low, mid, x, y) * f2(2 * cur + 1, mid + 1, high, x, y);
	return val % MOD;
}

long long f3(int cur, int low, int high, int x) {

	if (x < low || high < x) return d[cur];
	if (low == high) return d[cur] = num[low];

	int mid = (low + high) / 2;
	long long val = f3(2 * cur, low, mid, x) * f3(2 * cur + 1, mid + 1, high, x);
	return d[cur] = val % MOD;
}

int main(void) {

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}
	f1(1, 1, n);
	for (int i = m + k; i; i--) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			num[b] = c;
			f3(1, 1, n, b);
		}
		else {
			printf("%lld\n", f2(1, 1, n, b, c));
		}
	}

	return 0;
}