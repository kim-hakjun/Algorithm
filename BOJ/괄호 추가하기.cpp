#include<iostream>
#include<string>

using namespace std;

int N, ans;
bool firstFlag = false;
string ex;

int calc(int a, int b, char oper) {
	if (oper == '+') return a + b;
	else if (oper == '-') return a - b;
	else return a * b;
}


void dfs(int idx, int sum) {
	if (idx >= ex.length()) {		
		if (idx == ex.length() - 1) {
			sum = calc(sum, ex[idx], ex[idx - 1]);
		}

		if (!firstFlag) {
			ans = sum;
			firstFlag = true;
		}
		else {
			ans = ans > sum ? ans : sum;		
		}

		return;
	}

	// 괄호 안했을 때
	if (idx == 0) {
		dfs(idx + 2, ex[idx] - '0');
	}
	else {
		dfs(idx + 2, calc(sum, ex[idx] - '0', ex[idx - 1]));
	}

	// 괄호 했을 때
	if (idx == 0) {
		dfs(idx + 4, calc(ex[idx] - '0', ex[idx + 2] - '0', ex[idx + 1]));
	}
	else if (idx != ex.length() - 1) {
		dfs(idx + 4, calc(sum, calc(ex[idx] - '0', ex[idx + 2] - '0', ex[idx + 1]), ex[idx - 1]));
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> ex;

	dfs(0, 0);

	cout << ans;
	return 0;
}