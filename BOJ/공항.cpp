#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int G, P, num, ans;
bool stop = false;
int parent[100001];

int Find(int x) {
	if (parent[x] == -1) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	parent[pb] = pa;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> G >> P;

	for (int i = 0; i <= G; i++) {
		parent[i] = -1;
	}

	for (int i = 0; i < P; i++) {
		cin >> num;
		if (stop) continue;

		int pnum = Find(num);

		if (pnum > 0) {
			ans++;
			Union(pnum - 1, pnum);
		}
		else
			stop = true;
	}

	cout << ans;
	return 0;
}