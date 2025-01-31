#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 11

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int n, m, k, x, y, z, ans;
int map[N][N], a[N][N];
vector<int> trees[N][N];

int main(void) {

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			map[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		trees[x][y].push_back(z);
		sort(trees[x][y].rbegin(), trees[x][y].rend());
	}

	while (k--) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int val = 0;
				vector<int> v = {};
				for (int tree : trees[i][j]) {
					if (map[i][j] >= tree) {
						map[i][j] -= tree;
						v.push_back(tree + 1);
					}
					else val += tree / 2;
				}
				trees[i][j] = v;
				map[i][j] += val;
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int tree : trees[i][j]) {
					if (tree % 5) continue;
					for (int k = 0; k < 8; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];

						if (nx < 1 || n < nx || ny < 1 || n < ny) continue;
						trees[nx][ny].insert(trees[nx][ny].begin(), 1);
					}
				}
				map[i][j] += a[i][j];
			}
		}
	}

	ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += trees[i][j].size();
		}
	}
	printf("%d", ans);

	return 0;
}