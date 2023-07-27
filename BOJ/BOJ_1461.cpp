#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, x, ans;
vector<int> l, r;

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x < 0)  l.push_back(-x);
		else r.push_back(x);
	}

	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	
	if (l.size()) ans += l[l.size() - 1];
	if (r.size()) ans += r[r.size() - 1];
	if (l.size() && r.size()) ans += min(l[l.size() - 1], r[r.size() - 1]);
	for (int i = l.size() - 1 - m; i > -1; i -= m) ans += 2 * l[i];
	for (int i = r.size() - 1 - m; i > -1; i -= m) ans += 2 * r[i];
	
	printf("%d", ans);

	return 0;
}