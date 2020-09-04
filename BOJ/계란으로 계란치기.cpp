#include <iostream>

using namespace std;

int N, ans;
int wei[9];
int dur[9];

void dfs(int idx, int cnt) {

	if (idx == N) {
		if (cnt > ans) ans = cnt;
		return;
	}

	int temp_cnt = cnt;
	bool used = false;
	for (int i = 0; i < N; i++) {
		if (i != idx && dur[idx] > 0 && dur[i] > 0) {
			used = true;

			dur[idx] -= wei[i];
			dur[i] -= wei[idx];

			if (dur[idx] <= 0) cnt += 1;
			if (dur[i] <= 0) cnt += 1;

			dfs(idx + 1, cnt);

			cnt = temp_cnt;
			dur[idx] += wei[i];
			dur[i] += wei[idx];
		}
	}
	if (!used) dfs(idx + 1, cnt);
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> dur[i] >> wei[i];
	}

	dfs(0, 0);
	cout << ans;

	return 0;
}