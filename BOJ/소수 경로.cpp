#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

bool notPrime[10000];  // false: 소수
bool visit[10000];
int T, a, b;

void getPrime() {
	for (int i = 2; i < 10000; i++) {
		if (notPrime[i]) continue;

		for (int j = i + i; j < 10000; j += i) {
			notPrime[j] = true;
		}
	}
}

int BFS(int from, int to) {
	int div[4] = { 1, 10, 100, 1000 };
	queue<int> q;
	q.push(from);
	visit[from] = true;

	int time = 0;
	while (!q.empty()) {
		int qs = q.size();

		for (int s = 0; s < qs; s++) {
			int cur = q.front();
			q.pop();

			if (cur == to) return time;

			int temp = cur;
			for (int i = 0; i < 4; i++) {  // 첫자리부터
				int each = temp % 10;

				for (int j = 0; j < 10; j++) {
					if (i == 3 && j == 0) continue;

					int next = cur - div[i] * each + div[i] * j;

					if (!notPrime[next] && !visit[next]) {
						q.push(next);
						visit[next] = true;
					}
				}
				temp /= 10;
			}
		}
		time++;
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	getPrime();

	cin >> T;
	while (T--) {
		cin >> a >> b;
		cout << BFS(a, b) << "\n";
		memset(visit, false, sizeof(visit));
	}

	return 0;
}