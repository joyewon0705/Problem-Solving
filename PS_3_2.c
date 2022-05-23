#pragma warning(disable:4996)
#include <stdio.h>
#define N 100
int n, m, tmp;
int sum[N + 1] = { 0 };
int M[N + 1][N / 2 + 2] = { 0 };

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}

	M[1][1] = sum[1];
	for (int i = 2; i <= n; i++) {
		M[i][1] = M[i - 1][1];
		for (int k = 0; k < i; k++) {
			if (sum[i] - sum[k] > M[i][1])
				M[i][1] = sum[i] - sum[k];
		}
	}

	for (int j = 2; j <= m; j++) {
		tmp = 2 * j - 1;
		M[tmp][j] = M[tmp - 2][j - 1] + sum[tmp] - sum[tmp - 1];
		for (int i = 2 * j; i <= n; i++) {
			M[i][j] = M[i - 1][j];
			for (int k = 2 * j - 2; k < i; k++) {
				tmp = M[k - 1][j - 1] + sum[i] - sum[k];
				if (tmp > M[i][j]) M[i][j] = tmp;
			}
		}
	}

	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%5d ", M[i][j]);
		}
		printf("\n\n");
	}
	*/

	printf("%d", M[n][m]);

	return 0;
}

/* 문제 잘못 이해함
#pragma warning(disable:4996)
#include <stdio.h>
#define N 100

int main(void) {
	int n, m, answer;
	int matrix[N][N] = { 0 };

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &matrix[i][i]);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			matrix[i][j] = matrix[i][j - 1] + matrix[j][j];
		}
	}
	
	// 디버깅용 행렬 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%5d ", matrix[i][j]);
		}
		printf("\n\n");
	}

	answer = matrix[0][0];
	if (m == 1) answer = matrix[0][n - 1];
	else if (m == 2) {
		for (int i = 0; i < n - 1; i++) {
			if (matrix[0][i] > answer) answer = matrix[0][i];
			if (matrix[i + 1][n - 1] > answer) answer = matrix[i + 1][n - 1];
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if ((j - i < n - m + 1) && matrix[i][j] > answer)
					answer = matrix[i][j];
			}
		}
	}

	printf("%d", answer);

	return 0;
}
*/