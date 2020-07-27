#include <vector>
#include <queue>

using namespace std;

bool visit[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    // �������� �ʱ�ȭ
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            visit[i][j] = false;
        }
    }

    queue<pair<int, int> > q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j] && picture[i][j] != 0) {
                number_of_area++;

                // BFS
                q.push({ i, j });
                visit[i][j] = true;

                int num = 0;
                while (!q.empty()) {
                    int cR = q.front().first;
                    int cC = q.front().second;
                    q.pop();
                    num++;

                    for (int dir = 0; dir < 4; dir++) {
                        int nR = cR + dx[dir];
                        int nC = cC + dy[dir];

                        if (nR < 0 || nC < 0 || nR >= m || nC >= n || visit[nR][nC] || picture[nR][nC] == 0) continue;

                        if (picture[i][j] == picture[nR][nC]) {
                            q.push({ nR, nC });
                            visit[nR][nC] = true;
                        }
                    }
                }

                if (num > max_size_of_one_area) max_size_of_one_area = num;
            }
        }
    }


    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}