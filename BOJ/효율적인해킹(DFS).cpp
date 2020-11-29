#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N, M, a, b, maxVal;
vector<int> info[10001];
int dp[10001];
bool visit[10001];

int dfs(int cur) {
	visit[cur] = true;

	int cnt = 1;
	for (int i = 0; i < info[cur].size(); i++) {
		int next = info[cur][i];
		if (!visit[next]) {
			cnt += dfs(next);			
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		info[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		dp[i] = dfs(i);

		if (maxVal < dp[i]) {
			maxVal = dp[i];
		}
		memset(visit, false, sizeof(visit));
	}

	for (int i = 1; i <= N; i++) {
		if (dp[i] == maxVal) {
			cout << i << " ";
		}
	}

	return 0;
}