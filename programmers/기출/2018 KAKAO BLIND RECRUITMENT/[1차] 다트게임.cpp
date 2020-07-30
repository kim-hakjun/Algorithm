#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;

    string info;
    int prev, cur;
    bool first = true;

    for (int i = 0; i < dartResult.length(); i++) {
        info += dartResult[i];
        if (dartResult[i] == '1' && dartResult[i + 1] == '0') continue;
        if (i != dartResult.length() - 1 && (dartResult[i + 1] < '0' || dartResult[i + 1] > '9')) continue;

        bool numFlag = false;
        for (int j = 0; j < info.length(); j++) {
            if (numFlag && info[j] == '0') continue;

            if (info[j] >= '0' && info[j] <= '9') {
                if (info[j] == '1' && info[j + 1] == '0') {
                    cur = 10;
                }
                else {
                    cur = info[j] - '0';
                }
                numFlag = true;
            }

            if (info[j] == 'D') {
                cur *= cur;
            }
            else if (info[j] == 'T') {
                cur *= (cur * cur);
            }
            else if (info[j] == '*') {
                cur *= 2;
                if (!first) {
                    prev *= 2;
                }
            }
            else if (info[j] == '#') {
                cur *= (-1);
            }
        }

        if (first) {
            prev = cur;
            first = false;
        }
        else {
            answer += prev;
            prev = cur;
        }

        info.clear();
    }

    answer += cur;

    return answer;
}