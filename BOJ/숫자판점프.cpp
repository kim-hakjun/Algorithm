#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

char info[5][5];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
unordered_map<string, bool> m;

void dfs(string cur, int cR, int cC, int cnt) {
	if (cnt == 6) {
		if (!m[cur]) {
			m[cur] = true;
		}
		return;
	}

	for (int dir = 0; dir < 4; dir++) {		
		int nR = cR + dx[dir];
		int nC = cC + dy[dir];

		if (nR < 0 || nC < 0 || nR >= 5 || nC >= 5) continue;

		dfs(cur + info[nR][nC], nR, nC, cnt + 1);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> info[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			string start = "";
			start += info[i][j];

			dfs(start, i, j, 1);
		}
	}

	cout << m.size();

	return 0;
}