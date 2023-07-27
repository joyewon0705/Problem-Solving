#pragma warning(disable:4996)
#include <stdio.h>
#include <stdbool.h>

#define N 10

int answer, total;
int paper_cnt[5] = { 0 };
int m[N][N] = { 0 };
void search(int x, int y, int cnt);
bool check(int x, int y, int k);

int main(void) {
	answer = 99;
	total = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &m[i][j]);
			if (m[i][j]) total++;
		}
	}

	search(0, 0, 0);
	if (answer > 25) answer = -1;
	printf("%d", answer);

	return 0;
}

void search(int x, int y, int cnt) {

	// 1�� ��ġ ã��
	while (m[x][y] == 0) {
		y++;
		if (y >= N) {
			x++;
			if (x >= N) {
				if (answer > cnt) answer = cnt;
				return;
			}
			y = 0;
		}
	}

	// ����ġ��
	if (answer <= cnt) return;

	// ��� ũ���� ������ ���� �õ�
	for (int k = 5; k > 0; k--) {

		// ������ ����ų� ���� ���̰� ���� ���
		if ((x + k > N) || (y + k > N) || (paper_cnt[k] == 5)) continue;

		// ������ ���� �õ�
		if (check(x, y, k)) {
			
			// ����
			for (int i = x; i < x + k; i++)
				for (int j = y; j < y + k; j++)
					m[i][j] = 0;
			paper_cnt[k]++;

			// DFS
			search(x, y, cnt + 1);

			// ����
			for (int i = x; i < x + k; i++)
				for (int j = y; j < y + k; j++)
					m[i][j] = 1;
			paper_cnt[k]--;
		}
	}
}

// ���� �������� Ȯ��
bool check(int x, int y, int k) {
	for (int i = x; i < x + k; i++) {
		for (int j = y; j < y + k; j++) {
			if (m[i][j] == 0) return false;
		}
	}
	return true;
}

// ����: https://11001.tistory.com/21