#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int R, C;
int answer = 0;
char map[10001][501];

int dx[3] = { -1,0,1 };

bool dfs(int r, int c) {
	if (c == C - 1) {
		return true;
	}

	for (int dir = 0; dir < 3; dir++) {
		int nr = r + dx[dir];
		int nc = c + 1;

		if (nr < 0 || nr >= R) continue;

		if (map[nr][nc] != 'x') {
			map[nr][nc] = 'x';

			if (dfs(nr, nc))
				return true;
		}

	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		if (dfs(i, 0)) answer++;
	}

	cout << answer;
	return 0;
}