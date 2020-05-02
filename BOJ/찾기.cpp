#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> ans;

vector<int> getPi(string p) {
	int pLen = p.size();
	int j = 0;

	vector<int> temp(pLen, 0);

	for (int i = 1; i < pLen; i++) {

		while (j > 0 && p[i] != p[j]) {
			j = temp[j - 1];
		}

		if (p[i] == p[j]) {
			temp[i] = ++j;
		}
	}

	return temp;
}

void KMP(string s, string p) {
	int sLen = s.size();
	int pLen = p.size();

	vector<int> pi = getPi(p);

	int j = 0;
	for (int i = 0; i < sLen; i++) {

		while (j > 0 && s[i] != p[j]) {
			j = pi[j - 1];
		}

		if (s[i] == p[j]) {
			if (j == pLen - 1) {
				ans.push_back(i - j + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s, p;
	getline(cin, s);
	getline(cin, p);

	KMP(s, p);

	cout << ans.size() << "\n";
	for (int i = 0, j = ans.size(); i < j; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}