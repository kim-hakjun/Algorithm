#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	if (s.length() == 1) return 1;

	int answer = 1000;
	string res = "";

	string cur;
	int idx, cnt;

	for (int cut = 1; cut <= (s.length() / 2); cut++) {

		cur = s.substr(0, cut);
		idx = cut;
		cnt = 1;

		while (1) {
			if (cur == s.substr(idx, cut)) {
				cnt++;
			}
			else {
				if (cnt > 1) {
					res += to_string(cnt);
					cnt = 1;
				}
				res += cur;
				cur = s.substr(idx, cut);
			}

			if (idx + cut > s.length()) {
				res += s.substr(idx, cut);
				break;
			}
			idx += cut;
		}

		if (answer > res.length())
			answer = res.length();

		res.clear();
	}

	return answer;
}