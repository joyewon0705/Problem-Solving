#include <stdio.h>
#pragma warning(disable:4996)
#define N 1000000
_Bool primeNumbers[N + 1] = { 0 };
int numbers[100] = { 0 };
char factorization[100][N + 1] = { 0 };
int totalFactorization[N + 1] = { 0 };

int main(void) {
	int n, temp, maxPrime, answer1, answer2;

	// 소수집합 구하기 (0: 소수, 1: 소수X)
	primeNumbers[0] = 1;
	primeNumbers[1] = 1;
	for (int i = 2; i * i < N + 1; ) {
		for (int j = i + 1; j < N + 1; j++)
			if ((primeNumbers[j] == 0) && (j % i == 0)) primeNumbers[j] = 1;
		while (primeNumbers[++i] != 0);
	}

	// 입력 및 소인수분해
	scanf("%d", &n);
	maxPrime = 0;
	for (int i = 0, j = 2; i < n; i++) {
		scanf("%d", &numbers[i]);
		temp = numbers[i];
		while (temp > 1) {
			if ((primeNumbers[j] == 0) && (temp % j == 0)) {
				if (j > maxPrime) maxPrime = j;
				while (temp % j == 0) {
					factorization[i][j]++;
					totalFactorization[j]++;
					temp /= j;
				}
			}
			j++;
		}
		j = 2;
	}

	// 계산 및 출력
	answer1 = 1;
	for (int i = 2; i < maxPrime + 1; i++) {
		totalFactorization[i] /= n;
		for (int j = 0; j < totalFactorization[i]; j++) answer1 *= i;
	}

	answer2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 2; j < maxPrime + 1; j++) {
			if (totalFactorization[j] - factorization[i][j] > 0)
				answer2 += totalFactorization[j] - factorization[i][j];
		}
	}

	printf("%d %d", answer1, answer2);

	return 0;
}

/*
#include <stdio.h>
#pragma warning(disable:4996)
#define N 1000000
int numbers[100] = { 0 };
_Bool primeNumbers[N + 1] = { 0 };
char numberOfPrime[100][N + 1] = { 0 };
int totalNumberOfPrime[N + 1] = { 0 };

int main(void) {
	int n, temp, answer1, answer2;

	// 소수집합 구하기
	primeNumbers[0] = 1;
	primeNumbers[1] = 1;
	for (int i = 2; i * i < N; ) {
		for (int j = i + 1; j < N + 1; j++) {
			if ((primeNumbers[j] == 0) && (j % i == 0)) primeNumbers[j] = 1;
		}
		while (primeNumbers[++i] == 1);
	}

	// 입력 및 소인수분해
	scanf("%d", &n);
	for (int i = 0, j = 2; i < n; i++, j = 2) {
		scanf("%d", &numbers[i]);
		temp = numbers[i];
		while (temp > 1) {
			while (temp % j == 0) {
				numberOfPrime[i][j]++;
				totalNumberOfPrime[j]++;
				temp /= j;
			}
			while (primeNumbers[++j] == 1);
		}
	}

	// 답 계산 및 출력
	answer1 = 1;
	answer2 = 0;
	for (int j = 2; j < N + 1; ) {
		temp = totalNumberOfPrime[j] / n;
		for (int i = 0; i < temp; i++) answer1 *= j;
		for (int i = 0; i < n; i++) {
			if (temp - numberOfPrime[i][j] > 0)
				answer2 += temp - numberOfPrime[i][j];
		}
		while (primeNumbers[++j] == 1);
	}
	printf("%d %d", answer1, answer2);

	return 0;
}
*/