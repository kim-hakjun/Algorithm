#include <string>
#include <vector>
#include <cstring>

using namespace std;

int EACH(int num, int p) {
    if (p == 1) return num % 10;
    else if (p == 2) return (num % 100) / 10;
    else return num / 100;
}

int solution(vector<vector<int>> baseball) {
    int answer = 0;

    int num, strike, ball;
    int st, ba;
    bool check[10];
    bool ex_flag = false;

    for (int i = 123; i < 1000; i++) {
        ex_flag = false;
        memset(check, false, sizeof(check));

        for (int t = 1; t <= 3; t++) {
            int cur = EACH(i, t);
            if (cur == 0 || check[cur]) {
                ex_flag = true;
                break;
            }
            check[cur] = true;
        }
        if (ex_flag) continue;

        for (int j = 0; j < baseball.size(); j++) {
            num = baseball[j][0];
            strike = baseball[j][1];
            ball = baseball[j][2];

            st = 0;
            ba = 0;

            for (int k = 1; k <= 3; k++) {
                int cur = EACH(i, k);
                for (int t = 1; t <= 3; t++) {
                    int target = EACH(num, t);

                    if (cur == target && k == t) st++;
                    else if (cur == target && k != t) ba++;
                }
            }

            if (st != strike || ba != ball) {
                break;
            }

            if (j == baseball.size() - 1) answer++;
        }

    }

    return answer;
}
