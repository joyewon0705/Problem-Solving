#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define LEN 11

int t, n;
char s[LEN];
vector<string> v;

int main(void) {

	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		v = vector<string>();

		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%s", s);
			v.push_back(s);
		}

		sort(v.begin(), v.end());

		bool chk = true;
		for (int i = 0; i < n - 1; i++) {
			int cur = v[i].length();
			int next = v[i + 1].length();

			if (cur >= next) continue;
			if (v[i + 1].substr(0, cur) == v[i]) {
				chk = false;
				break;
			}
		}

		if (chk) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}