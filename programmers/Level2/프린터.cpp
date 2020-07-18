#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    priority_queue<int, vector<int>, less<int> > pq;
    queue<pair<int, int> > q;

    for (int i = 0; i < priorities.size(); i++) {
        q.push({ i, priorities[i] });
        pq.push(priorities[i]);
    }

    bool flag = false;
    while (!pq.empty()) {
        int pqP = pq.top();
        pq.pop();

        while (!q.empty()) {
            int qI = q.front().first;
            int qP = q.front().second;
            q.pop();

            if (pqP == qP) {
                answer++;
                if (location == qI) {
                    flag = true;
                }
                break;
            }
            else {
                q.push({ qI, qP });
            }
        }
        if (flag) break;
    }

    return answer;
}