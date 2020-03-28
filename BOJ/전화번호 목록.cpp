#define _CRT_SECURE_NO_WARNINGS
/*
	Trie example
*/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct Trie {
	bool finish;
	Trie* next[10];

	Trie():finish(false) {
		memset(next, 0, sizeof(next));
	}

	~Trie() {
		for (int i = 0; i < 10; i++) {
			if (next[i]) delete next[i];
		}
	}

	void insert(const char* key) {
		if (*key == '\0') {
			finish = true;
		}
		else {
			int cur = *key - '0';
			if (next[cur] == NULL) {
				next[cur] = new Trie();
			}
			next[cur]->insert(key + 1);
		}
	}

	Trie* find(const char* key) {
		if (*key == '\0') return this;
		int cur = *key - '0';
		if (next[cur] == NULL) return NULL;
		else return next[cur]->find(key + 1);
	}

	bool exist(const char* key) {
		if (*key == '\0') return false;

		if (finish) return true;

		int cur = *key - '0';
		return next[cur]->exist(key + 1);
	}
};

int T, N;
string str_set[10001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--) {
		Trie* root = new Trie;

		bool flag = false;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> str_set[i];
			root->insert(&str_set[i][0]);
		}
		for (int i = 0; i < N; i++) {
			if (root->exist(&str_set[i][0])) {
				flag = true;
				break;
			}
		}

		if (flag) cout << "NO\n";
		else cout << "YES\n";

		delete root;
	}

	return 0;
}