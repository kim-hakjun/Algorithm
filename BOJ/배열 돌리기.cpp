#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int R, C, K;
int arr[301][301];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> K;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> arr[i][j];

	int num;
	if (R > C) num = C / 2;
	else num = R / 2;

	for (int dist = 0; dist < num; dist++) {
		int turn = K % (2 * R + 2 * C - 8 * dist - 4);

		while (turn--) {
			int first = arr[dist][dist];
			// 霉青
			for (int col = dist + 1; col < C - dist; col++) {
				arr[dist][col - 1] = arr[dist][col];
			}

			// 场凯
			for (int row = dist + 1; row < R - dist; row++) {
				arr[row - 1][C - 1 - dist] = arr[row][C - 1 - dist];
			}

			// 场青
			for (int col = C - 1 - dist - 1; col >= dist; col--) {
				arr[R - 1 - dist][col + 1] = arr[R - 1 - dist][col];
			}

			// 霉凯
			for (int row = R - 1 - dist - 1; row > dist; row--) {
				arr[row + 1][dist] = arr[row][dist];
			}
			arr[dist + 1][dist] = first;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}