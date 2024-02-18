#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int ans;
string S, T;
queue<string> q;

int main(void) {

	cin >> S;
	cin >> T;

	q.push(T);
	while (!q.empty()) {
		string cur = q.front();
		q.pop();

		if (cur.size() < S.size()) continue;
		if (cur == S) {
			ans = 1;
			break;
		}

		if (cur[cur.size() - 1] == 'A') {
			string next = cur;
			next.pop_back();
			q.push(next);
		}
		if (cur[0] == 'B') {
			string next = cur;
			reverse(next.begin(), next.end());
			next.pop_back();
			q.push(next);
		}
	}

	printf("%d", ans);

	return 0;
}