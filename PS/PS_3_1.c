#pragma warning(disable:4996)
#include <stdio.h>
int n, tmp;
long long answer;
int candy[10001] = { 0 };								// candy[i] = 가격 i의 사탕 개수
long long cases[500001] = { 0 };						// cases[i] = 총 사탕 가격이 i가 되는 경우의 수
_Bool isPrime[500001] = { 0 };							// isPrime[i] = 수 i의 소수여부

int main(void) {

	// 소수 집합 구하기
	for (int i = 2; i < 500001; i++) isPrime[i] = 1;
	for (int i = 2; i * i < 500001;) {
		for (int j = i + 1; j < 500001; j++)
			if (isPrime[j] && j % i == 0) isPrime[j] = 0;
		while (isPrime[++i] == 0);
	}

	// 입력
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		candy[tmp]++;
	}

	// 총 사탕 가격마다 가능한 경우의 수 계산
	cases[0] = 1;										// 아무것도 사지 않는 경우
	for (int i = 1; i < 10001; i++) {
		if (candy[i] > 0)								// i = 사탕 가격
			for (int j = 500000; j >= 0; j--) {			// j = 총 사탕 가격
				for (int k = 1; k <= candy[i]; k++) {	// k = 가격 i의 사탕 개수
					if (j - i * k < 0) break;
					cases[j] += cases[j - i * k];		// (i * k)를 만드는 경우마다 (j - i * k)를 만드는 경우의 수를 더함

				}
			}
	}

	// 총 사탕 가격이 소수인 경우의 수 계산
	answer = 0;
	for (int i = 2; i < 500001; i++)
		if (isPrime[i]) answer += cases[i];
	answer *= (candy[0] + 1);							// 공짜 사탕을 0 ~ candy[0]개 포함하는 경우의 수를 곱함

	// 출력
	printf("%lld", answer);

	return 0;
}

/* 빼기
#include <stdio.h>
#define N 10000
int n, total, answer;
int candy[50] = { 0 };			// 구매할 사탕 가격
int amount[N + 1] = { 0 };		// 각 종류의 사탕 개수
_Bool isPrime[N * 50 + 1] = { 0 };	// 소수집합
void search(int k, int sum);

int main(void) {

	// 소수집합 구하기
	for (int i = 2; i < N * 50 + 1; i++) isPrime[i] = 1;
	for (int i = 2; i * i < N * 50 + 1;) {
		for (int j = i + 1; j < N * 50 + 1; j++)
			if (isPrime[j] && j % i == 0) isPrime[j] = 0;
		while (isPrime[++i] == 0);
	}

	// 입력
	scanf("%d", &n);
	total = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &candy[i]);
		amount[candy[i]]++;
		total += candy[i];
	}

	// 계산
	answer = 0;
	search(0, total);

	// 출력
	printf("%d", answer);

	return 0;
}

void search(int k, int remain) {
	int c = candy[k];

	if (k == n) {
		if (isPrime[remain]) answer++;
		return;
	}
	if (amount[c] > 1) {
		int tmp = amount[c];
		amount[c] = -1;
		for (int i = tmp; i > 0; i--)
			search(k + 1, remain - c * i);
	}
	else if (amount[c] == 1) {
		search(k + 1, remain - c);
	}
	search(k + 1, remain);
	return;
}
*/

/* 결과에 대해서 소수인지 판별하는 알고리즘
#include <stdio.h>
#define N 10000
int n, answer;
int candy[50] = { 0 };			// 구매할 사탕 가격
int amount[N + 1] = { 0 };		// 각 종류의 사탕 개수
void search(int k, int sum);

int main(void) {

	// 입력
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &candy[i]);
		amount[candy[i]]++;
	}

	// 계산
	answer = 0;
	search(0, 0);

	// 출력
	printf("%d", answer);

	return 0;
}

void search(int k, int sum) {
	if (k == n) {
		if (sum < 2) return;
		for (int i = 2; i * i < sum + 1; i++) {
			if (sum % i == 0) return;
		}
		answer++;
		return;
	}
	if (amount[candy[k]] < 1) search(k + 1, sum);
	else if (amount[candy[k]] > 1) {
		int tmp = amount[candy[k]] + 1;
		amount[candy[k]] = -1;
		for (int i = 0; i < tmp; i++)
			search(k + 1, sum + candy[k] * i);
	}
	else {
		search(k + 1, sum + candy[k]);
		search(k + 1, sum);
	}
	return;
}
*/

/* 미리 소수집합을 구해놓는 알고리즘
#include <stdio.h>
#define N 10000
int n, answer;
int candy[50] = { 0 };			// 구매할 사탕 가격
int amount[N + 1] = { 0 };		// 각 종류의 사탕 개수
_Bool isPrime[N * 50 + 1] = { 0 };	// 소수집합
void search(int k, int sum);

int main(void) {

	// 소수집합 구하기
	for (int i = 2; i < N * 50 + 1; i++) isPrime[i] = 1;
	for (int i = 2; i * i < N * 50 + 1;) {
		for (int j = i + 1; j < N * 50 + 1; j++)
			if (isPrime[j] && j % i == 0) isPrime[j] = 0;
		while (isPrime[++i] == 0);
	}

	// 입력
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &candy[i]);
		amount[candy[i]]++;
	}

	// 계산
	answer = 0;
	search(0, 0);

	// 출력
	printf("%d", answer);

	return 0;
}

void search(int k, int sum) {
	int c = candy[k];

	if (k == n) {
		if (isPrime[sum]) answer++;
		return;
	}
	if (amount[c] == 1) search(k + 1, sum + c);
	else if (amount[c] > 1) {
		int tmp = amount[c] + 1;
		amount[c] = 0;
		for (int i = 1; i < tmp; i++)
			search(k + 1, sum + c * i);
	}
	search(k + 1, sum);
	return;
}
*/