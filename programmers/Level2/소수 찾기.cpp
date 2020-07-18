#include <string>
#include <vector>
#include <set>

using namespace std;

const int INF = 1e7;

bool notPrime[INF];
bool visit[7];
set<int> s;

int dfs(string total, string cur) {
    int sum = 0;
    for (int i = 0; i < total.length(); i++) {
        if (!visit[i]) {
            visit[i] = true;

            string temp = cur + total[i];
            if (temp.length() != 0) {
                int val = stoi(temp);
                if (s.find(val) == s.end()) {
                    s.insert(val);
                    if (!notPrime[val]) sum++;
                }
            }

            sum += dfs(total, temp);
            visit[i] = false;
        }
    }

    return sum;
}

int solution(string numbers) {
    int answer = 0;

    notPrime[0] = true; notPrime[1] = true;
    for (int i = 2; i <= INF; i++) {
        if (notPrime[i] == true) continue;

        for (int j = i + i; j <= INF; j = j + i) {
            notPrime[j] = true;
        }
    }

    for (int i = 0; i < 7; i++) visit[i] = false;

    answer = dfs(numbers, "");
    return answer;
}