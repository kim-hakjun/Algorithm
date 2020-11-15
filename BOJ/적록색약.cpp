#include<iostream>

using namespace std;

int N, ans[2];
char M[101][101];
bool V[101][101][2];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void dfs(int r, int c, bool daltonism) {
	V[r][c][(int)daltonism] = true;

	for (int dir = 0; dir < 4; dir++) {
		int nR = r + dx[dir];
		int nC = c + dy[dir];

		if (nR < 0 || nC < 0 || nR >= N || nC >= N || V[nR][nC][(int)daltonism]) continue;

		if (M[r][c] == 'B') {
			if (M[nR][nC] == 'B') {
				dfs(nR, nC, daltonism);			
			}
		}
		else {
			if (daltonism) {
				if (M[nR][nC] != 'B') {
					dfs(nR, nC, daltonism);
				}
			}
			else {
				if (M[nR][nC] == M[r][c]) {
					dfs(nR, nC, daltonism);
				}
			}
		}
	}
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
			if (!V[i][j][0]) {
				dfs(i, j, false);
				ans[0]++;
			}
			if (!V[i][j][1]) {
				dfs(i, j, true);
				ans[1]++;
			}
		}
	}

	cout << ans[0] << " " << ans[1];
	return 0;
}