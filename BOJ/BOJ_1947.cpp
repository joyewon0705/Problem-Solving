#include <iostream>

#define N 1010101
#define MOD 1000000000

int n;
long long d[N];

int main(void) {

	scanf("%d", &n);
	d[2] = 1; d[3] = 2;
	for (int i = 4; i <= n; i++) {

		d[i] = (i - 1) * ((d[i - 2] + d[i - 1]) % MOD) % MOD;
	}
	printf("%lld", d[n]);

	return 0;
}