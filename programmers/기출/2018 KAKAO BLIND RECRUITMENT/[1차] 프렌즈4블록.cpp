#include <string>
#include <vector>

using namespace std;

int dx[3] = { 0, 1, 1 };
int dy[3] = { 1, 0, 1 };

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int R = board.size();
    int C = board[0].size();
    vector<pair<int, int> > temp;

    while (1) {
        for (int r = 0; r < R - 1; r++) {
            for (int c = 0; c < C - 1; c++) {
                bool flag = true;
                char cur = board[r][c];
                if (cur == 'X') continue;

                for (int dir = 0; dir < 3; dir++) {
                    if (cur != board[r + dx[dir]][c + dy[dir]]) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    temp.push_back({ r, c });
                }
            }
        }

        // 블록 제거
        if (temp.size() == 0) break;
        for (int i = 0; i < temp.size(); i++) {
            int x = temp[i].first;
            int y = temp[i].second;
            if (board[x][y] != 'X') {
                answer++;
                board[x][y] = 'X';
            }
            for (int dir = 0; dir < 3; dir++) {
                if (board[x + dx[dir]][y + dy[dir]] != 'X') {
                    answer++;
                    board[x + dx[dir]][y + dy[dir]] = 'X';
                }
            }
        }
        temp.clear();

        // 블록 Drop
        for (int c = 0; c < C; c++) {
            for (int r = R - 2; r >= 0; r--) {
                if (board[r][c] == 'X') continue;

                int nR = r;
                while (nR + 1 < R && board[nR + 1][c] == 'X') {
                    nR += 1;
                }
                if (nR != r) {
                    board[nR][c] = board[r][c];
                    board[r][c] = 'X';
                }
            }
        }
    }

    return answer;
}