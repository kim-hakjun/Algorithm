#include <iostream>
#include <vector>
using namespace std;

int N, root, del;
int ans;
vector<int> childs[51];

void dfs(int idx) {
	bool flag = false;

	for (int i = 0; i < childs[idx].size(); i++) {
		int next = childs[idx][i];

		if (childs[idx][i] != del) {
			flag = true;
			dfs(next);
		}
	}

	if (!flag) ans++;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == -1) root = i;
		else childs[num].push_back(i);
	}
	cin >> del;

	if (del == root) ans = 0;
	else dfs(root);

	cout << ans;
	return 0;
}