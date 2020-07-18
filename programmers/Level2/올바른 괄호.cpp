#include<string>
#include<stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        char cur = s[i];

        if (cur == '(') st.push(cur);
        else {
            if (st.empty() || st.top() == ')') {
                answer = false;
                break;
            }
            else {
                st.pop();
            }
        }
    }

    if (answer && !st.empty()) {
        answer = false;
    }

    return answer;
}