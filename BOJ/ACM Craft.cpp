#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T, N, K, a, b, target;
int cost[1001];
vector<int> edge[1001];
int topo[1001];
int temp[1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> cost[i];
		}
		for (int i = 0; i < K; i++) {
			cin >> a >> b;
			edge[a].push_back(b);
			topo[b]++;
		}
		cin >> target;

		queue<pair<int, int> > q;
		for (int i = 1; i <= N; i++) {
			if (topo[i] == 0) {
				temp[i] = cost[i];
				q.push({ i, cost[i] });
			}
		}

		while (!q.empty()) {
			int cur = q.front().first;
			int curCost = q.front().second;
			q.pop();

			if (cur == target) break;

			for (int i = 0; i < edge[cur].size(); i++) {
				int next = edge[cur][i];
				int nextCost = curCost + cost[next];

				temp[next] = max(temp[next], nextCost);

				if (--topo[next] == 0) {
					q.push({ next, temp[next] });
				}
			}
		}

		cout << temp[target] << "\n";
		for (int i = 1; i <= N; i++) {
			edge[i].clear();
			topo[i] = 0;
			temp[i] = 0;
		}
	}

	return 0;
}