#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#define INF 1<<30
#define N 101010
typedef pair<int, int> P;

int n, k, ans;
int m[N][2];
queue<P> q;
stack<int> st;

int main(void) {

	scanf("%d %d", &n, &k);

	for (int i = 0; i < N; i++) m[i][0] = INF;

	m[n][0] = 0; m[n][1] = n;
	q.push({ n - 1, n });
	q.push({ n + 1, n });
	q.push({ n * 2, n });
	while (!q.empty()) {
		int cur = q.front().first;
		int prt = q.front().second;
		q.pop();

		if (cur < 0) continue;
		if (cur > N) continue;
		if (m[cur][0] < m[prt][0] + 2) continue;
		m[cur][0] = m[prt][0] + 1;
		m[cur][1] = prt;
		if (cur == k) break;

		q.push({ cur - 1, cur });
		q.push({ cur + 1, cur });
		q.push({ cur * 2, cur });
	}

	printf("%d\n", m[k][0]);
	for (int i = k; i != n; i = m[i][1]) st.push(i);
	printf("%d ", n);
	while (st.size()) {
		printf("%d ", st.top());
		st.pop();
	}

	return 0;
}