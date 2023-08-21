#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1<<30
#define N 101010

int n, m, a, b;
int list[N], t[4 * N];

int segmentTree(int cur, int low, int high) {

	if (low == high) return t[cur] = list[low];

	int mid = (low + high) / 2;
	return t[cur] = min(segmentTree(cur * 2, low, mid), segmentTree(cur * 2 + 1, mid + 1, high));
}

int getMin(int cur, int low, int high) {

	if (low > b || high < a) return INF;
	if (a <= low && high <= b) return t[cur];

	int mid = (low + high) / 2;
	return min(getMin(cur * 2, low, mid), getMin(cur * 2 + 1, mid + 1, high));
}

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
	}

	segmentTree(1, 1, n);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", getMin(1, 1, n));
	}

	return 0;
}