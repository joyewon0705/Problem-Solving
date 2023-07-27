#pragma warning(disable:4996)
#include <stdio.h>
#define N 55
#define MOD 1000007
int search(int i, int j, int k, int l);
int n, m, c, x, y, answer;
int location[N][N] = { 0 };		// location[i][j] = �ش� ��ġ�� �ִ� ������ ��ȣ, ������ 0
int D[N][N][N][N] = { 0 };		// D[i][j][k][l] = k�� �������� l��°�� ���ļ� i�� j���� ������ ����� �� 

int main(void) {
	x = y = answer = 0;

	// �Է�
	scanf("%d %d %d", &n, &m, &c);
	for (int i = 1; i <= c; i++) {
		scanf("%d %d", &x, &y);
		location[x][y] = i;
	}

	// �ʱ�ȭ
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= c; k++)
				for (int l = 0; l <= c; l++)
					D[i][j][k][l] = -1;

	// ��� �� ���
	if (location[1][1] == 0) D[1][1][0][0] = 1;
	else D[1][1][location[1][1]][1] = 1;
	for (int i = 0; i <= c; i++) {
		answer = 0;
		for (int j = 0; j <= c; j++)
			answer = (answer + search(n, m, j, i)) % MOD;
		printf("%d ", answer);
	}

	return 0;
}

int search(int i, int j, int k, int l) {

	if (i < 1 || j < 1) return 0;
	if (D[i][j][k][l] != -1) return D[i][j][k][l];

	D[i][j][k][l] = 0;
	if (location[i][j]) {
		if (location[i][j] == k) {
			for (int c = 0; c < k; c++)
				D[i][j][k][l] += (search(i - 1, j, c, l - 1) + search(i, j - 1, c, l - 1)) % MOD;
		}
	}
	else
		D[i][j][k][l] = (search(i - 1, j, k, l) + search(i, j - 1, k, l)) % MOD;

	return D[i][j][k][l];
}

/*
#include <stdio.h>
#define N 55
#define MOD 1000007
int n, m, c, x, y;
int arcade[N][N] = { 0 };
int D[N][N][N] = { 0 };
int max[N][N][N] = { 0 };

int main(void) {

	// �Է�
	scanf("%d %d %d", &n, &m, &c);
	for (int i = 1; i < c + 1; i++) {
		scanf("%d %d", &x, &y);
		arcade[x][y] = i;
	}

	// 0�� �湮���� �� ����� ���� ���
	D[0][0][1] = 1;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (arcade[i][j]) continue;
			else D[0][i][j] = (D[0][i][j - 1] + D[0][i - 1][j]) % MOD;
		}
	}

	// k�� �湮���� �� ����� ���� ���
	for (int k = 1; k < c + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				if (arcade[i][j]) {
					max[k][i][j] = arcade[i][j];
					if (max[k][i][j] >= max[k - 1][i][j - 1])
						D[k][i][j] += D[k - 1][i][j - 1];
					if (max[k][i][j] >= max[k - 1][i - 1][j])
						D[k][i][j] += D[k - 1][i - 1][j];
					D[k][i][j] %= MOD;
				}
				else {
					D[k][i][j] = (D[k][i][j - 1] + D[k][i - 1][j]) % MOD;
					if ((D[k][i][j - 1]) && (max[k][i][j] < max[k][i][j - 1]))
						max[k][i][j] = max[k][i][j - 1];
					if ((D[k][i - 1][j]) && (max[k][i][j] < max[k][i - 1][j]))
						max[k][i][j] = max[k][i - 1][j];
				}
			}
		}
	}

	for (int k = 0; k < c + 1; k++)
		printf("%d ", D[k][n][m]);

	return 0;
}
*/

