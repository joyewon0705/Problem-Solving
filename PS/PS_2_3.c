#pragma warning(disable:4996)
#include <stdio.h>
#define N 300

int main(void) {
	int n, m, sum, max, low, high, answer;
	int beads[N] = { 0 };
	int set[N] = { 0 };

	// 입력
	scanf("%d %d", &n, &m);
	sum = max = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &beads[i]);
		sum += beads[i];					// sum = n개 입력의 합
		if (beads[i] > max) max = beads[i];	// max = n개 입력 중 가장 큰 값
	}

	// 이진 탐색
	low = max;								// 초기 하한값을 max로 설정
	high = answer = sum;					// 초기 상한값을 sum으로 설정
	while (low <= high) {
		int mid, i, j, tmp;

		mid = (low + high) / 2;				// 중간값 설정
		tmp = mid;
		for (i = 0, j = 1; i < n; i++) {	// 집합 나누기
			if (tmp < beads[i]) {
				tmp = mid;
				j++;
			}
			tmp -= beads[i];
		}
		if (j > m) {						// 집합의 개수가 m보다 클 때
			low = mid + 1;
		}
		else {								// 집합의 개수가 m보다 작거나 같을 때
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

	// 출력
	printf("%d\n", answer);
	for (int i = 0; i < m; i++) printf("%d ", set[i]);

	return 0;
}

/* 100프로에서 틀리던 것 ..
#include <stdio.h>
#define N 300

int main(void) {
	int n, m, sum, max, low, high, k;
	int beads[N] = { 0 };
	int set[N] = { 0 };

	// 입력
	scanf("%d %d", &n, &m);
	sum = max = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &beads[i]);
		sum += beads[i];					// sum = n개 입력의 합
		if (beads[i] > max) max = beads[i];	// max = n개 입력 중 가장 큰 값
	}

	// 이진 탐색
	low = max;								// 초기 하한값을 max로 설정
	high = k = sum;							// 초기 상한값을 sum으로 설정
	while (low <= high) {
		int mid, i, j, tmp;
		int tmpSet[N] = { 0 };

		mid = (low + high) / 2;				// 중간값 설정
		tmp = mid;
		for (i = 0, j = 1; i < n; i++) {	// 집합 나누기
			if (tmp < beads[i]) {
				tmp = mid;
				j++;
			}
			tmp -= beads[i];
			tmpSet[j - 1]++;
		}
		if (j > m) {						// 집합의 개수가 m보다 클 때
			low = mid + 1;
		}
		else {								// 집합의 개수가 m보다 작거나 같을 때
			if (j < m) {					// 집합의 개수가 m보다 작으면 m이 되도록 분배
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