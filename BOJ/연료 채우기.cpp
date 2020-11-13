#include<iostream>
#include<queue>

#define pii pair<int, int>
using namespace std;

int N, a, b, dest, fuel;
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<pii, vector<pii>, greater<pii> > pq;
	priority_queue<int> temp;

	cin >> N;
	while (N--) {
		cin >> a >> b;
		pq.push({ a, b });
	}
	cin >> dest >> fuel;

	while (fuel < dest) {
		while (!pq.empty()) {
			if (fuel < pq.top().first) break;
			temp.push(pq.top().second);
			pq.pop();
		}

		if (temp.empty()) {
			ans = -1;
			break;
		}

		fuel += temp.top();
		temp.pop();
		ans++;
	}

	cout << ans;
	return 0;
}