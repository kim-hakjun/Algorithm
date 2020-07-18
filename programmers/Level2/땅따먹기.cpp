#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int R = land.size();
    int C = land[0].size();
    vector<vector<int> > dp(R, vector<int>(C, 0));

    for (int i = 0; i < C; i++) {
        dp[0][i] = land[0][i];
    }

    for (int i = 1; i < R; i++) {
        for (int j = 0; j < C; j++) {
            for (int k = 0; k < C; k++) {
                if (j != k) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + land[i][j]);
                }
            }
            if (i == R - 1) answer = max(answer, dp[i][j]);
        }
    }
    return answer;
}