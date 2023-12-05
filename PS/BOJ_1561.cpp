#include <iostream>

#define INF (long long)1<<60
#define M 10101

int n, m, ans;
long long low, mid, high, cnt, mt;
int t[M];

bool chk(long long mid) {
	cnt = 0;

	for (int i = 1; i <= m; i++) {
		cnt += mid / t[i] + 1;
	}
	
	if (cnt < n) return false;
	else return true;
}

int main(void) {

	low = INF;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &t[i]);
		if (low > t[i]) low = t[i];
	}

	if (n <= m) {
		printf("%d", n);
		return 0;
	}

	high = low * n;
	while (low <= high) {
		mid = (low + high) / 2;
		if (chk(mid)) {
			high = mid - 1;
			mt = mid;
		}
		else low = mid + 1;
	}

	cnt = 0;
	for (int i = 1; i <= m; i++) {
		cnt += (mt - 1) / t[i] + 1;
	}
	for (int i = 1; i <= m; i++) {
		if (mt % t[i] == 0) {
			cnt += 1;
			if (cnt == n) {
				ans = i;
				break;
			}
		}
	}

	printf("%d", ans);

	return 0;
}