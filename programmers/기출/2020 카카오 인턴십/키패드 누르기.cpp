#include <string>
#include <vector>

#define ABS(X) ((X > 0) ? (X) : -(X))
using namespace std;

int dist(int start, int end) {
    return ABS(((start - 1) / 3) - ((end - 1) / 3)) + ABS(((start - 1) % 3) - ((end - 1) % 3));
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int leftHand = 10;
    int rightHand = 12;

    for (int i = 0; i < numbers.size(); i++) {
        int cur = numbers[i];
        if (cur == 0) cur = 11;

        if (cur == 1 || cur == 4 || cur == 7) {
            answer += 'L';
            leftHand = cur;
        }
        else if (cur == 3 || cur == 6 || cur == 9) {
            answer += 'R';
            rightHand = cur;
        }
        else {
            int leftDist = dist(leftHand, cur);
            int rightDist = dist(rightHand, cur);

            if (leftDist == rightDist) {
                if (hand == "left") {
                    answer += 'L';
                    leftHand = cur;
                }
                else {
                    answer += 'R';
                    rightHand = cur;
                }
            }
            else if (leftDist > rightDist) {
                answer += 'R';
                rightHand = cur;
            }
            else {
                answer += 'L';
                leftHand = cur;
            }
        }
    }

    return answer;
}