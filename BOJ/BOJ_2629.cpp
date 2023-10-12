#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define N 40404

int n, m;
bool chk[N];
vector<int> v, l;

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		v.push_back(m);
	}


	for (int i = 0; i < n; i++) {
		int tmp = l.size();
		for (int j = 0; j < tmp; j++) {
			int val = v[i] + l[j];
			if (!chk[val]) {
				chk[val] = true;
				l.push_back(val);
			}
			val = abs(v[i] - l[j]);
			if (!chk[val]) {
				chk[val] = true;
				l.push_back(val);
			}
		}
		if (!chk[v[i]]) {
			chk[v[i]] = true;
			l.push_back(v[i]);
		}
	}

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		if (chk[m]) printf("Y ");
		else printf("N ");
	}

	return 0;
}