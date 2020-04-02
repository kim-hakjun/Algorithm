#include <string>
#include <vector>

using namespace std;

int N, M;

vector<vector<int> > rotate_arr(vector<vector<int> > past) {
	vector<vector<int> > temp;
	temp.resize(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[j][N - 1 - i] = past[i][j];
		}
	}

	return temp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;

	N = key.size();
	M = lock.size();

	int need = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (lock[i][j] == 0) need++;
		}
	}

	int sR = N * (-1) + 1;
	int eR = M - 1;

	int sum = 0;
	bool except_flag = false;
	for (int dir = 0; dir < 4; dir++) {

		for (int i = sR; i <= eR; i++) {
			for (int j = sR; j <= eR; j++) {

				sum = 0;
				except_flag = false;

				for (int k = i; k < i + N; k++) {
					for (int l = j; l < j + N; l++) {

						if (k < 0 || l < 0 || k >= M || l >= M) continue;

						if (key[k - i][l - j] == 1 && lock[k][l] == 0) sum++;
						else if (key[k - i][l - j] == 1 && lock[k][l] == 1) except_flag = true;
					}
				}

				if (!except_flag && sum == need) return true;
			}
		}

		key = rotate_arr(key);
	}

	return false;
}