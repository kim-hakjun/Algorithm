/*
	# DFS 풀이

	### 메모이제이션 안되는 이유(반례) ###
		4 4
		1 2
		1 3
		2 4
		3 4
*/

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N, M, a, b, ans;
vector<int> in[501], out[501];
int inD[501], outD[501];
bool visit[501];

int dfs_in(int cur) {
	visit[cur] = true;

	int temp = 0;
	for (int i = 0; i < in[cur].size(); i++) {
		int next = in[cur][i];
		if (!visit[next]) {
			temp += (dfs_in(next) + 1);
		}
	}
	
	return temp;
}

int dfs_out(int cur) {
	visit[cur] = true;

	int temp = 0;
	for (int i = 0; i < out[cur].size(); i++) {
		int next = out[cur][i];
		if (!visit[next]) {
			temp += (dfs_out(next) + 1);
		}
	}

	return temp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		in[b].push_back(a);
		out[a].push_back(b);
	}

	// in-degree
	for (int i = 1; i <= N; i++) {
		inD[i] = dfs_in(i);
		memset(visit, false, sizeof(visit));
	}
	
	// out-degree
	for (int i = 1; i <= N; i++) {
		outD[i] = dfs_out(i);
		memset(visit, false, sizeof(visit));
	}

	for (int i = 1; i <= N; i++) {
		if (inD[i] + outD[i] == N - 1) {
			ans++;
		}
	}

	cout << ans;
	return 0;
}