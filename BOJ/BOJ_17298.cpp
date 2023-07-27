#include <iostream>
#include <stack>
using namespace std;

#define N 1010101

int n, a;
int list[N];
stack<pair<int, int>> st;

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		while (!st.empty() && st.top().first < a) {
			list[st.top().second] = a;
			st.pop();
		}
		st.push({ a, i });
	}

	for (int i = 0; i < n; i++) {
		if (list[i]) printf("%d ", list[i]);
		else printf("-1 ");
	}

	return 0;
}