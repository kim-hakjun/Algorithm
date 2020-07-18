#include <string>
#include <vector>
#include <cmath>

using namespace std;

string trans(int num, int n) {
    int temp = n;
    int len = 1;
    while (temp <= num) {
        temp *= n;
        len++;
    }

    string ret;
    for (; len > 0; len--) {
        int val = num / (int)pow(n, (len - 1));
        if (val < 10) ret += to_string(val);
        else {
            ret += 'A' + (val - 10);
        }
        num %= (int)pow(n, (len - 1));
    }

    return ret;
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    int num = 0;
    int cnt = 0;

    while (answer.length() < t) {
        string cur = trans(num, n);
        for (int i = 0; i < cur.length(); i++) {
            cnt++;
            if (m == p) {
                if (cnt % m == 0) answer += cur[i];
            }
            else {
                if (cnt % m == p) answer += cur[i];
            }
            if (answer.length() == t) break;
        }
        num++;
    }

    return answer;
}