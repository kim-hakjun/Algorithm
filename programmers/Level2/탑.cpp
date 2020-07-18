#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;

    stack<pair<int, int> > s;

    for (int i = 0; i < heights.size(); i++) {
        if (s.empty()) {
            answer.push_back(0);
            s.push({ i + 1, heights[i] });
        }
        else {
            while (1) {
                if (s.top().second <= heights[i]) {
                    s.pop();
                    if (s.empty()) {
                        answer.push_back(0);
                        s.push({ i + 1, heights[i] });
                        break;
                    }
                }
                else {
                    answer.push_back(s.top().first);
                    s.push({ i + 1, heights[i] });
                    break;
                }
            }
        }
    }

    return answer;
}