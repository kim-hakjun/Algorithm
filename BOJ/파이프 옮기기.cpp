// DP Ç®ÀÌ
#include <iostream>

using namespace std;

int N;
int M[17][17];
int dp[17][17][3];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> M[i][j];
		}
	}

	dp[1][2][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (M[i][j] == 0) {
				dp[i][j][0] += (dp[i][j - 1][0] + dp[i][j - 1][2]);
				dp[i][j][1] += (dp[i - 1][j][1] + dp[i - 1][j][2]);
				
				if (M[i - 1][j] == 0 && M[i][j - 1] == 0) {
					dp[i][j][2] += (dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2]);
				}
			}
		}
	}

	cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
	return 0;
}