#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 1<<30
#define N 101010
typedef pair<int, int> P;

int n, m, a, b, c = INF;
int A[N];
priority_queue<P, vector<P>, greater<P>> pq;

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		pq.push({ A[i], i });
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d %d", &a, &b);
			A[a] = b;
			pq.push({ b, a });
		}
		else {
			c = INF;
			while (true) {
				b = pq.top().first;
				a = pq.top().second;
				pq.pop();

				if (A[a] != b) continue;
				c = b;
				break;
			}
			printf("%d\n", a);
			pq.push({ A[a], a });
		}
	}

	return 0;
}