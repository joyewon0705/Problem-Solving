#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> P;

int t, n, x, y;
P dst;

int main(void) {

	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		bool isHappy = false;
		vector<bool> isVisit;
		vector<P> v;
		queue<int> q;

		scanf("%d", &n);
		for (int i = 0; i < n + 2; i++) {
			scanf("%d %d", &x, &y);
			v.push_back({ x, y });
			isVisit.push_back(false);
		}
		dst = { x, y };

		q.push(0);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			if (isVisit[cur]) continue;
			isVisit[cur] = true;

			P pos = v[cur];
			if (pos.first == dst.first && pos.second == dst.second) {
				isHappy = true;
				break;
			}

			for (int i = 0; i < n + 2; i++) {
				if (isVisit[i]) continue;
				int dist = abs(pos.first - v[i].first) + abs(pos.second - v[i].second);
				if (dist > 1000) continue;
				q.push(i);
			}
		}

		if (isHappy) printf("happy\n");
		else printf("sad\n");
	}

	return 0;
}