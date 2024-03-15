#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

#define N 101
typedef struct _info { int a, h, w, i; }_info;

int n, a, h, w;
int d[N];
vector<_info> v = { { 0 } };
stack<int> st;

bool cmp(_info a, _info b) {
	return a.a < b.a;
}

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &a, &h, &w);
		v.push_back({ a, h, w, i });
	}

	sort(v.begin(), v.end(), cmp);

	h = 0;
	for (int i = 1; i <= n; i++) {
		d[i] = v[i].h;
		for (int j = i - 1; j; j--) {
			if (v[i].w > v[j].w) {
				d[i] = max(d[i], d[j] + v[i].h);
			}
		}
		h = max(h, d[i]);
	}
	
	while (n) {
		if (h == d[n]) {
			st.push(v[n].i);
			h -= v[n].h;
		}
		n--;
	}

	printf("%d\n", st.size());
	while (!st.empty()) {
		printf("%d\n", st.top());
		st.pop();
	}

	return 0;
}