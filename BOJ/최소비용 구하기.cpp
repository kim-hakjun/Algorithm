#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
#define pii pair<int, int>

using namespace std;

int N, M, from, to, cost, start, dest;
int dist[1001];
vector<pii> map[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) dist[i] = INF;

	for (int i = 0; i < M; i++) {
		cin >> from >> to >> cost;
		map[from].push_back({ cost, to });
	}
	cin >> start >> dest;

	priority_queue<pii, vector<pii>, greater<pii> > pq;
	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {

		int fromCost = pq.top().first;
		int from = pq.top().second;
		pq.pop();

		for (int i = 0; i < map[from].size(); i++) {
			int to = map[from][i].second;
			int toCost = map[from][i].first;

			if (dist[to] > fromCost + toCost) {
				dist[to] = fromCost + toCost;
				pq.push({ dist[to], to });
			}
		}
	}

	cout << dist[dest];
	return 0;
}