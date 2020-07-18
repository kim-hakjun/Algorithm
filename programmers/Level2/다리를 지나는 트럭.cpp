#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> q;
    int sum = 0;

    for (int i = 0; i < truck_weights.size(); i++) {
        int cur = truck_weights[i];

        bool flag = false;
        // 새로운 트럭이 올라갈 수 있는지
        while (!flag) {
            // 다리에 트럭이 꽉 찼을 경우
            if (q.size() == bridge_length) {
                sum -= q.front();
                q.pop();
            }

            if (sum + cur <= weight) {
                q.push(cur);
                sum += cur;
                flag = true;
            }
            else
                q.push(0);

            answer++;
        }
    }

    // 다리에 남은 모든 트럭이 건너게 되는 시간
    if (!q.empty()) answer += bridge_length;

    return answer;
}