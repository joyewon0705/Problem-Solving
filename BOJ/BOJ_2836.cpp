#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> P;

int n, m, a, b;
long long ans;
vector<P> v;

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		if (a > b) v.push_back({ b, a });
	}

	sort(v.begin(), v.end());
	
	a = b = 0;
	for (P cur : v) {
		if (b < cur.first) {
			ans += b - a;
			a = cur.first;
			b = cur.second;
		}
		else {
			if (b < cur.second) b = cur.second;
		}
	}
	ans = m + (ans + b - a) * 2;

	printf("%lld", ans);

	return 0;
}