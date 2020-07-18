#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }

    while (pq.top() < K) {
        if (pq.size() < 2) {
            answer = -1;
            break;
        }

        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        pq.push(x + y * 2);
        answer++;
    }

    return answer;
}