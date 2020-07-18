#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int A, int B) {
    string sA = to_string(A);
    string sB = to_string(B);

    if (sA[0] != sB[0]) {
        return sA > sB;
    }
    else {
        return sA + sB > sB + sA;
    }
}

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), cmp);

    for (int i = 0; i < numbers.size(); i++) {
        answer += to_string(numbers[i]);
    }

    if (answer[0] == '0') answer = "0";

    return answer;
}