#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n, m, a, l, r;
vector<int> v;

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	a = 2000000000;
	l = 0; r = 1;
	while (r < n) {
		int t = abs(v[r] - v[l]);
		if (t >= m && a > t) a = t;
		if (t < m || l + 1 == r) r++;
		else l++;
	}

	printf("%d", a);

	return 0;
}