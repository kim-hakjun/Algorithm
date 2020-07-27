#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> m;

    string state, id, nick;
    int type = 0;
    for (int i = 0; i < record.size(); i++) {
        for (int j = 0; j < record[i].size(); j++) {
            char cur = record[i][j];
            if (cur != ' ') {
                if (type == 0) state += cur;
                else if (type == 1) id += cur;
                else nick += cur;
            }
            else {
                type++;
            }
        }

        if (state == "Enter" || state == "Change") {
            m[id] = nick;
        }
        if (state != "Change") {
            answer.push_back(state + " " + id);
        }
        state.clear(); id.clear(); nick.clear();
        type = 0;
    }

    for (int i = 0; i < answer.size(); i++) {
        if (answer[i].substr(0, 5) == "Enter") {
            answer[i] = m[answer[i].substr(6, answer[i].length())] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
        }
        else {
            answer[i] = m[answer[i].substr(6, answer[i].length())] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
        }
    }

    return answer;
}