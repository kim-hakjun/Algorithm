#include<iostream>
#include<vector>

using namespace std;

int N, ans;
bool notPrime[4000001];	// false: 소수
vector<int> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	// 1. 소수 판별(에라토스테네스의 체) 및 벡터 배열에 추가
	notPrime[1] = true;
	for (int cur = 2; cur <= N; cur++) {

		if (!notPrime[cur]) {
			arr.push_back(cur);
			int i = 2;
			while (cur * i <= N) {
				notPrime[cur * i] = true;
				i++;
			}
		}
	}

	// 2. 투포인터 알고리즘
	int left = 0;
	int sum = 0;
	for (int right = 0; right < arr.size(); right++) {
		sum += arr[right];

		while (left <= right) {

			if (sum < N) {
				break;
			}
			else {
				if (sum == N) {
					ans++;
				}
				sum -= arr[left++];
			}
		}
	}

	cout << ans;
	return 0;
}