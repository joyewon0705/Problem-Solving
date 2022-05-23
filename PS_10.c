#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 55
#define MAX 70707070

typedef struct _Qentry {
	int n;
	struct _Qentry* next;
}_Qentry;

typedef struct _Queue {
	_Qentry* front;
	_Qentry* rear;
}_Queue;

int n, a, b, f, tmp, source, sink, amount, answer;
int capacity[N][N], flow[N][N], parent[N];
_Queue q;
void push(_Queue* q, int n);
int pop(_Queue* q);
_Bool empty(_Queue* q);

int main(void) {

	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%c %c %d", &a, &b, &f);
		getchar();
			
		if ('a' <= a) a = a - 'a' + 26;
		else a = a - 'A';

		if ('a' <= b) b = b - 'a' + 26;
		else b = b - 'A';

		capacity[a][b] += f;
		capacity[b][a] += f;
	}

	source = 'A' - 'A';
	sink = 'Z' - 'A';
	while (1) {
		memset(parent, -1, N * sizeof(int));
		q = (_Queue){NULL, NULL};
		parent[source] = source;
		push(&q, source);

		while (!empty(&q) && (parent[sink] == -1)) {
			tmp = pop(&q);
			for (int i = 0; i < N; i++) {
				if ((capacity[tmp][i] - flow[tmp][i] > 0) && (parent[i] == -1)) {
					push(&q, i);
					parent[i] = tmp;
				}
			}
		}

		if (parent[sink] == -1) break;

		amount = MAX;
		for (int i = sink; i != source; i = parent[i]) {
			if (amount > (tmp = capacity[parent[i]][i] - flow[parent[i]][i]))
				amount = tmp;
		}

		for (int i = sink; i != source; i = parent[i]) {
			flow[parent[i]][i] += amount;
			flow[i][parent[i]] -= amount;
		}

		answer += amount;
	}

	printf("%d", answer);

	return 0;
}

void push(_Queue* q, int n) {
	_Qentry* tmp;

	tmp = (_Qentry*)malloc(sizeof(_Qentry));
	tmp->n = n;
	tmp->next = NULL;
	if (q->rear == NULL) {
		q->front = tmp;
		q->rear = tmp;
	}
	else {
		q->rear->next = tmp;
		q->rear = q->rear->next;
	}
	
	/*
	// 디버깅용
	tmp = q->front;
	printf("push(%d): ", n);
	while (tmp != NULL) {
		printf("%d -> ", tmp->n);
		tmp = tmp->next;
	}
	printf("NULL\n");
	*/
}

int pop(_Queue* q) {
	int tmp;
	_Qentry* tmpQ;

	if (q->front == NULL) return -1;

	tmp = q->front->n;
	tmpQ = q->front;
	q->front = q->front->next;
	if (q->front == NULL) q->rear = NULL;

	free(tmpQ);
	tmpQ = NULL;

	/*
	// 디버깅용
	tmpQ = q->front;
	printf("pop(): ");
	while (tmpQ != NULL) {
		printf("%d -> ", tmpQ->n);
		tmpQ = tmpQ->next;
	}
	printf("NULL\n");
	*/

	return tmp;
}

_Bool empty(_Queue* q) {
	if (q->front == NULL) return 1;
	else return 0;
}

// 참고: https://everenew.tistory.com/178
// 참고: https://velog.io/@sunjoo9912/%EB%B0%B1%EC%A4%80-6086-%EC%B5%9C%EB%8C%80-%EC%9C%A0%EB%9F%89