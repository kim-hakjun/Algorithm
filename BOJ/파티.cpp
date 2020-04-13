#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define INF 1e9

using namespace std;

int N, M, X, from, to , cost;
int dist[1001][1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> X;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) dist[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> from >> to >> cost;
		dist[from][to] = cost;
	}

	for (int mid = 1; mid <= N; mid++) {
		for (int start = 1; start <= N; start++) {
			for (int end = 1; end <= N; end++) {				
				if (dist[start][end] > dist[start][mid] + dist[mid][end])
					dist[start][end] = dist[start][mid] + dist[mid][end];
			}
		}
	}

	int ans = -1;
	for (int i = 1; i <= N; i++) {
		int sum = dist[i][X] + dist[X][i];
		if (sum != 0 && ans < sum) ans = dist[i][X] + dist[X][i];
	}

	cout << ans;
	return 0;
}