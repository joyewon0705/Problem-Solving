#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1<<30
#define N 55

int n, a, b;
int m[N][N], s[N];
vector<int> v;

int main(void) {

	scanf("%d", &n);
	while (true) {
		scanf("%d %d", &a, &b);
		if (a == -1 && b == -1) break;
		m[a][b] = 1;
		m[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (m[i][j] == 0) m[i][j] = INF;
		}
		m[i][i] = 0;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (m[i][k] >= INF) continue;
			for (int j = 1; j <= n; j++) {
				if (m[k][j] >= INF) continue;
				if (m[i][j] > m[i][k] + m[j][k]) 
					m[i][j] = m[i][k] + m[k][j];
			}
		}
	}

	a = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (s[i] < m[i][j]) s[i] = m[i][j];
		}
		if (a > s[i]) {
			a = s[i];
			b = 1;
			v = { i };
		}
		else if (a == s[i]) {
			b++;
			v.push_back(i);
		}
	}

	sort(v.begin(), v.end());

	printf("%d %d\n", a, b);
	for (int prt : v) printf("%d ", prt);

	return 0;
}