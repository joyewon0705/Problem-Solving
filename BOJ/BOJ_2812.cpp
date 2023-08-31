#include <iostream>
#include <deque>
using namespace std;

char ch;
int n, k;
deque<char> dq;

int main(void) {

	scanf("%d %d\n", &n, &k);
	scanf("%c", &ch);
	dq.push_back(ch);
	for (int i = 1; i < n; i++) {
		scanf("%c", &ch);
		while (k && !dq.empty() && dq.back() < ch) {
			dq.pop_back();
			k--;
		}
		dq.push_back(ch);
	}
	while (k) {
		dq.pop_back();
		k--;
	}
	while (!dq.empty()) {
		printf("%c", dq.front());
		dq.pop_front();
	}

	return 0;
}