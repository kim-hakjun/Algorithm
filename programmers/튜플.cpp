#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> saved;
    vector<int> temp;
    string num = "";
    bool open = false;

    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] == '{') open = true;

        if (open) {
            if (s[i] >= '0' && s[i] <= '9') {
                num += s[i];
            }
            else if (s[i] == ',' || s[i] == '}') {
                temp.push_back(stoi(num));
                num.clear();
                if (s[i] == '}') {
                    open = false;
                    saved.push_back(temp);
                    temp.clear();
                }
            }
        }
    }

    sort(saved.begin(), saved.end(), cmp);

    bool check[100001];
    memset(check, false, sizeof(check));

    for (int i = 0; i < saved.size(); i++) {
        for (int j = 0; j < saved[i].size(); j++) {
            if (!check[saved[i][j]]) {
                answer.push_back(saved[i][j]);
                check[saved[i][j]] = true;
            }
        }
    }

    return answer;
}