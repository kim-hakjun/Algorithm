#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, a, b, c, ans;
vector<pair<int, int> > adj[10001];
bool visit[10001];

void BFS(int idx, bool end_flag) {
	int temp = 0;
	int tempIdx = 0;
	queue<pair<int, int> > q;
	q.push({ idx, 0 });
	visit[idx] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int curDist = q.front().second;
		q.pop();

		if (temp < curDist) {
			temp = curDist;
			tempIdx = cur;
		}

		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int nextDist = adj[cur][i].second;

			if (!visit[next]) {
				visit[next] = true;
				q.push({ next, curDist + nextDist });
			}
		}
	}

	if (!end_flag) {
		memset(visit, false, sizeof(visit));
		BFS(tempIdx, true);
	}
	else
		ans = temp;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	BFS(1, false);

	cout << ans;
	return 0;
}