#include<iostream>
#include<algorithm>

using namespace std;

int N, ans;
int M[501][501], dp[501][501];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int dfs(int r, int c) {
	int& ret = dp[r][c];
	if (ret != 0) return ret;

	for (int dir = 0; dir < 4; dir++) {
		int nR = r + dx[dir];
		int nC = c + dy[dir];

		if (nR < 0 || nC < 0 || nR >= N || nC >= N) continue;

		if (M[nR][nC] > M[r][c]) {
			ret = max(ret, dfs(nR, nC) + 1);
		}
	}

	if (ret == 0) {
		ret = 1;
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> M[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans = max(ans, dfs(i, j));
		}
	}

	cout << ans;
	return 0;
}