#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct Trie {

	int cnt = 0;
	Trie* next[26];

	Trie() {
		memset(next, NULL, sizeof(next));
	}

	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (next[i]) delete next[i];
		}
	}

	// 문자열 넣음
	void insert(const char* key) {
		cnt++;
		if (*key == '\0') return;

		int cur = *key - 'a';
		if (next[cur] == NULL) {
			next[cur] = new Trie();
		}
		next[cur]->insert(key + 1);
	}

	// ?접미사 포함한 문자열 개수
	int exist_back(const char* query) {
		if (*query == '?') return cnt;

		// query가 없는 경우 처리
		int cur = *query - 'a';
		if (next[cur] == NULL) return 0;
		else return next[cur]->exist_back(query + 1);
	}

	// ?접두사 포함한 문자열 개수
	int exist_front(const char* query) {
		if (*query == '?') return cnt;

		// query가 없는 경우 처리
		int cur = *query - 'a';
		if (next[cur] == NULL) return 0;
		else return next[cur]->exist_front(query + 1);
	}
};

Trie tries_back[10001];	 // 접미사가 ???인 경우의 트라이 + 단어의 길이는 10000 이하
Trie tries_front[10001]; // 접두사가 ???인 경우의 트라이 + 단어의 길이는 10000 이하

vector<string> words;
vector<string> queries;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	// 입출력 예제
	words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
	queries = { "fro??", "????o", "fr???", "fro???", "pro?" };

	for (int i = 0; i < words.size(); i++) {
		int len = words[i].length();

		tries_back[len].insert(&words[i][0]);
		
		reverse(words[i].begin(), words[i].end());
		tries_front[len].insert(&words[i][0]);
	}

	for (int i = 0; i < queries.size(); i++) {
		int len = queries[i].length();
		if (queries[i][0] == '?') {
			reverse(queries[i].begin(), queries[i].end());
			cout << tries_front[len].exist_front(&queries[i][0]) << " ";
		}
		else {
			cout << tries_back[len].exist_back(&queries[i][0]) << " ";
		}
	}

	return 0;
}