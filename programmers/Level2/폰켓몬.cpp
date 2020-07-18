#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    unordered_map<int, bool> m;
    for (int i = 0; i < nums.size(); i++) {
        m[nums[i]] = true;
    }

    return m.size() > (nums.size() / 2) ? (nums.size() / 2) : m.size();
}