#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int R, C, N, hei, cLabel;
char map[101][101];
int label[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool check[101];

bool broken(int side, int height) {	// side: 0(왼쪽) 1(오른쪽)
	int start;
	int throw_dir[2] = { 1, -1 };

	if (side == 0) start = 0;
	else start = C - 1;

	while (start >= 0 && start < C) {
		if (map[R - height][start] == 'x') {
			map[R - height][start] = '.';
			return true;
		}
		start += throw_dir[side];
	}
	return false;
}

void labeling(int r, int c) {
	cLabel++;

	queue<pair<int, int> > q;
	q.push({ r, c });
	label[r][c] = cLabel;

	while (!q.empty()) {
		int cR = q.front().first;
		int cC = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nR = cR + dx[dir];
			int nC = cC + dy[dir];

			if (nR < 0 || nC < 0 || nR >= R || nC >= C || label[nR][nC] != -1) continue;

			if (map[nR][nC] == 'x') {
				q.push({ nR, nC });
				label[nR][nC] = cLabel;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> hei;

		// 부순 미네랄이 있는지 확인
		if (!broken(i % 2, hei)) continue;

		// 미네랄 덩어리 개수 계산
		cLabel = 0;
		memset(label, -1, sizeof(label));
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				if (map[r][c] == 'x' && label[r][c] == -1) {
					labeling(r, c);
				}
			}
		}

		// 미네랄이 여러 개일 경우
		if (cLabel > 1) {
			memset(check, false, sizeof(check));
			// 각 미네랄이 땅에 붙었는지 확인
			for (int c = 0; c < C; c++) {
				if (map[R - 1][c] == 'x') {
					check[label[R - 1][c]] = true;
				}
			}

			// 땅에 안붙은 라벨의 미네랄 drop
			int min_diff = 101;
			for (int la = 1; la <= cLabel; la++) {
				if (!check[la]) {
					// 땅에 안붙은 미네랄이 떨어질 높이 : min_diff
					for (int c = 0; c < C; c++) {
						int bot = R;
						for (int r = R - 1; r >= 0; r--) {
							if (map[r][c] == 'x') {
								if (label[r][c] != la) {
									bot = r;
								}
								else {
									min_diff = min(min_diff, bot - r - 1);
								}
							}
						}
					}

					for (int r = R - 1; r >= 0; r--) {
						for (int c = 0; c < C; c++) {
							if (label[r][c] == la) {
								map[r][c] = '.';
								map[r + min_diff][c] = 'x';
							}
						}
					}
					break;
				}
			}
		}
	}

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << map[r][c];
		}
		cout << "\n";
	}

	return 0;
}