/*
VERSION2-能算基本的加减乘除幂，支持括号和浮点数以及负数
更新内容：
1. 支持负数(在input以#标记)
2. 支持幂运算(^)
3. 读取逻辑改了。先从stdin过滤掉无效(空)字符，用input进行处理
特性：
1. 输入-2^2被处理成(-2)^2
2. 单行输入输出
待办：
1. 把main弄成class封装起来
2. 有单目的负号(记作#)，但是没有单目的正号
3. 不支持 3(4) -> 3*4 =12
*/
#include <cmath>
#include <iostream>
#include <stack>
using namespace std;
double calc(double num1, double num2, char oper) {
    switch (oper) {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
    case '/': return num1 / num2;
    case '#': return -num2;
    case '^': return pow(num1, num2);
    default: return 0;
    }
}
int prec(char op) {
    switch (op) {
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    case '^': case '#': return 3; // 一元负号记作#。比如说-(1)
    default: return 0;
    }
}
void calculate(stack<char>& op, stack<double>& num) {
    double num2 = num.top(); // 后入栈的作为被减(除)数
    num.pop();
    char oper = op.top();
    op.pop();
    if (oper == '#') {
        num.push(calc(0, num2, oper));
    }
    double num1 = num.top(); // num1先入栈 num2后入栈
    num.pop();
    num.push(calc(num1, num2, oper));
};
int is_calc_op(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    else
        return 0;
}
int main() {
    stack<char>   op;
    stack<double> num;

    string number;
    string input;
    char   ch;

    /*从stdin输入，只读取有效字符存入string input中*/
    while (cin.get(ch)) {
        if (isdigit(ch) || ch == '.' || ch == '(' || ch == ')' ||
            is_calc_op(ch)) {
            input += ch;
        }
        if (ch == '\n') {
            input += ch;
            break;
        }
    }
    /*input是处理过后的字符串，逐位进行入栈出栈操作*/
    for (auto i = 0; i < input.size(); i++) {
        ch = input[i];
        char pre_ch = '\0';
        if (i > 0)
            pre_ch = input[i - 1]; // pre_ch用于负数的处理逻辑

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
        /*0. 负号(记作#)*/
        if (ch == '-' && (pre_ch == '(' || is_calc_op(pre_ch) || i == 0)) {
            op.push('#');
            continue;
        }

        /*1.运算符*/
        if (is_calc_op(ch)) {
            while (!op.empty() && op.top() != '(' && prec(ch) <= prec(op.top()))
                calculate(op, num);
            op.push(ch);
            continue;
        }
        /*2.(*/
        else if (ch == '(')
            op.push(ch);
        /*3.)*/
        else if (ch == ')') {
            while (op.top() != '(') {
                calculate(op, num);
            }
            op.pop(); // 挖掉剩余的(
        } else if (ch == '\n')
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
    while(!num.empty())num.pop();
    while(!op.empty())op.pop();
}