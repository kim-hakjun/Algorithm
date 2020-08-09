#include <iostream>

using namespace std;

int ans = -1;
int sR = -1;
int sC = -1;
int need;
int M[10][10];
int paper[5] = { 5, 5, 5, 5, 5 };

bool attachTest(int r, int c, int paperSize) {
	if (r + paperSize > 10 || c + paperSize > 10) return false;

	for (int i = r; i < r + paperSize; i++) {
		for (int j = c; j < c + paperSize; j++) {
			if (M[i][j] == 0) {
				return false;
			}
		}
	}

	return true;
}

void dfs(int r, int c, int num) {
	if (ans != -1 && ans < num + 1) return;

	for (int sz = 4; sz >= 0; sz--) {
		if (paper[sz] != 0) {	// sz 크기 종이 남아있는지
			if (attachTest(r, c, sz + 1)) {	// 붙힐 수 있는지

				// 붙힘
				paper[sz]--;
				need -= (sz + 1) * (sz + 1);
				for (int i = r; i < r + sz + 1; i++) {
					for (int j = c; j < c + sz + 1; j++) {
						M[i][j] = 0;
					}
				}
				
				if (need == 0) {
					if (ans == -1 || ans > num + 1) {
						ans = num + 1;
					}
				}
				else {
					int nR = -1;
					int nC = -1;
					for (int i = r; i < 10; i++) {
						for (int j = 0; j < 10; j++) {
							if (M[i][j] == 1) {
								nR = i;
								nC = j;
								break;
							}
						}
						if (nR != -1) break;
					}
					dfs(nR, nC, num + 1);
				}

				// 복구
				paper[sz]++;
				need += (sz + 1) * (sz + 1);
				for (int i = r; i < r + sz + 1; i++) {
					for (int j = c; j < c + sz + 1; j++) {
						M[i][j] = 1;
					}
				}
			}
		}
	}

}

void input() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> M[i][j];
			if (M[i][j] == 1) {
				need++;
				if (sR == -1) {
					sR = i;
					sC = j;
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	input();

	if (need == 0) {
		ans = 0;
	}
	else {
		dfs(sR, sC, 0);
	}

	cout << ans;
	return 0;
}