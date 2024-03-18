#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<bool> chk;
vector<int> v;
stack<int> st;

bool f(int cur, int cnt) {

	if (cur > n) return false;
	if (cnt == 4) {
		if (cur == n) return true;
		else return false;
	}

	for (int i = v.size() - 1; i >= 0; i--) {
		st.push(v[i]);
		if (f(cur + v[i], cnt + 1)) return true;
		st.pop();
	}
	return false;
}

int main(void) {

	scanf("%d", &n);

	chk = vector<bool>(n + 1, true);
	chk[0] = chk[1] = false;
	for (int i = 2; i * i <= n;) {
		for (int j = i + 1; j <= n; j++) {
			if (j % i == 0) chk[j] = false;
		}
		while (!chk[++i]) ;
	}
	for (int i = 2; i <= n; i++) {
		if (chk[i]) v.push_back(i);
	}
	
	if (f(0, 0)) {
		for (int i = 0; i < 4; i++) {
			printf("%d ", st.top());
			st.pop();
		}
	}
	else printf("-1");

	return 0;
}