#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> P;

int n, x, y;
long long ans;
vector<P> v;

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		v.push_back({ x, y });
	}

	sort(v.begin(), v.end());

	x = v[0].first; y = v[0].second;
	for (int i = 1; i < n; i++) {
		if (v[i].first > y) {
			ans += y - x;
			x = v[i].first;
			y = v[i].second;
		}
		else {
			if (v[i].second > y) {
				y = v[i].second;
			}
		}
	}
	ans += y - x;

	printf("%lld", ans);

	return 0;
}