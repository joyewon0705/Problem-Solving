#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

#define N 101

int n;
bool isVisit[N], ans[N];
int nums[N];
vector<int> v;
set<int> s;

bool func(int chk, int cur) {

	if (isVisit[cur]) return false;

	isVisit[cur] = true;
	v.push_back(cur);
	if (cur == chk) return true;
	if (func(chk, nums[cur])) return true;
	return false;
}

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &nums[i]);
	}

	for (int j = 1; j <= n; j++) {
		memset(isVisit, false, sizeof(isVisit));
		v = vector<int>();

		if (func(j, nums[j])) {
			for (int cur : v) {
				if (ans[cur]) continue;
				ans[cur] = true;
				s.insert(cur);
			}
		}
	}

	printf("%d\n", s.size());
	for (int prt : s) {
		printf("%d\n", prt);
	}

	return 0;
}