#include <iostream>
#include <vector>

using namespace std;

int N, input, ans;
vector<int> hitInfo[9];
vector<int> order;
int state[5];
bool check[9];

void simul() {
	int score = 0;

	int cnt = 0;
	int cur = 0;
	for (int inning = 0; inning < N; inning++) {
		for (int j = 1; j <= 4; j++) state[j] = 0;

		int out = 0;
		while (out != 3) {
			if (cnt == 3) cur = 0;
			else cur = order[cnt];

			int run = hitInfo[cur][inning];

			if (run == 0) {
				out++;
			}
			else {
				for (int j = 3; j >= 1; j--) {
					if (state[j] != 0) {
						int nextState = j + run;
						if (nextState > 3) {
							nextState = 4;
						}

						state[nextState] += state[j];
						state[j] = 0;
					}
				}
				state[run]++;
			}

			cnt++;
			if (cnt == 9) cnt = 0;
		}

		score += state[4];
	}

	if (ans < score) ans = score;
	return;
}

void dfs() {
	if (order.size() == 3) {
		order.push_back(0);
		dfs();
		order.pop_back();
	}
	else if (order.size() == 9) {
		simul();
		return;
	}

	for (int i = 0; i < 9; i++) {
		if (i != 0 && !check[i]) {
			check[i] = true;
			order.push_back(i);
			dfs();
			order.pop_back();
			check[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> input;
			hitInfo[j].push_back(input);
		}
	}

	dfs();

	cout << ans;
	return 0;
}