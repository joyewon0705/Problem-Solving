#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int k, q;
ll n, x, y;

ll getDepth(ll x) {
	ll i = 1, j = 0;
	 
	while (x > i) {
		j++;
		i += pow(k, j);
	}
	return j;
}

long long f() {
	long long  dx, dy, ans;

	dx = getDepth(x);
	dy = getDepth(y);

	ans = 0;
	while (dx > dy) {
		x = (x + k - 2) / k;
		dx--;
		ans++;
	}
	while (dx < dy) {
		y = (y + k - 2) / k;
		dy--;
		ans++;
	}
	while (x != y) {
		x = (x + k - 2) / k;
		y = (y + k - 2) / k;
		ans += 2;
	}
	return ans;
}

int main(void) {

	scanf("%lld %d %d", &n, &k, &q);
	for (int i = 0; i < q; i++) {
		scanf("%lld %lld", &x, &y);

		if (k == 1) printf("%lld\n", abs(x - y));
		else printf("%lld\n", f());
	}

	return 0;
}