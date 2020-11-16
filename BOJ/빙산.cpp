#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int R, C, ans;
int M[301][301], temp[301][301];
bool V[301][301];
bool allZero;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool isOut(int r, int c) {
	return r < 0 || c < 0 || r >= R || c >= C;
}

bool separate() {
	allZero = true;

	queue<pair<int, int> > q;
	bool firstCheck = false;
	memset(V, false, sizeof(V));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (M[i][j] != 0 && !V[i][j]) {
				allZero = false;
				if (firstCheck) {
					return true;
				}

				firstCheck = true;
				q.push({ i, j });
				V[i][j] = true;

				while (!q.empty()) {
					int cR = q.front().first;
					int cC = q.front().second;
					q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nR = cR + dx[dir];
						int nC = cC + dy[dir];

						if (isOut(nR, nC) || V[nR][nC]) continue;

						if (M[nR][nC] != 0) {
							q.push({ nR, nC });
							V[nR][nC] = true;
						}
					}
				}
			}
		}
	}

	return false;
}

void removeIce() {
	memcpy(temp, M, sizeof(M));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (M[i][j] != 0) {
				for (int dir = 0; dir < 4; dir++) {
					int nR = i + dx[dir];
					int nC = j + dy[dir];

					if (isOut(nR, nC)) continue;

					if (temp[nR][nC] == 0) {
						M[i][j]--;
						if (M[i][j] == 0) {
							break;
						}
					}
				}
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> M[i][j];
		}
	}

	// 1. 2개로 나누어지는가
	while (!separate()) {
		if (allZero) break;

		// 2. 빙산 제거
		removeIce();
		ans++;
	}

	if (allZero) cout << 0;
	else cout << ans;

	return 0;
}