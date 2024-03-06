#include <iostream>
#include <vector>
using namespace std;

#define N 44
#define K 101
typedef pair<int, int > P;

int n, m, k, r, c, b, ans;
bool notebook[N][N];
vector<P> stickers[K], ssize;

vector<P> rotate(vector<P> v, int t) {
	vector<P> nv;

	for (P cd : v) {
		nv.push_back({ cd.second, t - cd.first });
	}
	return nv;
}

bool attach(int x, int y, vector<P> v) {
	bool chk = true;

	for (P cd : v) {
		if (notebook[x + cd.first][y + cd.second]) {
			chk = false;
			break;
		}
	}
	if (chk) {
		for (P cd : v) {
			notebook[x + cd.first][y + cd.second] = true;
			ans++;
		}
	}
	return chk;
}

void f(int cur) {
	int r = ssize[cur].first;
	int c = ssize[cur].second;
	vector<P> v = stickers[cur];

	for (int h = 0; h < 4; h++) {
		for (int i = 1; i <= n - r + 1; i++) {
			for (int j = 1; j <= m - c + 1; j++) {
				if (attach(i, j, v)) return;
			}
		}
		int t = r;
		r = c;
		c = t;
		v = rotate(v, t - 1);
	}
}

int main(void) {

	scanf("%d %d %d", &n, &m, &k);
	for (int h = 0; h < k; h++) {
		scanf("%d %d", &r, &c);
		ssize.push_back({ r, c });
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				scanf("%d", &b);
				if (b) stickers[h].push_back({ i, j });
			}
		}
	}

	for (int h = 0; h < k; h++) f(h);

	printf("%d", ans);

	return 0;
}