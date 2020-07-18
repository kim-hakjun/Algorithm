#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int A, int B) {
    return A > B;
}

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end(), cmp);

    for (int i = 10000; i >= 0; i--) {
        if (i > citations.size()) continue;
        else {
            if (citations[i - 1] >= i) {
                answer = i;
                break;
            }
        }
    }

    return answer;
}