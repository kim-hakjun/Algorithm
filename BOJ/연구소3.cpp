#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int ans = -1;
int N, M, need;
int lab[51][51];
bool visit[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool check[11];

vector<pair<int, int> > allVirus, activeVirus;

void BFS() {
	memset(visit, false, sizeof(visit));
	int temp = need;	// 퍼뜨려야할 칸의 수

	queue<pair<int, int> > q;
	for (int i = 0; i < M; i++) {
		q.push(activeVirus[i]);
		visit[activeVirus[i].first][activeVirus[i].second] = true;
	}

	int time = 0;
	while (!q.empty() && temp != 0) {
		int qs = q.size();
		while (qs--) {
			int cR = q.front().first;
			int cC = q.front().second;
			q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nR = cR + dx[dir];
				int nC = cC + dy[dir];

				if (nR < 0 || nC < 0 || nR >= N || nC >= N || visit[nR][nC]) continue;

				if (lab[nR][nC] != 1) {
					q.push({ nR, nC });
					visit[nR][nC] = true;

					if (lab[nR][nC] == 0) {
						temp--;
					}
				}

			}
		}
		time++;
	}

	// if (temp != 0) : 바이러스를 모든 칸에 퍼뜨리지 못함
	if (temp == 0) {
		if (ans == -1) ans = time;
		else if (ans > time) ans = time;	
	}

}

void selectVirus(int idx, int cnt) {
	if (cnt == M) {
		BFS();
		return;
	}

	for (int i = idx; i < allVirus.size(); i++) {		
		if (!check[i]) {
			check[i] = true;
			activeVirus.push_back(allVirus[i]);
			selectVirus(i + 1, cnt + 1);
			activeVirus.pop_back();
			check[i] = false;
		}
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 0) {
				need++;
			}else if (lab[i][j] == 2) {
				allVirus.push_back({ i, j });
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	input();
	selectVirus(0, 0);

	cout << ans;
	return 0;
}