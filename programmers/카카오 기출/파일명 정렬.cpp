#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct INFO {
    string HEAD;
    string NUMBER;
    string TAIL;
};

bool cmp(INFO A, INFO B) {
    transform((A.HEAD).begin(), (A.HEAD).end(), (A.HEAD).begin(), ::tolower);
    transform((B.HEAD).begin(), (B.HEAD).end(), (B.HEAD).begin(), ::tolower);

    if (A.HEAD != B.HEAD) return A.HEAD < B.HEAD;
    else {
        int nA = stoi(A.NUMBER);
        int nB = stoi(B.NUMBER);
        return nA < nB;
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;

    vector<INFO> fileSet;
    for (int i = 0; i < files.size(); i++) {
        string h, n, t;
        int type = 0;
        for (int j = 0; j < files[i].length(); j++) {
            char cur = files[i][j];

            if (type == 0) {
                if (cur >= '0' && cur <= '9') {
                    type = 1;
                    n += cur;
                }
                else {
                    h += cur;
                }
            }
            else if (type == 1) {
                if (cur < '0' || cur > '9' || n.length() == 5) {
                    type = 2;
                    t += cur;
                }
                else {
                    n += cur;
                }
            }
            else t += cur;
        }
        fileSet.push_back({ h, n, t });
    }

    stable_sort(fileSet.begin(), fileSet.end(), cmp);   // Æ²·È´ø ÀÌÀ¯(sort -> stable_sort)
    for (int i = 0; i < fileSet.size(); i++) {
        answer.push_back(fileSet[i].HEAD + fileSet[i].NUMBER + fileSet[i].TAIL);
    }

    return answer;
}