#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define ll long long

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll X, Y;
	cin >> X >> Y;
	ll init = (Y * 100 / X);
	if (init == 99) {
		cout << -1;
		return 0;
	}

	ll ans = 1e9 + 1;
	ll from = 1;
	ll to = 1e9;
	while (from <= to) {
		ll mid = (from + to) / 2;

		if (((Y + mid) * 100 / (X + mid)) != init) {
			to = mid - 1;
			if (ans > mid) ans = mid;
		}
		else
			from = mid + 1;
	}

	cout << ans;
	return 0;
}