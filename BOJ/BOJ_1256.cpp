#include <iostream>
#include <string>
using namespace std;

#define N 101
#define K 1010101010

int n, m, k;
string ans = "";
int d[2 * N][N];

int combination(int n, int r) {

	if (n == r || r <= 0) return 1;
	if (d[n][r]) return d[n][r];
	d[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
	if (d[n][r] >= K) d[n][r] = K;
	return d[n][r];
}

void f(int n, int m, int k) {
	int noc = combination(n + m - 1, n - 1);

	if (n && noc >= k) {
		ans += "a";
		f(n - 1, m, k);
	}
	else if (m) {
		ans += "z";
		f(n, m - 1, k - noc);
	}
}

int main(void) {

	scanf("%d %d %d", &n, &m, &k);
	f(n, m, k);
	if (ans.size() == n + m) printf("%s", ans.c_str());
	else printf("-1");

	return 0;
}