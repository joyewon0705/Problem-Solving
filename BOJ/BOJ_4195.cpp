#include <iostream>
#include <string>
#include <map>
using namespace std;

#define N 202020
#define LEN 22

int t, f, n, a, b;
char s1[LEN], s2[LEN];
int parent[N], cnt[N];
map<string, int> m;

int getParent(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = getParent(parent[x]);
}

int main(void) {

	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		m = map<string, int>();
		n = 0;

		scanf("%d", &f);
		for (int i = 0; i < f; i++) {
			scanf("%s %s", s1, s2);
			if (m.find(string(s1)) == m.end()) {
				m.insert({ string(s1), n });
				parent[n] = n;
				cnt[n++] = 1;
			}
			if (m.find(string(s2)) == m.end()) {
				m.insert({ string(s2), n });
				parent[n] = n;
				cnt[n++] = 1;
			}
			
			a = m[string(s1)]; b = m[string(s2)];
			a = getParent(a);
			b = getParent(b);
			if (a != b) {
				parent[b] = a;
				cnt[a] += cnt[b];
			}

			printf("%d\n", cnt[a]);
		}
	}

	return 0;
}