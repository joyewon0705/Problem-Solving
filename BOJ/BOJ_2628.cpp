#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 101

int n, m, k, a, b, ans;
vector<int> c, r;

int main(void) {

	scanf("%d %d", &n, &m);
	scanf("%d", &k);
	c = { 0, n };
	r = { 0, m };
	while (k--) {
		scanf("%d %d", &a, &b);
		if (a) c.push_back(b);
		else r.push_back(b);
	}

	sort(c.begin(), c.end());
	sort(r.begin(), r.end());

	for (int i = 0; i < c.size() - 1; i++) {
		for (int j = 0; j < r.size() - 1; j++) {
			int val = (c[i + 1] - c[i]) * (r[j + 1] - r[j]);
			if (ans < val) ans = val;
		}
	}

	printf("%d", ans);

	return 0;
}