#include <iostream>
#include <string>

using namespace std;

int ans;

void getPi(string p) {
	int len = p.size();
	int* pi = new int[len];

	pi[0] = 0;
	int j = 0;
	for (int i = 1; i < len; i++) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}

		if (p[i] == p[j]) {
			pi[i] = ++j;
			if (j > ans) ans = j;
		}
		else pi[i] = 0;
	}

	delete pi;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	string str;
	cin >> str;

	for (int i = 0, j = str.size(); i < j; i++) {
		getPi(str.substr(i, j));
	}

	cout << ans;
	return 0;
}