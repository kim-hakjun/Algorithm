#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

bool alpha(char A) {
    return (A >= 'a' && A <= 'z');
}

double jaca(string A, string B) {
    int inter = 0;
    int sum = 0;
    bool visit[1001];
    for (int i = 0; i < B.length(); i++) visit[i] = false;

    for (int i = 0; i < A.length() - 1; i++) {
        if (!alpha(A[i]) || !alpha(A[i + 1])) continue;
        bool flag = false;
        sum++;

        for (int j = 0; j < B.length() - 1; j++) {
            if (!alpha(B[j]) || !alpha(B[j + 1])) continue;

            if (!visit[j] && A.substr(i, 2) == B.substr(j, 2)) {
                inter++;
                visit[j] = true;
                flag = true;
                break;
            }
        }
    }

    for (int i = 0; i < B.length() - 1; i++) {
        if (alpha(B[i]) && alpha(B[i + 1]) && !visit[i]) sum++;
    }

    if (sum + inter == 0) return 1;
    else return (double)inter / sum;
}

int solution(string str1, string str2) {
    int answer = 0;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    cout << jaca(str1, str2);
    answer = jaca(str1, str2) * 65536;
    return answer;
}