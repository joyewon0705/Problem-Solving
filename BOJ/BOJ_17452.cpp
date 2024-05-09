#include <iostream>

#define N 1010101

int t, n;
long long d[N];

int main(void) {

	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j += i) {
			d[j] += i;
		}
		d[i] += d[i - 1];
	}

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%lld\n", d[n]);
	}

	return 0;
}