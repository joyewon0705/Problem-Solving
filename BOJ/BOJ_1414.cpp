#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define N 55
typedef pair<int, int> P;

char ch;
int n, chk, ans;
bool isVisit[N];
vector<P> v[N];
priority_queue<P, vector<P>, greater<P>> pq;

int main(void) {

	scanf("%d\n", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%c", &ch);
			if (ch == '0') continue;
			int d;
			if (ch >= 'a') d = ch - 'a' + 1;
			else d = ch - 'A' + 27;
			v[i].push_back({ d, j });
			v[j].push_back({ d, i });
			ans += d;
		}
		getchar();
	}

	chk = n;
	pq.push({ 0, 1 });
	while (!pq.empty()) {
		int cnt = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (isVisit[cur]) continue;
		isVisit[cur] = true;
		ans -= cnt;
		chk--;

		for (P next : v[cur]) pq.push(next);
	}

	if (chk) ans = -1;
	printf("%d", ans);

	return 0;
}