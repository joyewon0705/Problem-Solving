#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define N 11
#define LEN 10

int n, m;
long long ans;
bool chk[N];
int alphabet[30];
char words[N][LEN];
vector<char> v;

void f(int cur) {

	if (cur >= m) {
		long long val = 0;
		for (int i = 0; i < n; i++) {
			long long tmp = 0;
			for (int j = 0; j < strlen(words[i]); j++) {
				tmp = tmp * 10 + alphabet[words[i][j] - 'A'];
			}
			val += tmp;
		}
		if (ans < val) ans = val;
		if (ans > 99436) {
			int t = alphabet[0];
		}
		return;
	}

	for (int i = 9; i > 9 - m; i--) {
		if (chk[i]) continue;
		chk[i] = true;
		alphabet[v[cur] - 'A'] = i;
		f(cur + 1);
		chk[i] = false;
	}
}

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", words[i]);
		for (int j = 0; j < strlen(words[i]); j++) {
			if (alphabet[words[i][j] - 'A']) continue;
			alphabet[words[i][j] - 'A'] = 1;
			v.push_back(words[i][j]);
		}
	}

	m = v.size();
	f(0);

	printf("%lld", ans);

	return 0;
}