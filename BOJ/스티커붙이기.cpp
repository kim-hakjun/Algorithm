#include <iostream>
#include <vector>

using namespace std;

int R, C, K, a, b, ans;
bool check[40][40];
vector<vector<vector<int> > > sticker;

void input() {
	for (int i = 0; i < K; i++) {
		vector<vector<int> > temp;
		cin >> a >> b;
		temp.resize(a, vector<int>(b, 0));

		for (int r = 0; r < a; r++) {
			for (int c = 0; c < b; c++) {
				cin >> temp[r][c];
			}
		}
		sticker.push_back(temp);
	}
}

vector<vector<int> > trans(vector<vector<int> > param) {
	int height = param.size();
	int width = param[0].size();

	vector<vector<int> > ret;
	ret.resize(width, vector<int>(height, 0));

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {			
			ret[j][height - 1 - i] = param[i][j];
		}
	}

	return ret;
}

bool fitTest(vector<vector<int> > cur) {
	int height = cur.size();
	int width = cur[0].size();

	for (int i = 0; i <= R - height; i++) {
		for (int j = 0; j <= C - width; j++) {
			bool flag = true;
			for (int r = 0; r < height; r++) {
				for (int c = 0; c < width; c++) {
					if (cur[r][c] == 1 && check[i + r][j + c]) {
						flag = false;
						break;
					}
				}
				if (!flag) break;
			}

			// 붙힌다
			if (flag) {
				for (int r = 0; r < height; r++) {
					for (int c = 0; c < width; c++) {
						if (cur[r][c] == 1) {
							check[i + r][j + c] = true;
							ans++;						
						}
					}
				}
				return true;
			}
		}
	}
	return false;
}

void simul() {
	for (int t = 0; t < K; t++) {
		vector<vector<int> > cur = sticker[t];
		for (int dir = 0; dir < 4; dir++) {
			// 안되면 90도 회전
			if (!fitTest(cur)) {
				cur = trans(cur);
			}
			else break;
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> R >> C >> K;

	input();
	simul();

	cout << ans;
	return 0;
}