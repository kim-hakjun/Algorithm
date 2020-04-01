#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

struct medal {
	int g, s, b;
};

bool cmp(medal a, medal b) {
	if (a.g != b.g) return a.g > b.g;
	else if (a.s != b.s) return a.s > b.s;
	else if (a.b != b.b) return a.b > b.b;
}

medal nation[1001];
medal ranking[1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N, K;
	cin >> N >> K;

	int a, b, c, d;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c >> d;
		nation[a - 1] = { b,c,d };
		ranking[a - 1] = nation[a - 1];
	}

	sort(ranking, ranking + N, cmp);

	for (int i = 0; i < N; i++) {
		if (ranking[i].g == nation[K - 1].g && ranking[i].s == nation[K - 1].s && ranking[i].b == nation[K - 1].b) {
			cout << i + 1;
			break;
		}
	}

	return 0;
}