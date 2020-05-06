#include <iostream>
#include <queue>
#include <algorithm>
#define INF 987654321
#define pii pair<int, int>
using namespace std;

int R, C;
int label = 1;
int map[101][101];
bool visit[101][101];
int dist[7][7];
int check[7];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void labeling(int r, int c) {
	queue<pair<int, int> > q;
	q.push({ r, c });
	visit[r][c] = true;

	while (!q.empty()) {
		int cR = q.front().first;
		int cC = q.front().second;
		map[cR][cC] = label;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nR = cR + dx[dir];
			int nC = cC + dy[dir];
			if (nR < 0 || nC < 0 || nR >= R || nC >= C || visit[nR][nC] || map[nR][nC] == 0) continue;

			q.push({ nR, nC });
			visit[nR][nC] = true;
		}
	}
	label++;
}

void sol(int r, int c, int from) {	// 거리 계산

	for (int dir = 0; dir < 4; dir++) {
		int cnt = 1;
		bool flag = true;
		int nR = r + dx[dir];
		int nC = c + dy[dir];

		if (nR < 0 || nC < 0 || nR >= R || nC >= C || map[nR][nC] == from) continue;

		while (map[nR][nC] == 0) {
			cnt++;
			nR += dx[dir];
			nC += dy[dir];
			if (nR < 0 || nC < 0 || nR >= R || nC >= C || map[nR][nC] == from) {
				flag = false;
				break;
			}
		}
		cnt--;
		if (flag && cnt >= 2) {	// 다른 섬을 찾았을 경우
			int to = map[nR][nC];
			dist[from][to] = min(dist[from][to], cnt);
			dist[to][from] = min(dist[to][from], cnt);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	// BFS : 섬 라벨링
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] && !visit[i][j]) labeling(i, j);
		}
	}

	fill(&dist[0][0], &dist[6][7], INF);
	// 거리 측정
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != 0) {
				sol(i, j, map[i][j]);
			}
		}
	}

	// MST
	// Prim
	int answer = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	check[1] = true;
	for (int j = 0; j < label; j++) {
		if (dist[1][j] != INF) {
			pq.push({ dist[1][j], j });
		}
	}

	int edge = 0;
	while (!pq.empty()) {
		int val = pq.top().first;
		int to = pq.top().second;
		pq.pop();
		if (check[to]) continue;
		check[to] = true;
		edge++;
		answer += val;

		for (int i = 1; i < label; i++) {
			if (dist[to][i] != INF && !check[i]) {
				pq.push({ dist[to][i], i });
			}
		}
	}
	// 최소일 떄 간선은 (정점 개수 - 1)개
	if (edge == label - 2) cout << answer;
	else cout << -1;

	return 0;
}