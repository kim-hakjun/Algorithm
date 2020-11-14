#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int R, C, K, ans;
char M[101][101];
int dp[101][101][81];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
string target;

int sol(int r, int c, int idx) {
	int& ret = dp[r][c][idx];
	if (ret != -1) return ret;

	if (idx == target.length() - 1) {
		ret = 1;
		return ret;
	}

	int temp = 0;
	for (int dir = 0; dir < 4; dir++) {
		for (int i = 1; i <= K; i++) {
			int nR = r + dx[dir] * i;
			int nC = c + dy[dir] * i;

			if (nR < 0 || nC < 0 || nR >= R || nC >= C) break;

			if (M[nR][nC] == target[idx + 1]) {
				temp += sol(nR, nC, idx + 1);
			}
		}
	}

	ret = temp;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// INPUT
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> M[i][j];
		}
	}
	cin >> target;
	memset(dp, -1, sizeof(dp));

	// Graph search & DP
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (M[i][j] == target[0]) {
				ans += sol(i, j, 0);
			}
		}
	}

	cout << ans;
	return 0;
}