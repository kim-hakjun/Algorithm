#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N, val;
	stack<pair<int, int> > st;
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> val;
		if (st.empty()) {
			st.push({ val, i });
			cout << 0 << " ";
		}
		else {
			while (1) {
				if (st.top().first < val) {
					st.pop();
					if (st.empty()) {
						st.push({ val, i });
						cout << 0 << " ";
						break;
					}				
				}
				else {
					cout << st.top().second << " ";
					st.push({ val, i });
					break;
				}
			}			
		}
	}

	return 0;
}