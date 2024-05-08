#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 101010

int n, s, d, x, y, ans;
vector<int> v[N];

int f(int cur, int before) {
	int ret = 0;
	for (int next : v[cur]) {
		if (next == before) continue;
		ret = max(ret, f(next, cur) + 1);
	}

	if (ret >= d && cur != s) ans++;
	return ret;
}

int main(void) {

	scanf("%d %d %d", &n, &s, &d);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}

	f(s, 0);

	printf("%d", 2 * ans);

	return 0;
}