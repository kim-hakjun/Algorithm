#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int T, N;
int ans;
int arr[100001];
bool visit[100001];
bool finish[100001];

void dfs(int idx) {

	visit[idx] = true;
	int nextVal = arr[idx];

	if (!visit[nextVal]) {
		dfs(nextVal);
	}
	else {
		if (!finish[nextVal]) {
			while (1) {
				ans++;
				if (nextVal == idx) break;
				nextVal = arr[nextVal];
			}
		}
	}

	finish[idx] = true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--) {
		ans = 0;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}

		memset(visit, false, sizeof(visit));
		memset(finish, false, sizeof(finish));

		for (int i = 1; i <= N; i++) {
			if (!visit[i]) {
				dfs(i);
			}
		}

		cout << N - ans << "\n";
	}
	return 0;
}