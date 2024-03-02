#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define N 101010

int n, u, v, ans;
bool isVisit[N];
vector<int> nb[N], vt;
queue<int> q, vo;

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &u, &v);
		nb[u].push_back(v);
		nb[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &u);
		vo.push(u);
	}

	ans = 1;
	isVisit[1] = true;
	vt.push_back(1);
	while (!vo.empty()) {
		vector<int> v;

		sort(vt.begin(), vt.end());
		for (int i = 0; i < vt.size(); i++) {
			v.push_back(vo.front());
			q.push(vo.front());
			vo.pop();
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < vt.size(); i++) {
			if (vt[i] != v[i]) {
				ans = 0;
				break;
			}
		}

		if (q.empty()) ans = 0;
		if (ans == 0) break;

		vt = vector<int>();
		int cur = q.front();
		q.pop();

		for (int next : nb[cur]) {
			if (isVisit[next]) continue;
			isVisit[next] = true;
			vt.push_back(next);
		}
	}
	
	if (vo.size() != vt.size()) ans = 0;
	printf("%d", ans);

	return 0;
}