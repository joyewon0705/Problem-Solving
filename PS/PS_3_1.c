#pragma warning(disable:4996)
#include <stdio.h>
int n, tmp;
long long answer;
int candy[10001] = { 0 };								// candy[i] = ���� i�� ���� ����
long long cases[500001] = { 0 };						// cases[i] = �� ���� ������ i�� �Ǵ� ����� ��
_Bool isPrime[500001] = { 0 };							// isPrime[i] = �� i�� �Ҽ�����

int main(void) {

	// �Ҽ� ���� ���ϱ�
	for (int i = 2; i < 500001; i++) isPrime[i] = 1;
	for (int i = 2; i * i < 500001;) {
		for (int j = i + 1; j < 500001; j++)
			if (isPrime[j] && j % i == 0) isPrime[j] = 0;
		while (isPrime[++i] == 0);
	}

	// �Է�
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		candy[tmp]++;
	}

	// �� ���� ���ݸ��� ������ ����� �� ���
	cases[0] = 1;										// �ƹ��͵� ���� �ʴ� ���
	for (int i = 1; i < 10001; i++) {
		if (candy[i] > 0)								// i = ���� ����
			for (int j = 500000; j >= 0; j--) {			// j = �� ���� ����
				for (int k = 1; k <= candy[i]; k++) {	// k = ���� i�� ���� ����
					if (j - i * k < 0) break;
					cases[j] += cases[j - i * k];		// (i * k)�� ����� ��츶�� (j - i * k)�� ����� ����� ���� ����

				}
			}
	}

	// �� ���� ������ �Ҽ��� ����� �� ���
	answer = 0;
	for (int i = 2; i < 500001; i++)
		if (isPrime[i]) answer += cases[i];
	answer *= (candy[0] + 1);							// ��¥ ������ 0 ~ candy[0]�� �����ϴ� ����� ���� ����

	// ���
	printf("%lld", answer);

	return 0;
}

/* ����
#include <stdio.h>
#define N 10000
int n, total, answer;
int candy[50] = { 0 };			// ������ ���� ����
int amount[N + 1] = { 0 };		// �� ������ ���� ����
_Bool isPrime[N * 50 + 1] = { 0 };	// �Ҽ�����
void search(int k, int sum);

int main(void) {

	// �Ҽ����� ���ϱ�
	for (int i = 2; i < N * 50 + 1; i++) isPrime[i] = 1;
	for (int i = 2; i * i < N * 50 + 1;) {
		for (int j = i + 1; j < N * 50 + 1; j++)
			if (isPrime[j] && j % i == 0) isPrime[j] = 0;
		while (isPrime[++i] == 0);
	}

	// �Է�
	scanf("%d", &n);
	total = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &candy[i]);
		amount[candy[i]]++;
		total += candy[i];
	}

	// ���
	answer = 0;
	search(0, total);

	// ���
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

/* ����� ���ؼ� �Ҽ����� �Ǻ��ϴ� �˰���
#include <stdio.h>
#define N 10000
int n, answer;
int candy[50] = { 0 };			// ������ ���� ����
int amount[N + 1] = { 0 };		// �� ������ ���� ����
void search(int k, int sum);

int main(void) {

	// �Է�
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &candy[i]);
		amount[candy[i]]++;
	}

	// ���
	answer = 0;
	search(0, 0);

	// ���
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

/* �̸� �Ҽ������� ���س��� �˰���
#include <stdio.h>
#define N 10000
int n, answer;
int candy[50] = { 0 };			// ������ ���� ����
int amount[N + 1] = { 0 };		// �� ������ ���� ����
_Bool isPrime[N * 50 + 1] = { 0 };	// �Ҽ�����
void search(int k, int sum);

int main(void) {

	// �Ҽ����� ���ϱ�
	for (int i = 2; i < N * 50 + 1; i++) isPrime[i] = 1;
	for (int i = 2; i * i < N * 50 + 1;) {
		for (int j = i + 1; j < N * 50 + 1; j++)
			if (isPrime[j] && j % i == 0) isPrime[j] = 0;
		while (isPrime[++i] == 0);
	}

	// �Է�
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &candy[i]);
		amount[candy[i]]++;
	}

	// ���
	answer = 0;
	search(0, 0);

	// ���
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