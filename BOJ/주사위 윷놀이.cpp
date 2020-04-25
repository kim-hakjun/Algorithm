#include <iostream>

using namespace std;

struct COOR {
	int row, col;
};

int map[4][22] = {
	{0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0},	// 경로1
	{10, 13, 16, 19, 25, 30, 35, 40},	// 경로2
	{20, 22, 24, 25, 30, 35, 40},	// 경로3
	{30, 28, 27, 26, 25, 30, 35, 40}	// 경로4
};
bool visit[4][22];
COOR horse[4];
int dices[10];
int ans;

/*
	// 예제 입력 3 218 나오는 이유
	: 경로2는 다른 모든 경로와 중첩될 수 있음
		-> 중첩되는 경우는 경로1로 통일
*/
COOR mov(int r, int c, int cnt) {
	int nextR = r;
	int nextC = c + cnt;
	bool endFlag = false;

	if (nextR == 0) {
		if (nextC == 5) {	// 경로1 -> 경로2
			nextR = 1;
			nextC = 0;
		}
		else if (nextC == 10) {	//경로2 -> 경로3
			nextR = 2;
			nextC = 0;
		}
		else if (nextC == 15) {	// 경로3 -> 경로4
			nextR = 3;
			nextC = 0;
		}
		else if (nextC == 20) {	// 경로4 <-> 경로2 중첩 방지
			nextR = 1;
			nextC = 7;
		}
		else if (nextC >= 21) {
			endFlag = true;
		}
	}
	else if (nextR == 1) {
		if (nextC >= 8) {
			endFlag = true;
		}
	}
	else if (nextR == 2) {
		if (nextC >= 3 && nextC <= 6) {
			nextR = 1;
			nextC += 1;
		}
		else if (nextC >= 7) {
			endFlag = true;
		}
	}
	else if (nextR == 3) {
		if (nextC >= 4 && nextC <= 7) {
			nextR = 1;
		}
		else if (nextC >= 8) {
			endFlag = true;
		}
	}

	if (endFlag) return { 0, 21 };
	else return { nextR, nextC };
}

// 백트래킹
void dfs(int turn, int sum) {
	if (turn == 10) {
		if (ans < sum) ans = sum;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (turn == 0 && i != 0) break;
		if (horse[i].col == 21) continue;

		COOR cur = horse[i];
		COOR nextCoor = mov(cur.row, cur.col, dices[turn]);

		if (!visit[nextCoor.row][nextCoor.col]) {
			horse[i] = nextCoor;
			visit[cur.row][cur.col] = false;

			if (nextCoor.col != 21) {
				visit[nextCoor.row][nextCoor.col] = true;
			}

			dfs(turn + 1, sum + map[horse[i].row][horse[i].col]);

			horse[i] = cur;
			visit[cur.row][cur.col] = true;
			visit[nextCoor.row][nextCoor.col] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// 초기화
	for (int i = 0; i < 10; i++) {
		cin >> dices[i];
	}

	for (int i = 0; i < 4; i++) {
		horse[i] = { 0, 0 };
	}

	// 완탐
	dfs(0, 0);

	cout << ans;
	return 0;
}