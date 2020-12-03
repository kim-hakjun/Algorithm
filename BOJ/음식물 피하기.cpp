#include<iostream>

using namespace std;

int N, M, K, a, b, ans;
bool map[101][101], visit[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int dfs(int r, int c) {
	visit[r][c] = true;

	int temp = 1;
	for (int dir = 0; dir < 4; dir++) {
		int nR = r + dx[dir];
		int nC = c + dy[dir];

		if (nR < 1 || nC < 1 || nR > N || nC > M) continue;

		if (map[nR][nC] && !visit[nR][nC]) {
			temp += dfs(nR, nC);
		}
	}

	return temp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	while (K--) {
		cin >> a >> b;
		map[a][b] = true;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] && !visit[i][j]) {
				int ret = dfs(i, j);
				if (ans < ret) {
					ans = ret;
				}
			}
		}
	}

	cout << ans;
	return 0;
}