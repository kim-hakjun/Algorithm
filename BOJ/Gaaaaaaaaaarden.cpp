#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int R, C, gNum, rNum, ans;
int M[51][51];
int check[51][51];	// 시간 체크
int flower[51][51];	// 1: 초록, 2: 빨강, 3: 꽃
bool possCheck[11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<pair<int, int> > poss, curG, curR;	// 배양액 선택

bool isOut(int r, int c) {
	return r < 0 || c < 0 || r >= R || c >= C;
}

void sol() {
	memset(check, -1, sizeof(check));
	memset(flower, -1, sizeof(flower));
	
	queue<pair<int, int> > gQ, rQ;

	// 배양액 초기화
	for (int i = 0; i < gNum; i++) {
		gQ.push(curG[i]);
		check[curG[i].first][curG[i].second] = 0;
		flower[curG[i].first][curG[i].second] = 1;
	}
	for (int i = 0; i < rNum; i++) {
		rQ.push(curR[i]);
		check[curR[i].first][curR[i].second] = 0;
		flower[curR[i].first][curR[i].second] = 2;
	}
	int temp_ans = 0;

	int time = 1;
	while (!gQ.empty()) {
		int gqS = gQ.size();
		while (gqS--) {
			int c_gR = gQ.front().first;
			int c_gC = gQ.front().second;
			gQ.pop();

			if (flower[c_gR][c_gC] == 3) continue;

			for (int dir = 0; dir < 4; dir++) {
				int n_gR = c_gR + dx[dir];
				int n_gC = c_gC + dy[dir];

				if (isOut(n_gR, n_gC) || M[n_gR][n_gC] == 0) continue;

				if (check[n_gR][n_gC] == -1) {
					flower[n_gR][n_gC] = 1;
					check[n_gR][n_gC] = time;
					gQ.push({ n_gR, n_gC });
				}
			}
		}

		int rqS = rQ.size();
		while (rqS--) {
			int c_rR = rQ.front().first;
			int c_rC = rQ.front().second;
			rQ.pop();

			for (int dir = 0; dir < 4; dir++) {
				int n_rR = c_rR + dx[dir];
				int n_rC = c_rC + dy[dir];

				if (isOut(n_rR, n_rC) || M[n_rR][n_rC] == 0) continue;

				if (check[n_rR][n_rC] == -1) {
					check[n_rR][n_rC] = time;
					flower[n_rR][n_rC] = 2;
					rQ.push({ n_rR, n_rC });
				}
				else if (flower[n_rR][n_rC] == 1 && check[n_rR][n_rC] == time) {
					flower[n_rR][n_rC] = 3;
					temp_ans++;
				}
			}
		}
		time++;
	}

	if (temp_ans > ans) ans = temp_ans;
}

void selectR(int idx, int num) {
	if (num == rNum) {
		sol();
		return;
	}

	for (int i = idx; i < poss.size(); i++) {
		if (!possCheck[i]) {
			possCheck[i] = true;
			curR.push_back(poss[i]);
			selectR(i + 1, num + 1);
			curR.pop_back();
			possCheck[i] = false;
		}
	}
}

void selectG(int idx, int num) {
	if (num == gNum) {
		selectR(0, 0);
		return;
	}

	for (int i = idx; i < poss.size(); i++) {
		if (!possCheck[i]) {
			possCheck[i] = true;
			curG.push_back(poss[i]);
			selectG(i + 1, num + 1);
			curG.pop_back();
			possCheck[i] = false;
		}
	}
}

void input() {
	cin >> R >> C >> gNum >> rNum;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> M[i][j];
			if (M[i][j] == 2) {
				poss.push_back({ i, j });
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	input();
	selectG(0, 0);

	cout << ans;
	return 0;
}