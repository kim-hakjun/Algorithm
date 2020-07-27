#include <string>
#include <vector>

using namespace std;

const int MAX = 200000000;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int low = 0;
    int high = MAX;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        // mid���� �ǳ� �� �ִ� �� �׽�Ʈ
        bool flag = true;
        int jump = 1;
        for (int i = 0; i < stones.size(); i++) {
            if (stones[i] < mid) {
                jump++;
                if (jump > k) {
                    flag = false;
                    break;
                }
            }
            else {
                jump = 1;
            }
        }

        if (flag) {  // ����
            answer = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }

    }

    return answer;
}