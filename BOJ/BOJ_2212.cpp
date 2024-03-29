#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, s, ans;
vector<int> v, w;

int main(void) {

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &s);
		v.push_back(s);
	}

	sort(v.begin(), v.end());
	for (int i = 1; i < n; i++) w.push_back(v[i] - v[i - 1]);
	sort(w.begin(), w.end(), greater<>());
	for (int i = k - 1; i < n - 1; i++) ans += w[i];
	
	printf("%d", ans);

	return 0;
}