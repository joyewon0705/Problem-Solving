#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10101
#define M 50505
#define K 22
#define MAX (1LL<<60)

typedef struct {
	int v;
	int w;
	int next;
}_Edge;
typedef struct {
	long long w;
	int v;
	int k;
} Qentry;

int n, m, k, u, v, w, Qsize, check;
long long tmpLL, answer;
Qentry Qtmp, * qe;
int edgep[N], Vdone[N][K];
long long D[N][K];
_Edge edges[M * 2];
Qentry TQ[M * K * 2];

Qentry* popQ(void);
void pushQ(long long w, int v, int k);

int main(void) {

	scanf("%d %d %d", &n, &m, &k);
	memset(edgep, -1, (n + 1) * sizeof(int));
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		edges[i] = (_Edge){ v - 1, w, edgep[u - 1] };
		edgep[u - 1] = i;
		edges[m + i] = (_Edge){ u - 1, w, edgep[v - 1] };
		edgep[v - 1] = m + i;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			D[i][j] = MAX;
			Vdone[i][j] = 0;
		}
	}

	Qsize = 0; D[0][k] = 0;
	pushQ(0, 0, k);
	while ((qe = popQ()) != NULL) {
		u = qe->v;
		check = qe->k;
		if (Vdone[u][check]) continue;
		Vdone[u][check] = 1;

		for (int i = edgep[u]; i != -1; i = edges[i].next) {
			v = edges[i].v;
			tmpLL = D[u][check] + edges[i].w;
			if (D[v][check] > tmpLL) {
				D[v][check] = tmpLL;
				pushQ(tmpLL, v, check);
			}
			if ((check > 0) && (D[v][check - 1] > D[u][check])) {
				D[v][check - 1] = D[u][check];
				pushQ(D[v][check - 1], v, check - 1);
			}
		}
	}

	answer = MAX;
	for (int i = 0; i <= k; i++) {
		if (answer > D[n - 1][i]) answer = D[n - 1][i];
	}

	printf("%lld", answer);

	return 0;
}

Qentry* popQ(void) {
	int i, j, k;
	Qentry* ret = NULL;

	if (Qsize > 0) {
		Qsize--;
		Qtmp = TQ[0]; TQ[0] = TQ[Qsize]; TQ[Qsize] = Qtmp;
		ret = &TQ[Qsize];
		i = 0;
		while (i * 2 + 1 < Qsize) {
			j = i * 2 + 1;
			k = j + 1;
			if ((k < Qsize) && (TQ[k].w < TQ[j].w) && (TQ[k].w < TQ[i].w)) {
				Qtmp = TQ[k]; TQ[k] = TQ[i]; TQ[i] = Qtmp;
				i = k;
			}
			else if (TQ[j].w < TQ[i].w) {
				Qtmp = TQ[j]; TQ[j] = TQ[i]; TQ[i] = Qtmp;
				i = j;
			}
			else break;
		}
	}

	return ret;
}

void pushQ(long long w, int v, int k) {
	int i, p;

	i = Qsize++;
	TQ[i] = (Qentry){ w, v, k };
	while (i > 0) {
		p = (i - 1) / 2;
		if (TQ[i].w < TQ[p].w) {
			Qtmp = TQ[i]; TQ[i] = TQ[p]; TQ[p] = Qtmp;
			i = p;
		}
		else break;
	}
}

