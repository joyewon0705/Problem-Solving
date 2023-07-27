#pragma warning(disable:4996)
#include <stdio.h>
#define N 300

int main(void) {
	int n, m, sum, max, low, high, answer;
	int beads[N] = { 0 };
	int set[N] = { 0 };

	// �Է�
	scanf("%d %d", &n, &m);
	sum = max = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &beads[i]);
		sum += beads[i];					// sum = n�� �Է��� ��
		if (beads[i] > max) max = beads[i];	// max = n�� �Է� �� ���� ū ��
	}

	// ���� Ž��
	low = max;								// �ʱ� ���Ѱ��� max�� ����
	high = answer = sum;					// �ʱ� ���Ѱ��� sum���� ����
	while (low <= high) {
		int mid, i, j, tmp;

		mid = (low + high) / 2;				// �߰��� ����
		tmp = mid;
		for (i = 0, j = 1; i < n; i++) {	// ���� ������
			if (tmp < beads[i]) {
				tmp = mid;
				j++;
			}
			tmp -= beads[i];
		}
		if (j > m) {						// ������ ������ m���� Ŭ ��
			low = mid + 1;
		}
		else {								// ������ ������ m���� �۰ų� ���� ��
			answer = mid;
			high = mid - 1;
		}
	}

	for (int i = 0, j = 1, tmp = answer; i < n; i++) {
		if (tmp < beads[i] || (n - i == m - j)) {
			tmp = answer;
			j++;
		}
		tmp -= beads[i];
		set[j - 1]++;
	}

	// ���
	printf("%d\n", answer);
	for (int i = 0; i < m; i++) printf("%d ", set[i]);

	return 0;
}

/* 100���ο��� Ʋ���� �� ..
#include <stdio.h>
#define N 300

int main(void) {
	int n, m, sum, max, low, high, k;
	int beads[N] = { 0 };
	int set[N] = { 0 };

	// �Է�
	scanf("%d %d", &n, &m);
	sum = max = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &beads[i]);
		sum += beads[i];					// sum = n�� �Է��� ��
		if (beads[i] > max) max = beads[i];	// max = n�� �Է� �� ���� ū ��
	}

	// ���� Ž��
	low = max;								// �ʱ� ���Ѱ��� max�� ����
	high = k = sum;							// �ʱ� ���Ѱ��� sum���� ����
	while (low <= high) {
		int mid, i, j, tmp;
		int tmpSet[N] = { 0 };

		mid = (low + high) / 2;				// �߰��� ����
		tmp = mid;
		for (i = 0, j = 1; i < n; i++) {	// ���� ������
			if (tmp < beads[i]) {
				tmp = mid;
				j++;
			}
			tmp -= beads[i];
			tmpSet[j - 1]++;
		}
		if (j > m) {						// ������ ������ m���� Ŭ ��
			low = mid + 1;
		}
		else {								// ������ ������ m���� �۰ų� ���� ��
			if (j < m) {					// ������ ������ m���� ������ m�� �ǵ��� �й�
				for (i = m - 1; tmpSet[i] == 0; i--) tmpSet[i] = 1;
				tmpSet[i] -= (m - i - 1);
			}
			k = mid;
			for (i = 0; i < m; i++) set[i] = tmpSet[i];
			high = mid - 1;
		}
	}

	printf("%d\n", k);
	for (int i = 0; i < m; i++) printf("%d ", set[i]);

	return 0;
}

*/

/*
#pragma warning(disable:4996)
#include <stdio.h>
#define N 300
int n, m, sum, max, answer;
int beads[N] = { 0 };
int set[N] = { 0 };
void search(int low, int high);
_Bool makeSet(int mid);

int main(void) {

	scanf("%d %d", &n, &m);
	sum = max = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &beads[i]);
		sum += beads[i];
		if (beads[i] > max) max = beads[i];
	}

	search(max, sum);

	printf("%d\n", answer);
	for (int i = 0; i < m; i++)printf("%d ", set[i]);

	return 0;
}

void search(int low, int high) {
	_Bool isFail;
	int mid;

	mid = (low + high) / 2;
	isFail = makeSet(mid);
	if (low == mid) return;

	if (isFail) search(mid + 1, high);
	else search(low, mid - 1);
}

_Bool makeSet(int mid) {
	int i, j, tmp;
	int tmpSet[N] = { 0 };

	i = 0;
	j = 1;
	tmp = mid;
	while (i < n) {
		if ((n - i - 1) == (m - j)) {
			tmpSet[j++] = 1;
			i++;
			continue;
		}
		if (tmp < beads[i]) {
			tmp = mid;
			j++;
		}
		tmp -= beads[i];
		tmpSet[i]++;
	}

	if (j == m) return 0;
	else {
		answer = mid;
		for (i = 0; i < m; i++) set[i] = tmpSet[i];
		return 1;
	}
}
*/