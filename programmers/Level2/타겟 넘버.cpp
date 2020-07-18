#include <string>
#include <vector>

using namespace std;

int dfs(vector<int> A, int T, int cur, int sum) {
    if (cur == A.size()) {
        if (sum == T) return 1;
        else return 0;
    }
    int ret = 0;
    ret += dfs(A, T, cur + 1, sum + A[cur]);
    ret += dfs(A, T, cur + 1, sum - A[cur]);

    return ret;
}

int solution(vector<int> numbers, int target) {
    int answer = dfs(numbers, target, 0, 0);
    return answer;
}