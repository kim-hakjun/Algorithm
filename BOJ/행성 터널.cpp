#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct coor {
	int num, x, y, z;
};

struct info {
	int from, to, dist;
};

int N, x, y, z, ans;
int parent[100001];
vector<coor> planets;
vector<info> dist;

bool cmpX(coor a, coor b) {
	return a.x < b.x;
}

bool cmpY(coor a, coor b) {
	return a.y < b.y;
}

bool cmpZ(coor a, coor b) {
	return a.z < b.z;
}

bool operator <(const info& a, const info& b) {
	return a.dist < b.dist;
}

int Find(int x) {
	if (parent[x] == -1) return x;
	return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
	int px = Find(x);
	int py = Find(y);

	if (px == py) return false;

	if (px < py)
		parent[py] = px;
	else
		parent[px] = py;

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;	
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> z;
		planets.push_back({ i,x,y,z });
	}

	for (int i = 0; i < N; i++) {
		parent[i] = -1;
	}

	sort(planets.begin(), planets.end(), cmpX);
	for (int i = 0; i < N - 1; i++) {
		dist.push_back({ planets[i].num, planets[i + 1].num, planets[i + 1].x - planets[i].x });
	}

	sort(planets.begin(), planets.end(), cmpY);
	for (int i = 0; i < N - 1; i++) {
		dist.push_back({ planets[i].num, planets[i + 1].num, planets[i + 1].y - planets[i].y });
	}

	sort(planets.begin(), planets.end(), cmpZ);
	for (int i = 0; i < N - 1; i++) {
		dist.push_back({ planets[i].num, planets[i + 1].num, planets[i + 1].z - planets[i].z });
	}

	sort(dist.begin(), dist.end());

	for (int i = 0; i < dist.size(); i++) {
		int from = dist[i].from;
		int to = dist[i].to;
		int diff = dist[i].dist;

		if (Union(from, to)) {
			ans += diff;
		}
	}

	cout << ans;
	return 0;
}