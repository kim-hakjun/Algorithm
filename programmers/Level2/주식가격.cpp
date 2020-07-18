#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    answer.resize(prices.size());

    stack<pair<int, int> > st;

    for (int i = 0; i < prices.size(); i++) {
        if (st.empty() || i == prices.size() - 1) {
            st.push({ i, prices[i] });
        }
        else {
            while (1) {
                if (st.empty() || st.top().second <= prices[i]) {
                    st.push({ i, prices[i] });
                    break;
                }
                else {
                    answer[st.top().first] = i - st.top().first;
                    st.pop();
                }
            }
        }
    }

    while (!st.empty()) {
        answer[st.top().first] = prices.size() - 1 - st.top().first;
        st.pop();
    }

    return answer;
}