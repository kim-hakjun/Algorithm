#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int temp_max = 0;
    for (int i = 0; i < progresses.size(); i++) {
        int temp = 100 - progresses[i];

        if (temp % speeds[i] == 0) progresses[i] = temp / speeds[i];
        else progresses[i] = (temp / speeds[i]) + 1;

        if (temp_max < progresses[i]) {
            temp_max = progresses[i];
            answer.push_back(1);
        }
        else {
            answer[answer.size() - 1] += 1;
        }
    }

    return answer;
}