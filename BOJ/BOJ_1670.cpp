#include <iostream>

#define N 10101
#define MOD 987654321

int n;
long long d[N];

int main(void) {

	scanf("%d", &n);

	d[0] = 1;
	for (int i = 2; i <= n; i += 2) {
		for (int j = 0; j <= i - 2; j += 2) {
			d[i] += d[j] * d[i - 2 - j];
			d[i] %= MOD;
		}
	}

	printf("%lld", d[n]);

	return 0;
}