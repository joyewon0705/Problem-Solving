#include <iostream>
#include <stack>
using namespace std;

#define N 80808

int n;
long long ans;
int h[N];
stack<int> st;

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &h[i]);
	}

	for (int i = 1; i <= n; i++) {
		while (!st.empty() && h[st.top()] <= h[i]) {
			ans += i - st.top() - 1;
			st.pop();
		}
		st.push(i);
	}

	while (!st.empty()) {
		ans += n - st.top();
		st.pop();
	}

	printf("%lld", ans);

	return 0;
}