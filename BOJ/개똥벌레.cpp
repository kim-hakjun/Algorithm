#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N, H;
	cin >> N >> H;

	int* bot = new int[N / 2];
	int* top = new int[N / 2];
	for (int i = 0; i < (N / 2); i++) {
		cin >> bot[i] >> top[i];
	}

	sort(bot, bot + (N / 2));
	sort(top, top + (N / 2));

	int ans = 1e6;
	int cnt = 0;
	for (int i = 1; i <= H; i++) {
		int temp = 0;
		// bot : i보다 크거나 같은 최소 인덱스
		int from = 0;
		int to = N / 2;
		int mid;
		while (from < to) {
			mid = (from + to) / 2;
			if (bot[mid] < i)
				from = mid + 1;
			else
				to = mid;
		}
		temp += ((N / 2) - to);

		// top : H - i보다 큰 최소 인덱스
		from = 0;
		to = N / 2;
		while (from < to) {
			mid = (from + to) / 2;
			if (top[mid] <= H - i)
				from = mid + 1;
			else
				to = mid;
		}
		temp += ((N / 2) - to);

		if (ans > temp) {
			ans = temp;
			cnt = 1;
		}
		else if (ans == temp) cnt++;
	}

	cout << ans << " " << cnt;
	return 0;
}