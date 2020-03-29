//	BFS/DFS + a
//	다시 풀어봐야 할 문제
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, house, sR, sC;
int ans = 1e9;
char map[51][51];
int val[51][51];
bool visit[51][51];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
vector<int> v;

int dfs(int r, int c, int from, int to) {
	if (r < 0 || c < 0 || r >= N || c >= N || visit[r][c] || val[r][c] < from || val[r][c] > to) {
		return 0;
	}

	int ret = 0;
	visit[r][c] = true;
	if (map[r][c] == 'K') ret++;

	for (int dir = 0; dir < 8; dir++) {
		int nR = r + dx[dir];
		int nC = c + dy[dir];
		ret += dfs(nR, nC, from, to);
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'P') {
				sR = i; sC = j;
			}
			else if (map[i][j] == 'K') house++;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> val[i][j];
			v.push_back(val[i][j]);
		}
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	int from = 0;
	for (int to = 0; to < v.size(); to++) {

		while (1) {
			memset(visit, false, sizeof(visit));

			if (dfs(sR, sC, v[from], v[to]) != house) break;

			ans = min(ans, v[to] - v[from]);
			from++;
		}
	}

	cout << ans;
	return 0;
}