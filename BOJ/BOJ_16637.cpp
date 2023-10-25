#include <iostream>
#include <deque>
using namespace std;

#define N 20

int n, ans = -1<<30;
char s[N];
deque<int> dq;

int calculate(int a, int o, int b) {
	if (o == '+') return a + b;
	if (o == '-') return a - b;
	if (o == '*') return a * b;
}

void func(int cur, bool chk) {

	if (cur >= n) {
		deque<int> tq = dq;
		int a = tq.front();
		tq.pop_front();
		while (!tq.empty()) {
			int o = tq.front();
			tq.pop_front();
			int b = tq.front();
			tq.pop_front();
			a = calculate(a, o, b);
		}
		if (ans < a) ans = a;
		return;
	}

	int o = s[cur];
	int b = s[cur + 1] - '0';

	if (!chk) {
		int a = dq.back(); 
		dq.pop_back();
		dq.push_back(calculate(a, o, b));
		func(cur + 2, true);
		dq.pop_back();
		dq.push_back(a);
	}
	dq.push_back(o);
	dq.push_back(b);
	func(cur + 2, false);
	dq.pop_back();
	dq.pop_back();
}

int main(void) {

	scanf("%d", &n);
	scanf("%s", s);

	dq.push_back(s[0] - '0');
	func(1, false);

	printf("%d", ans);

	return 0;
}