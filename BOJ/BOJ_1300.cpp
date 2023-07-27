#include <iostream>
#include <algorithm>
using namespace std;

int n, k, low, high, mid, ans;

int main(void) {

	scanf("%d", &n);
	scanf("%d", &k);

	low = 1, high = k;
	while (low <= high) {
		mid = (low + high) / 2;
		long long cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += min(mid / i, n);
		}
		if (cnt < k) low = mid + 1;
		else {
			ans = mid;
			high = mid - 1;
		}
	}

	printf("%d", ans);

	return 0;
}