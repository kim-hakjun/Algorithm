#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

typedef struct coor {
	int row, col;
}COOR;

int R, C;
char map[11][11];
bool state[11][11][11][11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
COOR b, r;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'B') {
				b.row = i; b.col = j;
			}
			else if (map[i][j] == 'R') {
				r.row = i, r.col = j;
			}
		}
	}

	queue<pair<COOR, COOR> > q;
	q.push({ b, r });
	state[b.row][b.col][r.row][r.col] = true;

	int time = 1;
	while (!q.empty()) {
		int qs = q.size();
		for (int i = 0; i < qs; i++){
			COOR cB = q.front().first;
			COOR cR = q.front().second;
			q.pop();

			for (int dir = 0; dir < 4; dir++) {
				bool b_out = false;
				bool r_out = false;
				int b_dist = 0;
				int r_dist = 0;

				// 파란색 이동
				int nBR = cB.row + dx[dir];
				int nBC = cB.col + dy[dir];
				while (!(nBR < 0 || nBC < 0 || nBR >= R || nBC >= C) && map[nBR][nBC] != '#') {
					if (map[nBR][nBC] == 'O') {
						b_out = true;
						break;
					}
					b_dist++;
					nBR += dx[dir];
					nBC += dy[dir];
				}
				if (b_out) continue;
				nBR -= dx[dir];
				nBC -= dy[dir];

				// 빨간색 이동
				int nRR = cR.row + dx[dir];
				int nRC = cR.col + dy[dir];
				while (!(nRR < 0 || nRC < 0 || nRR >= R || nRC >= C) && map[nRR][nRC] != '#') {
					if (map[nRR][nRC] == 'O') {
						r_out = true;
						break;
					}
					r_dist++;
					nRR += dx[dir];
					nRC += dy[dir];
				}
				if (r_out) {
					cout << 1;
					return 0;
				}
				nRR -= dx[dir];
				nRC -= dy[dir];

				if (nBR == nRR && nBC == nRC) {
					if (r_dist > b_dist) {
						nRR -= dx[dir];
						nRC -= dy[dir];
					}
					else {
						nBR -= dx[dir];
						nBC -= dy[dir];
					}
				}

				if (!state[nBR][nBC][nRR][nRC]) {
					q.push({ {nBR, nBC}, {nRR, nRC} });
					state[nBR][nBC][nRR][nRC] = true;
				}

			}
		}
		time++;
		if (time > 10) break;
	}

	cout << 0;
	return 0;
}