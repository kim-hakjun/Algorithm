#include<iostream>
#include<vector>

using namespace std;

int N, M, a, b, x, y;
vector<int> adj[101];
bool visit[101];

int dfs(int cur, int cnt) {
	visit[cur] = true;
	if (cur == b) return cnt;

	int ret = -1;
	for (int i = 0; i < adj[cur].size(); i++) {
		int next = adj[cur][i];

		if (!visit[next]) {
			ret = dfs(next, cnt + 1);
			if (ret != -1) break;
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> a >> b >> M;
	while (M--) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	cout << dfs(a, 0);

	return 0;
}