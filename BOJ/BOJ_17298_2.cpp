#include <iostream>
#include <stack>
using namespace std;

#define N 1010101

int n;
int a[N], nge[N];
stack<int> st;

int main(void) {
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		while (!st.empty() && a[st.top()] < a[i]) {
			nge[st.top()] = a[i];
			st.pop();
		}
		st.push(i);
	}

	for (int i = 1; i <= n; i++) {
		if (nge[i]) printf("%d ", nge[i]);
		else printf("-1 ");
	}

	return 0;
}