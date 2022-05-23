#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

#define N 10101

typedef struct node {
	int v;
	struct node* next;
}node;

int n, m, s, t, a, b, k, top, num, idx, tmp;
int stack[N], visit[N], finish[N], count[N], pre[N], visited[N], dp[N], par[N];
node arr[N], x[N];
int search(int v, int t);
void travel(int v);
int scc(int v);
void creat_node(node* list, int a, int b);

int main(void) {
	top = -1; num = 0; idx = 1;

	scanf("%d %d %d %d", &n, &m, &s, &t);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		creat_node(x, a, b);
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i] == 0) scc(i);
		dp[i] = -1;
	}
	travel(s);
	k = search(finish[s], finish[t]);

	if (k > 0) printf("%d", k);
	else printf("0");

	return 0;
}

int search(int v, int t) {
	node* p;

	if (dp[v] != -1) return  dp[v];
	if (v == t) return count[t];

	p = arr[v].next;
	while (p != NULL) {
		if (dp[v] < (tmp = search(p->v, t))) dp[v] = tmp;
		p = p->next;
	}

	if (dp[v] != -1) return dp[v] += count[v];
	else return -1;
}

void travel(int v) {
	node* p;

	if (visited[v] != 0) return;

	p = x[v].next;
	visited[v] = 1;
	while (p != NULL) {
		if (finish[v] != finish[p->v])
			creat_node(arr, finish[v], finish[p->v]);
		travel(p->v);
		p = p->next;
	}
}

int scc(int v) {
	node* p;

	p = x[v].next;
	visit[v] = ++num;
	stack[++top] = v;
	par[v] = visit[v];
	while (p != NULL) {
		if (visit[p->v] == 0) {
			if (par[v] > (tmp = scc(p->v))) par[v] = tmp;
		}
		else if (finish[p->v] == 0) {
			if (par[v] > visit[p->v]) par[v] = visit[p->v];
		}
		p = p->next;
	}

	if (par[v] == visit[v]) {
		int t;
		while (1) {
			t = stack[top];
			top -= 1;
			count[idx] += 1;
			finish[t] = idx;
			if (t == v) break;
		}
		idx += 1;
	}

	return par[v];
}

void creat_node(node* list, int a, int b) {
	node* new_node;

	new_node = (node*)calloc(1, sizeof(node));
	new_node->v = b;
	new_node->next = list[a].next;
	list[a].next = new_node;
}

/*
#include <stdio.h>
#include <stdlib.h>

#define N 10101
#define M 101010

typedef struct _List {
	int u;
	int v;
} _List;

int n, m, s, t, k, cnt, snn, stk_size, sc_stk_size, sc_cnt;
int arr[N];
int sc_arr[N], sc_chk[N], sc_size[N], sc_stk[N];
int dp[N], dfsn[N], sn[N];
int stk[N], finish[N], indegree[N];
_List list[N], sc_list[N];
int dfs(int cur);
int cmp(const void* a, const void* b);

int main(void) {

	scanf("%d %d %d %d", &n, &m, &s, &t);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &list[i].u, &list[i].v);
		arr[list[i].u]++;
	}

	arr[0] = 0;
	for (int i = 1; i <= n; i++)
		arr[i] += arr[i - 1];

	qsort(list, m, sizeof(_List), cmp);

	for (int i = 1; i <= n; i++)
		if (dfsn[i] == 0) dfs(i);

	sc_cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = arr[i - 1] + 1; j <= arr[i]; j++) {
			if (sn[list[j].u] != sn[list[j].v]) {
				indegree[sn[list[j].v]]++;
				sc_list[++sc_cnt].u = sn[list[j].u];
				sc_list[sc_cnt].v = sn[list[j].v];
				sc_arr[sn[list[j].u]]++;
			}
		}
	}

	qsort(sc_list, sc_cnt, sizeof(_List), cmp);

	for (int i = 1; i <= sn; i++) {
		dp[i] = sc_size[i];
		sc_arr[i] += sc_arr[i - 1];
		if (indegree[i] == 0)
			sc_stk[++sc_stk_size] = i;
	}

	sc_chk[sn[s]] = 1;
	while (sc_stk_size > 0) {
		k = sc_stk[sc_stk_size--];
		for (int i = sc_arr[k - 1] + 1; i <= sc_arr[k]; i++) {
			int next = sc_list[i].v;
			if (sc_chk[k]) {
				sc_chk[next]++;
				if (dp[next] < (dp[t] + sc_size[next]))
					dp[next] = dp[t] + sc_size[next];
			}
			if (--indegree[next] == 0)
				sc_stk[++sc_stk_size] = next;
		}
	}

	if (sc_chk[sn[t]])
		printf("%d", dp[sn[t]]);
	else printf("0");

	return 0;
}

int dfs(int cur) {
	int result, next, tmp, t;

	dfsn[cur] = ++cnt;
	stk[++stk_size] = cur;
	result = dfsn[cur];
	for (int i = arr[cur - 1] + 1; i <= arr[cur]; i++) {
		next = list[i].v;
		if (dfsn[next] == 0) {
			if (result > (tmp = dfs(next))) result = tmp;
		}
		else if (!finish[next]) {
			if (result > dfsn[next]) result = dfsn[next];
		}
	}
	if (dfsn[cur] == result) {
		snn++;
		while (1) {
			t = stk[stk_size--];
			sn[t] = snn;
			finish[t] = 1;
			sc_size[snn]++;
			if (cur == t) break;
		}
	}
	return result;
}

int cmp(const void* a, const void* b) {
	return (*(_List*)a).u > (*(_List*)b).u;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

#define N 10101
#define M 101010

int n, m, s, t, a, b, answer;
_Bool path[N][N] = { 0 };
_Bool isVisit[N] = { 0 };
int set[N];
int scc[N];
int findset(int n);
_Bool dfsNode(int u, int v);

int main(void) {

	scanf("%d %d %d %d", &n, &m, &s, &t);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		path[a][b] = 1;
	}

	// 도시 i에서 j로의 경로 유무 검사
	for (int i = 1; i <= n; i++) {
			isVisit[i] = 1;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			path[i][j] = dfsNode(i, j);
		}
			isVisit[i] = 0;
	}

	// 초기화
	for (int i = 1; i <= n; i++) {
		set[i] = i;
		scc[i] = 1;
	}
	memset(isVisit, 0, n * sizeof(_Bool));

	// scc 구하기
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (path[i][j] && path[j][i]) {
				int u = findset(i);
				int v = findset(j);
				set[v] = u;
				scc[u] += set[v];
			}
		}
	}

	return 0;
}

int dfsScc(int setN) {

	for (int i = 1; i <= n; i++) {
		if (set[i] == setN) {
			for (int j = 1; j <= n; j++) {
				if ((set[j] != setN) && path[i][j]) {
					// ㅠㅠ
				}
			}
		}
	}
}

int findset(int n) {
	if (set[n] != n) set[n] = findset(n);
	return set[n];
}

_Bool dfsNode(int u, int v) {
	if (path[u][v]) return 1;

	for (int i = 0; i < n; i++) {
		if (!isVisit[i] && path[u][i]) {
			isVisit[i] = 1;
			path[u][v] = dfsNode(i, v);
			isVisit[i] = 0;
		}
	}
	return path[u][v];
}
*/