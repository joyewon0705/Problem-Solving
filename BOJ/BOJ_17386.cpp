#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

int chk1, chk2;
P a, b, c, d;

int ccw(P a, P b, P c) {
	ll ret = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
	if (ret < 0) return -1;
	else if (ret > 0) return 1;
	else return 0;
}

int main(void) {
	
	scanf("%lld %lld %lld %lld", &a.first, &a.second, &b.first, &b.second);
	scanf("%lld %lld %lld %lld", &c.first, &c.second, &d.first, &d.second);

	chk1 = ccw(a, b, c) * ccw(a, b, d);
	chk2 = ccw(c, d, a) * ccw(c, d, b);
	
	if (chk1 < 0 && chk2 < 0) printf("1");
	else printf("0");

	return 0;
}