#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define pii pair<int, int>

using namespace std;

const int INF = 800001;
int V, E, from, to, val, v1, v2;
vector<pii> cost[801];
int dist[801];

int dijkstra(int start, int dest) {
	for (int i = 1; i <= V; i++) dist[i] = INF;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int fromDist = pq.top().first;
		int from = pq.top().second;
		pq.pop();

		for (int i = 0; i < cost[from].size(); i++) {
			int toDist = cost[from][i].first;
			int to = cost[from][i].second;

			if (dist[to] > dist[from] + toDist) {
				dist[to] = dist[from] + toDist;
				pq.push({ dist[to], to });
			}
		}
	}

	return dist[dest];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> from >> to >> val;
		cost[from].push_back({ val, to });
		cost[to].push_back({ val, from });
	}
	cin >> v1 >> v2;

	int ans = min((dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, V)), (dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, V)));

	if (ans >= INF) cout << -1;
	else cout << ans;
	return 0;
}