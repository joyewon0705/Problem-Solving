#include <iostream>

#define MOD 1000000007

int n, k;
long long ans = 1;

long long f(int x) {

	if (x == 0) return 1;
	if (x % 2) return (ans * f(x - 1)) % MOD;
	else {
		long long ret = f(x / 2);
		return (ret * ret) % MOD;
	}
}

int main(void) {

	scanf("%d %d", &n, &k);

	for (int i = 1; i <= k; i++) ans = (ans * i) % MOD;
	ans = f(MOD - 2);
	for (int i = n - k + 1; i <= n; i++) ans = (ans * i) % MOD;

	printf("%d", ans);

	return 0;
}