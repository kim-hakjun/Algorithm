#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

int R, C, ans;
bool arr[1001][1001], visit[1001][1001];
int labeling[1001][1001];
int curLabel = 1;
int dx[4] = { -1, 1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<int> cnt;

bool isOut(int r, int c) {
	return r < 0 || c < 0 || r >= R || c >= C;
}

void BFS(int r, int c) {
	queue<pair<int, int> > q;
	q.push({ r, c });
	visit[r][c] = true;
	labeling[r][c] = curLabel;

	int num = 1;
	while (!q.empty()) {
		int cR = q.front().first;
		int cC = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nR = cR + dx[dir];
			int nC = cC + dy[dir];

			if (isOut(nR, nC)) continue;

			if (arr[nR][nC] && !visit[nR][nC]) {
				q.push({ nR, nC });
				visit[nR][nC] = true;
				labeling[nR][nC] = curLabel;
				num++;
			}
		}
	}

	cnt.push_back(num);
	curLabel++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}
	
	// 1. 라벨링 및 개수 저장
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] && !visit[i][j]) {
				BFS(i, j);
			}
		}
	}

	// 2. 모양 최대 크기 계산
	set<int> S;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!arr[i][j]) {
				
				for (int dir = 0; dir < 4; dir++) {
					int nR = i + dx[dir];
					int nC = j + dy[dir];

					if (isOut(nR, nC)) continue;

					if (arr[nR][nC]) {
						S.insert(labeling[nR][nC] - 1);
					}
				}
				int temp = 1;
				for (set<int>::iterator iter = S.begin(); iter != S.end(); iter++) {
					temp += cnt[*iter];
				}

				ans = ans < temp ? temp : ans;

				S.clear();
			}
		}
	}

	cout << ans;
	return 0;
}