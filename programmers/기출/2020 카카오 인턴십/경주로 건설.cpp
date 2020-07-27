#include <string>
#include <vector>
#include <queue>

using namespace std;

struct info {
    int r, c, dir, sum;
};

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int temp[26][26];

int solution(vector<vector<int>> board) {
    int answer = 0;

    int rSize = board.size();
    int cSize = board[0].size();

    queue<info> q;
    q.push({ 0, 0, -1, 0 });

    while (!q.empty()) {
        int cR = q.front().r;
        int cC = q.front().c;
        int cDir = q.front().dir;
        int cSum = q.front().sum;
        q.pop();

        if (answer != 0 && answer < cSum) continue;

        if (cR == rSize - 1 && cC == cSize - 1) {
            if (answer == 0) answer = cSum;
            else {
                if (answer > cSum) answer = cSum;
            }
        }

        for (int dir = 0; dir < 4; dir++) {
            int nR = cR + dx[dir];
            int nC = cC + dy[dir];
            int nSum = cSum;

            if (nR < 0 || nC < 0 || nR >= rSize || nC >= cSize) continue;

            if (board[nR][nC] == 0) {
                if ((cR == 0 && cC == 0) || cDir == dir) nSum += 100;
                else nSum += 600;

                if (temp[nR][nC] == 0 || temp[nR][nC] >= nSum) {
                    q.push({ nR, nC, dir, nSum });
                    temp[nR][nC] = nSum;
                }
            }
        }
    }

    return answer;
}