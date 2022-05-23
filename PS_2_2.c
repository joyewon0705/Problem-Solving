#pragma warning(disable:4996)
#include <stdio.h>
#define N 100000
int dailyAmount[N];

int main(void) {
	int n, m, sum, max, low, high, mid, tmp, k, i, j;

	scanf("%d %d", &n, &m);
	sum = max = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &dailyAmount[i]);
		sum += dailyAmount[i];
		if (dailyAmount[i] > max) max = dailyAmount[i];
	}

	low = max;
	high = sum;
	k = high;
	while (1) {
		mid = (low + high) / 2;
		tmp = 0;
		for (i = 0, j = m; i < n; i++) {
			if (tmp < dailyAmount[i]) {
				tmp = mid;
				j--;
			}
			tmp -= dailyAmount[i];
		}
		if (j < 0) {
			if (low == mid) {
				printf("%d", k);
				return 0;
			}
			low = mid;
		}
		else {
			k = mid;
			if (low == mid) {
				printf("%d", k);
				return 0;
			}
			high = mid;
		}
	}

	return 0;
}

/*
#include <stdio.h>
#define N 100000

int main(void) {
	int n, m, sum, std, tmp, answer;
	int amount[N][2] = { 0 };	// [0]: 금액, [1]: 집합

	// 입력
	scanf("%d %d", &n, &m);
	sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &amount[i][0]);
		sum += amount[i][0];
	}

	// 집합 생성
	answer = 0;
	for (int i = 1, j = 0; i < m + 1; i++) {

		printf("{ ");

		std = sum / (m - i + 1);
		tmp = 0;
		if (n - j == m - i + 1) {
			amount[j][1] = i;
			tmp += amount[j][0];
			sum -= amount[j][0];
			if (tmp > answer) answer = tmp;

			printf("%d }\n", amount[j][0]);

			j++;
			continue;
		}
		while ((tmp < std) && (n - j > m - i)) {
			amount[j][1] = i;
			tmp += amount[j][0];
			sum -= amount[j][0];

			printf("%d ", amount[j][0]);

			j++;
		}
		if (tmp > answer) answer = tmp;

		printf("}\n");
	}

	// 출력
	printf("%d", answer);

	return 0;
}

*/