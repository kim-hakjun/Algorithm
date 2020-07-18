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
        // ���ο� Ʈ���� �ö� �� �ִ���
        while (!flag) {
            // �ٸ��� Ʈ���� �� á�� ���
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

    // �ٸ��� ���� ��� Ʈ���� �ǳʰ� �Ǵ� �ð�
    if (!q.empty()) answer += bridge_length;

    return answer;
}