#include <queue>
#include <vector>

using namespace std;

int N;
bool visit[101][101][4];
int dx[4] = { 0,-1,1,0 };   // 동 북 남 서
int dy[4] = { 1,0,0,-1 };

bool innerTest(int r, int c) {
	if (r < 0 || c < 0 || r >= N || c >= N) return false;
	else return true;
}

int solution(vector<vector<int>> board) {
	int answer = 0;

	N = board.size();

	queue<pair<pair<int, int>, int> > q;
	q.push({ { 0, 0 },0 });
	visit[0][0][0] = true;

	while (!q.empty()) {
		int qs = q.size();

		for (int i = 0; i < qs; i++) {
			int cR = q.front().first.first;
			int cC = q.front().first.second;
			int cD = q.front().second;
			q.pop();

			if ((cR == N - 1 && cC == N - 1) || (cR + dx[cD] == N - 1 && cC + dy[cD] == N - 1)) {
				return answer;
			}

			int nR, nC, nD;
			// 일반적인 이동 (회전 X)
			for (int dir = 0; dir < 4; dir++) {
				nR = cR + dx[dir];
				nC = cC + dy[dir];
				if (innerTest(nR, nC) && innerTest(nR + dx[cD], nC + dy[cD])) {
					if (board[nR][nC] == 0 && board[nR + dx[cD]][nC + dy[cD]] == 0 && !visit[nR][nC][cD]) {
						q.push({ {nR,nC},cD });
						visit[nR][nC][cD] = true;
					}
				}
			}

			// 회전 시도
			for (int dir = 0; dir < 4; dir++) {
				if ((cD == 0 || cD == 3) && (dir == 0 || dir == 3)) continue;   // 현재 가로일 때
				else if ((cD == 1 || cD == 2) && (dir == 1 || dir == 2)) continue;  // 현재 세로일 때

				// 1. 회전 축 : 꼬리(머리가 이동)
				nR = cR + dx[cD] + dx[dir];
				nC = cC + dy[cD] + dy[dir];
				nD = 3 - dir;

				if (innerTest(nR, nC)) {
					if (board[cR + dx[dir]][cC + dy[dir]] == 0 && board[nR][nC] == 0 && !visit[nR][nC][nD]) {
						q.push({ {nR,nC}, nD });
						visit[nR][nC][nD] = true;
					}
				}

				// 2. 회전 축 : 머리(꼬리가 이동)
				nR = cR;
				nC = cC;
				nD = dir;

				if (innerTest(cR + dx[dir], cC + dy[dir])) {
					if (board[cR + dx[dir]][cC + dy[dir]] == 0 && board[cR + dx[cD] + dx[dir]][cC + dy[cD] + dy[dir]] == 0 && !visit[nR][nC][nD]) {
						q.push({ {nR, nC}, dir });
						visit[nR][nC][dir] = true;
					}
				}

			}

		}
		answer++;

	}

	return answer;
}