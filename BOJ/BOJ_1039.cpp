#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

typedef pair<int, int> P;

int n, m, k, ans;
queue<P> q;
set<int> isVisit[11];

int main(void) {

	scanf("%d %d", &n, &k);

	for (int i = 1; n / i; i *= 10) m++;

	ans = -1;
	q.push({ n, 0 });
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cnt == k) {
			if (ans < cur) ans = cur;
			continue;
		}

		if (isVisit[cnt].find(cur) != isVisit[cnt].end()) continue;
		isVisit[cnt].insert(cur);

		string tmp = to_string(cur);
		for (int i = 0; i < m; i++) {
			for (int j = i + 1; j < m; j++) {
				if (i == 0 && tmp[j] == '0') continue;
				int t = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = t;
				q.push({ stoi(tmp), cnt + 1});
				tmp[j] = tmp[i];
				tmp[i] = t;
			}
		}
	}

	printf("%d", ans);

	return 0;
}