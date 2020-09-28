#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<set>

using namespace std;

int R, C;
int Map[1001][1001];
int label[1001][1001];
bool visit[1001][1001];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<int> label_temp;
int label_num = 1;

bool isOut(int r, int c) {
	return r < 0 || c < 0 || r >= R || c >= C;
}

void BFS(int r, int c) {
	queue<pair<int, int> > q;
	q.push({ r, c });
	visit[r][c] = true;
	label[r][c] = label_num;

	int cnt = 0;
	while (!q.empty()) {
		int cR = q.front().first;
		int cC = q.front().second;
		cnt++;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nR = cR + dx[dir];
			int nC = cC + dy[dir];

			if (isOut(nR, nC)) continue;

			if (Map[nR][nC] == 0 && !visit[nR][nC]) {
				q.push({ nR, nC });
				visit[nR][nC] = true;
				label[nR][nC] = label_num;
			}
		}
	}

	label_temp.push_back(cnt);
	label_num++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// input
	cin >> R >> C;
	string inp;
	for (int i = 0; i < R; i++) {
		cin >> inp;
		for (int j = 0; j < C; j++) {
			Map[i][j] = inp[j] - '0';
		}
	}

	// labeling
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (Map[i][j] == 0 && !visit[i][j]) {
				BFS(i, j);
			}
		}
	}

	// output
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (Map[i][j] == 1) {
				set<int> s;
				for (int dir = 0; dir < 4; dir++) {
					int nR = i + dx[dir];
					int nC = j + dy[dir];
					if (!isOut(nR, nC)) {
						if (Map[nR][nC] == 0) {
							s.insert(label[nR][nC]);
						}
					}
				}

				int sum = 0;
				for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
					sum += label_temp[(*iter) - 1];
				}

				cout << (sum + 1) % 10;
			}
			else {
				cout << 0;
			}
		}
		cout << "\n";
	}

	return 0;
}