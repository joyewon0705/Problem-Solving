#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
long long ans;
vector<int> v;

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		v.push_back(m);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int t = v[i] + v[j];
			int l = lower_bound(v.begin() + (j + 1), v.end(), -t) - v.begin();
			int u = upper_bound(v.begin() + (j + 1), v.end(), -t) - v.begin();
			ans += u - l;
		}
	}

	printf("%lld", ans);

	return 0;
}