/*
#include <stdio.h>
#include <stdlib.h>

#define N 10101
#define M 50505
#define K 22
#define MAX (1LL<<60)

typedef struct _Edge {
	int u;
	int v;
	int w;
}_Edge;

long long n, m, k, u, v, w, cnt, answer, tmp;
_Bool dijkstra[N];
long long edgep[N], D[N][K];
_Edge edges[M * 2];

int cmp(const void* a, const void* b);

int main(void) {

	scanf("%lld %lld %lld", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		scanf("%lld %lld %lld", &u, &v, &w);
		edges[i].u = u; edges[i].v = v; edges[i].w = w;
		edges[m + i].u = v; edges[m + i].v = u; edges[m + i].w = w;
	}

	qsort(edges, m * 2, sizeof(_Edge), cmp);
	for (int i = 0; i < 2 * m; i++) {
		if (cnt == edges[i].u) continue;
		else {
			cnt++;
			edgep[cnt] = i;
		}
	}
	edgep[cnt + 1] = 2 * m;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			D[i][j] = MAX;
		}
	}
	dijkstra[1] = 1; D[n + 1][0] = MAX; u = 1; cnt = 1;
	while (cnt < n) {
		for (int i = edgep[u]; i < edgep[u + 1]; i++) {
			v = edges[i].v;
			if (dijkstra[v]) continue;
			tmp = D[u][0] + edges[i].w;
			if (D[v][0] > tmp) {
				D[v][0] = tmp;
				for (int j = 1; j <= k; j++) {
					if (D[v][j] == 0) continue;
					if (D[v][j] > D[u][j - 1]) D[v][j] = D[u][j - 1];
					if (D[v][j] > (tmp = D[u][j] + edges[i].w)) D[v][j] = tmp;
				}
			}
		}
		u = n + 1;
		for (int i = 2; i <= n; i++) {
			if (dijkstra[i]) continue;
			if (D[u][0] > D[i][0]) u = i;
		}
		dijkstra[u] = 1;
		cnt++;
	}

	if (u > n) {
		printf("%d", 0);
		return 0;
	}

	answer = MAX;
	for (int i = 0; i <= k; i++) {
		if (answer > D[n][i]) answer = D[n][i];
	}

	printf("%lld", answer);

	return 0;
}

int cmp(const void* a, const void* b) {
	return (*(_Edge*)a).u - (*(_Edge*)b).u;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

#define N 10101
#define M 50505
#define K 22
#define MAX (1LL<<60)

typedef struct _Edge {
	int v;
	int w;
	int next;
}_Edge;

long long n, m, k, u, v, w, tmp, idx, answer;
_Bool dijkstra[N] = { 0 };
long long edgep[N], D[N][K] = { 0 };
_Edge edges[M * 2];

int main(void) {

	scanf("%d %d %d", &n, &m, &k);
	memset(edgep, -1, n * sizeof(int));
	for (int i = 0; i < m * 2; i += 2) {
		scanf("%d %d %d", &u, &v, &w);
		edges[i].v = v; edges[i].w = w; edges[i].next = edgep[u]; edgep[u] = i;
		edges[i + 1].v = u; edges[i + 1].w = w; edges[i + 1].next = edgep[v]; edgep[v] = i + 1;
	}

	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			D[i][j] = MAX;
		}
	}
	dijkstra[1] = 1; D[n + 1][0] = MAX; u = 1;
	while (u < n) {
		idx = edgep[u];
		while (idx != -1) {
			v = edges[idx].v;
			if (dijkstra[v]) continue;
			tmp = D[u][0] + edges[idx].w;
			if (D[v][0] > tmp) {
				D[v][0] = tmp;
				for (int j = 1; j <= k; j++) {
					if (D[v][j] == 0) continue;
					if (D[v][j] > D[u][j - 1]) D[v][j] = D[u][j - 1];
					if (D[v][j] > (tmp = D[u][j] + edges[idx].w)) D[v][j] = tmp;
				}
			}
			idx = edges[idx].next;
		}
		u = n + 1;
		for (int i = 2; i <= n; i++) {
			if (dijkstra[i]) continue;
			if (D[u][0] > D[i][0]) u = i;
		}
		dijkstra[u] = 1;
	}

	if (u > n) {
		printf("%d", 0);
		return 0;
	}

	answer = MAX;
	for (int i = 0; i <= k; i++) {
		if (answer > D[n][i]) answer = D[n][i];
	}

	printf("%lld", answer);

	return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

#define N 10101
#define M 50505
#define K 22
#define MAX 9223372036854775800

typedef struct _Edge {
	int u;
	int v;
	int w;
}_Edge;

int n, m, k, u, v, w, cnt;
long long answer, tmp;
_Bool dijkstra[N];
int edgep[N];
long long D[N][K];
_Edge edges[M * 2];

int cmp(const void* a, const void* b);

int main(void) {

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		edges[i].u = u; edges[i].v = v; edges[i].w = w;
		edges[m + i].u = v; edges[m + i].v = u; edges[m + i].w = w;
	}

	qsort(edges, m * 2, sizeof(_Edge), cmp);
	for (int i = 0; i < 2 * m; i++) {
		if (cnt == edges[i].u) continue;
		else {
			cnt++;
			edgep[cnt] = i;
		}
	}
	edgep[cnt + 1] = 2 * m;

	// memset(D, MAX, n * K * sizeof(long long));
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			D[i][j] = MAX;
		}
	}
	dijkstra[1] = 1; D[n + 1][0] = MAX; u = 1;
	while (u < n) {
		for (int i = edgep[u]; i < edgep[u + 1]; i++) {
			v = edges[i].v;
			if (dijkstra[v]) continue;
			tmp = D[u][0] + edges[i].w;
			if (D[v][0] > tmp) {
				D[v][0] = tmp;
				for (int j = 1; j <= k; j++) {
					if (D[v][j] == 0) continue;
					if (D[v][j] > D[u][j - 1]) D[v][j] = D[u][j - 1];
					if (D[v][j] > (tmp = D[u][j] + edges[i].w)) D[v][j] = tmp;
				}
			}
		}
		u = n + 1;
		for (int i = 2; i <= n; i++) {
			if (dijkstra[i]) continue;
			if (D[u][0] > D[i][0]) u = i;
		}
		dijkstra[u] = 1;
	}

	if (u > n) {
		printf("%d", 0);
		return 0;
	}

	answer = MAX;
	for (int i = 0; i <= k; i++) {
		if (answer > D[n][i]) answer = D[n][i];
	}

	printf("%lld", answer);

	return 0;
}

int cmp(const void* a, const void* b) {
	return (*(_Edge*)a).u > (*(_Edge*)b).u;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

#define N 10101
#define M 50505
#define K 22
#define MAX 1010101

typedef struct _Edge {
	int u;
	int v;
	int w;
}_Edge;

int n, m, k, u, v, w, min;
int edgep[N];
long long tmp, answer;
long long D[N][K];
long long dijkstra[N];
_Edge edges[2 * M];

int search(int u, int v);
int cmp(const void* a, const void* b);

int main(void) {	// 6프로 시간초과..ㅠㅠ

	// 입력
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		edges[i].u = u; edges[i].v = v; edges[i].w = w;
		edges[m + i].u = v; edges[m + i].v = u; edges[m + i].w = w;
	}

	// edge 오름차순 정렬
	qsort(edges, 2 * m, sizeof(_Edge), cmp);
	for (int i = 0, cnt = 0; i < 2 * m; i++) {
		if (cnt == edges[i].u) continue;
		if (cnt < edges[i].u) {
			cnt++;
			edgep[cnt] = i;
		}
	}

	// dijkstra + DP
	dijkstra[1] = -1; u = 1; dijkstra[n + 1] = MAX;
	for (int i = 2; i <= n; i++) {
		dijkstra[i] = MAX;
		for (int j = 0; j <= k; j++) {
			D[i][j] = MAX;
		}
	}
	while (u != n) {
		for (int i = edgep[u]; i < edgep[u + 1]; i++) {
			v = edges[i].v;
			if (dijkstra[v] < 0) continue;
			tmp = D[u][0] + edges[i].w;
			if (dijkstra[v] > tmp) {
				dijkstra[v] = tmp;
				D[v][0] = dijkstra[v];
				for (int j = 1; j <= k; j++) {
					if (D[v][j] > D[u][j - 1]) D[v][j] = D[u][j - 1];
					if (D[v][j] > (tmp = D[u][j] + edges[i].w)) D[v][j] = tmp;
				}
			}
		}
		min = n + 1;
		for (int i = 1; i <= n; i++) {
			if (dijkstra[i] < 0) continue;
			if (dijkstra[min] > dijkstra[i]) min = i;
		}
		dijkstra[min] = -1;
		u = min;
	}

	// answer 찾기
	answer = D[n][0];
	for (int j = 0; j <= k; j++) {
		if (answer > D[n][j]) answer = D[n][j];
	}

	// 출력
	printf("%lld", answer);

	return 0;
}

int cmp(const void* a, const void* b) {
	if ((*(_Edge*)a).u == (*(_Edge*)b).u) 
		return (*(_Edge*)a).v > (*(_Edge*)b).v;
	else 
		return (*(_Edge*)a).u > (*(_Edge*)b).u;
}
*/