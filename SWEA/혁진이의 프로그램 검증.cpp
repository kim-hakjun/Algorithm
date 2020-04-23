#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef struct info {
    int r, c, dir, memo;
}INFO;

int T, R, C;
char map[21][21];
bool visit[21][21][4][16];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> R >> C;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> map[i][j];
            }
        }

        int memo = 0;
        queue<INFO> q;
        q.push({ 0, 0, 0, memo });
        visit[0][0][0][memo] = true;

        bool end_flag = false;
        while (!q.empty()) {

            int cR = q.front().r;
            int cC = q.front().c;
            int nD = q.front().dir;
            int nM = q.front().memo;
            q.pop();

            if (map[cR][cC] == '@') {
                end_flag = true;
                break;
            }

            int nR, nC;
            char cur = map[cR][cC];
            if ('0' <= cur && cur <= '9') nM = cur - '0';
            else if (cur == '<') nD = 2;
            else if (cur == '>') nD = 0;
            else if (cur == '^') nD = 1;
            else if (cur == 'v') nD = 3;
            else if (cur == '_') {
                if (nM == 0) nD = 0;
                else nD = 2;
            }
            else if (cur == '|') {
                if (nM == 0) nD = 3;
                else nD = 1;
            }
            else if (cur == '+') {
                nM = (nM + 1) % 16;
            }
            else if (cur == '-') {
                nM -= 1;
                if (nM == -1) nM = 15;
            }
            else if (cur == '?') {
                for (int dir = 0; dir < 4; dir++) {
                    nR = cR + dx[dir];
                    nC = cC + dy[dir];

                    if (nR < 0) nR = R - 1;
                    else if (nR >= R) nR = 0;
                    else if (nC < 0) nC = C - 1;
                    else if (nC >= C) nC = 0;

                    if (!visit[nR][nC][dir][nM]) {
                        q.push({ nR, nC, dir, nM });
                        visit[nR][nC][dir][nM] = true;
                    }
                }
            }

            if (cur != '?') {
                nR = cR + dx[nD];
                nC = cC + dy[nD];
                if (nR < 0) nR = R - 1;
                else if (nR >= R) nR = 0;
                else if (nC < 0) nC = C - 1;
                else if (nC >= C) nC = 0;

                if (!visit[nR][nC][nD][nM]) {
                    q.push({ nR, nC, nD, nM });
                    visit[nR][nC][nD][nM] = true;
                }
            }
        }

        cout << "#" << t << " ";
        if (end_flag) cout << "YES\n";
        else cout << "NO\n";
        memset(visit, false, sizeof(visit));
    }

    return 0;
}