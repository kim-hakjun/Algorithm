/*
	손님이 기다린 총 시간 찾기
*/

#include<iostream>
#include<queue>

using namespace std;

// Test case
int n = 2;
vector<pair<int, int> > info = { {1, 7}, {2, 8}, {5, 5} };
bool use[101];
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;	// {끝나는 시간, 창구}

	for (int i = 0; i < info.size(); i++) {
		while (!pq.empty()) {
			int endTime = pq.top().first;	// 가장 빨리 끝날 시간
			int num = pq.top().second;	// 가장 빨리 끝날 창구 번호

			if (endTime < info[i].first) {
				pq.pop();
			}
			else {
				if (pq.size() == n) {	// 모든 창구가 사용중일 경우
					ans += (endTime - info[i].first);
					pq.pop();
					pq.push({ info[i].first + info[i].second, num });
				}
				else {	// 빈 창구가 있을 경우
					for (int j = 1; j <= n; j++) {
						if (!use[j]) {
							use[j] = true;
							pq.push({ info[i].first + info[i].second, j });
							break;
						}
					}
				}
				break;
			}
		}

		// 모든 창구가 비었을 경우
		if (pq.empty()) {
			pq.push({ info[i].first + info[i].second, 1 });
			use[1] = true;
		}
	}

	cout << ans;
	return 0;
}