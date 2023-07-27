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
int parent[N];			// parent[i] = 노드 i가 속하는 집합
long long cnt[N];		// cnt[i] = 집합 i의 원소 개수
edge edges[N] = { 0 };	// edges[i] = 가중치 i의 간선
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
				* x와 y의 set이 다르다
				*     == x, y가 속한 각 set 사이의 경로가 없다
				*     == edge(x, y)를 마지막으로 간선 제거가 끝났다
				* edge(x,y)를 마지막으로 간선 제거가 끝나는 경우의 수
				*     = x가 속한 set의 원소 개수 * y가 속한 set의 원소 개수
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

// 참고: https://zoosso.tistory.com/833