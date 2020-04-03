#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

long long N, type, K;
long long temp, fac, ans_val;
int chk;
bool check[21];

long long fact(int num) {	
	if (num == 1 || num == 0) return 1;	
	return num * fact(num - 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> type;

	if (type == 1) {
		cin >> K;
		K -= 1;

		for (int i = 1; i <= N; i++) {

			fac = fact(N - i);
			temp = K / fac;
			chk = 0;
			for (int j = 1; j <= N; j++) {
				if (!check[j]) {
					if (chk == temp) {
						cout << j << " ";
						check[j] = true;
						break;
					}
					chk++;
				}
			}

			K %= fac;
		}
	}
	else {
		int num;
		ans_val = 1;
		for (int i = 1; i <= N; i++) {
			cin >> num;

			fac = fact(N - i);
			chk = 0;
			for (int j = 1; j <= N; j++) {
				if (!check[j]) chk++;

				if (num == j) {
					check[num] = true;
					ans_val += ((chk - 1) * fac);
				}
			}
		}
		cout << ans_val;
	}

    return 0;
}