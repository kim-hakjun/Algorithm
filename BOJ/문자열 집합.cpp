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
	Trie* next[26];
	Trie() :finish(false) {
		memset(next, 0, sizeof(next));
	}

	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i]) delete next[i];
	}

	void insert(const char* key) {
		if (*key == '\0') {
			finish = true;
		}
		else {
			int cur = *key - 'a';
			if (next[cur] == NULL) {
				next[cur] = new Trie();
			}
			next[cur]->insert(key + 1);
		}
	}

	bool find(const char* key) {
		if (finish && *key == '\0') return true;

		int cur = *key - 'a';
		if (next[cur] == NULL) return false;
		else return next[cur]->find(key + 1);
	}

};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int ans = 0;
	int N, M;
	string str;
	Trie* root = new Trie();

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		root->insert(&str[0]);
	}

	for (int i = 0; i < M; i++) {
		cin >> str;
		if (root->find(&str[0])) ans++;
	}

	cout << ans;
	return 0;
}