#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

char map[12][6];
bool check[12][6];
bool flag = false;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int answer = 0;

void bfs(int row, int col) {
	int cx, cy, nx, ny, qsize;
	int cnt = 1;

	vector<pair<int, int> > store;
	queue<pair<int, int> > q;

	store.push_back({ row, col });
	q.push({ row, col });
	check[row][col] = true;

	while (!q.empty()) {
		qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			cx = q.front().first;
			cy = q.front().second;
			q.pop();

			for (int dir = 0; dir < 4; dir++) {
				nx = cx + dx[dir];
				ny = cy + dy[dir];

				if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;

				if (check[nx][ny] == false && (map[nx][ny] == map[cx][cy])) {
					check[nx][ny] = true;
					q.push({ nx, ny });
					store.push_back({ nx, ny });
					cnt++;
				}
			}
		}
	}

	if (cnt >= 4) {
		flag = true;
		for (int j = 0; j < store.size(); j++) {
			map[store[j].first][store[j].second] = '.';
		}
		return;
	}
}

void drop() {
	for (int i = 11; i >= 1; i--) {
		for (int j = 0; j <= 5; j++) {
			if (map[i - 1][j] != '.' && map[i][j] == '.') {
				int cur = i;
				char temp = map[i - 1][j];
				map[i - 1][j] = '.';

				while ((map[cur][j] == '.') && cur != 12) cur++;

				map[cur - 1][j] = temp;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			scanf(" %c", &map[i][j]);
		}
	}

	while (1) {
		flag = false;
		memset(check, false, sizeof(check));
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j <= 5; j++) {
				if (map[i][j] != '.' && check[i][j] == false)
					bfs(i, j);
			}
		}
		if (flag == false) break;
		answer++;
		// 터지고난 뒤 떨어지는 단계
		drop();
	}

	printf("%d\n", answer);
	return 0;
}