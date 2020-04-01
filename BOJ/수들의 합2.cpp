#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N, M, ans;
int arr[10001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int sum = 0;
	int left = 0;

	for (int right = 0; right < N; right++) {
		sum += arr[right];

		while (1) {
			if (sum < M) break;
			else if (sum >= M) {
				if (sum == M) ans++;
				sum -= arr[left++];
			}
		}
	}

	cout << ans;
	return 0;

/*
	for (int i = 0; i < N; i++) {
		long long sum = 0;
		for (int j = i; j < N; j++) {
			sum += arr[j];

			if (sum >= M) {
				if (sum == M) ans++;
				break;
			}
		}
	}
*/
}