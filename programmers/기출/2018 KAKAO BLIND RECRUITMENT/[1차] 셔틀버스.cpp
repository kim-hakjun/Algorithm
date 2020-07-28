#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string makeTime(int h, int m) {
    string temp;
    if (h < 10) {
        temp = "0";
    }
    temp += (to_string(h) + ":");

    if (m < 10) {
        temp += "0";
    }
    temp += to_string(m);

    return temp;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    sort(timetable.begin(), timetable.end());

    int hour = 9;
    int min = 0;

    int order = 0;
    for (int i = 0; i < n; i++) {
        string time = makeTime(hour, min);
        int maxCnt = m;

        while (order < timetable.size()) {
            if (time < timetable[order]) break;

            maxCnt--;
            order++;
            if (maxCnt == 0) {
                break;
            }
        }

        if (i == n - 1) {
            if (maxCnt == 0) {
                hour = stoi(timetable[order - 1].substr(0, 2));
                min = stoi(timetable[order - 1].substr(3, 2)) - 1;
                if (min < 0) {
                    hour -= 1;
                    min += 60;
                }
            }
            answer = makeTime(hour, min);
        }
        else {
            min += t;
            if (min >= 60) {
                hour += 1;
                min -= 60;
            }
        }
    }

    return answer;
}