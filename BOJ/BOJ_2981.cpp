#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> num, ans;

int gcd(int a, int b) {
	if (a % b) return gcd(b, a % b);
	else return b;
}

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m);
		num.push_back(m);
	}

	sort(num.begin(), num.end());
	int m = num[1] - num[0];
	for (int i = 2; i < n; i++) {
		m = gcd(m, num[i] - num[i - 1]);
	}

	for (int i = 2; i * i <= m; i++) {
		if (m % i) continue;
		ans.push_back(i);
		if (i != m / i) ans.push_back(m / i);
	}
	ans.push_back(m);

	sort(ans.begin(), ans.end());
	for (int a : ans) printf("%d ", a);

	return 0;
}