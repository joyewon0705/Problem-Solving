#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, ans;
vector<int> v1, v2;

bool cmp(int a, int b) { return a > b; }

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m);
		if (m == 1) ans += 1;
		else if (m > 0) v1.push_back(m);
		else v2.push_back(-m);
	}

	sort(v1.begin(), v1.end(), cmp);
	sort(v2.begin(), v2.end(), cmp);

	for (int i = 0; i < v1.size(); i += 2) {
		if (i + 1 < v1.size()) {
			ans += v1[i] * v1[i + 1];
		}
		else ans += v1[i];
	}
	for (int i = 0; i < v2.size(); i += 2) {
		if (i + 1 < v2.size()) {
			ans += v2[i] * v2[i + 1];
		}
		else ans -= v2[i];
	}

	printf("%d", ans);

	return 0;
}