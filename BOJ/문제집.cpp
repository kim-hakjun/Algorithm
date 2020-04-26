#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[32001];
int topo[32001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M, a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		topo[b]++;
	}

	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 1; i <= N; i++) {
		if (topo[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.top();
		q.pop();
		cout << cur << " ";

		for (int i = 0; i < edge[cur].size(); i++) {
			if (--topo[edge[cur][i]] == 0) q.push(edge[cur][i]);
		}
	}

	return 0;
}