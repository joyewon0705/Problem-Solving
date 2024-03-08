#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define N 101010

int n, a, b, cnt;
vector<int> v[N], list;
stack<int> st;

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		list.push_back(a);
	}

	cnt++;
	st.push(1);
	while (!st.empty()) {
		int cur = st.top();

		if (cnt < n) {
			for (int next : v[cur]) {
				if (next == list[cnt]) {
					cnt++;
					st.push(next);
					break;
				}
			}
		}
		if (cur == st.top()) st.pop();
	}

	if (cnt != n) printf("0");
	else printf("1");

	return 0;
}