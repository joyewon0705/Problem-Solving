#include <iostream>
#include <set>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

bool chk;
int s, t;
string ans;
queue<pair<ll, string>> q;
set<ll> list = { 0 };

int main(void) {

	scanf("%d %d", &s, &t);

	q.push({ s, "" });
	while (!q.empty()) {
		ll cur = q.front().first;
		string str = q.front().second;
		q.pop();

		if (cur == t) {
			chk = true;
			ans = str;
			break;
		}

		if (list.find(cur) != list.end()) continue;
		list.insert(cur);

		if (cur < t) q.push({ cur * cur, str + "*" });
		if (cur < t) q.push({ cur + cur, str + "+" });
		q.push({ cur / cur, str + "/" });
	}

	if (s == t) printf("0");
	else if (chk) printf("%s", ans.c_str());
	else printf("-1");

	return 0;
}