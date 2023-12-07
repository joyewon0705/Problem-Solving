#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 202020
#define S 2020
typedef struct _ball { int i, c, s; } _ball;

int n, c, s, sum;
int ans[N], cs[N], ss[S];
vector<_ball> v;

bool cmp(_ball a, _ball b) {
	if (a.s == b.s) return a.c < b.c;
	else return a.s < b.s;
}

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &c, &s);
		v.push_back({ i, c, s });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		c = v[i].c;
		s = v[i].s;

		ans[v[i].i] = sum - cs[c] - ss[s];
		if (i != 0 && c == v[i - 1].c && s == v[i - 1].s) ans[v[i].i] = ans[v[i - 1].i];

		sum += s;
		cs[c] += s;
		ss[s] += s;
	}

	for (int i = 0; i < n; i++)
		printf("%d\n", ans[i]);

	return 0;
}