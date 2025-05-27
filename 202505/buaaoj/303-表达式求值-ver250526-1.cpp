/*
VERSION1-能算基本的加减乘除，支持括号和浮点数
特性 1.不能处理负号 2.除以0不报错 3.读取逻辑是逐个读入字符while (cin.get(ch))，以后改
*/
#include <iostream>
#include <stack>
using namespace std;
double calc(double num1, double num2, char oper) {
    switch (oper) {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
    case '/': return num1 / num2;
    default: return 0;
    }
}
int prec(char op) {
    switch (op) {
    case '+': case '-':return 1;
    case '*': case '/':return 2;
    default: return 0;
    }
}
void calculate(stack<char>& op, stack<double>& num) {
    double num1 = num.top();
    num.pop();
    double num2 = num.top();
    num.pop();
    char temp = op.top();
    op.pop();
    num.push(calc(num2, num1, temp));
};
int main() {
    stack<char>   op;
    stack<double> num;

    string number;

    char ch;
    while (cin.get(ch)) {
        /***是数字，读入数字并入栈***/
        if (isdigit(ch) || ch == '.') {
            number += ch;
        } else {
            if (!number.empty()) {
                num.push(stod(number));
                number.clear();
            }
        }
        /***是符号***/
        /*1.运算符*/
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!op.empty() && op.top() != '(' && prec(ch) <= prec(op.top()))
                calculate(op, num);
            op.push(ch);
            continue;
        }
        /*2.(*/
        if (ch == '(')
            op.push(ch);
        /*3.)*/
        if (ch == ')') {
            while (op.top() != '(') {
                calculate(op, num);
            }
            op.pop(); // 挖掉剩余的(
        }
        if (ch == '\n')
            break;
    }
    if (!number.empty()) {
        num.push(stod(number));
        number.clear();
    }
    while (!op.empty()) {
        calculate(op, num);
    }
    cout << num.top() << endl;
    // num.pop();
}

/*
待办：
1. 加入负数ing
2. 也许要弄一个防除以0
*/