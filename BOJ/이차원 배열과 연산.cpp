#include <iostream>

using namespace std;

int R, C, K;
int rLen, cLen, ans;
int A[100][100];
int valCnt[101];

// 열 연산
void colOperation() {
	int prevR = rLen;
	int prevC = cLen;

	int nextLen = 0;

	for (int c = 1; c <= prevC; c++) {
		// 개수 초기화
		for (int cnt = 1; cnt <= 100; cnt++) {
			valCnt[cnt] = 0;
		}
		int maxCnt = 0;

		// 개수 카운트
		for (int r = 1; r <= prevR; r++) {
			if (A[r][c] == 0) continue;

			valCnt[A[r][c]]++;
			if (valCnt[A[r][c]] > maxCnt) {
				maxCnt = valCnt[A[r][c]];
			}
			A[r][c] = 0;
		}

		// 개수 적은 것부터
		int rIdx = 0;
		for (int cnt = 1; cnt <= maxCnt; cnt++) {
			for (int val = 1; val <= 100; val++) {
				if (valCnt[val] == cnt) {
					A[rIdx + 1][c] = val;
					A[rIdx + 2][c] = cnt;
					rIdx += 2;
				}
				// 배열 최대 크기 100
				if (rIdx == 100) {
					break;
				}
			}
			if (rIdx == 100) {
				break;
			}
		}

		// 최대 행 길이 갱신
		if (rIdx > nextLen) {
			nextLen = rIdx;
		}		
	}
	rLen = nextLen;
}

void rowOperation() {	// 열연산과 동일
	int prevR = rLen;
	int prevC = cLen;

	int nextLen = 0;

	for (int r = 1; r <= prevR; r++) {
		for (int cnt = 1; cnt <= 100; cnt++) {
			valCnt[cnt] = 0;
		}
		int maxCnt = 0;

		for (int c = 1; c <= prevC; c++) {
			if (A[r][c] == 0) continue;

			valCnt[A[r][c]]++;
			if (valCnt[A[r][c]] > maxCnt) {
				maxCnt = valCnt[A[r][c]];
			}
			A[r][c] = 0;
		}

		int cIdx = 0;
		for (int cnt = 1; cnt <= maxCnt; cnt++) {
			for (int val = 1; val <= 100; val++) {
				if (valCnt[val] == cnt) {
					A[r][cIdx + 1] = val;
					A[r][cIdx + 2] = cnt;
					cIdx += 2;
				}
				if (cIdx == 100) {
					break;
				}
			}
			if (cIdx == 100) {
				break;
			}
		}

		if (cIdx > nextLen) {
			nextLen = cIdx;
		}		
	}
	cLen = nextLen;
}

void input() {
	rLen = 3; cLen = 3;
	cin >> R >> C >> K;
	for (int i = 1; i <= rLen; i++) {
		for (int j = 1; j <= cLen; j++) {
			cin >> A[i][j];
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	input();

	while (A[R][C] != K) {
		if (ans == 100) {
			ans = -1;
			break;
		}

		if (rLen >= cLen) {
			rowOperation();
		}
		else {
			colOperation();
		}
		ans++;
	}

	cout << ans;
	return 0;
}