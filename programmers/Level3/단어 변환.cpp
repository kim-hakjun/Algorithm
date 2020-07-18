#include <string>
#include <vector>

using namespace std;

bool visit[51];
int minVal = 51;

void DFS(int cnt, string cur, string target, vector<string> words) {
    if (cur == target) {
        minVal = minVal > cnt ? cnt : minVal;
        return;
    }

    for (int i = 0; i < words.size(); i++) {
        if (visit[i]) continue;

        int diff = 0;
        for (int j = 0; j < words[i].length(); j++) {
            if (cur[j] != words[i][j]) {
                diff++;
                if (diff > 1) break;
            }
        }

        if (diff == 1) {
            visit[i] = true;
            DFS(cnt + 1, words[i], target, words);
            visit[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    DFS(0, begin, target, words);
    if (minVal != 51) answer = minVal;

    return answer;
}