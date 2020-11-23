#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int V, from, to, dist, ans;
vector<pair<int, int> > adj[100001];
bool visit[100001];

void bfs(int cur, bool flag) {
	int temp = 0;
	int tempX = 0;
	
	queue<pair<int, int> > q;
	visit[cur] = true;
	for (int i = 0; i < adj[cur].size(); i++) {
		q.push(adj[cur][i]);
		visit[adj[cur][i].first] = true;
	}

	while (!q.empty()) {		
		int cX = q.front().first;
		int cDist = q.front().second;
		q.pop();

		if (temp < cDist) {
			temp = cDist;
			tempX = cX;
		}

		for (int i = 0; i < adj[cX].size(); i++) {
			int next = adj[cX][i].first;
			int nextDist = adj[cX][i].second;
			if (!visit[next]) {
				q.push({ next, cDist + nextDist });
				visit[next] = true;
			}
		}
	}

	if (flag) {
		ans = temp;
	}
	else {
		memset(visit, false, sizeof(visit));
		bfs(tempX, true);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> V;
	for (int i = 1; i <= V; i++) {
		cin >> from >> to;
		while (to != -1) {
			cin >> dist;
			adj[from].push_back({ to, dist });
			adj[to].push_back({ from, dist });
			cin >> to;
		}
	}

	bfs(1, false);
	cout << ans;

	return 0;
}