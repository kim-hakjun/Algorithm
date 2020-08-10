#include <iostream>
#include <queue>

using namespace std;

int N, K;
bool visit[500001][2];

int BFS() {
	queue<int> q;
	q.push(N);
	visit[N][0] = true;

	int time = 0;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int cur = q.front();
			q.pop();

			if (visit[K][time % 2]) {
				return time;
			}

			if (cur + 1 <= 500000 && !visit[cur + 1][(time + 1) % 2]) {
				q.push(cur + 1);
				visit[cur + 1][(time + 1) % 2] = true;
			}
			if (cur - 1 >= 0 && !visit[cur - 1][(time + 1) % 2]) {
				q.push(cur - 1);
				visit[cur - 1][(time + 1) % 2] = true;
			}
			if (cur * 2 <= 500000 && !visit[cur * 2][(time + 1) % 2]) {
				q.push(cur * 2);
				visit[cur * 2][(time + 1) % 2] = true;
			}

		}

		time++;
		K += time;
		if (K > 500000) {
			break;
		}
	}

	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> K;

	cout << BFS();
	return 0;
}