#include <string>
#include <vector>

using namespace std;

vector<vector<int> > map;

bool build_pillar(int r, int c) {
	// 1. �ٴ� ���� �ְų� ���� ���� �� �κ� ���� �ְų�
	// 2. �ٸ� ��� ���� �ְų�
	if (r == 0 || (map[r][c] & (1 << 1)) || (c >= 1 && map[r][c - 1] & (1 << 1)) || (r >= 1 && map[r - 1][c] & (1 << 0))) return true;
	else return false;
}

bool build_pan(int r, int c) {
	// 1. ���� �� �κ��� ��� ���� �ְų�
	// 2. ���� �� �κ��� �ٸ� ���� ���ÿ� ����
	if (r >= 1 && ((map[r - 1][c] & (1 << 0)) || (map[r - 1][c + 1] & (1 << 0)))) return true;
	else if (c >= 1 && map[r][c - 1] & (1 << 1) && map[r][c + 1] & (1 << 1)) return true;
	else return false;
}

bool delete_pillar(int r, int c) {
	// 1. �� ��� ���� �ٸ� ����� �ְų� 
	// 2. �� ��� ���� �ٸ� ���� �ְų�
	if (map[r + 1][c] & (1 << 0) && !build_pillar(r + 1, c)) return false;
	else if (map[r + 1][c] & (1 << 1) && !build_pan(r + 1, c)) return false;
	else if (c >= 1 && map[r + 1][c - 1] & (1 << 1) && !build_pan(r + 1, c - 1)) return false;
	return true;
}

bool delete_pan(int r, int c) {
	// 1. ���� ���ڶ��� ����� �ְų�
	// 2. ���� ���ڶ��� �ٸ� ���� �ְų�
	if ((map[r][c] & (1 << 0) && !build_pillar(r, c)) || (map[r][c + 1] & (1 << 0) && !build_pillar(r, c + 1))) return false;
	else if (map[r][c - 1] & (1 << 1) && !build_pan(r, c - 1) || map[r][c + 1] & (1 << 1) && !build_pan(r, c + 1)) return false;

	return true;
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;

	map.resize(n + 1, vector<int>(n + 1, 0));

	for (int i = 0; i < build_frame.size(); i++) {
		int y = build_frame[i][0];
		int x = build_frame[i][1];
		int type = build_frame[i][2];
		bool build_flag = build_frame[i][3];

		if (build_flag) {	// ��ġ �۾�
			if (type == 0 && build_pillar(x, y)) {	// ���	��ġ ������ ��
				map[x][y] |= (1 << 0);
			}
			else if (type == 1 && build_pan(x, y)) {  // �� ��ġ ������ ��
				map[x][y] |= (1 << 1);
			}
		}
		else {	// ���� �۾�
			// �ϴ� ���� ��
			map[x][y] ^= (1 << type);

			if (type == 0) {
				if (!delete_pillar(x, y)) map[x][y] ^= (1 << type);
			}
			else {
				if (!delete_pan(x, y)) map[x][y] ^= (1 << type);
			}
		}
	}

	for (int j = 0; j < n + 1; j++) {
		for (int i = 0; i < n + 1; i++) {
			if (map[i][j] != 0) {
				if (map[i][j] & (1 << 0)) answer.push_back({ j, i, 0 });
				if (map[i][j] & (1 << 1)) answer.push_back({ j, i, 1 });
			}
		}
	}

	return answer;
}