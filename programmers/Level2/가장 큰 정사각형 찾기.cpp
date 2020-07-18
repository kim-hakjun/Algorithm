#include<vector>

using namespace std;

int minVal(int a, int b, int c) {
    return a < b ? (a < c ? a : (b < c) ? b : c) : (b < c ? b : (a < c) ? a : c);
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int R = board.size();
    int C = board[0].size();

    vector<vector<int>> dp;
    dp.resize(R, vector<int>(C, 0));

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (board[r][c] == 1) {
                if (r == 0 || c == 0) dp[r][c] = 1;
                else {
                    dp[r][c] = minVal(dp[r - 1][c - 1], dp[r][c - 1], dp[r - 1][c]) + 1;
                }
                if (answer < dp[r][c]) answer = dp[r][c];
            }
        }
    }

    return answer * answer;
}