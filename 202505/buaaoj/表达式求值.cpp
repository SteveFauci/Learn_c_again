#include <iostream>
#include <stack>
double calc(double num1, double num2, char oper) {
    switch (oper) {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        return num1 / num2;
    default:
        return 0;
    }
}
using namespace std;
int main() {
    stack<char>   op;
    stack<double> num;
    string        number;

    char ch;
    while (cin.get(ch)) {
        if (ch == '\n')
            break;
        if (isdigit(ch) || ch == '.') {
            number += ch;
        } else {
            if (!number.empty()) {
                num.push(stod(number));
                number.clear();
            } // 读到数字如114.514转为string再转为double并压入栈中
            if (ch == '+' || ch == '-') {
                if (op.empty())
                    op.push(ch);
                else {
                    char temp = op.top();
                    if (temp == '(')
                        op.push(ch);
                    else {
                        double num1 = num.top();
                        num.pop();
                        double num2 = num.top();
                        num.pop();
                        double ans0 = calc(num2, num1, temp);
                        num.push(ans0);
                        op.pop();
                    };
                }
            } else if (ch == '*' || ch == '/') {
                if (op.empty())
                    op.push(ch);
                else {
                    char temp = op.top();
                    if (temp == '(' || temp == '+' || temp == '-')
                        op.push(ch);
                    else {
                        double num1 = num.top();
                        num.pop();
                        double num2 = num.top();
                        num.pop();
                        double ans0 = calc(num2, num1, temp);
                        num.push(ans0);
                        op.pop();
                    };
                }
            } else if (ch == '(') {
                op.push(ch);
            } else if (ch == ')') {
                if (!op.empty()) {
                    char temp = op.top();
                    while (op.top() != '(') {
                        double num1 = num.top();
                        num.pop();
                        double num2 = num.top();
                        num.pop();
                        double ans0 = calc(num2, num1, temp);
                        num.push(ans0);
                        op.pop();
                        temp = op.top();
                    }
                    op.pop();
                }
            }
        }
    }
    if (!number.empty()) {
        num.push(stod(number));
        number.clear();
    }
    while (!op.empty()) {
        if (!op.empty()) {
            char   temp = op.top();
            double num1 = num.top();
            num.pop();
            double num2 = num.top();
            num.pop();
            double ans0 = calc(num2, num1, temp);
            num.push(ans0);
            op.pop();
        }
    }
    double ans = num.top();
    cout << ans << endl;
}