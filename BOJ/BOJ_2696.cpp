#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int t, n, m;

int main(void) {

	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		priority_queue<int> l;
		priority_queue<int, vector<int>, greater<int>> r;

		scanf("%d", &n);
		printf("%d\n", (n + 1) / 2);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &m);

			if (i % 2) {
				if (!l.empty() && l.top() > m) {
					r.push(l.top());
					l.pop();
					l.push(m);
				}
				else r.push(m);
				printf("%d ", r.top());
			}
			else {
				if (!r.empty() && r.top() < m) {
					l.push(r.top());
					r.pop();
					r.push(m);
				}
				else l.push(m);
			}
		}
		printf("\n");
	}

	return 0;
}