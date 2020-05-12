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

        // mid명이 건널 수 있는 지 테스트
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

        if (flag) {  // 가능
            answer = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }

    }

    return answer;
}