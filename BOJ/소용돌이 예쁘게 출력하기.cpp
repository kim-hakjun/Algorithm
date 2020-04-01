#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
long long map[50][5];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int sR, sC, eR, eC;
	cin >> sR >> sC >> eR >> eC;

	eR -= sR;
	eC -= sC;

	int curR = sR * (-1);
	int curC = sC * (-1);
	int curD = 0;

	int check = 0;

	if (0 <= curR && curR <= eR && 0 <= curC && curC <= eC) {
		map[curR][curC] = 1;
		check++;
	}	

	int cnt = 1;
	long long num = 2;
	long long maxNum = -1;
	while (check != (eR + 1) * (eC + 1)) {

		for (int i = 0; i < cnt; i++) {
			curR += dx[curD];
			curC += dy[curD];

			if (0 <= curR && curR <= eR && 0 <= curC && curC <= eC) {
				map[curR][curC] = num;
				check++;
				maxNum = num;
			}
			num++;
		}

		if (curD == 1 || curD == 3) cnt++;

		curD = (curD + 1) % 4;
	}

	int len = 0;
	while (maxNum != 0) {
		len++;
		maxNum /= 10;
	}

	for (int i = 0; i <= eR; i++) {
		for (int j = 0; j <= eC; j++) {
			cout.width(len);
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}