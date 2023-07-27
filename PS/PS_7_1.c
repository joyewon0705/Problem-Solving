#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

#define N 16
#define MAX 200000000

int n, answer;
int w[N][N];
int d[N][1 << N];
int search(int cur, int visited);

int main(void) {

	memset(d, -1, N * (1 << N) * sizeof(int));

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &w[i][j]);
		}
	}

	answer = search(0, 1);
	if (answer == MAX) answer = 0;
	printf("%d", answer);

	return 0;
}

int search(int cur, int visited) {

	if (visited == (1 << n) - 1) {
		if (w[cur][0]) return w[cur][0];
		else return MAX;
	}
	if (d[cur][visited] != -1) return d[cur][visited];
	d[cur][visited] = MAX;

	for (int i = 0; i < n; i++) {
		if (((visited & (1 << i)) == 0) && w[cur][i]) {
			int tmp = w[cur][i];
			tmp += search(i, visited | (1 << i));
			if (d[cur][visited] > tmp) d[cur][visited] = tmp;
		}
	}
	return d[cur][visited];
}

/*
#include <stdio.h>
#include <stdlib.h>

#define N 20
#define MAX 200000000

int n, answer;
_Bool isVisit[N] = { 0 };
int min[N];
int w[N][N];
void search(int cur, int cnt, int cost);

// 6프로 시간초과..
int main(void) {

	memset(min, MAX, N * sizeof(int));

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &w[i][j]);
			if (w[i][j] < min[j]) min[j] = w[i][j];
		}
	}

	answer = MAX;
	isVisit[0] = 1;
	search(0, 0, 0);

	if (answer == MAX) answer = 0;
	printf("%d", answer);

	return 0;
}

void search(int cur, int cnt, int cost) {
	int remain;

	if (cnt >= n) return;
	if (cost >= answer) return;
	if (cnt == n - 1) {
		if (w[cur][0]) {
			cost += w[cur][0];
			if (answer > cost) answer = cost;
		}
		return;
	}

	remain = min[0];
	for (int i = 0; i < n; i++) {
		if (!isVisit[i]) remain += min[i];
	}
	if (cur + remain >= answer) return;

	for (int i = 0; i < n; i++) {
		if (isVisit[i]) continue;
		if (w[cur][i]) {
			isVisit[i] = 1;
			search(i, cnt + 1, cost + w[cur][i]);
			isVisit[i] = 0;
		}
	}
}
*/