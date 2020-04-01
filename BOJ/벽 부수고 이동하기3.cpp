#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#define pii pair<pair<int, int>, int>
using namespace std;

int R, C, K;
int map[1001][1001];
bool visit[1001][1001][11][2];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> R >> C >> K;
	cin.ignore();
	string str;
	for (int i = 0; i < R; i++) {
		getline(cin, str);
		for (int j = 0; j < C; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	queue<pii> q;
	q.push({ { 0,0 }, 0 });
	visit[0][0][0][0] = true;

	int time = 0;	// Â¦¼ö: ³·, È¦¼ö: ¹ã
	while (!q.empty()) {
		int qs = q.size();
		for (int i = 0; i < qs; i++) {
			int cR = q.front().first.first;
			int cC = q.front().first.second;
			int cChan = q.front().second;
			q.pop();

			if (cR == R - 1 && cC == C - 1) {
				cout << time + 1;
				return 0;
			}

			for (int dir = 0; dir < 4; dir++) {
				int nR = cR + dx[dir];
				int nC = cC + dy[dir];

				if (nR < 0 || nC < 0 || nR >= R || nC >= C) continue;

				if (map[nR][nC] == 0 && !visit[nR][nC][cChan][1 - (time % 2)]) {
					q.push({ {nR,nC}, cChan });
					visit[nR][nC][cChan][1 - (time % 2)] = true;
				}
				else if (map[nR][nC] == 1) {
					if (time % 2 == 0) { // ³·¿¡¸¸ ºÎ¼ú ¼ö ÀÖÀ½
						if (cChan < K && !visit[nR][nC][cChan + 1][1]) {
							q.push({ {nR, nC}, cChan + 1 });
							visit[nR][nC][cChan + 1][1] = true;
						}
					}
					else {
						if (!visit[cR][cC][cChan][0]) {
							q.push({ {cR,cC}, cChan });
							visit[cR][cC][cChan][0] = true;
						}
					}
				}
			}
		}
		time++;	
	}

	cout << -1;
	return 0;
}