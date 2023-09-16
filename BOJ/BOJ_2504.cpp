#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

#define N 33

bool chk = true;
int n, ans;
char s[N];
stack<int> st;

int main(void) {

	scanf("%s", s);

	n = strlen(s);
	for (int i = 0; chk && i < n; i++) {
		if (s[i] == '(') st.push(-2);
		else if (s[i] == '[') st.push(-3);
		else {
			int tmp = 0;
			while (!st.empty() && st.top() > 0) {
				tmp += st.top();
				st.pop();
			}
			if (st.empty()) chk = false;
			else if (s[i] == ')' && st.top() == -2) {
				st.pop();
				if (tmp) st.push(2 * tmp);
				else st.push(2);
			}
			else if (s[i] == ']' && st.top() == -3) {
				st.pop();
				if (tmp) st.push(3 * tmp);
				else st.push(3);
			}
			else chk = false;
		}
	}

	while (chk && !st.empty()) {
		if (st.top() < 0) {
			chk = false;
			break;
		}
		ans += st.top();
		st.pop();
	}

	if (chk) printf("%d", ans);
	else printf("0");

	return 0;
}