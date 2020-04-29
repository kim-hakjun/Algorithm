#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int R, C;
char map[21][21];
bool check[26];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int answer;

void dfs(int r, int c, int cnt) {
	for (int dir = 0; dir < 4; dir++) {
		int nr = r + dx[dir];
		int nc = c + dy[dir];
		if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;

		int temp = map[nr][nc] - 'A';
		if (check[temp] == false) {
			check[temp] = true;
			dfs(nr, nc, cnt + 1);
			check[temp] = false;
		}
	}
	answer = max(answer, cnt);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	check[map[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	cout << answer;
	return 0;
}