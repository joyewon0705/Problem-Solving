#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;
string T, P;
vector<int> v, pi;

int main(void) {

	getline(cin, T);
	getline(cin, P);

	n = T.length();
	m = P.length();
	pi = vector<int>(m, 0);
	for (int i = 1, j = 0; i < m; i++) {
		while (j && P[i] != P[j]) j = pi[j - 1];
		if (P[i] == P[j]) pi[i] = ++j;
	}

	for (int i = 0, j = 0; i < n; i++) {
		while (j && T[i] != P[j]) j = pi[j - 1];
		if (T[i] == P[j]) {
			if (j == m - 1) {
				v.push_back(i - m + 2);
				j = pi[j];
			}
			else j++;
		}
	}

	printf("%d\n", v.size());
	for (int prt : v) printf("%d ", prt);

	return 0;
}