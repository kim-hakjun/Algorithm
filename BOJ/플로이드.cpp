#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define INF 1e9

using namespace std;

int N, M, from, to, val;
int cost[101][101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) cost[i][j] = 0;
			else cost[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> from >> to >> val;
		cost[from][to] = min(cost[from][to], val);		
	}

	for (int i = 1; i <= N; i++) {		
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {				
				if (cost[j][k] > cost[j][i] + cost[i][k]) {
					cost[j][k] = cost[j][i] + cost[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (cost[i][j] == INF) cout << 0 << " ";
			else cout << cost[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}