#include <iostream>
#include <vector>

using namespace std;

int N, a, b;
vector<int> adj[100001];
int temp[100001];
bool visit[100001];

void dfs(int idx) {
	visit[idx] = true;

	for (int i = 0; i < adj[idx].size(); i++) {
		int next = adj[idx][i];
		if (!visit[next]) {
			temp[next] = idx;
			dfs(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);

	for (int i = 2; i <= N; i++) {
		cout << temp[i] << "\n";
	}

	return 0;
}