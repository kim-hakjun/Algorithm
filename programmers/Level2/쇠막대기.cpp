#include <string>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;

    stack<char> st;

    for (int i = 0; i < arrangement.size(); i++) {
        char cur = arrangement[i];

        if (cur == '(') {
            st.push('(');
        }
        else {
            if (!st.empty() && st.top() == '(') {
                st.pop();
                if (arrangement[i - 1] == '(') {
                    answer += st.size();
                }
                else {
                    answer++;
                }
            }
        }
    }

    return answer;
}