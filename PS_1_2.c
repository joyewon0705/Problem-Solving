#include <stdio.h>
#pragma warning(disable:4996)
#define N 10000
int tree[N + 1][3];		// 0행: 부모, 1행: 왼쪽자식, 2행: 오른쪽자식
_Bool isNode[N + 1] = { 0 };
_Bool matrix[N + 1][N + 1] = { 0 };
int depth, breadth;

int main(void) {
	int drawTree(int, int, int);
	int n, number, left, right, root, answerLevel, answerBreadth;

	// 초기화
	for (int i = 0; i < N + 1; i++)
		tree[i][0] = tree[i][1] = tree[i][2] = -1;

	// 노드 개수 입력
	scanf("%d", &n);

	// 노드 정보 입력
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &number, &left, &right);
		tree[number][1] = left;
		tree[number][2] = right;
		tree[left][0] = number;
		tree[right][0] = number;
		isNode[number] = isNode[left] = isNode[right] = 1;
	}

	// 루트 노드 검색
	for (root = 0; isNode[root] == 0; root++);
	while (tree[root][0] != -1) root = tree[root][0];

	// 좌표 지정
	depth = breadth = 0;
	drawTree(root, 1, 1);

	// 디버깅용 트리 출력
	/*
	for (int i = 1; i < depth + 1; i++) {
		for (int j = 1; j < breadth + 1; j++) {
			if (matrix[i][j] == 0) printf("  ");
			else printf("%2d", matrix[i][j]);
		}
		printf("\n");
	}
	*/

	// 답 계산
	answerLevel = answerBreadth = 0;
	for (int i = 1; i < depth + 1; i++) {
		int min = 1;
		int max = breadth;
		while (matrix[i][min] == 0) min++;
		while (matrix[i][max] == 0) max--;
		if ((max - min + 1) > answerBreadth) {
			answerLevel = i;
			answerBreadth = max - min + 1;
		}
	}

	// 출력
	printf("%d %d", answerLevel, answerBreadth);

	return 0;
}

int drawTree(int node, int x, int y) {
	// 왼쪽 자식 노드 검색
	if (tree[node][1] == -1) matrix[x][y] = node;
	else y = drawTree(tree[node][1], x + 1, y);
	// 좌표 지정
	matrix[x][y] = 1;
	if (x > depth) depth = x;
	if (y > breadth) breadth = y;
	// 오른쪽 자식 노드 검색
	if (tree[node][2] == -1) return (y + 1);
	else return drawTree(tree[node][2], x + 1, y + 1);
}