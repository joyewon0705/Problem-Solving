#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s, t;

int main(void) {

	cin >> s;
	cin >> t;

	while (s.size() < t.size()) {

		if (t[t.size() - 1] == 'A') {
			t.pop_back();
		}
		else if (t[t.size() - 1] == 'B') {
			t.pop_back();
			reverse(t.begin(), t.end());
		}
		else break;
	}

	if (s == t) cout << "1" << endl;
	else cout << "0" << endl;

	return 0;
}