#include <iostream>
#include <algorithm>

using namespace std;

int x, n, arr[1000000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	while (cin >> x) {
		x *= 10000000;

		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		sort(arr, arr + n);

		bool flag = false;
		for (int i = 0; i < n; i++) {
			int one = arr[i];

			int left = i + 1;
			int right = n - 1;

			while (left <= right) {
				int mid = (left + right) / 2;

				int temp = one + arr[mid];
				if (temp == x) {
					cout << "yes " << one << " " << arr[mid] << "\n";
					flag = true;
					break;
				}
				else if (temp > x) {
					right = mid - 1;
				}
				else
					left = mid + 1;
			}
			if (flag) break;
		}
			if (!flag) cout << "danger\n";
	}

	return 0;
}