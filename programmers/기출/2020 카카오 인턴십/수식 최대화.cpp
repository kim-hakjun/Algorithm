#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

#define ABS(A) (A > 0) ? A : -(A)
using namespace std;

unordered_map<char, int> m;

// 연산 순서 경우의 수
char oper[6][3] = {
    {'+', '-', '*'},
    {'+', '*', '-'},
    {'-', '+', '*'},
    {'-', '*', '+'},
    {'*', '+', '-'},
    {'*', '-', '+'}
};

long long calc(long long a, long long b, char op) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
}

long long val(int idx, string exp) {
    for (int i = 0; i < 3; i++) {
        m[oper[idx][i]] = i;
    }

    stack<long long> nums;
    stack<char> opers;

    string temp;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*') {
            nums.push(stoll(temp));
            temp.clear();

            while (!opers.empty() && m[opers.top()] >= m[exp[i]]) {
                long long B = nums.top(); nums.pop();
                long long A = nums.top(); nums.pop();
                nums.push(calc(A, B, opers.top()));
                opers.pop();
            }
            opers.push(exp[i]);

        }
        else {
            temp += exp[i];
        }
    }

    nums.push(stoll(temp));
    while (!opers.empty()) {
        long long B = nums.top(); nums.pop();
        long long A = nums.top(); nums.pop();
        nums.push(calc(A, B, opers.top()));

        opers.pop();
    }

    return nums.top();
}

long long solution(string expression) {
    long long answer = 0;

    for (int i = 0; i < 6; i++) {
        long long res = val(i, expression);
        res = ABS(res);
        answer = answer < res ? res : answer;
    }

    return answer;
}