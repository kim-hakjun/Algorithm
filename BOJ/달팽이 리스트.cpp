#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int arr[200001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, v, mod, num;
	cin >> n >> m >> v;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	mod = n - v + 1;
	for (int i= 0; i < m; i++) {
		cin >> num;
		num += 1;

		if (num < v) cout << arr[num] << "\n";
		else cout << arr[v + (num - v) % mod] << "\n";
	}

	return 0;
}