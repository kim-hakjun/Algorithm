#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#define INF 1e6
using namespace std;

struct coor {
	int r, c;
	bool flag = false;
};

char map[51][51];
int visit[51][51][4];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int N;
coor in, out;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') {
				if (in.flag) {
					out.r = i;
					out.c = j;
				}
				else {
					in.r = i;
					in.c = j;
					in.flag = true;
				}
			}

			for (int k = 0; k < 4; k++) visit[i][j][k] = INF;
		}
	}

	queue<pair<pair<int, int>, int> > q;

	for (int dir = 0; dir < 4; dir++) {
		int nR = in.r + dx[dir];
		int nC = in.c + dy[dir];

		if (nR < 0 || nC < 0 || nR >= N || nC >= N) continue;

		if (map[nR][nC] != '*') {
			q.push({ {nR, nC}, dir });
			visit[nR][nC][dir] = 0;
		}
	}

	while (!q.empty()) {
		
		int cR = q.front().first.first;
		int cC = q.front().first.second;
		int cD = q.front().second;
		q.pop();
		int nR, nC, nD;

		if (map[cR][cC] == '!') {	// 거울 반사
			for (int dir = 0; dir < 4; dir++) {
				if (cD == dir || !((cD <= 1 && dir <= 1) || (cD >= 2 && dir >= 2))) {	// 가던 방향 or 거울 설치

					int nR = cR + dx[dir];
					int nC = cC + dy[dir];
					int nD = dir;
					int nextVal;

					if (nR < 0 || nC < 0 || nR >= N || nC >= N || map[nR][nC] == '*') continue;

					if (cD == dir)
						nextVal = visit[cR][cC][cD];
					else
						nextVal = visit[cR][cC][cD] + 1;

					if (visit[nR][nC][nD] > nextVal) {
						q.push({ {nR,nC}, nD });
						visit[nR][nC][nD] = nextVal;
					}
				}
			}
		}
		else {
			nR = cR + dx[cD];
			nC = cC + dy[cD];
			nD = cD;

			if (!(nR < 0 || nC < 0 || nR >= N || nC >= N || map[nR][nC] == '*')) {
				if (visit[nR][nC][nD] > visit[cR][cC][cD]) {
					q.push({ {nR,nC},nD });
					visit[nR][nC][nD] = visit[cR][cC][cD];
				}
			}
		}
	}

	int ans = INF;
	for (int dir = 0; dir < 4; dir++) {
		if (visit[out.r][out.c][dir] != -1 && visit[out.r][out.c][dir] < ans) ans = visit[out.r][out.c][dir];
	}

	cout << ans;
	return 0;
}