#include <iostream>

using namespace std;

int N, M, ans, arr[100000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int left = 0;
	int right = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] > left) left = arr[i];
		right += arr[i];
	}

	while (left <= right) {
		int mid = (left + right) / 2;
		int bal = mid;	// ÀÜ°í
		int cnt = 1;	// Ãâ±Ý È½¼ö

		for (int i = 0; i < N; i++) {
			bal -= arr[i];
			if (bal < 0) {
				cnt++;
				bal = mid - arr[i];
			}
		}

		if (cnt > M) {
			left = mid + 1;
		}
		else {
			ans = mid;
			right = mid - 1;
		}
	}

	cout << ans;
	return 0;
}