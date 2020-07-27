/*
    문제 해설 참고...
    1) 방향성 그래프로 만든다.
    2) 사이클이 존재하는지 판단
*/

#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> edges[200001];
vector<int> direct[200001];
bool check[200001];
bool visit[200001];

bool dfs(int idx) {
    if (check[idx]) return true;

    if (visit[idx]) return false;
    visit[idx] = true;

    for (int i = 0; i < direct[idx].size(); i++) {
        int nextIdx = direct[idx][i];
        if (!dfs(nextIdx)) return false;
    }

    check[idx] = true;
    return true;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;

    for (int i = 0; i < path.size(); i++) {
        edges[path[i][0]].push_back(path[i][1]);
        edges[path[i][1]].push_back(path[i][0]);
    }

    // 방향성 그래프
    queue<int> q;
    q.push(0);
    visit[0] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < edges[cur].size(); i++) {
            int nextIdx = edges[cur][i];

            if (!visit[nextIdx]) {
                q.push(nextIdx);
                visit[nextIdx] = true;
                direct[cur].push_back(nextIdx);
            }
        }
    }
    for (int i = 0; i < order.size(); i++) {
        direct[order[i][0]].push_back(order[i][1]);
    }

    memset(visit, false, sizeof(visit));
    // cycle
    answer = dfs(0);

    return answer;
}