#pragma warning(disable:4996)
#include <stdio.h>
#define N 1000

int main(void) {
	int n, max = 0;
	int numbers[N] = { 0 }, P[N] = { 0 }, LIS[N] = { 0 };

	for (int i = 0; i < N; i++) {
		LIS[i] = 1010;
		P[i] = -1;
	}

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &numbers[i]);

	LIS[0] = numbers[0];
	P[0] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (numbers[i] <= LIS[j]) {
				LIS[j] = numbers[i];
				P[i] = j;
				if (j > max) max = j;
				break;
			}
		}
	}

	printf("%d\n", max + 1);
	for (int i = n - 1; i >= 0; i--) {
		if (P[i] == max) max--;
		else P[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		if (P[i] != -1) printf("%d ", numbers[i]);
	}

	return 0;
}