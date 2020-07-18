#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    int sum = 0;
    int left = 1;
    for (int right = 1; right <= n; right++) {
        sum += right;
        while (sum >= n) {
            if (sum == n) answer++;
            sum -= left++;
        }
    }

    return answer;
}