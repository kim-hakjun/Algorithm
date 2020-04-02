#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool valid_test(string p) {
	stack<char> st;

	for (int i = 0; i < p.length(); i++) {
		if (st.empty()) st.push(p[i]);
		else {
			if (p[i] == ')' && st.top() == '(') st.pop();
			else st.push(p[i]);
		}
	}

	if (st.empty()) return true;
	else return false;
}

string solution(string p) {
	string answer = "";
	if (p.empty()) return answer;

	int open = 0;
	int close = 0;
	string u, v;
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(') open++;
		else if (p[i] == ')') close++;

		if (open == close) {
			u = p.substr(0, i + 1);
			v = p.substr(i + 1, p.length() - (i + 1));
			break;
		}
	}

	if (valid_test(u)) {
		u += solution(v);
		answer = u;
	}
	else {
		answer += '(';
		answer += solution(v);
		answer += ')';

		u = u.substr(1, u.length() - 2);
		for (int i = 0; i < u.length(); i++) {
			if (u[i] == '(') u[i] = ')';
			else u[i] = '(';
		}
		answer += u;
	}

	return answer;
}