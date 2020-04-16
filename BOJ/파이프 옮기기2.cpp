#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N;
int map[33][33];
long long dp[33][33][3];	// 가로 세로 대각
int dx[3] = { 0,1,1 };
int dy[3] = { 1,0,1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> map[i][j];

	for (int i = 1; i < N; i++) {
		if (map[0][i] == 1) break;
		else dp[0][i][0] += 1;
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (map[i][j] == 1) continue;

			if (map[i][j - 1] == 0) dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
			if (map[i - 1][j] == 0) dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];

			if ((map[i - 1][j - 1] | map[i][j-1] | map[i-1][j]) == 0) 
				dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];

		}
	}

	cout << dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];
	return 0;
}