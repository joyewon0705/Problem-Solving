#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define N 1010
typedef struct _info { int a, b, c; }_info;

int a, b, c, ans;
bool isVisit[N][N];
vector<int> v = vector<int>(3);
queue<_info> q;

int main(void) {

	scanf("%d %d %d", &a, &b, &c);

	q.push({ a, b, c });
	while (!q.empty()) {
		v[0] = q.front().a;
		v[1] = q.front().b;
		v[2] = q.front().c;
		q.pop();

		sort(v.begin(), v.end());
		a = v[0]; b = v[1]; c = v[2];

		if (a == b && b == c) {
			ans = 1;
			break;
		}
		if (isVisit[a][c]) continue;
		isVisit[a][c] = true;

		if (a < b) q.push({ a + a, b - a, c });
		if (a < c) q.push({ a + a, b, c - a });
		if (b < c) q.push({ a, b + b, c - b });
	}

	printf("%d", ans);

	return 0;
}