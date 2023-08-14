#include <iostream>

#define N 1010101

int n, m, k;
long long a, b, c;
long long v[N];
long long t[4 * N];

long long segmentTree(int cur, int low, int high) {

	if (low == high) return t[cur] = v[low];

	int mid = (low + high) / 2;
	return t[cur] = segmentTree(cur * 2, low, mid) + segmentTree(cur * 2 + 1, mid + 1, high);
}

long long getSum(int b, int c, int cur, int low, int high) {

	if (low > c || high < b) return 0;
	if (low >= b && high <= c) return t[cur];

	int mid = (low + high) / 2;
	return getSum(b, c, cur * 2, low, mid) + getSum(b, c, cur * 2 + 1, mid + 1, high);
}

void update(int cur, int idx, long long val, int low, int high) {
	
	if (idx < low || idx > high) return;

	t[cur] += val;
	if (low == high) return;

	int mid = (low + high) / 2;
	update(cur * 2, idx, val, low, mid);
	update(cur * 2 + 1, idx, val, mid + 1, high);
}

int main(void) {

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &v[i]);
	}
	
	segmentTree(1, 1, n);
	for (int t = 0; t < m + k; t++) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1) {
			update(1, b, c - v[b], 1, n);
			v[b] = c;
		}
		else if (a == 2) {
			long long sum = getSum(b, c, 1, 1, n);
			printf("%lld\n", sum);
		}
	}

	return 0;
}