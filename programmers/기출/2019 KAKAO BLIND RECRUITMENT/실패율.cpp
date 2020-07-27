#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct INFO {
    double rate;
    int cur;
};

bool cmp(INFO A, INFO B) {
    if (A.rate == B.rate) {
        return A.cur < B.cur;
    }
    else return A.rate > B.rate;
}

int state[502];

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    for (int i = 0; i < stages.size(); i++) {
        state[stages[i]]++;
    }

    vector<INFO> rates;
    for (int i = 1; i <= N; i++) {
        int allNum = 0;
        for (int j = i; j <= N + 1; j++) {
            allNum += state[j];
        }
        if (allNum == 0) allNum = 1;

        rates.push_back({ (double)state[i] / allNum, i });
    }

    sort(rates.begin(), rates.end(), cmp);

    for (int i = 0; i < N; i++) {
        answer.push_back(rates[i].cur);
    }

    return answer;
}