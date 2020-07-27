#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    int N = board.size();
    vector<int> basket;

    for (int i = 0; i < moves.size(); i++) {
        int cur = moves[i] - 1;

        for (int row = 0; row < N; row++) {
            if (board[row][cur] != 0) {
                if (!basket.empty() && basket.back() == board[row][cur]) {
                    basket.pop_back();
                    answer += 2;
                }
                else {
                    basket.push_back(board[row][cur]);
                }
                board[row][cur] = 0;
                break;
            }
        }

    }

    return answer;
}