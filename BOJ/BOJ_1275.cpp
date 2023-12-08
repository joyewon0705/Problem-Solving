#include <iostream>

#define N 101010
typedef long long ll;

int n, q, x, y, a, b;
int num[N];
ll sum[4 * N];

ll init(int cur, int low, int high) {

	if (low == high) return num[low];
	int mid = (low + high) / 2;
	return sum[cur] = init(2 * cur, low, mid) + init(2 * cur + 1, mid + 1, high);
}

ll getSum(int cur, int low, int high) {

	if (y < low || high < x) return 0;
	if (low == high) return num[low];
	if (x <= low && high <= y) return sum[cur];
	int mid = (low + high) / 2;
	return getSum(2 * cur, low, mid) + getSum(2 * cur + 1, mid + 1, high);
}

ll update(int cur, int low, int high) {

	if (low == high) {
		if (low == a) num[a] = b;
		return num[low];
	}
	if (low <= a && a <= high) {
		int mid = (low + high) / 2;
		return sum[cur] = update(2 * cur, low, mid) + update(2 * cur + 1, mid + 1, high);
	}
	return sum[cur];
}

int main(void) {

	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}
	init(1, 1, n);

	for (int i = 0; i < q; i++) {
		scanf("%d %d %d %d", &x, &y, &a, &b);
		if (x > y) {
			int t = x;
			x = y;
			y = t;
		}
		printf("%lld\n", getSum(1, 1, n));
		update(1, 1, n);
	}

	return 0;
}