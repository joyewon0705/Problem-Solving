#pragma warning(disable:4996)
#include <stdio.h>

#define N 101010
#define MOD 1000000000

typedef struct edge {
	int x;
	int y;
} edge;

int n, m, x, y, w, max;
long long sum, answer;
int parent[N];			// parent[i] = ��� i�� ���ϴ� ����
long long cnt[N];		// cnt[i] = ���� i�� ���� ����
edge edges[N] = { 0 };	// edges[i] = ����ġ i�� ����
int findset(int x);

int main(void) {
	max = sum = answer = 0;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &w);
		edges[w].x = x;
		edges[w].y = y;
		sum += w;
		if (max < w) max = w;
	}
	sum %= MOD;

	// creat-set
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		cnt[i] = 1;
	}

	// union
	for (int i = max; i > 0; i--) {
		if (edges[i].x) {
			x = findset(edges[i].x);
			y = findset(edges[i].y);
			if (x != y) {
				/*
				* x�� y�� set�� �ٸ���
				*     == x, y�� ���� �� set ������ ��ΰ� ����
				*     == edge(x, y)�� ���������� ���� ���Ű� ������
				* edge(x,y)�� ���������� ���� ���Ű� ������ ����� ��
				*     = x�� ���� set�� ���� ���� * y�� ���� set�� ���� ����
				*/
				answer += sum * cnt[x] * cnt[y];
				answer %= MOD;
				parent[y] = x;
				cnt[x] += cnt[y];
			}
			sum = (sum - i + MOD) % MOD;
		}
	}

	printf("%lld", answer);

	return 0;
}

int findset(int x) {
	if (parent[x] != x) parent[x] = findset(parent[x]);
	return parent[x];
}

// ����: https://zoosso.tistory.com/833