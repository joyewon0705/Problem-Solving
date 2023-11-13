#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define N 10101 

int n, m, a, b, cnt, ans;
bool isVisit[N];
vector<int> v[N], list;
queue<int> q;

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		memset(isVisit, false, sizeof(isVisit));
		cnt = 0;

		q.push(i);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			if (isVisit[cur]) continue;
			isVisit[cur] = true;
			cnt++;

			for (int next : v[cur]) {
				q.push(next);
			}
		}

		if (ans < cnt) {
			ans = cnt;
			list = vector<int>();
			list.push_back(i);
		}
		else if (ans == cnt) {
			list.push_back(i);
		}
	}

	sort(list.begin(), list.end());

	for (int cur : list) printf("%d ", cur);

	return 0;
}