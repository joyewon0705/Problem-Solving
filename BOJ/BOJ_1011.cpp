#include <iostream>

int t, x, y;

int main(void) {
	
	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		scanf("%d %d", &x, &y);

		if (y - x == 1) {
			printf("1\n");
			continue;
		}

		x += 1; y -= 1;
		int low = 1, high = 1, cnt = 2;
		while (x < y) {
			cnt++;
			int tmp = y - x;
			if (low - 1 <= tmp && tmp <= low + 1 && tmp - 1 <= high && high <= tmp + 1) break;
			if (high - 1 <= tmp && tmp < high + 1 && tmp - 1 <= low && low <= tmp + 1) break;
			if (low < high) {
				low++;
				x += low;
			}
			else {
				high++;
				y -= high;
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}