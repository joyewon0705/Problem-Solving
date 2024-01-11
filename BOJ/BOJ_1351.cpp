#include <iostream>
#include <map>
using namespace std;

long long n, p, q;
map<long long, long long> m;

long long f(long long x) {
	long long a, b, ret = 0;

	if (x == 0) return 1;

	a = x / p;
	if (m.find(a) == m.end()) {
		b = f(a);
		m.insert({ a, b });
	}
	ret += m[a];

	a = x / q;
	if (m.find(a) == m.end()) {
		b = f(a);
		m.insert({ a, b });
	}
	ret += m[a];

	return ret;
}

int main(void) {

	scanf("%lld %lld %lld", &n, &p, &q);
	printf("%lld", f(n));

	return 0;
}