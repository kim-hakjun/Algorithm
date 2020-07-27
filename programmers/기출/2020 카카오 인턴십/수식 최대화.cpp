#include <string>
#include <vector>
#include <stack>

#define ABS(A) (A > 0) ? A : -(A)
using namespace std;

// 연산 순서 경우의 수
char oper[6][3] = {
    {'+', '-', '*'},
    {'+', '*', '-'},
    {'-', '+', '*'},
    {'-', '*', '+'},
    {'*', '+', '-'},
    {'*', '-', '+'}
};

long long cal(long long X, long long Y, char op) {
    if (op == '+') return X + Y;
    else if (op == '-') return X - Y;
    else return X * Y;
}

// 후위표기식 
long long val(int idx, string expression) {
    long long A, B;
    int prior[50];
    for (int i = 0; i < 50; i++) prior[i] = 100;
    for (int i = 0; i < 3; i++) {
        prior[(int)oper[idx][i]] = i;
    }

    stack<long long> num;
    stack<char> oper;

    string temp = "";
    for (int i = 0; i < expression.length(); i++) {
        char cur = expression[i];
        if (cur == '-' || cur == '+' || cur == '*') {
            num.push(stoll(temp));
            temp.clear();
            while (!oper.empty() && prior[(int)cur] <= prior[(int)oper.top()]) {
                B = num.top(); num.pop();
                A = num.top(); num.pop();
                num.push(cal(A, B, oper.top()));
                oper.pop();
            }
            oper.push(cur);
        }
        else {
            temp += cur;
        }
    }
    num.push(stoll(temp));

    while (!oper.empty()) {
        B = num.top(); num.pop();
        A = num.top(); num.pop();
        num.push(cal(A, B, oper.top()));
        oper.pop();
    }

    return num.top();
}

long long solution(string expression) {
    long long answer = 0;

    for (int i = 0; i < 6; i++) {
        long long res = ABS(val(i, expression));
        answer = answer < res ? res : answer;
    }

    return answer;
}