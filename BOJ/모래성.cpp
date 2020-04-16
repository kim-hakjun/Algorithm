#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int R, C, ans;
int map[1001][1001];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int> > q;
	char inp;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> inp;
			if (inp == '.') {
				map[i][j] = 0;
				q.push({ i, j });
			}
			else map[i][j] = inp - '0';
		}
	}

	while (!q.empty()) {
		int qs = q.size();
		for (int i = 0; i < qs; i++) {
			int cR = q.front().first;
			int cC = q.front().second;
			q.pop();

			for (int dir = 0; dir < 8; dir++) {
				int nR = cR + dx[dir];
				int nC = cC + dy[dir];

				if (nR < 0 || nC < 0 || nR >= R || nC >= C) continue;

				if (map[nR][nC] > 0) {
					map[nR][nC]--;
					if (map[nR][nC] == 0) {
						q.push({ nR, nC });
					}
				}
			}
		}
		ans++;
	}

	cout << ans - 1;
	return 0;
}