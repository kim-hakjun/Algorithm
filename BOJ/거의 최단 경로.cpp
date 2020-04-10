#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 1e6
#define pii pair<int, int>

using namespace std;

int N, M, start, dest;
int adj[501][501];
int dist[501];

void Dijkstra() {
	for (int i = 0; i < N; i++) {
		dist[i] = INF;
	}

	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {		
		int fromDist = pq.top().first;
		int from = pq.top().second;
		pq.pop();

		for (int i = 0; i < N; i++) {
			if (adj[from][i] != -1) {
				
				if (dist[i] > fromDist + adj[from][i]) {
					dist[i] = fromDist + adj[from][i];
					pq.push({ dist[i], i });
				}
			}
		}
	}
}

void erasePath() {	
	queue<pair<int, int> > q;
	q.push({ 0, dest });

	while (!q.empty()) {
		int cur = q.front().second;
		int curDist = q.front().first;
		q.pop();

		for (int i = 0; i < N; i++) {
			if (adj[i][cur] != -1) {
				if (dist[i] + curDist + adj[i][cur] == dist[dest]) {
					q.push({ adj[i][cur] + curDist,i });
					adj[i][cur] = -1;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;

		memset(adj, -1, sizeof(adj));
		cin >> start >> dest;

		int from, to, val;
		for (int i = 0; i < M; i++) {
			cin >> from >> to >> val;
			adj[from][to] = val;
		}

		Dijkstra();
		erasePath();
		Dijkstra();

		if (dist[dest] == INF) cout << -1 << "\n";
		else cout << dist[dest] << "\n";
	}

	return 0;
}