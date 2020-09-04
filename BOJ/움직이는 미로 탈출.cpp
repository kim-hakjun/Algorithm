/*
	계속 56% 오답 원인
	: 이동하지 않고 머무르거나 재방문이 허용되는 문제임
	  하지만 V[nR][nC][time + 1] 안하고 V[nR][nC][time]로 체크하면 시작단계에서 (7, 0)에 머물 수 없음.
*/

#include <iostream>
#include <queue>

using namespace std;

char M[8][8];
bool V[8][8][10]; // 8행 크기 체스판이므로 3차원의 크기는 8보다 큰 값
int dx[9] = { -1,-1,-1,0,0,0,1,1,1 };
int dy[9] = { -1,0,1,-1,0,1,-1,0,1 };

bool isOut(int r, int c) {
	return r < 0 || c < 0 || r >= 8 || c >= 8;
}

bool BFS() {
	queue<pair<int, int> > q;
	q.push({ 7, 0 });
	V[7][0][0] = true;

	int time = 0;
	while (!q.empty()) {
		int qs = q.size();

		while (qs--) {
			int cR = q.front().first;
			int cC = q.front().second;
			q.pop();

			if (cR == 0 && cC == 7) return true;

			for (int dir = 0; dir < 9; dir++) {
				int nR = cR + dx[dir];
				int nC = cC + dy[dir];

				// 이탈했거나 이미 방문한 경우 스킵
				if (isOut(nR, nC) || V[nR][nC][time + 1]) continue;

				// 이동할 곳에 벽이 있는 경우 스킵
				if (!isOut(nR - time, nC)) {
					if (M[nR - time][nC] != '.') continue;
				}

				// 이동할 곳에 벽이 내려올 예정인 경우 스킵
				if (!isOut(nR - time - 1, nC)) {
					if (M[nR - time - 1][nC] != '.') continue;
				}

				q.push({ nR, nC });
				V[nR][nC][time + 1] = true;
			}
		}
		time++;
	}

	return false;
}

void input() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> M[i][j];
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	input();
	cout << BFS();

	return 0;
}