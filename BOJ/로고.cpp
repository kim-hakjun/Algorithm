/*
	※ (0, 0)에서 연필이 내려져있는 상태로 시작한다는 점 생각
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, sX, sY, eX, eY, ans;
bool M[1001][1001][4];
bool V[1001][1001];
vector<pair<int, int> > startPnt;
int dx[4] = { 1,0,-1,0 };	// 동 북 서 남
int dy[4] = { 0,1,0,-1 };

void BFS(int r, int c) {
	queue<pair<int, int> > q;
	q.push({ r, c });
	V[r][c] = true;

	while (!q.empty()) {
		int cX = q.front().first;
		int cY = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nX = cX + dx[dir];
			int nY = cY + dy[dir];

			if (!M[cX][cY][dir]) continue;

			if (nX < 0 || nY < 0 || nX > 1000 || nY > 1000) continue;

			for (int nDir = 0; nDir < 4; nDir++) {
				if (M[nX][nY][nDir] && !V[nX][nY]) {
					q.push({ nX, nY });
					V[nX][nY] = true;
				}
			}
		}
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> sX >> sY >> eX >> eY;
		sX += 500; sY += 500; eX += 500; eY += 500;
		startPnt.push_back({ sX, sY });
		for (int j = sX; j < eX; j++) {
			M[j][sY][0] = true;	// 동
			M[j][eY][0] = true;

			M[j + 1][sY][2] = true;	// 서
			M[j + 1][eY][2] = true;
		}
		for (int j = sY; j < eY; j++) {
			M[eX][j][1] = true;	// 북
			M[sX][j][1] = true;

			M[sX][j + 1][3] = true;	// 남
			M[eX][j + 1][3] = true;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	input();
	// (0, 0)에 연결된 선
	BFS(500, 500);

	for (int i = 0; i < N; i++) {
		if (!V[startPnt[i].first][startPnt[i].second]) {
			BFS(startPnt[i].first, startPnt[i].second);
			ans++;			
		}
	}

	cout << ans;
	return 0;
}