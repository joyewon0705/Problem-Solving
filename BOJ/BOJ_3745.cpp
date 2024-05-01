#include <iostream>

#define N 101010

int n, cnt;
int p[N], d[N];

int main(void) {

	while (scanf("%d", &n) != -1) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &p[i]);
		}

		cnt = 1;
		d[1] = p[1];
		for (int i = 2; i <= n; i++) {
			if (p[i] > d[cnt]) {
				cnt++;
				d[cnt] = p[i];
			}
			else {
				int low = 1, mid = 0, high = cnt;
				while (low < high) {
					mid = (low + high) / 2;
					if (d[mid] < p[i]) low = mid + 1;
					else high = mid;
				}
				d[high] = p[i];
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}