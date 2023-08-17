#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1<<30
#define N 101010
typedef pair<int, int> P;

int n, m, a, b;
int list[N];
P tree[4 * N];

P segmentTree(int cur, int low, int high) {

	if (low == high) {
		tree[cur] = { list[low], list[high] };
		return tree[cur];
	}

	int mid = (low + high) / 2;
	P left = segmentTree(cur * 2, low, mid);
	P right = segmentTree(cur * 2 + 1, mid + 1, high);
	return tree[cur] = { min(left.first, right.first), max(left.second, right.second) };
}

P getMinMax(int cur, int low, int high) {

	if (b < low || high < a) return { INF, -1 };
	if (a <= low && high <= b) return tree[cur];

	int mid = (low + high) / 2;
	P left = getMinMax(cur * 2, low, mid);
	P right = getMinMax(cur * 2 + 1, mid + 1, high);
	return { min(left.first, right.first), max(left.second, right.second) };
}

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
	}
	segmentTree(1, 1, n);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		P ans = getMinMax(1, 1, n);
		printf("%d %d\n", ans.first, ans.second);
	}

	return 0;
}