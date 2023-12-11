#include <iostream>

#define M 10101

int t, m, sum, ans;
int a[M];

int main(void) {

	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		ans = sum = 0;

		scanf("%d", &m);
		for (int i = 1; i <= m; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		
		for (int i = 1; i <= m; i++) {
			ans += a[i];
			sum -= a[i];

			if (sum % ans != 0) continue;
			if (ans > sum) {
				ans += sum;
				break;
			}

			int t = 0;
			for (int j = i + 1; j <= m; j++) {
				t += a[j];
				if (t == ans) t = 0;
				else if (t > ans) break;
			}
			if (t == 0) break;
		}

		printf("%d\n", ans);
	}

	return 0;
}