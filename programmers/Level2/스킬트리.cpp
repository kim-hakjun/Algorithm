#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    int priorArr[26] = { 0, };

    priorArr[skill[0] - 'A'] = -1;
    for (int i = 1; i < skill.size(); i++) {
        priorArr[skill[i] - 'A'] = (skill[i - 1] - 'A') + 1;
    }

    for (int n = 0; n < skill_trees.size(); n++) {
        string temp = skill_trees[n];
        bool flag = true;
        int priorVal = -1;

        for (int i = 0; i < temp.size(); i++) {
            int curIdx = temp[i] - 'A';
            if (priorArr[curIdx] == 0) continue;
            else {
                if (priorArr[curIdx] == priorVal) {
                    priorVal = curIdx + 1;
                }
                else {
                    flag = false;
                    break;
                }
            }
        }

        if (flag) answer++;
    }

    return answer;
}