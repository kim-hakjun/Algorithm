#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool start = true;
    int minVal, maxVal;

    bool minus = false;
    string temp = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-') minus = true;
        else {
            if (s[i] == ' ' || i == s.length() - 1) {
                if (i == s.length() - 1) temp += s[i];

                int val = stoi(temp);
                if (minus) val = -val;
                if (start) {
                    start = false;
                    minVal = val;
                    maxVal = val;
                }
                else {
                    minVal = minVal > val ? val : minVal;
                    maxVal = maxVal < val ? val : maxVal;
                }
                temp.clear();
                minus = false;
            }
            else {
                temp += s[i];
            }
        }
    }

    answer = to_string(minVal) + " " + to_string(maxVal);
    return answer;
}