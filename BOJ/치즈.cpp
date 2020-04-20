#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int R, C, ans, temp;
int map[101][101];
bool visit[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<pair<int, int> > coors;

bool bfs() {
	memset(visit, false, sizeof(visit));

	queue<pair<int, int> > q;
	q.push({ 0, 0 });
	visit[0][0] = true;
	bool flag = false;

	while (!q.empty()) {
		int cR = q.front().first;
		int cC = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nR = cR + dx[dir];
			int nC = cC + dy[dir];

			if (nR < 0 || nC < 0 || nR >= R || nC >= C || visit[nR][nC]) continue;

			if (map[nR][nC] == 0) {
				q.push({ nR, nC });
				visit[nR][nC] = true;
			}

			if (map[cR][cC] == 0 && map[nR][nC] == 1) {
				flag = true;
				visit[nR][nC] = true;
				coors.push_back({ nR, nC });
			}
		}
	}

	return flag;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		if (!bfs()) break;

		temp = coors.size();
		for (int i = 0; i < temp; i++) {
			map[coors[i].first][coors[i].second] = 0;
		}
		coors.clear();
		ans++;
	}

	cout << ans << "\n" << temp;
	return 0;
}