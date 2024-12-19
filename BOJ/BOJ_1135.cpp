#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 55

int n, m;
int cnt[N];
vector<int> v[N];

int f(int cur) {
	int ret = 0;
	vector<int> tv;

	for (int next : v[cur]) {
		tv.push_back(f(next));
	}
	sort(tv.begin(), tv.end());
	for (int i = 0, m = tv.size(); i < m; i++) {
		ret = max(ret, tv[i] + m - i);
	}
	return ret;
}

int main(void) {

	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1; i < n; i++) {
		scanf("%d", &m);
		v[m].push_back(i);
	}
	printf("%d", f(0));

	return 0;
}