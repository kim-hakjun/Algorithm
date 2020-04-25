#include <iostream>

using namespace std;

struct COOR {
	int row, col;
};

int map[4][22] = {
	{0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0},	// ���1
	{10, 13, 16, 19, 25, 30, 35, 40},	// ���2
	{20, 22, 24, 25, 30, 35, 40},	// ���3
	{30, 28, 27, 26, 25, 30, 35, 40}	// ���4
};
bool visit[4][22];
COOR horse[4];
int dices[10];
int ans;

/*
	// ���� �Է� 3 218 ������ ����
	: ���2�� �ٸ� ��� ��ο� ��ø�� �� ����
		-> ��ø�Ǵ� ���� ���1�� ����
*/
COOR mov(int r, int c, int cnt) {
	int nextR = r;
	int nextC = c + cnt;
	bool endFlag = false;

	if (nextR == 0) {
		if (nextC == 5) {	// ���1 -> ���2
			nextR = 1;
			nextC = 0;
		}
		else if (nextC == 10) {	//���2 -> ���3
			nextR = 2;
			nextC = 0;
		}
		else if (nextC == 15) {	// ���3 -> ���4
			nextR = 3;
			nextC = 0;
		}
		else if (nextC == 20) {	// ���4 <-> ���2 ��ø ����
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

// ��Ʈ��ŷ
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

	// �ʱ�ȭ
	for (int i = 0; i < 10; i++) {
		cin >> dices[i];
	}

	for (int i = 0; i < 4; i++) {
		horse[i] = { 0, 0 };
	}

	// ��Ž
	dfs(0, 0);

	cout << ans;
	return 0;
}