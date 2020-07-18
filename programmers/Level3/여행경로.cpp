#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool end_flag = false;
vector<bool> visit;
vector<string> tempAns;

bool cmp(vector<string> A, vector<string> B) {
    return A[1] < B[1];
}

void DFS(string cur, vector<vector<string>> tickets, vector<string> param) {
    if (param.size() == visit.size()) {
        end_flag = true;
        tempAns = param;
        return;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (visit[i]) continue;

        if (tickets[i][0] == cur) {
            visit[i] = true;
            param.push_back(tickets[i][1]);

            DFS(tickets[i][1], tickets, param);
            if (end_flag) return;

            param.pop_back();
            visit[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    visit.resize(tickets.size() + 1, false);
    sort(tickets.begin(), tickets.end(), cmp);

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == "ICN") {
            DFS("ICN", tickets, { "ICN" });
            if (end_flag) break;
        }
    }

    answer = tempAns;
    return answer;
}