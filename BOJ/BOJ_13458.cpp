#include <iostream>

#define N 1010101

int n, b, c;
long long ans = 0;
int A[N];

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d %d", &b, &c);

	for (int i = 1; i <= n; i++) {
		A[i] -= b;
		ans++;
		if (A[i] > 0) {
			ans += A[i] / c;
			if (A[i] % c) ans++;
		}
	}

	printf("%lld", ans);

	return 0;
}