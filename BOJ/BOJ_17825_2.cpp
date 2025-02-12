#include <iostream>
#include <queue>
using namespace std;

#define INF 21

typedef pair<int, int> P;
typedef struct _info { P p[4]; int val; }_info;
int score[5][22] = { { }, 
	{ 10, 13, 16, 19 }, { 20, 22, 24 }, { 30, 28, 27, 26 }, 
	{ 25, 30, 35 } };

int n, ans;
queue<_info> q;

P getP(P p, int n) {
	int x = p.first, y = p.second;

	if (y == 0 && (x == 5 || x == 10 || x == 15)) {
		y = x / 5; x = 0; 
	}

	x += n;
	if (y == 0 && x > 20) return { INF, INF };
	else if (y == 4) {
		if (x > 3) return { INF, INF };
		else if (x > 2) return { 20, 0 };
	}
	else if (y == 2) {
		if (x > 6) return { INF, INF };
		else if (x == 6) return { 20, 0 };
		else if (x > 2) return { x - 3, 4 };
	}
	else if (y == 1 || y == 3) {
		if (x > 7) return { INF, INF };
		else if (x == 7) return { 20, 0 };
		else if (x > 3) return { x - 4, 4 };
	}
	return { x, y };
}

int main(void) {

	for (int i = 1; i <= 20; i++) score[0][i] = i * 2;

	q.push({ { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } }, 0 });
	for (int i = 0; i < 10; i++) {
		scanf("%d", &n);

		for (int j = q.size(); j; j--) {
			_info cur = q.front();
			q.pop();

			if (ans < cur.val) ans = cur.val;

			for (int k = 0; k < 4; k++) {
				_info next = cur;

				if (next.p[k].first >= INF) continue;

				next.p[k] = getP(next.p[k], n);
				if (next.p[k].first < INF && 
					(cur.p[0] == next.p[k] || cur.p[1] == next.p[k] 
						|| cur.p[2] == next.p[k] || cur.p[3] == next.p[k])) continue;

				next.val += score[next.p[k].second][next.p[k].first];
				q.push(next);
			}
		}
	}

	while (!q.empty()) {
		_info cur = q.front();
		q.pop();

		if (ans < cur.val) ans = cur.val;
			if (ans == 193)
				int t = 3;
	}
	printf("%d", ans);

	return 0;
}