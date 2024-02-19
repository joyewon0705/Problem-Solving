#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define INF 1<<30
#define N 55
#define K 7
typedef struct _info { int r, c, s; }_info;

bool chk[7];
int n, m, k, r, c, s, ans = INF;
int A[N][N];
vector<_info> v;

void f(int cur, int cnt) {
	int cA[N][N];

	chk[cur] = true;
	memcpy(cA, A, sizeof(A));

	if (cur) {
		r = v[cur].r;
		c = v[cur].c;
		s = v[cur].s;

		for (int k = s; k; k--) {
			int tmp = A[r - k][c - k];
			for (int i = r - k; i < r + k; i++) {
				A[i][c - k] = A[i + 1][c - k];
			}
			for (int j = c - k; j < c + k; j++) {
				A[r + k][j] = A[r + k][j + 1];
			}
			for (int i = r + k; i > r - k; i--) {
				A[i][c + k] = A[i - 1][c + k];
			}
			for (int j = c + k; j > c - k; j--) {
				A[r - k][j] = A[r - k][j - 1];
			}
			A[r - k][c - k + 1] = tmp;
		}
	}

	if (cnt == k) {
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= m; j++) {
				sum += A[i][j];
			}
			if (ans > sum) ans = sum;
		}
	}
	else {
		for (int next = 1; next <= k; next++) {
			if (chk[next]) continue;
			f(next, cnt + 1);
		}
	}

	memcpy(A, cA, sizeof(A));
	chk[cur] = false;
}

int main(void) {

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	v.push_back({ 0, 0, 0 });
	for (int i = 1; i <= k; i++) {
		scanf("%d %d %d", &r, &c, &s);
		v.push_back({ r, c, s });
	}

	f(0, 0);

	printf("%d", ans);

	return 0;
}