#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define INF 1e9
#define pii pair<int, int>

using namespace std;

int N, M, from, to, cost, start, dest;
int dist[1001];
int map[1001][1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(map, -1, sizeof(map));

	cin >> N >> M;
	for (int i = 1; i <= N; i++) dist[i] = INF;

	for (int i = 0; i < M; i++) {
		cin >> from >> to >> cost;
		if (map[from][to] == -1) map[from][to] = cost;
		else map[from][to] = min(map[from][to], cost);
	}
	cin >> start >> dest;

	priority_queue<pii, vector<pii>, greater<pii> > pq;
	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int fromCost = pq.top().first;
		int from = pq.top().second;
		pq.pop();

		for (int i = 1; i <= N; i++) {
			if (map[from][i] == -1) continue;

			int nextCost = map[from][i];

			if (dist[i] > fromCost + nextCost) {
				dist[i] = fromCost + nextCost;
				pq.push({ dist[i], i });
			}
		}
	}
	cout << dist[dest] << "\n";

	// ±æ ÃßÀû
	vector<int> trace;
	trace.push_back(dest);
	queue<pii> q;
	q.push({ 0,dest });
	while (!q.empty()) {
		int qs = q.size();
		for (int t = 0; t < qs; t++) {
			bool flag = false;
			int fromDist = q.front().first;
			int from = q.front().second;
			q.pop();

			for (int i = 1; i <= N; i++) {
				if (map[i][from] == -1) continue;

				if (fromDist + map[i][from] + dist[i] == dist[dest]) {
					trace.push_back(i);
					q.push({ fromDist + map[i][from], i });
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
	}

	cout << trace.size() << "\n";
	for (int i = trace.size() - 1; i >= 0; i--) {
		cout << trace[i] << " ";
	}
	return 0;
}