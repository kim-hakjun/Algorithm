#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#define INF 1e6
#define info pair<int, pair<int, int> >

using namespace std;

int map[126][126];
int dist[126][126];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	while (1) {
		cin >> N;
		if (N == 0) break;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				dist[i][j] = INF;
			}
		}

		priority_queue<info, vector<info>, greater<info> > pq;
		pq.push({ map[0][0], {0, 0} });

		while (!pq.empty()) {		
			int fromDist = pq.top().first;
			int cR = pq.top().second.first;
			int cC = pq.top().second.second;
			pq.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nR = cR + dx[dir];
				int nC = cC + dy[dir];

				if (nR < 0 || nC < 0 || nR >= N || nC >= N) continue;

				if (dist[nR][nC] > fromDist + map[nR][nC]) {
					dist[nR][nC] = fromDist + map[nR][nC];
					pq.push({ dist[nR][nC], {nR, nC} });
				}
			}
		
		}
		
		cout << "Problem " << t << ": " << dist[N - 1][N - 1] << "\n";
		t++;
	}

	return 0;
}