#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

#define N 101
#define M 20202
#define INF 1010

int n, m, u, v, w, tmp, * answer;
_Bool edges[N][N], isVisit[N];
int weight[N][N], bellman[N][N], path[2][N][N];
void print_answer(int k);
_Bool isCycle(int k);

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		edges[u][v] = 1;
		weight[u][v] = w;
	}

	path[0][1][1] = -1;
	bellman[0][1] = 0;
	for (int j = 2; j <= n; j++)
		bellman[0][j] = -INF;

	for (int loop = 1; loop < n; loop++) {
		memcpy(bellman[loop], bellman[loop - 1], (n + 1) * sizeof(int));
		memcpy(path[loop % 2], path[(loop - 1) % 2], (n + 1) * N * sizeof(int));
		for (int i = 1; i <= n; i++) {
			if (bellman[loop - 1][i] == -INF) continue;
			if ((loop > 1) && (bellman[loop - 1][i] == bellman[loop - 2][i])) continue;
			for (int j = 1; j <= n; j++) {
				if (edges[i][j]) {
					tmp = bellman[loop - 1][i] + weight[i][j];
					if (bellman[loop][j] < tmp) {
						bellman[loop][j] = tmp;
						memcpy(path[loop % 2][j], path[(loop - 1) % 2][i], (n + 1) * sizeof(int));
						path[loop % 2][j][j] = i;
					}
				}
			}
		}
	}

	// 사이클 검사
	memcpy(bellman[n], bellman[n - 1], (n + 1) * sizeof(int));
	for (int i = 1; i <= n; i++) {
		if (bellman[n - 1][i] == -INF) continue;
		if (bellman[n - 1][i] == bellman[n - 2][i]) continue;
		for (int j = 1; j <= n; j++) {
			if (edges[i][j]) {
				tmp = bellman[n - 1][i] + weight[i][j];
				if (bellman[n][j] < tmp) {
					isVisit[j] = 1;
					if (isCycle(j)) {
						printf("%d", -1);
						return 0;
					}
				}
			}
		}
	}

	answer = path[(n - 1) % 2][n];
	print_answer(n);

	return 0;
}

_Bool isCycle(int k) {

	if (k == n) return 1;

	for (int i = 1; i <= n; i++) {
		if (isVisit[i]) continue;
		if (edges[k][i]) {
			isVisit[i] = 1;
			if (isCycle(i)) return 1;
			isVisit[i] = 0;
		}
	}
	return 0;
}

void print_answer(int k) {

	if (answer[k] == -1) {
		printf("%d ", k);
		return;
	}
	else {
		print_answer(answer[k]);
		printf("%d ", k);
		return;
	}
}

/*
#include <stdio.h>
#include <string.h>

#define N 101
#define M 20202
#define INF 1010

int n, m, u, v, w, tmp;
_Bool edges[N][N];
int weight[N][N], bellman[N][N], path[N][N][N];
void print_answer(int k);

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		edges[u][v] = 1;
		weight[u][v] = w;
	}

	path[0][1][1] = -1;
	bellman[0][1] = 0;
	for (int j = 2; j <= n; j++)
		bellman[0][j] = -INF;

	for (int loop = 1; loop < n; loop++) {
		memcpy(bellman[loop], bellman[loop - 1], (n + 1) * sizeof(int));
		memcpy(path[loop], path[loop - 1], (n + 1) * (n + 1) * sizeof(int));
		for (int i = 1; i <= n; i++) {
			if (bellman[loop - 1][i] == -INF) continue;
			if ((loop > 1) && (bellman[loop - 1][i] == bellman[loop - 2][i])) continue;
			for (int j = 1; j <= n; j++) {
				if (edges[i][j]) {
					tmp = bellman[loop - 1][i] + weight[i][j];
					if (bellman[loop][j] < tmp) {
						bellman[loop][j] = tmp;
						memcpy(path[loop][j], path[loop - 1][i], (n + 1) * sizeof(int));
						path[loop][j][j] = i;
					}
				}
			}
		}
	}

	// 루프 확인
	memcpy(bellman[n], bellman[n - 1], (n + 1) * sizeof(int));
	for (int i = 1; i <= n; i++) {
		if (bellman[n - 1][i] == -INF) continue;
		if (bellman[n - 1][i] == bellman[n - 2][i]) continue;
		for (int j = 1; j <= n; j++) {
			if (edges[i][j]) {
				tmp = bellman[n - 1][i] + weight[i][j];
				if (bellman[n][j] < tmp) {
					printf("%d", -1);
					return 0;
				}
			}
		}
	}

	// 출력
	print_answer(n);

	return 0;
}

void print_answer(int k) {

	if (path[n - 1][n][k] == -1) {
		printf("%d ", k);
		return;
	}
	else {
		print_answer(path[n - 1][n][k]);
		printf("%d ", k);
		return;
	}
}
*/