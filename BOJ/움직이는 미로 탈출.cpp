/*
	��� 56% ���� ����
	: �̵����� �ʰ� �ӹ����ų� ��湮�� ���Ǵ� ������
	  ������ V[nR][nC][time + 1] ���ϰ� V[nR][nC][time]�� üũ�ϸ� ���۴ܰ迡�� (7, 0)�� �ӹ� �� ����.
*/

#include <iostream>
#include <queue>

using namespace std;

char M[8][8];
bool V[8][8][10]; // 8�� ũ�� ü�����̹Ƿ� 3������ ũ��� 8���� ū ��
int dx[9] = { -1,-1,-1,0,0,0,1,1,1 };
int dy[9] = { -1,0,1,-1,0,1,-1,0,1 };

bool isOut(int r, int c) {
	return r < 0 || c < 0 || r >= 8 || c >= 8;
}

bool BFS() {
	queue<pair<int, int> > q;
	q.push({ 7, 0 });
	V[7][0][0] = true;

	int time = 0;
	while (!q.empty()) {
		int qs = q.size();

		while (qs--) {
			int cR = q.front().first;
			int cC = q.front().second;
			q.pop();

			if (cR == 0 && cC == 7) return true;

			for (int dir = 0; dir < 9; dir++) {
				int nR = cR + dx[dir];
				int nC = cC + dy[dir];

				// ��Ż�߰ų� �̹� �湮�� ��� ��ŵ
				if (isOut(nR, nC) || V[nR][nC][time + 1]) continue;

				// �̵��� ���� ���� �ִ� ��� ��ŵ
				if (!isOut(nR - time, nC)) {
					if (M[nR - time][nC] != '.') continue;
				}

				// �̵��� ���� ���� ������ ������ ��� ��ŵ
				if (!isOut(nR - time - 1, nC)) {
					if (M[nR - time - 1][nC] != '.') continue;
				}

				q.push({ nR, nC });
				V[nR][nC][time + 1] = true;
			}
		}
		time++;
	}

	return false;
}

void input() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> M[i][j];
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	input();
	cout << BFS();

	return 0;
}