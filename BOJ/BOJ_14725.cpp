#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct trie {
	map<string, trie*> m;

	void insert(vector<string> v, int idx) {
		
		if (idx == v.size()) return;
		
		if (m.find(v[idx]) == m.end()) {
			trie* next = new trie;
			m.insert({ v[idx], next });
		}
		m[v[idx]]->insert(v, idx + 1);
	}

	void dfs(int depth) {
		for (auto next : m) {
			for (int i = 0; i < depth; i++) printf("--");
			printf("%s\n", next.first.c_str());
			next.second->dfs(depth + 1);
			delete next.second;
		}
	}
};

int n, k;
string str;
trie *root = new trie;

int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		
		vector<string> v;
		for (int j = 0; j < k; j++) {
			cin >> str;
			v.push_back(str);
		}
		root->insert(v, 0);
	}

	root->dfs(0);
	delete root;

	return 0;
}