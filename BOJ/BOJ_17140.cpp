#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

#define N 101
typedef pair<int, int> P;

int r, c, k, mr, mc, ans;
int A[N][N];

void f(bool chk) {

	if (chk) {
		int nmc = 0;
		for (int i = 0; i < mr; i++) {
			map<int, int> m;
			for (int j = 0; j < mc; j++) {
				if (A[i][j]) {
					if (m.find(A[i][j]) == m.end()) m.insert({ A[i][j], 1 });
					else m[A[i][j]]++;
				}
			}

			vector<P> v;
			for (P cur : m) {
				v.push_back({ cur.second, cur.first });
			}
			sort(v.begin(), v.end());

			if (nmc < 2 * v.size()) nmc = 2 * v.size();
			for (int j = 0; j < v.size(); j++) {
				A[i][2 * j] = v[j].second;
				A[i][2 * j + 1] = v[j].first;
			}
			for (int j = 2 * v.size(); j < mc; j++) {
				A[i][j] = 0;
			}
		}
		mc = nmc % N;
	}
	else {
		int nmr = 0;
		for (int j = 0; j < mc; j++) {
			map<int, int> m;
			for (int i = 0; i < mr; i++) {
				if (A[i][j]) {
					if (m.find(A[i][j]) == m.end()) m.insert({ A[i][j], 1 });
					else m[A[i][j]]++;
				}
			}

			vector<P> v;
			for (P cur : m) {
				v.push_back({ cur.second, cur.first });
			}
			sort(v.begin(), v.end());

			if (nmr < 2 * v.size()) nmr = 2 * v.size();
			for (int i = 0; i < v.size(); i++) {
				A[2 * i][j] = v[i].second;
				A[2 * i + 1][j] = v[i].first;
			}
			for (int i = 2 * v.size(); i < mr; i++) {
				A[i][j] = 0;
			}
		}
		mr = nmr % N;
	}
}

int main(void) {

	scanf("%d %d %d", &r, &c, &k);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	r--; c--;
	mr = mc = 3;
	ans = -1;
	for (int i = 0; i <= 100; i++) {
		if (A[r][c] == k) {
			ans = i;
			break;
		}
		if (mr >= mc) f(true);
		else f(false);
	}

	printf("%d", ans);

	return 0;
}