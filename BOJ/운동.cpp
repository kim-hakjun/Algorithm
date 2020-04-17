#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define INF 1e9

using namespace std;

int V, E, from, to, val;
int cost[401][401];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			cost[i][j] = INF;
		}
	}

	for (int i = 0; i < E; i++) {
		cin >> from >> to >> val;
		cost[from][to] = val;
	}

	for (int mid = 1; mid <= V; mid++) {
		for (int start = 1; start <= V; start++) {
			for (int dest = 1; dest <= V; dest++) {
				if (cost[start][dest] > cost[start][mid] + cost[mid][dest]) {
					cost[start][dest] = cost[start][mid] + cost[mid][dest];
				}
			}
		}
	}

	int ans = INF;
	for (int i = 1; i <= V; i++) {
		if (ans > cost[i][i]) ans = cost[i][i];
	}

	if (ans == INF) cout << -1;
	else cout << ans;

	return 0;
}