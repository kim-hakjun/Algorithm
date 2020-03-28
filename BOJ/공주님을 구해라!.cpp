#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int R, C, T;
int map[101][101];
bool visit[101][101][2];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> R >> C >> T;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> map[i][j];

	queue<pair<pair<int, int>, int>  > q;
	q.push({ {1,1},0 });
	visit[1][1][0] = true;

	int time = 0;
	while (!q.empty()) {
		int qs = q.size();
		for (int i = 0; i < qs; i++) {
			int cR = q.front().first.first;
			int cC = q.front().first.second;
			int key = q.front().second;
			q.pop();

			if (cR == R && cC == C) {
				cout << time;
				return 0;
			}

			for (int dir = 0; dir < 4; dir++) {
				int nR = cR + dx[dir];
				int nC = cC + dy[dir];
				int nKey = key;
				if (nR < 1 || nC < 1 || nR > R || nC > C) continue;

				if (map[nR][nC] == 1) {
					if (key == 1 && !visit[nR][nC][1]) {
						q.push({ {nR,nC},1 });
						visit[nR][nC][1] = true;
					}
				}
				else {
					if (!visit[nR][nC][key]) {
						if (map[nR][nC] == 2) {
							map[nR][nC] = 0;
							nKey = 1;
						}
						q.push({ {nR,nC},nKey });
						visit[nR][nC][key] = true;
					}
				}
			}
		}
		time++;
		if (time > T) break;
	}

	cout << "Fail";
	return 0;
}