/*
	+ BOJ 5214(환승) 풀어볼 것
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, L, start, dest;
vector<int> lines[100001], station_info[100001];
bool visit_line[100001], visit_station[100001];

int BFS() {
	queue<pair<int, int> > q;

	for (int i = 0; i < station_info[start].size(); i++) {
		int line = station_info[start][i];
		if (visit_line[line]) continue;
		visit_line[line] = true;

		for (int j = 0; j < lines[line].size(); j++) {
			if (visit_station[lines[line][j]]) continue;

			q.push({ lines[line][j], 0 });
			visit_station[lines[line][j]] = true;
		}
	}

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == dest) {
			return cnt;
		}

		for (int i = 0; i < station_info[cur].size(); i++) {
			int line = station_info[cur][i];
			if (visit_line[line]) continue;
			visit_line[line] = true;

			for (int j = 0; j < lines[line].size(); j++) {
				if (visit_station[lines[line][j]]) continue;

				q.push({ lines[line][j], cnt + 1 });
				visit_station[lines[line][j]] = true;
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;
	while (L--) {
		int num;
		while (1) {
			cin >> num;
			if (num == -1) break;

			lines[L].push_back(num);
			station_info[num].push_back(L);
		}
	}
	cin >> start >> dest;

	cout << BFS();

	return 0;
}