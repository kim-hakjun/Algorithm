#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> ans;

bool check(int combi, vector<vector<string>> relation) {
    unordered_map<string, bool> m;
    int R = relation.size();
    int C = relation[0].size();

    for (int r = 0; r < R; r++) {
        string cur = "";

        for (int c = 0; c < C; c++) {
            if (combi & (1 << c)) {
                cur += relation[r][c];
            }
        }
        if (m[cur] == true) return false;
        else m[cur] = true;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;

    int C = relation[0].size();
    for (int i = 1; i < (1 << C); i++) {
        if (check(i, relation)) {
            bool flag = true;
            for (int j = 0; j < ans.size(); j++) {
                if ((i & ans[j]) == ans[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans.push_back(i);
            }
        }
    }

    answer = ans.size();
    return answer;
}