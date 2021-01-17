#include<iostream>

#define SIZE 1000001
#define ll long long
using namespace std;

int N, M, K, a, b ,c;
ll arr[SIZE];
ll tree[4 * SIZE];

ll initTree(int start, int end, int node) {

	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = initTree(start, mid, node * 2) + initTree(mid + 1, end, node * 2 + 1);
}

// arr의 left ~ right sum 출력
ll sum(int start, int end, int node, int left, int right) {

	if (left > end || right < start) return 0;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

// arr의 target번째 newVal로 갱신 -> 세그먼트트리 갱신
void update(int start, int end, int node, int target, int newVal) {

	if (target < start || target > end) return;
	tree[node] -= (arr[target] - newVal);

	if (start == end) return;

	int mid = (start + end) / 2;
	update(start, mid, node * 2, target, newVal);
	update(mid + 1, end, node * 2 + 1, target, newVal);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	// 세그먼트 트리 초기화
	initTree(1, N, 1);

	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;

		if (a == 1) {	// b번째 수를 c로 바꿈
			update(1, N, 1, b, c);
			arr[b] = c;
		}
		else {	// b번째 수부터 c번째 수의 합 출력
			cout << sum(1, N, 1, b, c) << "\n";
		}
	}

	return 0;
}