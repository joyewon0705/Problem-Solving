#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

#define M 55
typedef pair<string, int> P;

int n, m, p;
string dp[M];

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p);
		if (i == 0 || dp[p] == "" || dp[p][0] < i + '0') dp[p] = i + '0';
	}
	scanf("%d", &m);

	for (int i = 2; i <= m; i++) {
		for (int j = 1; j <= i / 2; j++) {
			if (!dp[j].length() && !dp[i - j].length()) continue;

			string tmp = "";
			for (int a = 0, b = 0; a < dp[j].length() || b < dp[i - j].length(); ) {
				if (a >= dp[j].length()) {
					tmp += dp[i - j][b];
					b++;
				}
				else if (b >= dp[i - j].length()) {
					tmp += dp[j][a];
					a++;
				}
				else {
					if (dp[j][a] > dp[i - j][b]) {
						tmp += dp[j][a];
						a++;
					}
					else {
						tmp += dp[i - j][b];
						b++;
					}
				}
			}

			if (dp[i] == "") dp[i] = tmp;
			else if (dp[i][0] == '0' && tmp[0] == '0') {
				if (dp[i].length() < tmp.length()) dp[i] = tmp;
			}
			else if (dp[i][0] != '0' && tmp[0] != '0') {
				if (dp[i].length() < tmp.length()) dp[i] = tmp;
				else if (dp[i].length() == tmp.length() && dp[i] < tmp) dp[i] = tmp;
			}
			else if (dp[i][0] == '0' && tmp[0] != '0') dp[i] = tmp;
		}
	}

	if (dp[m][0] == '0') dp[m] = "0";
	cout << dp[m];

	return 0;
}