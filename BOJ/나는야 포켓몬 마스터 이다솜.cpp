#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

/*
	해시 사용
*/

using namespace std;

int N, M;
string s;
unordered_map<string, int> dict_s;
unordered_map<int, string> dict_n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		dict_s[s] = i + 1;
		dict_n[i + 1] = s;
	}

	while (M--) {
		cin >> s;
		if (s[0] >= '0' && s[0] <= '9') {
			cout << dict_n.find(stoi(s))->second;
		}
		else {
			cout << dict_s.find(s)->second;
		}
		cout << "\n";
	}

	return 0;
}