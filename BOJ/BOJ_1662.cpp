#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

char S[55];
int ans, cnt;
stack<int> st;

int main(void) {

	scanf("%s", S);

	for (int i = strlen(S) - 1; i > -1; i--) {
		if (S[i] == ')') {
			st.push(cnt);
			cnt = 0;
		}
		else if (S[i] == '(') {
			i--;
			cnt *= S[i] - '0';
			cnt += st.top();
			st.pop();
		}
		else cnt++;
	}

	printf("%d", cnt);

	return 0;
}