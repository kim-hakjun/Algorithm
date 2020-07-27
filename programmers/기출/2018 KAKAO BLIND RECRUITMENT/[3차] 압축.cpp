#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;

    // init
    unordered_map<string, int> m;
    for (int i = 0; i < 26; i++) {
        string cur;
        cur += ('A' + i);
        m[cur] = i + 1;
    }

    int idx = 0;
    int cnt = 27;
    while (idx < msg.length()) {
        int maxLen = 0;
        for (int j = 1; j <= msg.length() - idx; j++) {
            if (m[msg.substr(idx, j)] == 0) break;
            else maxLen++;
        }

        answer.push_back(m[msg.substr(idx, maxLen)]);
        if (idx + maxLen != msg.length()) {
            m[msg.substr(idx, maxLen + 1)] = cnt;
            cnt++;
        }
        idx += maxLen;
    }

    return answer;
}