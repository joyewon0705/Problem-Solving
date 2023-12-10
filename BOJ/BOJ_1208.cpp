#include <iostream>
#include <map>
using namespace std;

#define N 44

int n, s;
long long ans;
int a[N];
map<int, int> m;

void left(int cur, int sum) {

	if (cur == n / 2) {
		m[sum]++;
		return;
	}

	left(cur + 1, sum);
	left(cur + 1, sum + a[cur]);
}

void right(int cur, int sum) {

	if (cur == n) {
		ans += m[s - sum];
		return;
	}

	right(cur + 1, sum);
	right(cur + 1, sum + a[cur]);
}

int main(void) {

	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	left(0, 0);
	right(n / 2, 0);

	if (s == 0) ans--;
	printf("%lld", ans);

	return 0;
}