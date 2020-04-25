#include <iostream>
#include <string>
#include <list>

// list STL È°¿ë

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	char inp;
	int N;
	cin >> str >> N;

	list<char> li;
	for (char c : str) {
		li.push_back(c);
	}
	list<char>::iterator cur = li.end();

	for (int i = 0; i < N; i++) {
		cin >> inp;

		if (inp == 'P') {
			cin >> inp;
			li.insert(cur, inp);
		}
		else if (inp == 'L') {
			if (cur != li.begin()) cur--;
		}
		else if (inp == 'D') {
			if (cur != li.end()) cur++;
		}
		else if (inp == 'B') {
			if (cur != li.begin()) {
				cur = li.erase(--cur);
			}
		}
	}

	for (auto i = li.begin(); i != li.end(); i++) {
		cout << *i;
	}
	return 0;
}