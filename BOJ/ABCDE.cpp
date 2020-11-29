#include<iostream>
#include<vector>

using namespace std;

int N, M, a, b;
vector<int> adj[2001];
bool visit[2001];

bool dfs(int cur, int cnt) {
	visit[cur] = true;

	if (cnt == 5) {
		return true;
	}

	for (int i = 0; i < adj[cur].size(); i++) {
		int next = adj[cur][i];

		if (!visit[next]) {
			if (dfs(next, cnt + 1)) {
				return true;
			}
		}
	}

	visit[cur] = false;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	while (M--) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		if (dfs(i, 1)) {
			cout << 1;
			break;
		}
		else {
			if (i == N - 1) {
				cout << 0;
			}
		}
	}

	return 0;
}