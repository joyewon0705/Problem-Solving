#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define V 20202

int k, v, e, a, b;
bool isVisit[V];
int chk[V];
vector<int> neighbors[V];
queue<int> q;

int main(void) {

	scanf("%d", &k);
	for (int tc = 0; tc < k; tc++) {
		bool isPossible = true;

		scanf("%d %d", &v, &e);

		for (int i = 1; i <= v; i++) {
			neighbors[i] = vector<int>();
			isVisit[i] = false;
			chk[i] = 0;
		}

		for (int i = 0; i < e; i++) {
			scanf("%d %d", &a, &b);
			neighbors[a].push_back(b);
			neighbors[b].push_back(a);
		}

		for (int i = 1; i <= v; i++) {
			if (chk[i]) continue;
			
			chk[i] = 1;
			q = queue<int>();
			q.push(i);
			while (!q.empty()) {
				int cur = q.front();
				q.pop();

				if (isVisit[cur]) continue;
				isVisit[cur] = true;

				int val = chk[cur] > 0 ? -1 : 1;
				for (int next : neighbors[cur]) {
					if (chk[next] == chk[cur]) {
						isPossible = false;
						break;
					}
					if (!chk[next]) chk[next] = val;
					q.push(next);
				}

				if (!isPossible) break;
			}

			if (!isPossible) break;
		}

		if (isPossible) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}