#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;

    for (int h = 3; h <= sum / 3; h++) {
        int w = sum / h;
        if (sum % h == 0 && h <= w) {
            if (w * 2 + (h - 2) * 2 == brown) {
                answer.push_back(w);
                answer.push_back(h);
            }
        }
    }

    return answer;
}