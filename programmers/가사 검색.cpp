#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct Trie {

    int cnt = 0;
    Trie* next[26];

    Trie() {
        memset(next, 0, sizeof(next));
    }

    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (next[i]) delete next[i];
        }
    }

    // ���ڿ� ����
    void insert(const char* key) {
        cnt++;
        if (*key == '\0') return;

        int cur = *key - 'a';
        if (next[cur] == NULL) {
            next[cur] = new Trie();
        }
        next[cur]->insert(key + 1);
    }

    // ?���̻� ������ ���ڿ� ����
    int exist_back(const char* query) {
        if (*query == '?') return cnt;

        // query�� ���� ��� ó��
        int cur = *query - 'a';
        if (next[cur] == NULL) return 0;
        else return next[cur]->exist_back(query + 1);
    }

    // ?���λ� ������ ���ڿ� ����
    int exist_front(const char* query) {
        if (*query == '?') {
            return cnt;
        }

        // query�� ���� ��� ó��
        int cur = *query - 'a';
        if (next[cur] == NULL) return 0;
        else return next[cur]->exist_front(query + 1);
    }
};

Trie tries_back[10001];  // ���̻簡 ???�� ����� Ʈ���� + �ܾ��� ���̴� 10000 ����
Trie tries_front[10001]; // ���λ簡 ???�� ����� Ʈ���� + �ܾ��� ���̴� 10000 ����

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

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
            answer.push_back(tries_front[len].exist_front(&queries[i][0]));
        }
        else {
            answer.push_back(tries_back[len].exist_back(&queries[i][0]));
        }
    }

    return answer;
}