#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, in, low, mid, high, ans;
vector<int> c, v;

bool chk(int mid) {
	int cur1 = n - 1, cur2 = m - 1;

	while (true) {
		if (c[cur1] >= v[cur2]) {
			cur1--;
			cur2 -= mid;
		}
		else return false;
		if (cur1 < 0 || cur2 < 0) break;
	}
	if (cur1 < 0 && cur2 >= 0) return false;
	return true;
}

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		c.push_back(in);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &in);
		v.push_back(in);
	}

	sort(c.begin(), c.end());
	sort(v.begin(), v.end());
	
	ans = -1;
	if (c[n - 1] >= v[m - 1]) {
		low = m / n ? m / n : 1; high = m;
		while (low <= high) {
			mid = (low + high) / 2;

			if (chk(mid)) {
				ans = mid;
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
	}

	printf("%d", ans);

	return 0;
}