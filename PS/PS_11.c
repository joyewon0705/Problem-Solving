#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 55
#define M 101

typedef struct _Coordinate _Coordinate;
typedef struct _Qentry _Qentry;
typedef struct _Queue _Queue;
typedef struct _LLentry _LLentry;
typedef struct _List _List;

_Bool search(int n);
_Bool dfs(int n);
void push(_Queue* q, _Coordinate cd);
_Coordinate pop(_Queue* q);
void add(_List* l, int n);
void clear(_List* l);

int r, c, c_size, p_size, low, high, mid, answer;
char info[N][N];
int chk[M][M], dist[M][M], par[2 * M], vis[2 * M];
_Coordinate C[M], P[M];
_Coordinate direction[] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
_List l[2 * M];

int main(void) {

	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		getchar();
		for (int j = 0; j < c; j++) {
			info[i][j] = getchar();

			if (info[i][j] == 'C') {
				C[c_size] = (_Coordinate){ i, j };
				c_size++;
			}
			else if (info[i][j] == 'P') {
				P[p_size] = (_Coordinate){ i, j };
				p_size++;
			}
		}
	}

	if (c_size == 0) {
		printf("%d", 0);
		return 0;
	}
	if (c_size > p_size) {
		printf("%d", -1);
		return 0;
	}

	for (int num = 0; num < c_size; num++) {
		memset(chk, -1, sizeof(chk));
		_Queue q = { NULL, NULL, 0 };

		push(&q, C[num]);
		chk[C[num].x][C[num].y] = 0;
		while (q.size) {
			_Coordinate tmpCD = pop(&q);
			for (int k = 0; k < 4; k++) {
				int x = tmpCD.x + direction[k].x;
				int y = tmpCD.y + direction[k].y;

				if (x < 0 || r <= x || y < 0 || c <= y) continue;
				if (chk[x][y] != -1) continue;
				if (info[x][y] == 'X') continue;

				chk[x][y] = chk[tmpCD.x][tmpCD.y] + 1;
				push(&q, (_Coordinate) { x, y });
			}
		}

		for (int i = 0; i < p_size; i++)
			dist[num][i] = chk[P[i].x][P[i].y];
	}

	low = 0; high = 3000; answer = -1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (search(mid)) {
			answer = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	printf("%d", answer);

	return 0;
}

_Bool search(int n) {
	for (int i = 0; i < 2 * M; i++) clear(&l[i]);
	for (int i = 0; i < c_size; i++) {
		for (int j = 0; j < p_size; j++) {
			if (dist[i][j] != -1 && dist[i][j] <= n) {
				add(&l[i], j + 100);
			}
		}
	}

	int cnt = 0;
	memset(par, -1, sizeof(par));
	for (int i = 0; i < c_size; i++) {
		memset(vis, 0, sizeof(vis));
		cnt += dfs(i);
	}

	return cnt == c_size;
}

_Bool dfs(int n) {
	int i;
	_LLentry* tmp;

	vis[n] = 1;
	tmp = l[n].head;
	while (tmp != NULL) {
		i = tmp->n;
		tmp = tmp->next;
		if (vis[i]) continue;
		vis[i] = 1;
		if (par[i] == -1 || dfs(par[i])) {
			par[i] = n;
			return 1;
		}
	}

	return 0;
}

// 참고: https://jovialcode.tistory.com/24 (algo)
// 참고: https://justicehui.github.io/ps/2019/09/30/BOJ1348/ (code) 
// 참고: https://kth990303.tistory.com/82 (tc)

// 자료구조

typedef struct _Coordinate {
	int x;
	int y;
}_Coordinate;

typedef struct _Qentry {
	_Coordinate cd;
	_Qentry* next;
}_Qentry;

typedef struct _Queue {
	_Qentry* front;
	_Qentry* rear;
	int size;
}_Queue;

typedef struct _LLentry {
	int n;
	_LLentry* next;
}_LLentry;

typedef struct _List {
	_LLentry* head;
	_LLentry* tail;
}_List;

void push(_Queue* q, _Coordinate cd) {
	_Qentry* tmpQ;

	tmpQ = (_Qentry*)malloc(sizeof(_Qentry));
	tmpQ->cd = cd;
	tmpQ->next = NULL;

	if (q->front == NULL) {
		q->front = tmpQ;
		q->rear = tmpQ;
		q->size++;
	}
	else {
		q->rear->next = tmpQ;
		q->rear = q->rear->next;
		q->size++;
	}
}

_Coordinate pop(_Queue* q) {
	_Coordinate tmpCD;
	_Qentry* tmpQ;

	if (q->front == NULL)
		return (_Coordinate) { -1, -1 };

	tmpCD = q->front->cd;
	tmpQ = q->front;
	q->front = q->front->next;
	if (q->front == NULL) q->rear = NULL;
	q->size--;

	free(tmpQ);
	tmpQ = NULL;
	return tmpCD;
}

