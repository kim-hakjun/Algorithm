#include<iostream>

using namespace std;

int N, S, len, arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int left = 0;
	long long sum = 0;

	for (int right = 0; right < N; right++) {
		sum += arr[right];

		while (left <= right && left < N) {			
			if (sum < S) {
				break;
			}
			else {
				if (sum >= S) {
					len = len == 0 ? right - left + 1 : (len < right - left + 1 ? len : right - left + 1);
				}
				sum -= arr[left++];
			}
		}
	}

	cout << len;
	return 0;
}