#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#define mypair pair<int, pair<int, int> >

using namespace std;

int R, C;
int map[101][101];
int cost[101][101];	// (0, 0)บฮลอ
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> C >> R;
	string inp;
	for (int i = 0; i < R; i++) {
		cin >> inp;
		for (int j = 0; j < C; j++) {
			map[i][j] = inp[j] - '0';
		}
	}

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cost[i][j] = 1e9;

	priority_queue<mypair, vector<mypair>, greater<mypair> > pq;
	cost[0][0] = 0;
	pq.push({ 0,{0,0} });

	while (!pq.empty()) {
		int cBreak = pq.top().first;
		int cR = pq.top().second.first;
		int cC = pq.top().second.second;
		pq.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nR = cR + dx[dir];
			int nC = cC + dy[dir];
			int nBreak = cBreak;

			if (nR < 0 || nC < 0 || nR >= R || nC >= C) continue;

			if (map[nR][nC] == 1) nBreak += 1;

			if (cost[nR][nC] >= nBreak) {
				if(cost[nR][nC] > nBreak) pq.push({ nBreak, {nR, nC} });
				cost[nR][nC] = nBreak;
			}
		}	
	}

	cout << cost[R - 1][C - 1];
	return 0;
}