/*
#include <stdio.h>
#define N 55
int n, m, c, x, y;
int location[N][2] = { 0 };
int D[N][N][N] = { 0 };
int max[N][N][N] = { 0 };

int main(void) {

	scanf("%d %d %d", &n, &m, &c);
	for (int i = 1; i <= c; i++)
		scanf("%d %d", &location[i][0], &location[i][1]);

	D[0][0][1] = 1;
	for (int i = 1; i <= c; i++)
		max[0][location[i][0]][location[i][1]] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (max[0][i][j] != 0) continue;
			D[0][i][j] = (D[0][i][j - 1] + D[0][i - 1][j]) % 1000007;
		}
	}

	x = y = 0;
	for (int k = 1; k <= c; k++) {
		for (int i = 1; i <= c; i++) {
			x = location[i][0];
			y = location[i][1];
			max[k][x][y] = i;
			if (max[k][x][y] > max[k - 1][x][y - 1])
				D[k][x][y] = (D[k][x][y] + D[k - 1][x][y - 1]) % 1000007;
			if (max[k][x][y] > max[k - 1][x - 1][y])
				D[k][x][y] = (D[k][x][y] + D[k - 1][x - 1][y]) % 1000007;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (max[k][i][j] != 0) continue;
				D[k][i][j] = (D[k][i][j - 1] + D[k][i - 1][j]) % 1000007;
				if ((D[k][i][j - 1]) && (max[k][i][j] < max[k][i][j - 1]))
					max[k][i][j] = max[k][i][j - 1];
				if ((D[k][i - 1][j]) && (max[k][i][j] < max[k][i - 1][j]))
					max[k][i][j] = max[k][i - 1][j];
			}
		}
	}

	for (int k = 0; k <= c; k++)
		printf("%d ", D[k][n][m]);

	return 0;
}
*/

/*
#include <stdio.h>
#define N 55
int n, m, c;
int location[N][2] = { 0 };		// ������ ��ġ�� ������ �迭
int D[N][N][N] = { 0 };			// D[k][i][j] = i�� j�� ���ұ��� �������� k�� ���ļ� ���� ���
int max[N][N][N] = { 0 };		// ��ģ �������� ��ȣ �� ���� ū ��

int main(void) {

	// �Է�
	scanf("%d %d %d", &n, &m, &c);
	for (int i = 1; i <= c; i++)
		scanf("%d %d", &location[i][0], &location[i][1]);

	// ���� (�������� 0�� ��ġ�� ���)
	D[0][0][1] = 1;
	for (int i = 1; i <= c; i++)
		max[0][location[i][0]][location[i][1]] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (max[0][i][j] != 0) continue;
			D[0][i][j] = D[0][i][j - 1] + D[0][i - 1][j];
		}
	}

	// ���
	for (int k = 1; k <= c; k++) {
		for (int i = 1; i <= c; i++) {				// �������� ��� D �� ���
			int x = location[i][0];
			int y = location[i][1];
			max[k][x][y] = i;
			if (max[k][x][y] >= max[k - 1][x][y - 1])
				D[k][x][y] += D[k - 1][x][y - 1];
			if (max[k][x][y] >= max[k - 1][x - 1][y])
				D[k][x][y] += D[k - 1][x - 1][y];
		}
		for (int i = 1; i <= n; i++) {				// ������ ���� D �� ���
			for (int j = 1; j <= m; j++) {
				if (max[k][i][j] != 0) continue;
				D[k][i][j] = D[k][i][j - 1] + D[k][i - 1][j];
				if ((D[k][i][j - 1]) && (max[k][i][j] < max[k][i][j - 1])) 
					max[k][i][j] = max[k][i][j - 1];
				if ((D[k][i - 1][j]) && (max[k][i][j] < max[k][i - 1][j])) 
					max[k][i][j] = max[k][i - 1][j];
			}
		}
	}

	// ���
	for (int k = 0; k <= c; k++)
		printf("%d ", D[k][n][m]);

	return 0;
}
*/

/*
	// ������ �迭 ���
	printf("----- D -----\n");
	for (int k = 0; k <= c; k++) {
		printf("%d�� ��ĥ ���)\n", k);
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				printf("%2d ", D[k][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("----- max -----\n");
	for (int k = 0; k <= c; k++) {
		printf("%d�� ��ĥ ���)\n", k);
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				printf("%2d ", max[k][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
*/