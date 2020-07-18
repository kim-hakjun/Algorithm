#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;

    priority_queue<int> pq;

    int last = 0;
    while (stock < k) {
        for (int i = last; i < dates.size(); i++) {
            if (stock >= dates[i]) {
                pq.push(supplies[i]);
                last = i + 1;
            }
            else
                break;
        }

        stock += pq.top();
        pq.pop();
        answer++;
    }

    return answer;
}