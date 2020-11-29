#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int N, arr[101];
bool visit[101], finish[101];
vector<int> ans;

void dfs(int cur) {
	visit[cur] = true;

	int next = arr[cur];

	if (visit[next]) {		
		if (!finish[next]) {
			ans.push_back(next);
			while (next != cur) {
				next = arr[next];

				ans.push_back(next);
			}
		}
	}
	else {
		dfs(next);
	}
	
	finish[cur] = true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			dfs(i);
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}