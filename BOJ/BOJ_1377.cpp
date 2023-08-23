#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> P;

int n, a, ans;
vector<P> v;

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		v.push_back({ a, i });
	}

	sort(v.begin(), v.end());

	int s = v.size();
	for (int i = 0; i < s; i++) {
		int tmp = v[i].second - i;
		if (ans < tmp) ans = tmp;
	}

	printf("%d", ans + 1);

	return 0;
}