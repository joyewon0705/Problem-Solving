#include <iostream>

#define N 1010101
typedef long long ll;

int range, ans;
ll min, max;
bool chk[N];

int main(void) {

	scanf("%lld %lld", &min, &max);

	range = max - min;
	for (int i = 0; i <= range; i++) chk[i] = true;
	for (ll i = 2; i * i <= max; i++) {
		ll low = min % (i * i) ? min / (i * i) + 1 : min / (i * i);
		for (ll j = low * i * i - min; j <= range; j += i * i) {
			chk[j] = false;
		}
	}
	for (ll i = 0; i <= range; i++) if (chk[i]) ans++;

	printf("%d", ans);

	return 0;
}