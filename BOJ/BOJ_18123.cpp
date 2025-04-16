#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

#define N 1010101
#define M 30

int n, s, u, v;
unordered_set<string> set;

string f(int cur, int parent, vector<int> ngh[]) {
	vector<string> v;

	for (int next : ngh[cur]) {
		if (next == parent) continue;
		v.push_back(f(next, cur, ngh));
	}
	sort(v.begin(), v.end());

	string ret(1, ngh[cur].size());
	for (string str : v) ret += str;
	
	return ret;
}

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &s);

		int max = 0;
		vector<int> ngh[M];
		for (int j = 1; j < s; j++) {
			scanf("%d %d", &u, &v);
			ngh[u].push_back(v);
			ngh[v].push_back(u);
		}

		int cnt = 0;
		int chk[M];
		queue<int> q;
		for (int i = 0; i < s; i++) {
			chk[i] = ngh[i].size();
			if (chk[i] > 0) cnt++;
			if (chk[i] == 1) q.push(i);
		}

		while (cnt > 2) {
			for (int i = q.size(); i; i--) {
				int cur = q.front();
				q.pop();

				cnt--;
				for (int next : ngh[cur]) {
					chk[next]--;
					if (chk[next] == 1) q.push(next);
				}
			}
		}

		vector<string> v;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			v.push_back(f(cur, -1, ngh));
		}
		sort(v.begin(), v.end());

		if (s == 1) set.insert("0");
		else set.insert(v[0]);
	}

	printf("%d", set.size());

	return 0;
}