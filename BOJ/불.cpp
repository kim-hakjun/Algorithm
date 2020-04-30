#include <iostream>
#include <queue>
#include <string>
using namespace std;

int T, W, H;
char map[1001][1001];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
queue<pair<int, int> > q;
queue<pair<int, int> > fQ;

void bfs(int row, int col) {
    int cnt = 0;
    q.push({ row, col });

    while (!q.empty()) {
        // ºÒ
        int qsize = fQ.size();
        for (int i = 0; i < qsize; i++) {
            int tempR = fQ.front().first;
            int tempC = fQ.front().second;
            fQ.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nextR = tempR + dx[dir];
                int nextC = tempC + dy[dir];

                if (nextR < 0 || nextC < 0 || nextR >= H || nextC >= W) continue;

                if (map[nextR][nextC] == '.') {
                    fQ.push({ nextR, nextC });
                    map[nextR][nextC] = '*';
                }
            }
        }
        // »ç¶÷
        qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            int tempR = q.front().first;
            int tempC = q.front().second;
            q.pop();

            if (tempR == 0 || tempR == H - 1 || tempC == 0 || tempC == W - 1) {
                cout << cnt + 1 << "\n";
                return;
            }

            for (int dir = 0; dir < 4; dir++) {
                int nextR = tempR + dx[dir];
                int nextC = tempC + dy[dir];

                if (nextR < 0 || nextC < 0 || nextR >= H || nextC >= W) continue;

                if (map[nextR][nextC] == '.') {
                    q.push({ nextR, nextC });
                    map[nextR][nextC] = '@';
                }
            }
        }
        cnt++;
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> T;
    string str;
    while (T--) {
        int startR, startC;
        cin >> W >> H;
        for (int i = 0; i < H; i++) {
            cin >> str;
            for (int j = 0; j < W; j++) {
                map[i][j] = str[j];
                if (map[i][j] == '@') {
                    startR = i;
                    startC = j;
                }
                else if (map[i][j] == '*')
                    fQ.push({ i,j });
            }
        }
        bfs(startR, startC);
        while (!q.empty()) q.pop();
        while (!fQ.empty()) fQ.pop();
    }
    return 0;
}