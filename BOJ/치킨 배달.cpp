#include <iostream>
#include <vector>

#define ABS(A) ((A < 0) ? -(A) : (A))

using namespace std;

const int INF = 1e9;

int ans;
int N, M;
int A[50][50];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visit[50][50];
vector<pair<int, int>> total, temp;

void sol() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] == 1) {
				int minDist = INF;
				for (int k = 0; k < M; k++) {
					int dist = ABS(temp[k].first - i) + ABS(temp[k].second - j);
					if (minDist > dist) {
						minDist = dist;
					}
				}
				cnt += minDist;
			}
		}
	}

	if (ans > cnt) ans = cnt;
}

void selectChic(int idx, int num) {
	if (num == M) {
		sol();
		return;
	}

	for (int i = idx; i < total.size(); i++) {
		temp.push_back(total[i]);
		selectChic(i + 1, num + 1);
		temp.pop_back();
	}
}

void input() {
	ans = INF;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			if (A[i][j] == 2) {
				total.push_back({ i, j });
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	input();
	selectChic(0, 0);

	cout << ans;
	return 0;
}