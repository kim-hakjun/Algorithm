#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_map<string, int> m;
    for (int i = 0; i < gems.size(); i++) {
        m[gems[i]]++;
    }

    int allNum = m.size();
    m.clear();

    int curNum = 0;
    int left = 0;
    for (int right = 0; right < gems.size(); right++) {
        m[gems[right]]++;
        if (m[gems[right]] == 1) {
            curNum++;
        }

        while (left <= right) {
            if (curNum == allNum) {
                if (answer.size() == 0 || (answer[1] - answer[0]) > (right - left)) {
                    answer.clear();
                    answer.push_back(left + 1);
                    answer.push_back(right + 1);
                }

                m[gems[left]]--;
                if (m[gems[left]] == 0) {
                    curNum--;
                }
                left++;
            }
            else
                break;
        }

    }

    return answer;
}