#include <iostream>

using namespace std;

struct FISH {
	int row, col, speed, dir, zmrl;
};

int rLen, cLen, M, r, c, s, d, z, ans;

FISH curMap[101][101];
FISH nextMap[101][101];

// 1: 상, 2: 하, 3: 우, 4: 좌
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

void moveFish() {
	for (int i = 1; i <= rLen; i++) {
		for (int j = 1; j <= cLen; j++) {
			if (curMap[i][j].row != 0) {
				int cR = curMap[i][j].row;
				int cC = curMap[i][j].col;
				int cSpeed = curMap[i][j].speed;
				int cDir = curMap[i][j].dir;
				int cZmrl = curMap[i][j].zmrl;

				int nR = cR + dx[cDir - 1] * cSpeed;
				int nC = cC + dy[cDir - 1] * cSpeed;
				int nDir = cDir;

				while (nR < 1 || nC < 1 || nR > rLen || nC > cLen) {
					if (nDir == 1) {	// 상
						nR = 1 + (1 - nR);
						nDir = 2;
					}
					else if (nDir == 2) {	// 하
						nR = rLen - (nR - rLen);
						nDir = 1;
					}
					else if (nDir == 3) {	// 우
						nC = cLen - (nC - cLen);
						nDir = 4;
					}
					else {	// 좌
						nC = 1 + (1 - nC);
						nDir = 3;
					}
				}

				if ((nextMap[nR][nC].row != 0 && nextMap[nR][nC].zmrl < cZmrl) || nextMap[nR][nC].row == 0) {
					nextMap[nR][nC] = { nR, nC, cSpeed, nDir, cZmrl };
				}
			}
		}
	}
}

void fishing(int col) {
	for (int i = 1; i <= rLen; i++) {
		if (curMap[i][col].row != 0) {
			curMap[i][col].row = 0;
			ans += curMap[i][col].zmrl;
			break;
		}
	}
}

void input() {
	cin >> rLen >> cLen >> M;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		if (d == 1 || d == 2) {
			if (s >= (rLen - 1) * 2) {
				s %= (rLen - 1) * 2;
			}
		}
		else {
			if (s >= (cLen - 1) * 2) {
				s %= (cLen - 1) * 2;
			}
		}

		curMap[r][c] = { r, c, s, d, z };
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	input();
	for (int curCol = 1; curCol <= cLen; curCol++) {
		fishing(curCol); // 물고기 낚시
		if (curCol == cLen) break;

		moveFish();	// 물고기 이동

		// 초기화
		for (int i = 1; i <= rLen; i++) {
			for (int j = 1; j <= cLen; j++) {
				curMap[i][j] = nextMap[i][j];
				nextMap[i][j] = { 0,0,0,0,0 };
			}
		}
	}

	cout << ans;
	return 0;
}