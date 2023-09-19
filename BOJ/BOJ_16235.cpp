#include <iostream>
#include <deque>
using namespace std;

#define N 11
typedef pair<int, int> P;
typedef pair<int, P> PP;
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int n, m, k, x, y, z;
int A[N][N], M[N][N];
deque<PP> Trees, Trees_alive, Trees_dead;
deque<P> Trees_productive;

int main(void) {

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &A[i][j]);
			M[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		Trees.push_back({ z, { x, y } });
	}

	for (int years = 0; years < k; years++) {
		Trees_alive = deque<PP>();
		Trees_dead = deque<PP>();
		Trees_productive = deque<P>();

		// SPRING
		while (!Trees.empty()) {
			int age = Trees.front().first;
			P pos = Trees.front().second;
			Trees.pop_front();

			if (M[pos.first][pos.second] < age) {
				Trees_dead.push_back({ age, pos });
				continue;
			}
			M[pos.first][pos.second] -= age;
			Trees_alive.push_back({ age + 1, pos });
			if ((age + 1) % 5 == 0) Trees_productive.push_back(pos);
		}

		// SUMMER
		while (!Trees_dead.empty()) {
			int age = Trees_dead.front().first;
			P pos = Trees_dead.front().second;
			Trees_dead.pop_front();

			M[pos.first][pos.second] += age / 2;
		}


		// AUTUMN
		while (!Trees_productive.empty()) {
			int x = Trees_productive.front().first;
			int y = Trees_productive.front().second;
			Trees_productive.pop_front();

			for (int k = 0; k < 8; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < 1 || n < nx || ny < 1 || n < ny) continue;
				Trees_alive.push_front({ 1, { nx, ny } });
			}
		}

		// WINTER
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				M[i][j] += A[i][j];
			}
		}

		Trees = Trees_alive;
	}

	printf("%d", Trees.size());

	return 0;
}