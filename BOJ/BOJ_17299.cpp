#include <iostream>
#include <stack>
using namespace std;

#define N 1010101
typedef pair<int, int> P;

int n;
int A[N], cnt[N], ans[N];
stack<P> st;

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		cnt[A[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		int a = A[i];
		while (!st.empty() && st.top().first < cnt[a]) {
			ans[st.top().second] = a;
			st.pop();
		}
		st.push({ cnt[a], i });
	}
	
	while (!st.empty()) {
		ans[st.top().second] = -1;
		st.pop();
	}

	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);

	return 0;
}