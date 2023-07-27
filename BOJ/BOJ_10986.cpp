#include <iostream>
#include <vector>
using namespace std;

#define M 1010

int n, m, in;
long long sum, ans;
long long chk[M];

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		sum += in;
		chk[sum % m]++;
	}
	ans = chk[0];
	for (int i = 0; i < m; i++) {
		ans += chk[i] * (chk[i] - 1) / 2;
	}
	printf("%lld", ans);

	return 0;
}