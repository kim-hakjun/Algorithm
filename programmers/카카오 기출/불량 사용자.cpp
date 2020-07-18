#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> s;

void dfs(vector<string> u, vector<string> b, int bits, int depth) {
    if (depth == b.size()) {
        s.insert(bits);
        return;
    }

    for (int i = 0; i < u.size(); i++) {
        if (bits & (1 << i) || b[depth].size() != u[i].size()) continue;
        bool flag = true;

        for (int j = 0; j < u[i].size(); j++) {
            if (b[depth][j] == '*') continue;
            if (u[i][j] != b[depth][j]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            dfs(u, b, bits | (1 << i), depth + 1);
        }
    }

}

int solution(vector<string> user_id, vector<string> banned_id) {
    dfs(user_id, banned_id, 0, 0);

    return s.size();
}