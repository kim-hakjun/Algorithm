#include <string>
#include <vector>

using namespace std;

vector<int> adj[201];
bool visit[201];

void DFS(int cur) {
    for (int i = 0; i < adj[cur].size(); i++) {
        if (!visit[adj[cur][i]]) {
            visit[adj[cur][i]] = true;
            DFS(adj[cur][i]);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (computers[i][j] == 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            DFS(i);
            answer++;
        }
    }

    return answer;
}