#include <iostream>
#include <vector>

#define ABS(A) ((A > 0) ? A : -(A))

using namespace std;

struct coor {
	int r, c;
};

int ans;
int R, C, D;
int M[15][15];
vector<int> archer;

int getDist(int sR, int sC, int tR, int tC) {
	return ABS(sR - tR) + ABS(sC - tC);
}

void simul() {
	int kill = 0;
	int temp[15][15];
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			temp[i][j] = M[i][j];
		}
	}

	coor targetCoor[3];
	bool findTarget[3];
	for (int time = 0; time < R; time++) {
		for (int i = 0; i < 3; i++) {
			findTarget[i] = false;
		}

		// 공격 대상 선택
		for (int i = 0; i < archer.size(); i++) {
			int sC = archer[i];

			int minDist = 100;
			for (int r = R - time - 1; r >= 0; r--) {
				for (int c = 0; c < C; c++) {
					if (temp[r][c] == 1) {
						int dist = getDist(R - time, sC, r, c);

						if (dist <= D) {
							if (minDist > dist) {
								// 가장 가까운 적
								targetCoor[i] = { r,c };
								findTarget[i] = true;
								minDist = dist;
							}
							else if (minDist == dist) {
								// 가장 왼쪽
								if (targetCoor[i].c > c) {
									targetCoor[i] = { r, c };
								}
							}
						}
					}
				}
			}
		}

		for (int i = 0; i < 3; i++) {
			if (findTarget[i]) {
				// 공격 대상 제거
				if (temp[targetCoor[i].r][targetCoor[i].c] == 1) {
					temp[targetCoor[i].r][targetCoor[i].c] = 0;
					kill++;
				}
			}
		}
	}

	if (ans < kill) {
		ans = kill;
	}
}

void selectArcher(int idx, int cnt) {
	if (cnt == 3) {
		simul();
		return;
	}

	for (int i = idx; i < C; i++) {
		archer.push_back(i);
		selectArcher(i + 1, cnt + 1);
		archer.pop_back();
	}

}

void input() {
	cin >> R >> C >> D;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> M[i][j];
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	input();
	selectArcher(0, 0);

	cout << ans;
	return 0;
}