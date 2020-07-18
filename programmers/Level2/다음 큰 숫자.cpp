#include <string>
#include <vector>

using namespace std;

int oneNum(int param) {
    int one = 0;
    int cur = 0;
    while ((1 << cur) < param) {
        if (param & (1 << cur)) one++;
        cur++;
    }
    return one;
}

int solution(int n) {
    int target = oneNum(n);

    int answer = n + 1;
    while (1) {
        if (oneNum(answer) == target) break;
        answer++;
    }

    return answer;
}