void add(_List* l, int n) {
	_LLentry* tmpLL;

	tmpLL = (_LLentry*)malloc(sizeof(_LLentry));
	tmpLL->n = n;
	tmpLL->next = NULL;

	if (l->head == NULL) {
		l->head = tmpLL;
		l->tail = tmpLL;
	}
	else {
		l->tail->next = tmpLL;
		l->tail = l->tail->next;
	}
}

void clear(_List* l) {
	_LLentry* tmpLL;

	tmpLL = l->head;
	l->tail = NULL;
	while (tmpLL != NULL) {
		l->head = l->head->next;
		free(tmpLL);
		tmpLL = l->head;
	}
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 55
#define M 101

typedef struct _Coordinate {
	int x;
	int y;
}_Coordinate;

typedef struct _Qentry {
	_Coordinate cd;
	struct _Qentry* next;
}_Qentry;

typedef struct _Queue {
	_Qentry* front;
	_Qentry* rear;
	int size;
}_Queue;

int r, c, x, y, cnt, cnt_c, cnt_p, low, mid, high, answer;
_Coordinate tmpCD;
_Queue q;
char info[N][N], dist[M][M];
int chk[M][M], g[2 * M][2 * M], par[2 * M], vis[2 * M];
_Coordinate C[M], P[M];
_Coordinate direction[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void push(_Queue* q, _Coordinate cd);
_Coordinate pop(_Queue* q);
_Bool research(int n);
_Bool dfs(int n);

int main(void) {

	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		getchar();
		for (int j = 0; j < c; j++) {
			info[i][j] = getchar();

			if (info[i][j] == 'C') {
				C[cnt_c] = (_Coordinate){ i,j };
				cnt_c++;
			}
			else if (info[i][j] == 'P') {
				P[cnt_p] = (_Coordinate){ i,j };
				cnt_p++;
			}
		}
	}

	if (cnt_c == 0) {
		printf("%d", 0);
		return 0;
	}
	if (cnt_c > cnt_p) {
		printf("%d", -1);
		return 0;
	}

	for (int num = 0; num < cnt_c; num++) {
		memset(chk, -1, M * M * sizeof(int));
		q = (_Queue){ NULL, NULL, 0 };
		push(&q, C[num]);
		chk[C[num].x][C[num].y] = 0;

		while (q.size) {
			tmpCD = pop(&q);
			for (int k = 0; k < 4; k++) {
				x = tmpCD.x + direction[k].x;
				y = tmpCD.y + direction[k].y;

				if (x < 0 || r <= x || y < 0 || c <= y) continue;
				if (chk[x][y] != -1) continue;
				if (info[x][y] == 'X') continue;

				chk[x][y] = chk[tmpCD.x][tmpCD.y] + 1;
				push(&q, (_Coordinate) { x, y });
			}
		}

		for (int i = 0; i < cnt_p; i++)
			dist[num][i] = chk[P[i].x][P[i].y];
	}

	answer = -1;
	low = 0; high = 10000;
	while (low <= high) {
		mid = (low + high) / 2;
		if (research(mid)) {
			answer = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}

	printf("%d", answer);

	return 0;
}

_Bool research(int n) {
	memset(g, 0, sizeof(g));
	for (int i = 0; i < cnt_c; i++) {
		int k = 0;
		for (int j = 0; j < cnt_p; j++) {
			if ((dist[i][j] != -1) && (dist[i][j] <= n))
				g[i][k++] = j + 100;
		}
	}

	cnt = 0;
	memset(par, -1, sizeof(par));
	for (int i = 0; i < cnt_c; i++) {
		memset(vis, 0, sizeof(vis));
		cnt += dfs(i);
	}

	return (cnt == cnt_c);
}

_Bool dfs(int n) {
	vis[n] = 1;
	for (int j = 0; g[n][j] != 0; j++) {
		int i = g[n][j];
		if (vis[i]) continue;
		vis[i] = 1;
		if ((par[i] == -1) || dfs(par[i])) {
			par[i] = n;
			return 1;
		}
	}
	return 0;
}

void push(_Queue* q, _Coordinate cd) {
	_Qentry* tmp;

	tmp = (_Qentry*)malloc(sizeof(_Qentry));
	tmp->cd = cd; tmp->next = NULL;

	if (q->front == NULL) {
		q->front = tmp;
		q->rear = tmp;
		q->size = 1;
	}
	else {
		q->rear->next = tmp;
		q->rear = q->rear->next;
		q->size += 1;
	}
}

_Coordinate pop(_Queue* q) {
	_Coordinate tmpCD = { -1, -1 };
	_Qentry* tmpQ;

	if (q->front == NULL) return tmpCD;

	tmpCD = q->front->cd;
	tmpQ = q->front;
	q->front = q->front->next;
	if (q->front == NULL) q->rear = NULL;
	q->size -= 1;

	free(tmpQ);
	tmpQ = NULL;
	return tmpCD;
}
*/