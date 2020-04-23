#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

typedef struct info {
    int r, c;
    string str;
}INFO;

int T, N, M;
char map[2001][2001];
bool visit[2001][2001];

int dx[2] = { 0,1 };
int dy[2] = { 1,0 };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        string answer;
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> map[i][j];
            }
        }

        queue<INFO> q;
        answer = map[0][0];
        q.push({ 0,0, answer });

        while (!q.empty()) {
            int qs = q.size();
            for (int i = 0; i < qs; i++) {
                int cR = q.front().r;
                int cC = q.front().c;
                string cur = q.front().str;
                q.pop();

                if (answer < cur) continue;

                if (cR == N - 1 && cC == M - 1) {
                    break;
                }

                vector<INFO> temp;
                for (int dir = 0; dir < 2; dir++) {
                    int nR = cR + dx[dir];
                    int nC = cC + dy[dir];

                    if (nR < 0 || nC < 0 || nR >= N || nC >= M || visit[nR][nC]) continue;
                    visit[nR][nC] = true;
                    temp.push_back({ nR, nC, cur + map[nR][nC] });
                }

                if (temp.size() == 1) {
                    answer = temp[0].str;
                    q.push(temp[0]);
                }
                else if (temp.size() == 2) {
                    if (temp[0].str.back() == temp[1].str.back()) {
                        answer = temp[0].str;

                        q.push(temp[0]);
                        if (temp[0].r != temp[1].r || temp[0].c != temp[1].c) {
                            q.push(temp[1]);
                        }
                    }
                    else {
                        int minVal = 0;
                        if (temp[0].str.back() > temp[1].str.back()) {
                            minVal = 1;
                        }
                        q.push(temp[minVal]);
                        answer = temp[minVal].str;
                    }
                }
            }
        }
        cout << "#" << t << " " << answer << "\n";
        memset(visit, false, sizeof(visit));
    }
    return 0;
}