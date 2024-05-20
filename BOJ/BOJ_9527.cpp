#include <iostream>

#define N 55
typedef long long ll;

ll a, b;
ll dp[N];

ll f(ll x) {
	ll ret = x & 1;
	for (int i = N; i; i--) {
		if (x & (1LL << i)) {
			x -= 1LL << i;
			ret += dp[i - 1] + x + 1;
		}
	}
	return ret;
}

int main(void) {

	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		dp[i] = dp[i - 1] * 2 + (1LL << i);
	}

	scanf("%lld %lld", &a, &b);
	printf("%lld", f(b) - f(a - 1));

	return 0;
}