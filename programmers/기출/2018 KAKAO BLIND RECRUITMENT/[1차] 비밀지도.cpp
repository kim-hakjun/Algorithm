#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; i++) {
        int tmp = (arr1[i] | arr2[i]);

        string tmp_str = "";
        for (int j = n - 1; j >= 0; j--) {
            if (tmp & (int)pow(2, j)) {
                tmp_str += '#';
            }
            else
                tmp_str += ' ';
        }

        answer.push_back(tmp_str);
    }

    return answer;
}