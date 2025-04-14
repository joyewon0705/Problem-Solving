#include <iostream>
#include <stack>
using namespace std;

#define N 505050

int n;
int h[N], a[N];
stack<int> st;

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &h[i]);
	}

	for (int i = n; i; i--) {
		while (!st.empty() && h[st.top()] <= h[i]) {
			a[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}

	for (int i = 1; i <= n; i++) printf("%d ", a[i]);

	return 0;
}