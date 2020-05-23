#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
	binary search »ç¿ë
*/

using namespace std;

int N, M;
vector<pair<string, int> > dict_s;
string dict_n[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> dict_n[i];
		dict_s.push_back({ dict_n[i], i});
	}

	sort(dict_s.begin(), dict_s.end());

	string inp;
	while (M--) {
		cin >> inp;
		if (inp[0] >= '0' && inp[0] <= '9') {
			cout << dict_n[stoi(inp)];
		}
		else {
			int left = 0;
			int right = N - 1;

			while (left <= right) {
				int mid = (left + right) / 2;

				if (dict_s[mid].first == inp) {
					cout << dict_s[mid].second;
					break;
				}
				else if (dict_s[mid].first > inp)
					right = mid - 1;
				else
					left = mid + 1;
			}
		}
		cout << "\n";
	}

	return 0;
}