#include<iostream>
#include<stack>
#include<string>

using namespace std;

int N;
char inp;
stack<char> st1, st2;
string str;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> str >> N;
	for (int i = 0; i < str.length(); i++) {
		st1.push(str[i]);
	}

	for (int i = 0; i < N; i++) {
		cin >> inp;
		if (inp == 'P') {
			cin >> inp;
			st1.push(inp);
		}
		else if (inp == 'L') {
			if (!st1.empty()) {
				st2.push(st1.top());
				st1.pop();
			}
		}
		else if (inp == 'D') {
			if (!st2.empty()) {
				st1.push(st2.top());
				st2.pop();
			}
		}
		else if (inp == 'B') {
			if (!st1.empty()) {
				st1.pop();
			}
		}
	}

	while (!st1.empty()) {
		st2.push(st1.top());
		st1.pop();
	}

	while (!st2.empty()) {
		cout << st2.top();
		st2.pop();
	}

	return 0;
}